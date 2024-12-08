/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.controller;

import pl.polsl.Głąbik.model.FloydWarshall;
import pl.polsl.Głąbik.view.Display;
import pl.polsl.Głąbik.model.Graph;

/**
 * Class responsible for passing the data to Display class
 *
 * @author Karol Głąbik
 */
public class ViewController {
    /**
     * Executes the Floyd-Warshall algorithm on the provided graph.
     * 
     * This method first displays the current state of the graph, including the 
     * initial distance matrix. It then runs the Floyd-Warshall algorithm to 
     * compute the shortest paths between all pairs of vertices. Finally, it 
     * displays the updated distance matrix after the algorithm execution.
     * 
     * @param graph graph with data about paths and costs
     * @param display represents instance of display class responsible for displaying info on the screen
     */
    public void executeFloydWarshall(FloydWarshall floydWarshall, Display display) {
        display.showEnteredPattern((Graph)floydWarshall.getGraph());
        display.showTable(floydWarshall.getGraph().getDist());
        floydWarshall.floydWarshallAlgorithm();
        display.printMessage("After execution Floyd-Warshall Algorithm:\n");
        display.showTable(floydWarshall.getGraph().getDist());
    }
}
