/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package pl.polsl.Głąbik.model;
import java.util.List;

/**
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
    @Override
    String toString();
}
