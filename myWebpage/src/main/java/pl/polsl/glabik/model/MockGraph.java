/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Glabik.model;

import java.util.List;

/**
 * Mock implementation of the {@link GraphInterface} used for testing purposes.
 * Provides predefined data for vertices, paths, and the distance matrix, 
 * and supports limited functionality to simulate graph operations.
 * 
 * This class is intended for testing and is not suitable for production use.
 * Unsupported operations throw an {@link UnsupportedOperationException}.
 * 
 * @author Karol Głąbik
 */
class MockGraph implements GraphInterface {

    // Distance matrix representing the graph's edges and their costs
    private List<List<Integer>> dist;

    // List of paths in the graph
    private List<Path> paths;

    // List of vertices in the graph
    private List<Vertice> vertices;

    /**
     * Constructor to initialize the mock graph with predefined data.
     *
     * @param dist the initial distance matrix
     * @param paths the list of paths
     * @param vertices the list of vertices
     */
    public MockGraph(List<List<Integer>> dist, List<Path> paths, List<Vertice> vertices) {
        this.dist = dist;
        this.paths = paths;
        this.vertices = vertices;
    }

    /**
     * Gets the current distance matrix.
     *
     * @return the list of lists representing the distance matrix
     */
    @Override
    public List<List<Integer>> getDist() {
        return dist;
    }

    /**
     * Gets the list of paths in the graph.
     *
     * @return the list of paths
     */
    @Override
    public List<Path> getPaths() {
        return paths;
    }

    /**
     * Gets the list of vertices in the graph.
     *
     * @return the list of vertices
     */
    @Override
    public List<Vertice> getVertices() {
        return vertices;
    }

    /**
     * Sets the distance matrix for the graph.
     *
     * @param dist the list of lists representing the new distance matrix
     */
    @Override
    public void setDist(List<List<Integer>> dist) {
        this.dist = dist;
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public PathDirectionManager getPathDirection() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void setVertices(List<Vertice> vertices) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void setPaths(List<Path> paths) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void setPathDirection(PathDirectionManager pathDirection) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void addVertice(Vertice vertice) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void removePath(int start, int end) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
    @Override
    public void removeAll() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
