/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
package pl.polsl.Głąbik.model;

import java.util.Arrays;
import java.util.List;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author Karoo
 */
public class FloydWarshallTest {

    List<Vertice> vertices;
    List<Path> paths;
    List<List<Integer>> dist;
    List<List<Integer>> distAfter;
    
    FloydWarshall fw;

    public FloydWarshallTest() {
        vertices = Arrays.asList(new Vertice(1), new Vertice(2), new Vertice(3));
        paths = Arrays.asList(
                new Path(new Vertice(1), new Vertice(2), 5),
                new Path(new Vertice(2), new Vertice(3), 10)
        );

        dist = Arrays.asList(
                Arrays.asList(0, 5, Integer.MAX_VALUE),
                Arrays.asList(Integer.MAX_VALUE, 0, 10),
                Arrays.asList(Integer.MAX_VALUE, Integer.MAX_VALUE, 0)
        );
        
        distAfter = Arrays.asList(
                Arrays.asList(0, 5, 15),
                Arrays.asList(Integer.MAX_VALUE, 0, 10),
                Arrays.asList(Integer.MAX_VALUE, Integer.MAX_VALUE, 0)
        );
    }

    @BeforeEach
    public void setUp() {
        GraphInterface graph = new MockGraph(dist, paths, vertices);
        fw = new FloydWarshall(graph, 3);
    }

    @AfterEach
    public void tearDown() {
        fw = null;
    }

    /**
     * Test of initializeDistances method, of class FloydWarshall.
     */
    @Test
    public void testInitializeDistances() {
        fw.initializeDistances();
        assertEquals(fw.getGraph().getDist(), dist, "Table of distances should be equal");
    }

    /**
     * Test of editDistance method, of class FloydWarshall.
     */
    @Test
    public void testEditDistance() {
        int start = 0;
        int end = 0;
        int cost = 0;
        fw.editDistance(start, end, cost);
        assertEquals(fw.getGraph().getDist().get(end).get(start), 0, "Distances should be equal");
    }

    /**
     * Test of floydWarshallAlgorithm method, of class FloydWarshall.
     */
    @Test
    public void testFloydWarshallAlgorithm() {
        fw.initializeDistances();
        fw.floydWarshallAlgorithm();
        assertEquals(fw.getGraph().getDist(), distAfter, "Tables of distances after floydWarshallAlg should be equal");
    }
}
