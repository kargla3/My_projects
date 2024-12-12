/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package pl.polsl.Głąbik.model;
import java.util.List;

/**
<<<<<<< HEAD
 * Interface representing the basic structure of a graph, enabling management of vertices, edges, and their costs.
 * Defines operations such as adding, removing, retrieving, and modifying graph elements.
 * 
 * @author Karol Głąbik
 */
public interface GraphInterface {
    /**
     * Retrieves the list of vertices in the graph.
     * 
     * @return a list of {@code Vertice} objects representing the vertices.
     */
    List<Vertice> getVertices();
    
    /**
     * Retrieves the list of paths (edges) in the graph.
     * 
     * @return a list of {@code Path} objects representing the paths.
     */
    List<Path> getPaths();
    
    /**
     * Retrieves the distance matrix representing the costs between vertices in the graph.
     * 
     * @return a list of lists of integers, where each value indicates the cost between vertices.
     */
    List<List<Integer>> getDist();
    
    /**
     * Retrieves the path direction manager, which handles directions of paths in the graph.
     * 
     * @return a {@code PathDirectionManager} object.
     */
    PathDirectionManager getPathDirection();
    
    /**
     * Sets the list of vertices in the graph.
     * 
     * @param vertices a list of {@code Vertice} objects to set as the graph's vertices.
     */
    void setVertices(List<Vertice> vertices);
    
    /**
     * Sets the list of paths in the graph.
     * 
     * @param paths a list of {@code Path} objects to set as the graph's paths.
     */
    void setPaths(List<Path> paths);
    
    /**
     * Sets the distance matrix representing the costs between vertices in the graph.
     * 
     * @param dist a list of lists of integers, where each value indicates the cost between vertices.
     */
    void setDist(List<List<Integer>> dist);
    
    /**
     * Sets the path direction manager, which handles directions of paths in the graph.
     * 
     * @param pathDirection a {@code PathDirectionManager} object.
     */
    void setPathDirection(PathDirectionManager pathDirection);
    
    /**
     * Adds a vertex to the graph.
     * 
     * @param vertice the {@code Vertice} object to add to the graph.
     */
    void addVertice(Vertice vertice);
    
    /**
     * Adds a path to the graph between two vertices with a specified cost.
     * 
     * @param start the starting {@code Vertice}.
     * @param end the ending {@code Vertice}.
     * @param cost the cost of the path.
     * @throws NumberFormatException if the cost is invalid (e.g., negative).
     */
    void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException;
    
    /**
     * Removes a path from the graph.
     * 
     * @param start the ID of the starting vertex.
     * @param end the ID of the ending vertex.
     */
    void removePath(int start, int end);
    
    /**
     * Removes all vertices and paths from the graph.
     */
    void removeAll();
    
    /**
     * Generates a string representation of the graph.
     * 
     * @return a {@code String} representing the graph's state.
     */
=======
 *
 * @author Karoo
 */
public interface GraphInterface {
    List<Vertice> getVertices();
    List<Path> getPaths();
    List<List<Integer>> getDist();
    PathDirectionManager getPathDirection();
    void setVertices(List<Vertice> vertices);
    void setPaths(List<Path> paths);
    void setDist(List<List<Integer>> dist);
    void setPathDirection(PathDirectionManager pathDirection);
    void addVertice(Vertice vertice);
    void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException;
    void removePath(int start, int end);
    void removeAll();
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @Override
    String toString();
}
