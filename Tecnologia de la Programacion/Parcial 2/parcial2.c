#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Crea y devuelve un array con las cantidades anuales de un
// depósito bancario que comienza con una cantidad de c euros y
// se incrementa anualmente con interés compuesto del r%, en un
// periodo de n años, es decir:
// v0 = c
// vi= vi-1 + vi-1 ∙ r/100, 0 < i ≤ n
double* deposito(int n, double c, double r)
{
    double* v = (double*)malloc((n + 1) * sizeof(double));
    if (v == NULL)
    {
        printf("Error al asignar memoria\n");
        return NULL;
    }
    v[0] = c;
    for (int i = 1; i <= n; i++)
    {
        v[i] = v[i - 1] + v[i - 1] * r / 100;
    }
    return v;
}

//Declarar un tipo de datos Estructura para representar estructuras de datos enlazadas (lineales) de números enteros.
typedef struct Estructura
{
    int dato; //Dato de la celda
    struct Estructura* siguiente; //Apuntador a la siguiente celda de la estructura de datos enlazada
} Estructura;

//Suprime los números negativos de la estructura de datos enlazada e.
void suprimir_negativos(Estructura** e)
{
    Estructura* actual = *e;
    Estructura* anterior = NULL;

    while (actual != NULL)
    {
        if (actual->dato < 0)
        {
            Estructura* temp = actual;
            if (anterior == NULL) // El primer nodo es negativo
            {
                *e = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            actual = actual->siguiente;
            free(temp);
        }
        else
        {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

//Declarar una estructura de datos enlazada para representar árboles binarios de números enteros, de nombre ArbolBinario.
typedef struct ArbolBinario
{
    int dato; //Dato de la celda
    struct ArbolBinario* izquierdo; //Apuntador al hijo izquierdo
    struct ArbolBinario* derecho; //Apuntador al hijo derecho
} ArbolBinario;


// Devuelve el número de elementos mayores que b en el árbol binario a.
int mayores(ArbolBinario a, int b)
{
    int contador = 0;
    if (a.derecho != NULL)
    {
        contador += mayores(*(a.derecho), b);
    }
    if (a.izquierdo != NULL)
    {
        contador += mayores(*(a.izquierdo), b);
    }
    if (a.dato > b)
    {
        contador++;
    }
    return contador;
}

int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    //Construir un array invocando a la función anterior para un periodo de n=5 años, cantidad inicial de 1000 euros y tasa de interés del 3% (c=1000, r=3).
    //Imprimir en pantalla los elementos del array.
    //Liberar el array.
    int n = 5;
    double c = 1000.0;
    double r = 3.0;
    double* v = deposito(n, c, r);

    if (v == NULL)
    {
        return 1;
    }

    printf("Año\tCantidad\n");
    printf("------------------\n");

    for (int i = 0; i <= n; i++)
    {
        printf("%d\t%.2f\n", i, v[i]);
    }

    free(v);
    v = NULL; // Evitar el uso de punteros colgantes



    //Leer un número m desde teclado (m≥0) y construir una estructura de datos enlazada e, con celda de encabezamiento, de m números enteros aleatorios entre -m y m.
    //Imprimir en pantalla los elementos de la estructura de datos enlazada e.


    int m;
    printf("Introduce un número entero no negativo (m): ");
    scanf("%d", &m);
    if (m < 0)
    {
        printf("El número debe ser no negativo.\n");
        return 1;
    }

    Estructura* encabezado = (Estructura*)malloc(sizeof(Estructura));
    if (encabezado == NULL)
    {
        printf("Error al asignar memoria para el encabezado\n");
        return 1;
    }
    encabezado->siguiente = NULL;
    Estructura* actual = encabezado;
    srand(time(NULL)); // Inicializar la semilla para números aleatorios

    for (int i = 0; i < m; i++)
    {
        Estructura* nuevo = (Estructura*)malloc(sizeof(Estructura));
        if (nuevo == NULL)
        {
            printf("Error al asignar memoria para un nuevo nodo\n");
            return 1;
        }
        nuevo->dato = rand() % (2 * m + 1) - m;
        nuevo->siguiente = NULL;
        actual->siguiente = nuevo;
        actual = nuevo;
    }


    actual = encabezado->siguiente;
    printf("Elementos de la estructura de datos enlazada:\n");
    while (actual != NULL)
    {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");

    //Suprimir los elementos negativos de la estructura de datos enlazada e invocando la función suprimir_negativos.
    suprimir_negativos(&encabezado->siguiente);


    //Imprimir en pantalla los elementos de la estructura de datos enlazada e.
    actual = encabezado->siguiente;
    printf("Elementos de la estructura de datos enlazada después de suprimir negativos:\n");
    while (actual != NULL)
    {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");

    //Liberar la memoria de la estructura de datos enlazada e.
    actual = encabezado->siguiente;


    //Imprimir en pantalla los elementos de la estructura de datos enlazada e.
    actual = encabezado->siguiente;
    free(encabezado); // Liberar el encabezado
    encabezado = NULL; // Evitar el uso de punteros colgantes




    //Construir un arbol binario que contenga un nodo 1 como raíz, y dos hijos izquierdo y derecho con nodos 2 y 3 respectivamente, el nodo 2 tiene un hijo izquierdo con nodo 4.
    //Imprimir en pantalla los elementos del árbol binario.
    ArbolBinario* raiz = (ArbolBinario*)malloc(sizeof(ArbolBinario));
    if (raiz == NULL)
    {
        printf("Error al asignar memoria para la raíz del árbol\n");
        return 1;
    }
    raiz->dato = 1;
    raiz->izquierdo = (ArbolBinario*)malloc(sizeof(ArbolBinario));
    if (raiz->izquierdo == NULL)
    {
        printf("Error al asignar memoria para el hijo izquierdo\n");
        free(raiz);
        return 1;
    }
    raiz->izquierdo->dato = 2;
    raiz->izquierdo->izquierdo = (ArbolBinario*)malloc(sizeof(ArbolBinario));
    if (raiz->izquierdo->izquierdo == NULL)
    {
        printf("Error al asignar memoria para el hijo izquierdo del nodo 2\n");
        free(raiz->izquierdo);
        free(raiz);
        return 1;
    }
    raiz->izquierdo->izquierdo->dato = 4;
    raiz->izquierdo->izquierdo->izquierdo = NULL;
    raiz->izquierdo->izquierdo->derecho = NULL;
    raiz->izquierdo->derecho = NULL;
    raiz->derecho = (ArbolBinario*)malloc(sizeof(ArbolBinario));
    if (raiz->derecho == NULL)
    {
        printf("Error al asignar memoria para el hijo derecho\n");
        free(raiz->izquierdo->izquierdo);
        free(raiz->izquierdo);
        free(raiz);
        return 1;
    }
    raiz->derecho->dato = 3;
    raiz->derecho->izquierdo = NULL;
    raiz->derecho->derecho = NULL;

    //Imprimir en pantalla el número de elementos mayores que un número b (leído desde teclado) del árbol a. En el ejemplo, mayores(a,b) con b=2 devuelve 2.
    int b;
    printf("Introduce un número entero (b): ");
    scanf("%d", &b);
    int resultado = mayores(*raiz, b);
    printf("Número de elementos mayores que %d en el árbol: %d\n", b, resultado);

    //Liberar la memoria del árbol binario.
    free(raiz->izquierdo->izquierdo);
    free(raiz->izquierdo);
    free(raiz->derecho);
    free(raiz);
    raiz = NULL; // Evitar el uso de punteros colgantes

    

    return 0;
}
