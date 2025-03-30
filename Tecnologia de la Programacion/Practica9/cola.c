/**
 * @file Cola.c
 * @brief Implementación del tipo abstracto de datos Cola (Queue).
 *
 * Este módulo implementa las operaciones básicas para la gestión de una cola,
 * incluyendo la creación, liberación, inserción, supresión, recuperación del
 * elemento frontal y verificación de si la cola está vacía.
 */

/**
 * @struct Celda
 * @brief Estructura interna para representar una celda en la cola.
 *
 * Cada celda contiene un elemento y un puntero a la siguiente celda en la cola.
 */

/**
 * @typedef Celda
 * @brief Define un alias para el puntero a la estructura Celda.
 */

/**
 * @struct ColaRep
 * @brief Estructura interna que representa la cola.
 *
 * Contiene punteros al frente y al posterior de la cola.
 */

/**
 * @brief Crea una cola vacía.
 *
 * Reserva memoria para la estructura de la cola y para una celda fantasma
 * que actúa como frente inicial.
 *
 * @return Cola Una cola vacía recién creada.
 */

/**
 * @brief Libera la memoria ocupada por la cola.
 *
 * Libera la memoria de cada celda de la cola y, finalmente, la memoria
 * de la estructura de la cola.
 *
 * @param c La cola a liberar.
 */

/**
 * @brief Inserta un elemento al final de la cola.
 *
 * Crea una nueva celda para el elemento y la enlaza al final de la cola.
 *
 * @param c La cola en la que se inserta el elemento.
 * @param e El elemento a insertar.
 */

/**
 * @brief Suprime el elemento del frente de la cola.
 *
 * Elimina la celda del frente de la cola y actualiza el puntero al frente.
 *
 * @param c La cola de la que se suprime el elemento.
 */

/**
 * @brief Recupera el elemento del frente de la cola.
 *
 * @param c La cola de la que se recupera el elemento.
 * @return Elemento El elemento en el frente de la cola.
 */

/**
 * @brief Verifica si la cola está vacía.
 *
 * @param c La cola a verificar.
 * @return int 1 si la cola está vacía, 0 en caso contrario.
 */
#include "Cola.h" 
#include <stdlib.h>

struct Celda 
{ 
    Elemento elem; 
    struct Celda * sig; 
}; 

typedef struct Celda * Celda; 

struct ColaRep 
{ 
    Celda frente, posterior; 
};

Cola crea() 
{ 
    Cola c = malloc(sizeof(struct ColaRep)); 
    c->frente = malloc(sizeof(struct Celda)); 
    c->frente->sig = NULL; 
    c->posterior = c->frente; 
    return c; 
} 

void libera(Cola c) 
{ 
    while(c->frente!=NULL) 
    { 
        Celda aux = c->frente; 
        c->frente = aux->sig; 
        free(aux); 
    } 
    free(c); 
}

void inserta(Cola c, Elemento e) 
{ 
    c->posterior->sig = malloc(sizeof(struct Celda)); 
    c->posterior = c->posterior->sig; 
    c->posterior->elem = e; 
    c->posterior->sig = NULL; 
} 

void suprime(Cola c) 
{ 
    Celda eliminado = c->frente; 
    c->frente = eliminado->sig; 
    free(eliminado); 
} 

Elemento recupera(Cola c) 
{ 
    return c->frente->sig->elem; 
} 

int vacia(Cola c) 
{ 
    return (c->frente->sig==NULL); 
}