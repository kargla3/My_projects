/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Enum.java to edit this template
 */
package pl.polsl.Glabik.model;

/**
 * Represents the direction of paths in a graph. This enumeration defines two
 * possible states for paths:
 *
 * {@code DIRECTED} - Indicates that paths have a specific direction (from a
 * starting vertex to an ending vertex).
 *
 * {@code UNDIRECTED} - Indicates that paths are bidirectional, meaning that the
 * connection between two vertices works in both directions.
 *
 * This enumeration can be used to manage and differentiate the behavior of
 * graphs or paths within a graph-based application.
 * 
 * @author Karol Głąbik
 */
public enum PathDirection {
    /**
     * Indicates that paths in the graph are directed. A directed path goes only
     * from a starting vertex to an ending vertex.
     */
    DIRECTED,
    /**
     * Indicates that paths in the graph are undirected. An undirected path
     * allows traversal in both directions between two vertices.
     */
    UNDIRECTED
}
