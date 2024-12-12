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
<<<<<<< HEAD
 * Class for testing the implementation of the Floyd-Warshall algorithm.
 * Includes tests for distance initialization, distance editing, and the main
 * algorithm.
 *
 * @author Karol Głąbik
 */
public class FloydWarshallTest {

    // Test data representing graph vertices
    List<Vertice> vertices;

    // Test data representing paths in the graph
    List<Path> paths;

    // Expected initial distance matrix before applying the algorithm
    List<List<Integer>> dist;

    // Expected distance matrix after applying the Floyd-Warshall algorithm
    List<List<Integer>> distAfter;

    // Instance of the Floyd-Warshall algorithm being tested
    FloydWarshall fw;

    /**
     * Constructor to initialize test data, including vertices, paths, and
     * distance matrices.
     */
=======
 *
 * @author Karoo
 */
public class FloydWarshallTest {

    List<Vertice> vertices;
    List<Path> paths;
    List<List<Integer>> dist;
    List<List<Integer>> distAfter;
    
    FloydWarshall fw;

>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
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
<<<<<<< HEAD

=======
        
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
        distAfter = Arrays.asList(
                Arrays.asList(0, 5, 15),
                Arrays.asList(Integer.MAX_VALUE, 0, 10),
                Arrays.asList(Integer.MAX_VALUE, Integer.MAX_VALUE, 0)
        );
    }

<<<<<<< HEAD
    /**
     * Set up a fresh instance of the Floyd-Warshall algorithm before each test.
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @BeforeEach
    public void setUp() {
        GraphInterface graph = new MockGraph(dist, paths, vertices);
        fw = new FloydWarshall(graph, 3);
    }

<<<<<<< HEAD
    /**
     * Clean up resources after each test by nullifying the Floyd-Warshall
     * instance.
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @AfterEach
    public void tearDown() {
        fw = null;
    }

    /**
<<<<<<< HEAD
     * Test the initialization of distances in the graph's distance matrix.
     * Verifies that the distance matrix matches the predefined values.
=======
     * Test of initializeDistances method, of class FloydWarshall.
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
     */
    @Test
    public void testInitializeDistances() {
        fw.initializeDistances();
        assertEquals(fw.getGraph().getDist(), dist, "Table of distances should be equal");
    }

    /**
<<<<<<< HEAD
     * Test the editing of distances in the graph's distance matrix. Includes
     * both valid and invalid inputs (e.g., negative costs).
     */
    @Test
    public void testEditDistance() {
        int[][] data = {
            {0, 0, 0},
            {1, 2, 4},
            {1, 2, -1},
            {0, 0, -4}
        };

        for (int[] testData : data) {
            if (testData[2] < 0) {
                try {
                    fw.editDistance(testData[0], testData[1], testData[2]);
                    fail("An exception should be thrown if cost is a negative number");
                } catch (NumberFormatException e) {
                }
            } else {
                fw.editDistance(testData[0], testData[1], testData[2]);
                assertEquals(fw.getGraph().getDist().get(testData[0]).get(testData[1]), testData[2],
                        "Distances should be equal: ");
            }
        }
    }

    /**
     * Test the main Floyd-Warshall algorithm. Verifies that the final distance
     * matrix matches the expected results.
=======
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
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
     */
    @Test
    public void testFloydWarshallAlgorithm() {
        fw.initializeDistances();
        fw.floydWarshallAlgorithm();
        assertEquals(fw.getGraph().getDist(), distAfter, "Tables of distances after floydWarshallAlg should be equal");
    }
}
