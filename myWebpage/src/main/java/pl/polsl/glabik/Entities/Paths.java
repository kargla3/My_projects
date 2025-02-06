package pl.polsl.Glabik.Entities;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import java.io.Serializable;
import lombok.*;

/**
 * Represents a path entity in a graph.
 * 
 * This entity stores information about a connection between two vertices,
 * including the start and end points, as well as the cost associated with the path.
 * It is linked to a <code>Graphs</code> entity through a many-to-one relationship.
 * 
 * @author Karol Głąbik
 */
@Getter
@Setter
@Entity
public class Paths implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    
    @ManyToOne
    @JoinColumn(name = "graph_id", nullable = false)
    private Graphs graph;
    
    private int start;
    private int end;
    private int cost;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        if (!(object instanceof Paths)) {
            return false;
        }
        Paths other = (Paths) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "pl.polsl.Glabik.Entities.Paths[ id=" + id + " ]";
    }
    
}
