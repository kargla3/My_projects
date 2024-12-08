/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.controller;

import pl.polsl.Głąbik.model.FloydWarshall;
import pl.polsl.Głąbik.model.Vertice;
import pl.polsl.Głąbik.view.Display;
import pl.polsl.Głąbik.model.Graph;

import java.util.Scanner;
/**
 * Class responsible for receiving data from user, processing it to create graph
 * 
 * @author Karol Głąbik
 */
public class ModelController {
    /**
     * Process input data from user to create graph
     * 
     * This method checks the provided command line arguments to determine 
     * if they meet the necessary conditions for creating a graph. If the 
     * conditions are not met (fewer than 2 arguments or incorrect edge 
     * specifications), it displays a pattern information message and 
     * prompts the user to manually enter the graph data. Otherwise, it 
     * parses the arguments to extract the number of vertices and edge 
     * information, and creates a graph accordingly.
     * 
     * Correct order of parameters: number of vertices Path1_vertice_start Path1_vertice_end Path1_cost Path2_vertice_start ...
     * 
     * @param args input arguments
     * @param display represents instance of display class responsible for displaying info on the screen
     * @return FloydWarshall
     */
   public FloydWarshall importData(String[] args, Display display) {
       if (args.length < 2 || (args.length - 1) % 3 != 0) {
           display.showPatternInfo();
           return createGraphMan(display);
       }
       else {
            int verticesCount = Integer.parseInt(args[0]);
            int[] edges = new int[args.length - 1];

            for (int i = 1; i < args.length; i++) {
                edges[i - 1] = Integer.parseInt(args[i]);
            }
            return createGraphArg(verticesCount, edges, display);
       }
   }

   /**
    * Creates graph manually.
    * 
    * This method ask user for essential data such as number of vertices, 
    * number of paths, and then for each path - starting point, ending point and cost.
    * If there is a wrong vertice number provided by user, it informs that error occured.
    * 
    * @param display represents instance of display class responsible for displaying info on the screen
    * @return FloydWarshall
    */
   private FloydWarshall createGraphMan(Display display) {
       Scanner scanner = new Scanner(System.in);
       display.printMessage("Enter number of vertices: ");
       int verticesCount = scanner.nextInt();
       
       Graph graphObj = new Graph();
       FloydWarshall graph = new FloydWarshall(graphObj, verticesCount);
       Vertice[] vertices = new Vertice[verticesCount];
       
       for (int i = 0; i < verticesCount; i++) {
            vertices[i] = new Vertice(i + 1);
            graph.getGraph().addVertice(vertices[i]);
       }
       
       display.printMessage("Enter number of paths: ");
       int pathsCount = scanner.nextInt();
       
       for (int i = 0; i < pathsCount; i++) {
            display.printMessage("Enter starting vertice: ");
            int start = scanner.nextInt();

            display.printMessage("Enter ending vertice: ");
            int end = scanner.nextInt();

            display.printMessage("Enter cost of path: ");
            int cost = scanner.nextInt();

            if(start < 1 || start > verticesCount || end < 1 || end > verticesCount) {
                display.printMessage("Error: The vertex used is invalid");
                continue;
            }
            
            try {
                graph.getGraph().addPath(vertices[start - 1], vertices[end - 1], cost);
            } catch (NumberFormatException e) {
                display.printMessage("Error in adding path: " + e.getMessage());
            }
        }

        graph.initializeDistances();
        return graph;
   }
   /**
    * Creates graph from parameters provided in command line
    * Correct order of parameters: number of vertices Path1_vertice_start Path1_vertice_end Path1_cost Path2_vertice_start ...
    * 
    * @param verticesCount number of vertices
    * @param pathsInfo info about paths included in graph - starting point, ending point, cost
    * @param display represents instance of display class responsible for displaying info on the screen
    * @return FloydWarshall
    */
   private FloydWarshall createGraphArg(int verticesCount, int[] pathsInfo, Display display) {
        Graph graphObj = new Graph();
        FloydWarshall graph = new FloydWarshall(graphObj, verticesCount);
       
        Vertice[] vertices = new Vertice[verticesCount];
        for(int i = 0; i < verticesCount; i++) {
            vertices[i] = new Vertice(i + 1);
            graph.getGraph().addVertice(vertices[i]);
        }
       
        for(int i = 0; i < pathsInfo.length; i += 3) {
            int start = pathsInfo[i];
            int end = pathsInfo[i+1];
            int cost = pathsInfo[i+2];
            
            if(start < 1 || start > verticesCount || end < 1 || end > verticesCount) {
                display.printMessage("Error: The vertex used is invalid");
                continue;
            }
                
            try {
                graph.getGraph().addPath(vertices[start - 1], vertices[end - 1], cost);
            } catch (NumberFormatException e) {
                display.printMessage("Error in adding path: " + e.getMessage());
            }
       }
       
       graph.initializeDistances();
       return graph;
   }
}
