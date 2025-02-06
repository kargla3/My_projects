package pl.polsl.Glabik.Entities;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import lombok.*;

/**
 * Represents a graph entity stored in the database.
 *
 * This entity stores information about a graph, including its creation date
 * and the list of paths associated with it. The graph has a one-to-many relationship 
 * with the <code>Paths</code> entity.
 * 
 * @author Karol Głąbik
 */
@Getter
@Setter
@Entity
public class Graphs implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String date;

    @OneToMany(mappedBy = "graph")
    private List<Paths> paths = new ArrayList<>();

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
        if (!(object instanceof Graphs)) {
            return false;
        }
        Graphs other = (Graphs) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "pl.polsl.Glabik.Entities.Graphs[ id=" + id + " ]";
    }

}
