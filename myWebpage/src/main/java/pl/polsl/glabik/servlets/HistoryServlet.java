/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package pl.polsl.Glabik.servlets;

import pl.polsl.Glabik.model.FloydWarshall;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import pl.polsl.Glabik.model.FloydWarshall;

/**
 * The HistoryServlet class retrieves and displays the most recent Floyd-Warshall result
 * stored in the user's session. It outputs the results as an HTML table.
 *
 * This servlet handles both HTTP GET and POST requests. It uses the session attribute
 * "result" to fetch the previously calculated <code>FloydWarshall</code> object.
 *
 * @author Karol Głąbik
 * @version 1.0
 */
@WebServlet(name = "HistoryServlet", urlPatterns = {"/History"})
public class HistoryServlet extends HttpServlet {

    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        processRequest(request, response);
    }

    /**
     * Processes the request and generates an HTML page displaying the last result
     * of the Floyd-Warshall algorithm stored in the session.
     *
     * The method retrieves the <code>FloydWarshall</code> object from the session and renders
     * its distance matrix as an HTML table. Infinite values are represented as "INF".
     *
     * @param request  the servlet request
     * @param response the servlet response
     * @throws IOException if an I/O error occurs during output
     */
    private void processRequest(HttpServletRequest request, HttpServletResponse response) throws IOException {
        HttpSession session = request.getSession();
        FloydWarshall fw = (FloydWarshall) session.getAttribute("result");

        try (PrintWriter out = response.getWriter()) {
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
            out.println("    border: 0.5px solid #000;");  // Cieńszy border
            out.println("    border-collapse: collapse;");
            out.println("}");
            out.println("th, td {");
            out.println("    width: 25px;");  // Kwadratowa szerokość komórki
            out.println("    height: 25px;"); // Kwadratowa wysokość komórki
            out.println("    text-align: center;");
            out.println("    vertical-align: middle;");
            out.println("    border: 0.5px solid #000;");  // Cieńszy border dla komórek
            out.println("    padding: 5px;");
            out.println("}");
            out.println("</style>");
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Last result</h1>");
            out.println("<table>");
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
            out.println("</table>");
            out.println("<div style=\"padding: 20px;\">");
            out.println("<button onclick=\"window.history.back()\">Back</button>");
            out.println("</div>");
            out.println("</body></html>");
        }
    }
}
