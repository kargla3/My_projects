/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Glabik.model;

import java.util.List;

/**
 * Represents an abstract base class for a graph structure.
 *
 * This class provides a blueprint for managing a graph, including its vertices,
 * paths, and basic operations such as adding, removing, and retrieving
 * elements. Concrete implementations of this class must provide their own logic
 * for these operations.
 * 
 * @author Karol Głąbik
 */
public abstract class BaseGraph {

    /**
     * Retrieves the list of vertices in the graph.
     *
     * @return a list of all vertices in the graph
     */
    public abstract List<Vertice> getVertices();

    /**
     * Retrieves the list of paths in the graph.
     *
     * @return a list of all paths in the graph
     */
    public abstract List<Path> getPaths();

    /**
     * Adds a vertex to the graph.
     *
     * @param vertice the vertex to be added
     */
    public abstract void addVertice(Vertice vertice);

    /**
     * Adds a path to the graph connecting two vertices with a specified cost.
     *
     * The behavior when one or both vertices do not exist depends on the
     * implementation. Implementations may throw exceptions in such cases.
     *
     * @param start the starting vertex of the path
     * @param end the ending vertex of the path
     * @param cost the cost of the path
     * @throws NumberFormatException if the specified vertices are invalid
     */
    public abstract void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException;

    /**
     * Removes a specific path from the graph.
     *
     * The path to be removed is identified by the IDs of its start and end
     * vertices.
     *
     * @param start the ID of the starting vertex of the path to be removed
     * @param end the ID of the ending vertex of the path to be removed
     */
    public abstract void removePath(int start, int end);

    /**
     * Removes all vertices and paths from the graph.
     *
     * After calling this method, the graph will be empty.
     */
    public abstract void removeAll();

    /**
     * Returns a string representation of the graph.
     *
     * This representation may include details about vertices and paths,
     * depending on the implementation.
     *
     * @return a string describing the graph
     */
    @Override
    public abstract String toString();
}
