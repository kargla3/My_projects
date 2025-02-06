package pl.polsl.Glabik.servlets;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.net.URLEncoder;
import java.util.List;
import java.util.ArrayList;
import java.time.LocalDateTime;
import pl.polsl.Glabik.Entities.Graphs;
import pl.polsl.Glabik.Entities.Paths;
import pl.polsl.Glabik.model.Path;
import pl.polsl.Glabik.model.Vertice;
import pl.polsl.Glabik.model.FloydWarshall;
import pl.polsl.Glabik.model.GraphInterface;
import pl.polsl.Glabik.model.Graph;
import pl.polsl.Glabik.Entities.Result;
import pl.polsl.Glabik.model.DatabaseService;

/**
 * Servlet responsible for handling requests to perform calculations using the
 * Floyd-Warshall algorithm. It accepts input for the number of vertices and
 * edges (with costs) and processes the data to compute shortest paths. Results
 * are stored in the session and saved as cookies for later use.
 *
 * The servlet supports both GET and POST methods. It validates input data,
 * processes it into a graph, and calculates shortest paths using the
 * Floyd-Warshall algorithm. Cookies are created to store the input data.
 *
 * @author Karol Głąbik
 * @version 1.0
 */
@WebServlet(name = "CalculateServlet", urlPatterns = {"/Calculate"})
public class CalculateServlet extends HttpServlet {

    GraphInterface graph = new Graph();
    FloydWarshall fw;
    int numVertices;
    List<Path> paths = new ArrayList<>();
    
    DatabaseService db;
    /**
     * Handles the HTTP <code>GET</code> method Processes the input request,
     * performs calculations, and stores results in the session.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        processRequest(request, response);

        session.setAttribute("result", fw);
        session.setAttribute("db", db);
    }

    /**
     * Handles the HTTP <code>POST</code> method Processes the input request,
     * performs calculations, and stores results in the session.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        processRequest(request, response);

        session.setAttribute("result", fw);
        session.setAttribute("db", db);
    }

    /**
     * Processes the HTTP request, validates input data, updates the graph,
     * performs the Floyd-Warshall algorithm, and sends results back to the
     * client.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws IOException if an I/O error occurs
     */
    private void processRequest(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html; charset=ISO-8859-2");
        
        HttpSession session = request.getSession();
        if(session.getAttribute("db") != null) {
            db = (DatabaseService) session.getAttribute("db");
        }
        else
        {
            db = new DatabaseService();
        }

        String verticesParam = request.getParameter("numVertices");
        String pathsParam = request.getParameter("vertices");
        graph.removeAll();

        if (verticesParam == null || pathsParam == null || verticesParam.length() == 0 || pathsParam.length() == 0) {
            response.sendError(response.SC_BAD_REQUEST, "You should give two parameters!");
        } else {
            try {
                numVertices = Integer.parseInt(verticesParam);
                if (numVertices < 0) {
                    throw new NumberFormatException("Number of vertices must be positive!");
                } else {
                    for (int i = 0; i < numVertices; i++) {
                        graph.addVertice(new Vertice(i + 1));
                    }
                }

                String verticesName = "vertices_" + System.currentTimeMillis();
                Cookie verticesCookie = new Cookie(verticesName, String.valueOf(numVertices));
                verticesCookie.setMaxAge(60 * 60 * 24); // Ważne przez 1 godzinę
                response.addCookie(verticesCookie);

                String[] extract = pathsParam.split(" ");
                if (extract.length % 3 != 0) {
                    throw new NumberFormatException("Wrong pattern of data!");
                } else {
                    for (int i = 0; i < extract.length; i += 3) {
                        int start = Integer.parseInt(extract[i]);
                        int end = Integer.parseInt(extract[i + 1]);
                        int cost = Integer.parseInt(extract[i + 2]);

                        if (start > numVertices || end > numVertices) {
                            throw new NumberFormatException("Incorrect vertices provided in path info");
                        }

                        graph.addPath(new Vertice(start), new Vertice(end), cost);
                    }
                }

                String encodedPathsParam = URLEncoder.encode(pathsParam, "UTF-8");
                String pathName = "path_" + System.currentTimeMillis();
                Cookie pathsCookie = new Cookie(pathName, encodedPathsParam);
                pathsCookie.setMaxAge(60 * 60 * 24);
                response.addCookie(pathsCookie);
                
                Result result = new Result();
                result.setNumVertices(numVertices);
                result.setPaths(pathsParam);
                db.persistObject(result);
            } catch (NumberFormatException e) {
                response.sendError(response.SC_BAD_REQUEST, e.toString());
            }
        }

        fw = new FloydWarshall(graph, numVertices);
        fw.initializeDistances();

        PrintWriter out = response.getWriter();
        printAll(out);
        
        Graphs graphs = new Graphs();
        graphs.setDate(LocalDateTime.now().toString());
        db.persistObject(graphs);
        
        for(Path p : fw.getGraph().getPaths()) {
            Paths paths = new Paths();
            paths.setStart(p.start().id());
            paths.setEnd(p.end().id());
            paths.setCost(p.cost());
            paths.setGraph(graphs);
            db.persistObject(paths);
        }
    }

    /**
     * Generates and sends an HTML response displaying the results of the
     * Floyd-Warshall algorithm.
     *
     * The method creates a styled HTML document containing the input data
     * provided by the user and the results of the shortest-path calculations.
     * It also includes a back button to navigate to the previous page.
     *
     * @param out the <code>PrintWriter</code> used to send HTML response to
     * client
     */
    private void printAll(PrintWriter out) {
        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("<head><title>Results</title>");
        out.println("<style>");
        out.println("body {");
        out.println("    display: flex;");
        out.println("    flex-direction: column;");
        out.println("    justify-content: center;");
        out.println("    align-items: center;");
        out.println("    height: 100vh;");
        out.println("    margin: 0;");
        out.println("    font-family: Arial, sans-serif;");
        out.println("    background-color: #f4f4f4;");
        out.println("}");
        out.println("form {");
        out.println("    max-width: 300px;");
        out.println("    width: 100%;");
        out.println("    background: #ffffff;");
        out.println("    padding: 20px;");
        out.println("    border-radius: 8px;");
        out.println("    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);");
        out.println("}");
        out.println(".form-group {");
        out.println("    margin-bottom: 15px;");
        out.println("}");
        out.println("label {");
        out.println("    display: block;");
        out.println("    font-weight: bold;");
        out.println("    margin-bottom: 5px;");
        out.println("}");
        out.println("input {");
        out.println("    width: 100%;");
        out.println("    padding: 5px;");
        out.println("}");
        out.println("input[type='submit'] {");
        out.println("    width: auto;");
        out.println("    cursor: pointer;");
        out.println("}");
        out.println("table {");
        out.println("    border: 0.5px solid #000;");
        out.println("    border-collapse: collapse;");
        out.println("}");
        out.println("th, td {");
        out.println("    width: 25px;");
        out.println("    height: 25px;");
        out.println("    text-align: center;");
        out.println("    vertical-align: middle;");
        out.println("    border: 0.5px solid #000;");
        out.println("    padding: 5px;");
        out.println("}");
        out.println("</style>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h1>Result of calculating shortest paths using Floyd-Warshall</h1>");
        out.println("<p>Data provided by user:</p>");
        out.println("<table border=\"0.5\">");
        printTable(out);
        out.println("</table>");
        fw.floydWarshallAlgorithm();
        out.println("<p>Result:</p>");
        out.println("<table>");
        printTable(out);
        out.println("</table>");
        out.println("<div style=\"padding: 20px;\">");
        out.println("<button onclick=\"window.history.back()\">Back</button>");
        out.println("</div>");
        out.println("</body></html>");
    }

    /**
     * Prints a table representation of the graph's distance matrix to the
     * provided <code>PrintWriter</code>
     *
     * The table includes headers for row and column indices (representing
     * vertices), and displays the distances between vertices as the cell
     * values. Infinite distances are represented as "INF".
     *
     * @param out the <code>PrintWriter</code> used to generate the HTML output
     */
    private void printTable(PrintWriter out) {
        for (int i = 0; i < fw.getGraph().getVertices().size() + 1; i++) {
            out.println("<tr>");

            for (int j = 0; j < fw.getGraph().getVertices().size() + 1; j++) {
                if (i == 0 && j == 0) {
                    out.println("<th>x</th>");
                } else if (i == 0) {
                    out.println("<th>" + j + "</th>");
                } else if (j == 0) {
                    out.println("<th>" + i + "</th>");
                } else {
                    Integer current_value = fw.getGraph().getDist().get(i - 1).get(j - 1);
                    if (current_value == Integer.MAX_VALUE) {
                        out.println("<td>INF</td>");
                    } else {
                        out.println("<td>" + current_value + "</td>");
                    }
                }
            }
            out.println("</tr>");
        }
    }
}
