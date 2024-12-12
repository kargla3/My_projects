/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
package pl.polsl.Głąbik.model;

import org.junit.jupiter.api.AfterEach;
<<<<<<< HEAD
import org.junit.jupiter.api.BeforeEach;
=======
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
<<<<<<< HEAD
 * Unit tests for the {@link Path} class. Verifies the functionality and
 * correctness of methods in the {@code Path} class.
 *
 * @author Karol Głąbik
 */
public class PathTest {

    Path path;

    /**
     * Default constructor for PathTest.
     */
    public PathTest() {
    }

    /**
     * Set up the test environment by initializing the Path instance. Runs
     * before each test.
     */
=======
 *
 * @author Karoo
 */
public class PathTest {
    
    Path path;
    
    public PathTest() {
    }
    
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @BeforeEach
    public void setUp() {
        path = new Path(new Vertice(1), new Vertice(2), 5);
    }
<<<<<<< HEAD

    /**
     * Tear down the test environment by clearing the Path instance. Runs after
     * each test.
     */
=======
    
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
    @AfterEach
    public void tearDown() {
        path = null;
    }

    /**
<<<<<<< HEAD
     * Test of the {@code toString} method in the {@link Path} class. Ensures
     * the method returns the correct string representation of a path.
=======
     * Test of toString method, of class Path.
>>>>>>> d298b6d0eaaada2ef2cf83280113d80212c98ba5
     */
    @Test
    public void testToString() {
        String expected_value = "Path from 1 to 2 costs 5";
        String actual_value = path.toString();
        assertEquals(expected_value, actual_value, "Strings should be equal");
    }

}
