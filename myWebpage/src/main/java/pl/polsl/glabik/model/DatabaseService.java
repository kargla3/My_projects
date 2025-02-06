package pl.polsl.Glabik.model;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.PersistenceException;
import java.util.List;


/**
 * This class provides access to the database and manages entity persistence operations.
 * It allows storing objects in the database and retrieving all records of a specified entity type.
 * 
 * The class uses an <code>EntityManagerFactory</code> to create entity managers, 
 * which handle database transactions.
 * 
 * 
 * @author Karol Głąbik
 */
public class DatabaseService {
    private final EntityManagerFactory emf = Persistence.createEntityManagerFactory("pl.polsl.lab_WebJPA");
    
    /**
     * Persists the given object to the database.
     * 
     * This method starts a transaction, persists the object, and commits the transaction.
     * If an error occurs, the transaction is rolled back.
     * 
     * @param object the entity object to persist in the database
     * @throws PersistenceException if the persistence operation fails
     */
    public void persistObject(Object object) {
        EntityManager em = emf.createEntityManager();
        em.getTransaction().begin();
        try {
            em.persist(object);
            em.getTransaction().commit();
        } catch (PersistenceException e) {
            e.printStackTrace();
            em.getTransaction().rollback();
        } finally {
            em.close();
        }
    }
    
    /**
     * Retrieves all records of the specified entity type from the database.
     * 
     * @param <T> the type of entity to retrieve
     * @param c   the class object representing the entity type
     * @return a list of all records of the specified entity type
     */
    public <T> List<T> findAll(Class<T> c) {
        EntityManager em = emf.createEntityManager();
        try {
            String query = "SELECT e FROM " + c.getSimpleName() + " e";
            return em.createQuery(query, c).getResultList();
        } finally {
            em.close();
        }
    }
}
