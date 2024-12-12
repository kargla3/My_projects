/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.model;

/**
 * Record represents path in a graph with its starting vertex, ending vertex and cost
 *
 * @author Karol Głąbik
 */
//@Deprecated
//public class Path {
//    private Vertice start; //begin of the path
//    private Vertice end;   //end of the path
//    private int cost;      //cost of the path
//    
//    /**
//     * Constructs a path with information about starting vertex, ending vertex and cost
//     * 
//     * @param start represents begin of the path
//     * @param end represents end of the path
//     * @param cost represents cost of the path
//     */
//    public Path(Vertice start, Vertice end, int cost){
//        this.start = start;
//        this.end = end;
//        this.cost = cost;
//    }
//    
//    /**
//     * 
//     * @return starting vertex of path
//     */
//    public Vertice getStart(){ //returns begin of the path
//        return start;
//    }
//    
//    /**
//     * 
//     * @return ending vertex of path
//     */
//    public Vertice getEnd(){ //returns end of the path
//        return end;
//    }
//    
//    /**
//     * 
//     * @return path cost
//     */
//    public int getCost(){ //returns cost of the path
//        return cost;
//    }
//    /**
//     * 
//     * @return all information about path
//     */
//    @Override
//    public String toString(){ //returns string of info about path
//        return "Path from "+start.id()+" to "+end.id()+" costs "+cost;
//    }
//}

public record Path(Vertice start, Vertice end, int cost) {
    @Override
    public String toString(){ //returns string of info about path
        return "Path from "+start.id()+" to "+end.id()+" costs "+cost;
    }
}