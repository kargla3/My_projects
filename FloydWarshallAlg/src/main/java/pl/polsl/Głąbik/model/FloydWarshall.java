/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.model;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import lombok.*;

/**
 * Implements the Floyd-Warshall algorithm to calculate the shortest paths
 * between all pairs of vertices in a weighted graph. Extends the {@code Graph}
 * class and adds methods for initializing and executing the algorithm.
 *
 * @author Karol Głąbik
 */
@Getter
public class FloydWarshall {

    private final GraphInterface graph;

    /**
     * Constructs a {@code FloydWarshall} instance for a graph with a given
     * number of vertices.
     *
     * Initializes the distance matrix with {@code Integer.MAX_VALUE} to
     * represent infinite distances, and sets the diagonal to zero.
     *
     * @param graph
     * @param size the number of vertices in the graph
     */
    
    public FloydWarshall(GraphInterface graph, int size) {
        this.graph = graph;
        List<List<Integer>> dist = new ArrayList<>();

        for (int i = 0; i < size; i++) {
            List<Integer> row = new ArrayList<>(Arrays.asList(new Integer[size]));
            for (int j = 0; j < size; j++) {
                row.set(j, Integer.MAX_VALUE);
            }
            dist.add(row);
        }

        for (int i = 0; i < size; i++) {
            dist.get(i).set(i, 0);
        }

        graph.setDist(dist);
    }

    /**
     * Initializes the distances between vertices based on the paths added to
     * the graph.
     *
     * The distance between two connected vertices is set to the cost of the
     * path between them.
     */
    public void initializeDistances() {
        for (Path path : graph.getPaths()) {
            int m = path.start().id() - 1;
            int n = path.end().id() - 1;
            int cost = path.cost();

            graph.getDist().get(m).set(n, cost);
        }
    }

    public void editDistance(int start, int end, int cost) {
        if(cost >= 0)
            graph.getDist().get(start).set(end, cost);
        else {
            throw new NumberFormatException("Cost must be a positive number");
        }
    }

    /**
     * Executes the Floyd-Warshall algorithm to compute the shortest paths
     * between all pairs of vertices in the graph.
     *
     * Updates the {@code dist} matrix with the minimum path costs.
     */
    public void floydWarshallAlgorithm() {
        int size = graph.getVertices().size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    Integer distJI = graph.getDist().get(j).get(i);
                    Integer distIK = graph.getDist().get(i).get(k);
                    Integer distJK = graph.getDist().get(j).get(k);

                    if (distJI != Integer.MAX_VALUE && distIK != Integer.MAX_VALUE && distJI + distIK < distJK) {
                        graph.getDist().get(j).set(k, distJI + distIK);
                    }
                }
            }
        }
    }
}
