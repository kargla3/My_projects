/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
package pl.polsl.Głąbik.model;

<<<<<<< HEAD
=======
import java.util.List;
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
//import org.junit.jupiter.params.ParameterizedTest;
//import org.junit.jupiter.params.provider.CsvSource;
import static org.junit.jupiter.api.Assertions.*;

/**
<<<<<<< HEAD
 * Unit tests for the {@link Graph} class. Verifies the functionality and
 * correctness of methods in the {@code Graph} class.
 *
 * This test class includes tests for adding vertices and paths, removing paths
 * and all elements, and ensuring the {@code toString} method outputs the
 * expected string representation of the graph.
 *
 * @author Karol Głąbik
=======
 *
 * @author Karoo
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
 */
public class GraphTest {

    Graph graph;

<<<<<<< HEAD
    /**
     * Default constructor for GraphTest.
     */
    public GraphTest() {
    }

    /**
     * Set up the test environment by initializing the Graph instance. Runs
     * before each test.
     */
=======
    public GraphTest() {
    }

>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @BeforeEach
    public void setUp() {
        graph = new Graph();
    }

<<<<<<< HEAD
    /**
     * Tear down the test environment by clearing the Graph instance. Runs after
     * each test.
     */
=======
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @AfterEach
    public void tearDown() {
        graph = null;
    }

    /**
<<<<<<< HEAD
     * Test of the {@code addVertice} method in the {@link Graph} class. Ensures
     * valid vertices are added and exceptions are thrown for invalid input.
=======
     * Test of addVertice method, of class Graph.
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
     */
//    @ParametrizedTest problem with importing parametrizedtest
//    @CsvSource({
//        "1",
//        "-1"
//    })
<<<<<<< HEAD
    public void testAddVertice() {
        Integer[] data = {1, -1, 0, null};

        for (Integer n : data) {
            if (n == null) {
                try {
                    graph.addVertice(null);
                    fail("An exception should be thrown if value is null");
                } catch (NumberFormatException e) {
                }
            } else if (n > 0) {
                graph.addVertice(new Vertice(n));
                assertEquals(graph.getVertices().get(0).id(), n, "The vertex ID should be " + n);
            } else if (n < 0) {
                try {
                    graph.addVertice(new Vertice(n));
                    fail("An exception should be thrown if vertice is negative number");
                } catch (NumberFormatException e) {
                }
            } else if (n == 0) {
                try {
                    graph.addVertice(new Vertice(n));
                    fail("An exception should be thrown if vertice is 0");
                } catch (NumberFormatException e) {
                }
            }
=======
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
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
        }
    }

    /**
<<<<<<< HEAD
     * Test of the {@code addPath} method in the {@link Graph} class. Ensures
     * valid paths are added and exceptions are thrown for invalid input.
     */
    @Test
    public void testAddPath() {
        Object[][] data = {
            {new Vertice(1), new Vertice(2), 5, false},
            {null, null, 5, true},
            {new Vertice(1), null, 5, true},
            {null, new Vertice(1), 5, true},
            {new Vertice(1), new Vertice(2), -1, true}
        };

        for (Object[] testCase : data) {
            Vertice start = (Vertice) testCase[0];
            Vertice end = (Vertice) testCase[1];
            int cost = (int) testCase[2];
            boolean shouldThrowException = (boolean) testCase[3];

            if (shouldThrowException) {
                try {
                    graph.addPath(start, end, cost);
                    fail("An exception should be thrown for invalid input: " + testCase.toString());
                } catch (NumberFormatException e) {
                }
            } else {
                graph.addPath(start, end, cost);
                assertEquals(graph.getPaths().get(graph.getPaths().size() - 1),
                        new Path(start, end, cost),
                        "The path should be correctly added: " + testCase.toString());
            }
=======
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
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
        }
    }

    /**
<<<<<<< HEAD
     * Test of the {@code removePath} method in the {@link Graph} class.
     * Ensures paths are removed correctly and exceptions are thrown for invalid input.
=======
     * Test of removePath method, of class Graph.
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
     */
    @Test
    public void testRemovePath() {
        graph.addPath(new Vertice(1), new Vertice(2), 5);

<<<<<<< HEAD
        Object[][] data = {
            {1, 2, false},
            {2, 0, true},
            {0, 0, true},
            {1, 1, true}
        };

        for (Object[] testCase : data) {
            int start = (int) testCase[0];
            int end = (int) testCase[1];
            boolean shouldThrowException = (boolean) testCase[2];

            if (shouldThrowException) {
                try {
                    graph.removePath(start, end);
                    fail("An exception should be thrown for invalid input: " + testCase);
                } catch (IllegalArgumentException e) {
                    // Oczekiwany wyjątek, test zalicza
                }
            } else {
                graph.removePath(start, end);
                assertEquals(graph.getPaths().size(), 0,
                        "Size of list should be 0 after removing the path: " + testCase);
            }
=======
        graph.removePath(1, 2);
        assertEquals(graph.getPaths().size(), 0, "Size of list should be 0");
        
        try {
            graph.removePath(2,0);
            fail("An exception should be thrown if cost is a negative number");
        } catch (IllegalArgumentException e) {
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
        }
    }

    /**
<<<<<<< HEAD
     * Test of the {@code removeAll} method in the {@link Graph} class.
     * Ensures all paths and vertices are removed correctly.
=======
     * Test of removeAll method, of class Graph.
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
     */
    @Test
    public void testRemoveAll() {
        graph.addPath(new Vertice(1), new Vertice(2), 5);
        graph.addVertice(new Vertice(1));

<<<<<<< HEAD
        int verticesSize = graph.getVertices().size();
        int pathsSize = graph.getPaths().size();

        graph.removeAll();
        assertEquals(graph.getPaths().size(), 0, "Size of paths list should be 0");
        assertEquals(graph.getVertices().size(), 0, "Size of vertices list should be 0");

        assertNotEquals(graph.getVertices().size(), verticesSize, "Sizes of lists should be 0");
        assertNotEquals(graph.getPaths().size(), pathsSize, "Sizes of lists should be 0");
    }

    /**
     * Test of the {@code toString} method in the {@link Graph} class.
     * Ensures the method returns the correct string representation of the graph.
=======
        graph.removeAll();
        assertEquals(graph.getPaths().size(), 0, "Size of paths list should be 0");
        assertEquals(graph.getVertices().size(), 0, "Size of vertices list should be 0");
    }

    /**
     * Test of toString method, of class Graph.
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
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
