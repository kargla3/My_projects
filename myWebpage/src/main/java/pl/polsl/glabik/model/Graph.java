/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Glabik.model;

import java.util.ArrayList;
import java.util.List;
import lombok.*;
import java.util.stream.Collectors;

/**
 * Class storages all of the vertices and paths provided by user.
 *
 * @author Karol Głąbik
 */
@Getter
@Setter
public class Graph extends BaseGraph implements GraphInterface {

    /**
     * Storages all of the vertices
     */
    private List<Vertice> vertices;
    /**
     * Storages all of the paths
     */
    private List<Path> paths;
    /**
     * Initialize a 2d arraylist of costs between vertices
     */
    private List<List<Integer>> dist;
    /**
     * Initialize a paths direction
     */
    private PathDirectionManager pathDirection;

    /**
     * Constructs lists of vertices, paths and distances between vertices. Paths
     * direction also provided.
     */
    public Graph() {
        vertices = new ArrayList<>();
        paths = new ArrayList<>();
        dist = new ArrayList<>();
        pathDirection = new PathDirectionManager(PathDirection.DIRECTED);
    }

    /**
     * This method provides adding new vertex to list
     *
     * @param vertice vertex added to list of vertices
     * @throws NumberFormatException if vertex provided by user is null or negative number.
     */
    @Override
    public void addVertice(Vertice vertice) throws NumberFormatException { //adding vertice to array
        if (vertice != null) {
            if (vertice.id() > 0) {
                vertices.add(vertice);
            } else {
                throw new NumberFormatException("Vertice should be positive number");
            }
        } else {
            throw new NumberFormatException("Vertice cant be null");
        }
    }

    /**
     * Method responsible for creating new path and adding it to the list of
     * paths. If vertex provided by user is null, then an exception is thrown.
     *
     * @param start starting vertex of path
     * @param end ending vertex of path
     * @param cost path cost
     * @throws NumberFormatException if there is invalid vertex provided by user
     */
    @Override
    public void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException { //addding path to array
        if (start == null || end == null) {
            throw new NumberFormatException("No such a vertices");
        }
        if (cost < 0) {
            throw new NumberFormatException("Cost cant be negative number");
        }
        paths.add(new Path(start, end, cost));

        if (pathDirection.getDirection() == PathDirection.UNDIRECTED) {
            paths.add(new Path(end, start, cost));
        }
    }

    /**
     * Removes a specific path from the graph.
     *
     * The path to be removed is identified by the IDs of its start and end
     * vertices. If the specified path does not exist, this method has no
     * effect.
     *
     * @param start the ID of the starting vertex of the path to be removed
     * @param end the ID of the ending vertex of the path to be removed
     * @throws IllegalArgumentException if path provided by user does not exists
     */
    @Override
    public void removePath(int start, int end) {
        if (!paths.stream().anyMatch(path -> path.start().id() == start && path.end().id() == end)) {
            throw new IllegalArgumentException("Path from " + start + " to " + end + " does not exist.");
        }
        paths.removeIf(path -> path.start().id() == start && path.end().id() == end);
    }

    /**
     * Removes all vertices and paths from the graph.
     *
     * After calling this method, the graph will be empty, and its internal
     * collections of vertices and paths will be cleared.
     */
    @Override
    public void removeAll() {
        vertices.clear();
        paths.clear();
    }

    /**
     * Returns a string representation of the graph, including details of all
     * vertices and paths.
     *
     * @return string of all vertices and paths. String contains a list of
     * vertex ID, and a list of paths each represented by its start, end
     * vertices, associated cost and direction of path ({@code DIRECTED} or
     * {@code UNDIRECTED}).
     */
    @Override
    public String toString() {
        String verticesString = vertices.stream()
                .map(vertice -> String.valueOf(vertice.id()))
                .collect(Collectors.joining(", "));

        String pathsString = paths.stream()
                .map(path -> String.format("(%d -> %d, cost: %d)",
                path.start().id(), path.end().id(), path.cost()))
                .collect(Collectors.joining("\n"));

        String directionString = "Path direction: " + pathDirection.getDirection();

        return "Vertices: " + verticesString + "\nPaths:\n" + pathsString + "\n" + directionString;
    }

}
