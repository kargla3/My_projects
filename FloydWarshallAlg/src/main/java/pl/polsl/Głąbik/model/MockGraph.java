/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.model;

<<<<<<< HEAD
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
=======
import pl.polsl.Głąbik.model.*;
import java.util.List;

/**
 *
 * @author Karoo
 */
class MockGraph implements GraphInterface {

    private List<List<Integer>> dist;
    private List<Path> paths;
    private List<Vertice> vertices;

>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    public MockGraph(List<List<Integer>> dist, List<Path> paths, List<Vertice> vertices) {
        this.dist = dist;
        this.paths = paths;
        this.vertices = vertices;
    }

<<<<<<< HEAD
    /**
     * Gets the current distance matrix.
     *
     * @return the list of lists representing the distance matrix
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public List<List<Integer>> getDist() {
        return dist;
    }

<<<<<<< HEAD
    /**
     * Gets the list of paths in the graph.
     *
     * @return the list of paths
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public List<Path> getPaths() {
        return paths;
    }

<<<<<<< HEAD
    /**
     * Gets the list of vertices in the graph.
     *
     * @return the list of vertices
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public List<Vertice> getVertices() {
        return vertices;
    }
<<<<<<< HEAD

    /**
     * Sets the distance matrix for the graph.
     *
     * @param dist the list of lists representing the new distance matrix
     */
=======
    
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void setDist(List<List<Integer>> dist) {
        this.dist = dist;
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public PathDirectionManager getPathDirection() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void setVertices(List<Vertice> vertices) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void setPaths(List<Path> paths) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void setPathDirection(PathDirectionManager pathDirection) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void addVertice(Vertice vertice) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void removePath(int start, int end) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

<<<<<<< HEAD
    /**
     * Not supported for mock class
     * 
     * @throws UnsupportedOperationException always 
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    public void removeAll() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
