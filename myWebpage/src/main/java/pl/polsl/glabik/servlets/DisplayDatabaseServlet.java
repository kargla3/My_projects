package pl.polsl.Glabik.servlets;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.util.List;
import pl.polsl.Glabik.Entities.Result;
import pl.polsl.Glabik.model.DatabaseService;

/**
 *
 * @author Karoo
 */
@WebServlet(name = "DisplayDatabaseServlet", urlPatterns = {"/Database"})
public class DisplayDatabaseServlet extends HttpServlet {
    DatabaseService db;
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        HttpSession session = request.getSession();
        if(session.getAttribute("db") != null) {
            db = (DatabaseService) session.getAttribute("db");
        }
        else
        {
            db = new DatabaseService();
        }
        
        List<Result> resultList = db.findAll(Result.class);
        
        PrintWriter out = response.getWriter();

        out.println("<html><head><title>Last data</title>");
        out.println("<style>");
        out.println("body {");
        out.println("    display: flex;");
        out.println("    flex-direction: column;");
        out.println("    align-items: center;");
        out.println("    height: 100vh;");
        out.println("    margin: 0;");
        out.println("    font-family: Arial, sans-serif;");
        out.println("    background-color: #f4f4f4;");
        out.println("    overflow-y: auto;");
        out.println("    justify-content: flex-start;");
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
        out.println("</style>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h2>Last data:</h2>");

        for(Result result : resultList) {
            int v = result.getNumVertices();
            String p = result.getPaths();
            out.println("<p>Number of vertices: " + v + "</p>");
            out.println("<p>Paths: " + p + "</p>");
        }
        
        out.println("<div style=\"padding: 20px;\">");
        out.println("<button onclick=\"window.history.back()\">Back</button>");
        out.println("</div>");
        out.println("</body></html>");
        
        session.setAttribute("db", db);
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
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
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
