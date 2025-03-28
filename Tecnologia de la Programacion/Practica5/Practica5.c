/**
 * @file Practica5.c
 * @brief This program demonstrates dynamic memory allocation and manipulation of arrays and matrices in C.
 *
 * The program includes functions for:
 *   - Printing arrays and matrices.
 *   - Checking if an element belongs to an array or a matrix.
 *   - Comparing two strings for equality.
 *
 * The main function allows the user to:
 *   - Input the size and elements of an array.
 *   - Search for an element in the array.
 *   - Reallocate the array to a new size and add new elements.
 *   - Input the dimensions and elements of a matrix.
 *   - Search for an element in the matrix.
 *   - Reallocate the matrix to new dimensions and add new elements.
 *   - Input two strings and compare them for equality.
 *
 * The program uses dynamic memory allocation with malloc, realloc, and free to manage the array and matrix.
 * It also uses standard input/output functions for user interaction.
 *
 * @author [Your Name]
 * @date [Date]
 */


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void ImprimirArray(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ImprimirMatriz(int f, int c, int **m)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int PerteneceArray(int v[], int n, int x)
{
    int i = 0;
    while( (i < n) && (v[i] != x) )
    {
        i++;
    }
    return i < n;
}

int PerteneceMatriz(int f, int c, int **m, int x)
{
    int i = 0;
    while( (i < f) && !PerteneceArray(m[i], c, x) )
    {
        i++;
    }
    return i < f;
}

int CadenasIguales(char c1[], char c2[])
{
    int i = 0;
    while( (c1[i] != '\0') && (c2[i] != '\0') && (c1[i] == c2[i]) )
    {
        i++;
    }
    return c1[i] == c2[i];
}


int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    printf("Introduzca el tamaño del array como un entero mayor o igual que 0: ");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Introduzca el valor de la posicion %d: ", i);
        scanf("%d", &v[i] );
    }

    printf("El array es: ");
    ImprimirArray(v, n);

    int x;
    printf("Introduzca un entero a buscar en el array: ");
    scanf("%d", &x);

    if(PerteneceArray(v, n, x))
    {
        printf("El %d pertenece al array\n", x);
    }
    else
    {
        printf("El %d no pertenece al array\n", x);
    }

    printf("Introduce el nuevo tamaño del array: ");
    int nuevo_tam;
    scanf("%d", &nuevo_tam);

    v = realloc(v, nuevo_tam * sizeof(int));

    for (int i = n; i < nuevo_tam; i++)
    {
        printf("Introduzca el valor de la posicion %d: ", i);
        scanf("%d", &v[i] );
    }

    ImprimirArray(v, nuevo_tam);

    if(PerteneceArray(v, nuevo_tam, x))
    {
        printf("El %d pertenece al array\n", x);
    }
    else
    {
        printf("El %d no pertenece al array\n", x);
    }

    free(v);


    int f;
    printf("Introduzca el largo de la matriz como un entero mayor o igual que 0: ");
    scanf("%d", &f);

    int c;
    printf("Introduzca el ancho de la matriz como un entero mayor o igual que 0: ");
    scanf("%d", &c);


    int **m = malloc(f * sizeof(int*));

    for (int i = 0; i < f; i++)
    {
        m[i] = malloc(c * sizeof(int));
    }
    

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Introduzca el valor de la posicion (%d, %d): ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    ImprimirMatriz(f, c, m);

    int u;
    printf("Introduzca un entero a buscar en la matriz: ");
    scanf("%d", &u);

    
    if( PerteneceMatriz(f, c, m, u) )
    {
        printf("El %d pertenece a la matriz\n", u);
    }
    else
    {
        printf("El %d no pertenece a la matriz\n", u);
    }

    int nuevo_filas;
    printf("Introduzca el nuevo largo de la matriz como un entero mayor o igual que 0: ");
    scanf("%d", &nuevo_filas);

    int nuevo_columnas;
    printf("Introduzca el nuevo ancho de la matriz como un entero mayor o igual que 0: ");
    scanf("%d", &nuevo_columnas);


    m = realloc(m, nuevo_filas * sizeof(int*));

    if(nuevo_filas > f)
    {
        for(int i = f; i < nuevo_filas; i++)
        {
            //m[i] = malloc(nuevo_columnas * sizeof(int));
            //Calloc inicializa a 0
            m[i] = calloc(nuevo_columnas, sizeof(int));
        }
    }

    for (int i = 0; i < nuevo_filas; i++)
    {
        for (int j = 0; j < nuevo_columnas; j++)
        {
            printf("Introduzca el valor de la posicion (%d, %d): ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    ImprimirMatriz(nuevo_filas, nuevo_columnas, m);



    for (int i = 0; i < nuevo_filas; i++)
    {
        free(m[i]);
    }
    free(m);
    
    char cadena1[100];
    char cadena2[100];

    // Consumir el carácter de nueva línea restante en el buffer
    getchar();

    printf("Introduzca una cadena de menos de 100 caracteres: ");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")] = 0; // Eliminar el salto de línea al final

    printf("Introduzca otra cadena de menos de 100 caracteres: ");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena2[strcspn(cadena2, "\n")] = 0; // Eliminar el salto de línea al final

    printf("La cadena 1 es: %s\n", cadena1);
    printf("La cadena 2 es: %s\n", cadena2);

    if( CadenasIguales(cadena1, cadena2) )
    {
        printf("Las cadenas son iguales\n");
    }
    else
    {
        printf("Las cadenas no son iguales\n");
    }

    printf("\nPulse una tecla para terminar");
    getchar();
    return 0;
}

