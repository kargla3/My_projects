/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package pl.polsl.Głąbik.floydwarshallalg;

import pl.polsl.Głąbik.model.FloydWarshall;
import pl.polsl.Głąbik.controller.*;

/**
 * Class contains main method
 *
 * @author Karol Głąbik
 */
public class FloydWarshallAlg {
    /**
     * 
     * @param args input arguments provided in command line while executing program
     * correct usage of input parameters
     * number of vertices Path1_vertice_start Path1_vertice_end Path1_cost Path2_vertice_start ...
     */
    public static void main(String[] args) {
        FloydWarshall graph = ModelController.importData(args);
        ViewController.executeFloydWarshall(graph);
    }
}
