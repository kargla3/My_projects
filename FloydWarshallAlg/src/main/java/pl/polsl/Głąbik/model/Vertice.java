/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.model;

/**
 * Record represents vertex in a graph with his own id
 *
 * @author Karol Głąbik
 */
//public class Vertice { 
//    private int id; // number of vertex
//    
//    /**
//     * Constructs a vertex with a specified ID.
//     * 
//     * @param id number of vertex
//     */
//    public Vertice(int id){
//        this.id = id;
//    }
//    
//    /**
//     * Provides access to id of vertex
//     * 
//     * @return id of the vertex
//     */
//    public int getId(){
//        return id;
//    }
//    /**
//     * 
//     * @return String with information about vertex
//     */
//    public String getString(){ // returns info about vertex
//        return "Vertice " + id;
//    }
//}

public record Vertice(int id) {
    @Override
    public String toString() {
        return "Vertex " + id;
    }
}
