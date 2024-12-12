/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pl.polsl.Głąbik.model;

import lombok.*;

/**
 * Class manages the direction of paths in a graph, allowing for toggling
 * between directed and undirected modes.
 *
 * This class encapsulates the {@link PathDirection} enum and provides
 * functionality to toggle the path direction.
 * 
 * @author Karol Głąbik
 */
@Getter
@Setter
public class PathDirectionManager {

    /**
     * Represents the current direction of paths in the graph. Can be either
     * {@code DIRECTED} or {@code UNDIRECTED}.
     */
    private PathDirection direction;

    /**
     * Constructs a {@code PathDirectionManager} with the specified initial
     * direction.
     *
     * @param initialDirection the initial direction of the paths.
     */
    public PathDirectionManager(PathDirection initialDirection) {
        this.direction = initialDirection;
    }

    /**
     * Provides a string representation of the current path direction.
     *
     * @return a string describing the current path direction.
     */
    @Override
    public String toString() {
        return "Current Path Direction: " + direction;
    }
}
