/**
 * @file practica8.c
 * @brief This program demonstrates the use of linked lists in C.
 *
 * The program defines a structure called EstructuraRep, which represents a node in a linked list.
 * It includes functions to create, print, concatenate, remove duplicates from, and free a linked list of this type.
 * The main function takes user input to create two linked lists, concatenates them, removes duplicates, and then frees the memory.
 */

/**
 * @typedef EstructuraRep* Estructura
 * @brief Defines a pointer to the EstructuraRep structure as Estructura for easier use.
 */

/**
 * @struct EstructuraRep
 * @brief Represents a node in a linked list.
 * @var EstructuraRep::elem The integer element stored in the node.
 * @var EstructuraRep::sig A pointer to the next node in the list.
 */

/**
 * @brief Creates a linked list of EstructuraRep nodes with random integer elements.
 *
 * @param n The number of nodes to create in the list.
 * @param a The lower bound for the random integer values.
 * @param b The upper bound for the random integer values.
 * @return A pointer to the first node of the created linked list.
 *
 * @note The function allocates memory for each node and initializes the 'elem' field with a random integer between 'a' and 'b' (inclusive).
 *       The first node created is a header node and does not contain any element.
 */
/**
 * @brief Prints the elements of a linked list to the console.
 *
 * @param e A pointer to the first node of the linked list.
 *
 * @note The function iterates through the list and prints the 'elem' field of each node, starting from the second node (skipping the header node).
 */
/**
 * @brief Prompts the user to enter three integers: n, a, and b.
 *
 * @param n A pointer to an integer where the user-provided value for 'n' will be stored.
 * @param a A pointer to an integer where the user-provided value for 'a' will be stored.
 * @param b A pointer to an integer where the user-provided value for 'b' will be stored.
 *
 * @note The function uses `scanf` to read the integers from the standard input.
 *       It prompts the user to enter 'n' (a non-negative integer), 'a' (an integer), and 'b' (an integer greater than or equal to 'a').
 */
/**
 * @brief Concatenates two linked lists into a new linked list.
 *
 * @param e1 A pointer to the first node of the first linked list.
 * @param e2 A pointer to the first node of the second linked list.
 * @return A pointer to the first node of the concatenated linked list.
 *
 * @note The function creates a new linked list by copying the elements from e1 and e2.
 *       The first node created is a header node and does not contain any element.
 */
/**
 * @brief Removes duplicate elements from a linked list.
 *
 * @param e A pointer to the first node of the linked list.
 *
 * @note The function iterates through the list and compares each element with the subsequent elements.
 *       If a duplicate is found, it is removed from the list.
 */
/**
 * @brief Frees the memory allocated for a linked list.
 *
 * @param e A pointer to the first node of the linked list.
 *
 * @note The function iterates through the list and frees each node.
 */
/**
 * @brief Main function of the program.
 *
 * @return 0 if the program executes successfully.
 *
 * @note The function initializes the random number generator, takes user input to create two linked lists,
 *       concatenates them, removes duplicates, prints the lists, and then frees the allocated memory.
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct EstructuraRep* Estructura;

struct EstructuraRep
{
    int elem;
    Estructura sig;
};

Estructura EstructuraCrea(int n, int a, int b)
{
    Estructura e = malloc(sizeof(struct EstructuraRep));
    Estructura aux = e;

    for(int i = 0; i < n; i++)
    {
        aux->sig = malloc(sizeof(struct EstructuraRep));
        aux = aux->sig;
        aux->elem = rand() % (b - a + 1) + a;
    }

    aux->sig = NULL;
    return e;
}

void EstructuraImprime(Estructura e)
{
    for(e = e->sig; e != NULL; e = e->sig)
    {
        printf("%d ", e -> elem);
    }
    printf("\n");
}

void PedirEntrada(int* n, int* a, int* b)
{
    printf("Introduce un numero n mayor o igual que 0: ");
    scanf("%d", n);

    printf("Introduce un numero entero a: ");
    scanf("%d", a);

    printf("Introduce un numero entero b >= a: ");
    scanf("%d", b);
}

Estructura EstructuraConcatena(Estructura e1, Estructura e2)
{
    Estructura e3 = malloc(sizeof(struct EstructuraRep));
    Estructura aux = e3;

    for(e1 = e1->sig; e1 != NULL; e1 = e1->sig)
    {
        aux->sig = malloc(sizeof(struct EstructuraRep));
        aux = aux->sig;
        aux->elem = e1->elem;
    }
    for(e2 = e2->sig; e2 != NULL; e2 = e2->sig)
    {
        aux->sig = malloc(sizeof(struct EstructuraRep));
        aux = aux->sig;
        aux->elem = e2->elem;
    }

    aux -> sig = NULL;
    return e3;
}

void EstructuraEliminaRepetidos(Estructura e) 
{
    for(e = e->sig; e != NULL; e = e->sig)
    {
        Estructura aux = e;
        while(aux->sig != NULL)
        {
            if(e->elem == aux->sig->elem)
            { 
                //Eliminar elemento repetido
                Estructura temp = aux->sig;
                aux->sig = temp->sig;
                free(temp);
            }
            else
            {
                aux = aux->sig;
            }
        }
    }
}

void EstructuraLibera(Estructura e) 
{
    Estructura aux;
    while (e != NULL) 
    {
        aux = e;
        e = e->sig;
        free(aux);
    }
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));

    int n, a, b;

    PedirEntrada(&n, &a, &b);
    Estructura e1 = EstructuraCrea(n, a, b);

    PedirEntrada(&n, &a, &b);
    Estructura e2 = EstructuraCrea(n, a, b);

    printf("Estructura 1:\n");
    EstructuraImprime(e1);
    printf("Estructura 2:\n");
    EstructuraImprime(e2);

    Estructura e3 = EstructuraConcatena(e1, e2);
    printf("Estructura concatenada:\n");
    EstructuraImprime(e3);

    EstructuraEliminaRepetidos(e3);
    printf("Estructura sin repetidos:\n");
    EstructuraImprime(e3);

    EstructuraLibera(e1);
    EstructuraLibera(e2);
    EstructuraLibera(e3);

    return 0;
}