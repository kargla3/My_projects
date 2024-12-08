/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.view;
import pl.polsl.Głąbik.model.Graph;
import java.util.List;

/**
 * Class provides displaying all of the data on the screen.
 * 
 * @author Karol Głąbik
 */
public class Display {
    /**
     * Displays a table of all vertices and paths provided by user.
     * If there is no path between pair of vertices, INF (infinity) is displayed.
     * The table includes headers and row labels to identify vertices.
     * 
     * @param distances 2d array of all distances between vertices
     */
    public void showTable(List<List<Integer>> distances) {
    int verticesCount = distances.size();
    System.out.print("\t");
    for (int j = 1; j <= verticesCount; j++) {
        System.out.print("V" + j + "\t");
    }
    System.out.println("\n");
        for(int i = 0; i < verticesCount; i++) {
            System.out.print("V" + (i + 1) + "\t");
            for(int j = 0; j < verticesCount; j++) {
                if(distances.get(i).get(j) == Integer.MAX_VALUE) {
                    System.out.print("INF\t");
                }
                else {
                    System.out.print(distances.get(i).get(j) + "\t");
                }
            }
            System.out.println("\n");
        }
        System.out.println();
    }
    
    /**
     * Displays information about correct order of parameters in case user didn't pass it correctly.
     */
    public void showPatternInfo() {
        System.out.println("Didnt receive correct pattern of data :");
        System.out.println("<number_of_vertices> <path_1_begin> <path_1_end> <path_1_cost> <path_2_begin> <path_2_end> <path_2_cost> ...");
        System.out.println("Switching to manual mode");
    }
    
    /**
     * Provides displaying message on the screen.
     * 
     * @param message message to be displayed
     */
    
    public void printMessage(String message) {
        System.out.println(message);
    }
    
    
    /**
     * Provides displaying details about graphs entered pattern.
     * Prints information in readable format.
     * 
     * @param graph contains vertices and paths information to be displayed.
     */
    public void showEnteredPattern(Graph graph) {
        System.out.println("Entered Pattern: ");
        System.out.println(graph.toString());
    }
}
