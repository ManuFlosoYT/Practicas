/**
 * @file Practica4.c
 * @brief This program demonstrates several basic operations on arrays, matrices, and strings in C.
 *
 * The program includes functions for:
 *   - Printing arrays and matrices.
 *   - Checking if an element belongs to an array or a matrix.
 *   - Comparing two strings for equality.
 *
 * The main function prompts the user to enter the size and elements of an array,
 * then checks if a given element belongs to the array.
 * It also prompts the user to enter the dimensions and elements of a matrix,
 * then checks if a given element belongs to the matrix.
 * Finally, it prompts the user to enter two strings and compares them for equality.
 *
 * @author [Your Name]
 * @date [Date]
 */

/**
 * @brief Prints the elements of an integer array.
 *
 * @param v The integer array to be printed.
 * @param n The number of elements in the array.
 */

/**
 * @brief Prints the elements of an integer matrix.
 *
 * @param f The number of rows in the matrix.
 * @param c The number of columns in the matrix.
 * @param m The integer matrix to be printed.
 */

/**
 * @brief Checks if an integer belongs to an integer array.
 *
 * @param v The integer array to be searched.
 * @param n The number of elements in the array.
 * @param x The integer to search for.
 * @return 1 if the integer belongs to the array, 0 otherwise.
 */

/**
 * @brief Checks if an integer belongs to an integer matrix.
 *
 * @param f The number of rows in the matrix.
 * @param c The number of columns in the matrix.
 * @param m The integer matrix to be searched.
 * @param x The integer to search for.
 * @return 1 if the integer belongs to the matrix, 0 otherwise.
 */

/**
 * @brief Checks if two strings are equal.
 *
 * @param c1 The first string.
 * @param c2 The second string.
 * @return 1 if the strings are equal, 0 otherwise.
 */

/**
 * @brief The main function of the program.
 *
 * @return 0 if the program executes successfully.
 */

#include <windows.h>
#include <stdio.h>

void ImprimirArray(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void ImprimirMatriz(int f, int c, int m[f][c])
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

int PerteneceMatriz(int f, int c, int m[f][c], int x)
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

    int v[n];

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


    int f;
    printf("Introduzca el largo de la matriz como un entero mayor o igual que 0: ");
    scanf("%d", &f);

    int c;
    printf("Introduzca el ancho de la matriz como un entero mayor o igual que 0: ");
    scanf("%d", &c);

    int m[f][c];

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
