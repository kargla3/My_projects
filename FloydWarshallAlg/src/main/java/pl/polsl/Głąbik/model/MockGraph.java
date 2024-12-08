/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.model;

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

    public MockGraph(List<List<Integer>> dist, List<Path> paths, List<Vertice> vertices) {
        this.dist = dist;
        this.paths = paths;
        this.vertices = vertices;
    }

    @Override
    public List<List<Integer>> getDist() {
        return dist;
    }

    @Override
    public List<Path> getPaths() {
        return paths;
    }

    @Override
    public List<Vertice> getVertices() {
        return vertices;
    }
    
    @Override
    public void setDist(List<List<Integer>> dist) {
        this.dist = dist;
    }

    @Override
    public PathDirectionManager getPathDirection() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void setVertices(List<Vertice> vertices) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void setPaths(List<Path> paths) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void setPathDirection(PathDirectionManager pathDirection) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void addVertice(Vertice vertice) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void addPath(Vertice start, Vertice end, int cost) throws NumberFormatException {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void removePath(int start, int end) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void removeAll() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
