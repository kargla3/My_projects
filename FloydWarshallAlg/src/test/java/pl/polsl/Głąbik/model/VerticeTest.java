/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
package pl.polsl.Głąbik.model;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit tests for the {@link Vertice} class.
 * Verifies the functionality and correctness of methods in the {@code Vertice} class.
 * 
 * @author Karol Głąbik
 */
public class VerticeTest {
    Vertice vertice;
    
    /**
     * Default constructor for VerticeTest.
     */
    public VerticeTest() {
    }

    /**
     * Set up the test environment by initializing a Vertice instance.
     * Runs before each test.
     */
    @BeforeEach
    public void setUp() {
        vertice = new Vertice(1);
    }
    
    /**
     * Tear down the test environment by clearing the Vertice instance.
     * Runs after each test.
     */
    @AfterEach
    public void tearDown() {
        vertice = null;
    }

    /**
     * Test of the {@code toString} method in the {@link Vertice} class.
     * Ensures the method returns the correct string representation of the vertex.
     */
    @Test
    public void testToString() {
        String expected_value = "Vertex " + vertice.id();
        String actual_value = vertice.toString();
        assertEquals(expected_value, actual_value, "Strings should be equal");
    }
}
