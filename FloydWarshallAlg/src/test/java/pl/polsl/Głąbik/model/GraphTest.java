/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
package pl.polsl.Głąbik.model;

import java.util.List;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
//import org.junit.jupiter.params.ParameterizedTest;
//import org.junit.jupiter.params.provider.CsvSource;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author Karoo
 */
public class GraphTest {

    Graph graph;

    public GraphTest() {
    }

    @BeforeEach
    public void setUp() {
        graph = new Graph();
    }

    @AfterEach
    public void tearDown() {
        graph = null;
    }

    /**
     * Test of addVertice method, of class Graph.
     */
//    @ParametrizedTest problem with importing parametrizedtest
//    @CsvSource({
//        "1",
//        "-1"
//    })
    @Test
    public void testAddVertice() {
        graph.addVertice(new Vertice(1));
        assertEquals(graph.getVertices().get(0).id(), 1, "The first vertex ID should be 1");

        try {
            graph.addVertice(new Vertice(-1));
            fail("An exception should be thrown if vertice is negative number");
        } catch (NumberFormatException e) {
        }

        try {
            graph.addVertice(null);
            fail("An exception should be thrown if value is null");
        } catch (NumberFormatException e) {
        }
    }

    /**
     * Test of addPath method, of class Graph.
     */
    @Test
    public void testAddPath() {
        graph.addPath(new Vertice(1), new Vertice(2), 5);
        assertEquals(graph.getPaths().get(0), new Path(new Vertice(1), new Vertice(2), 5), "The first path should be 1->2, cost 5");

        try {
            graph.addPath(null, null, 5);
            fail("An exception should be thrown if vertices are null");
        } catch (NumberFormatException e) {
        }

        try {
            graph.addPath(new Vertice(1), null, 5);
            fail("An exception should be thrown if vertex is null");
        } catch (NumberFormatException e) {
        }

        try {
            graph.addPath(null, new Vertice(1), 5);
            fail("An exception should be thrown if vertex is null");
        } catch (NumberFormatException e) {
        }
        
        try {
            graph.addPath(new Vertice(1), new Vertice(2), -1);
            fail("An exception should be thrown if cost is a negative number");
        } catch (NumberFormatException e) {
        }
    }

    /**
     * Test of removePath method, of class Graph.
     */
    @Test
    public void testRemovePath() {
        graph.addPath(new Vertice(1), new Vertice(2), 5);

        graph.removePath(1, 2);
        assertEquals(graph.getPaths().size(), 0, "Size of list should be 0");
        
        try {
            graph.removePath(2,0);
            fail("An exception should be thrown if cost is a negative number");
        } catch (IllegalArgumentException e) {
        }
    }

    /**
     * Test of removeAll method, of class Graph.
     */
    @Test
    public void testRemoveAll() {
        graph.addPath(new Vertice(1), new Vertice(2), 5);
        graph.addVertice(new Vertice(1));

        graph.removeAll();
        assertEquals(graph.getPaths().size(), 0, "Size of paths list should be 0");
        assertEquals(graph.getVertices().size(), 0, "Size of vertices list should be 0");
    }

    /**
     * Test of toString method, of class Graph.
     */
    @Test
    public void testToString() {
        graph.addPath(new Vertice(1), new Vertice(2), 5);
        graph.addVertice(new Vertice(1));

        String expected_output = "Vertices: 1\nPaths:\n(1 -> 2, cost: 5)\nPath direction: DIRECTED";
        String actual_output = graph.toString();
        assertEquals(expected_output, actual_output, "Strings should be equal");
    }

}
