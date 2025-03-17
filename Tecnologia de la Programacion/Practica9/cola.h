/**
 * @file cola.h
 * @brief Header file for the Cola (Queue) data structure.
 *
 * This file defines the data types and function prototypes for a queue data structure,
 * specifically designed to manage patients in a doctor's office.
 */

/**
 * @typedef struct
 * @brief Represents a patient with a name and DNI (National Identity Document).
 */

/**
 * @typedef struct ColaRep* Cola
 * @brief Represents a queue of patients.
 */

/**
 * @brief Creates an empty queue.
 * @return A pointer to the newly created empty queue.
 */

/**
 * @brief Frees the memory allocated to the queue.
 * @param c The queue to be freed.
 */

/**
 * @brief Inserts an element at the end of the queue.
 * @param c The queue to insert into.
 * @param e The element to be inserted.
 */

/**
 * @brief Removes the element at the front of the queue.
 * @param c The queue to remove from.
 */

/**
 * @brief Retrieves the element at the front of the queue.
 * @param c The queue to retrieve from.
 * @return The element at the front of the queue.
 */

/**
 * @brief Checks if the queue is empty.
 * @param c The queue to check.
 * @return 1 if the queue is empty, 0 otherwise.
 */


// Fichero Cola.h 
#ifndef COLA_H_INCLUDED 
#define COLA_H_INCLUDED 
// Tipo de datos de los elementos de las colas, el cual 
// representa pacientes de un consultorio. 
typedef struct
{ 
    char nombre[30]; 
    char DNI[10]; 
} Elemento; 
// Tipo de datos de las colas. 

typedef struct ColaRep * Cola; 

// Devuelve una cola vacía. 

Cola crea(); // Libera la memoria asignada a la cola c. 

void libera(Cola c); // Inserta el elemento e en el último lugar de la cola c. 

void inserta(Cola c, Elemento e); // Suprime el elemento situado en primer lugar de la cola c. 

void suprime(Cola c); // Devuelve el elemento situado en primer lugar de la cola c. 

Elemento recupera(Cola c); // Devuelve 0 si la cola c no es vacía, y 1 en caso contrario. 

int vacia(Cola c); 

#endif // COLA_H_ INCLUDED