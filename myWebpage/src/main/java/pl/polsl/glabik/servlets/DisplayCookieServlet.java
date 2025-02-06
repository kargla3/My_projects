/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package pl.polsl.Glabik.servlets;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.net.URLDecoder;

/**
 *
 * The DisplayCookieServlet retrieves and displays information stored in cookies.
 * It processes both GET and POST requests to display the number of vertices and paths
 * stored in cookies as HTML content.
 *
 * The servlet is mapped to the "/Cookies" URL pattern.

 * @author Karol Głąbik
 * @version 1.0
 */
@WebServlet(name = "DisplayCookieServlet", urlPatterns = {"/Cookies"})
public class DisplayCookieServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * Retrieves cookies from the request and displays their content in an HTML format.
     * Specifically, it looks for cookies with names containing "vertices" and "path".
     *
     * @param request servlet request
     * @param response servlet response
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws IOException {
        response.setContentType("text/html;charset=UTF-8");
        Cookie[] cookies = request.getCookies();

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

        if (cookies != null) {
            for (Cookie cookie : cookies) {
                String name = cookie.getName();
                String value = URLDecoder.decode(cookie.getValue(), "UTF-8");
                if (name.contains("vertices")) {
                    out.println("<p>Number of vertices: " + value + "</p>");
                } else if (name.contains("path")) {
                    out.println("<p>Paths: " + value + "</p>");
                }
            }
        } else {
            out.println("<p>No data provided in last 24h.</p>");
        }
        out.println("<div style=\"padding: 20px;\">");
        out.println("<button onclick=\"window.history.back()\">Back</button>");
        out.println("</div>");
        out.println("</body></html>");
    }

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
}
