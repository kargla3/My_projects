/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
package pl.polsl.Głąbik.model;

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
public class PathTest {
    
    Path path;
    
    public PathTest() {
    }
    
    @BeforeEach
    public void setUp() {
        path = new Path(new Vertice(1), new Vertice(2), 5);
    }
    
    @AfterEach
    public void tearDown() {
        path = null;
    }

    /**
     * Test of toString method, of class Path.
     */
    @Test
    public void testToString() {
        String expected_value = "Path from 1 to 2 costs 5";
        String actual_value = path.toString();
        assertEquals(expected_value, actual_value, "Strings should be equal");
    }

}
