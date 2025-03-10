/**
 * @file Practica3.c
 * @brief This program prompts the user to enter integers and real numbers within specified ranges,
 *        and then generates random numbers within those ranges.
 *
 * The program includes functions for:
 *   - Clearing the input buffer.
 *   - Reading integers from the keyboard with error checking.
 *   - Reading integers within a specified range.
 *   - Generating random integers within a specified range.
 *   - Pausing the program until a key is pressed.
 *   - Reading real numbers from the keyboard with error checking.
 *   - Generating random real numbers within a specified range.
 *
 * The main function prompts the user for integer inputs (n, m, r) and real number inputs (p, k),
 * ensuring that the integers are within the range [n, m]. It then generates and displays a random
 * integer between n and m, and a random real number between p and k.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Vac�a el buffer de entrada.
void despejarEntrada(void)
{
    while( getchar() != '\n' );
}

//Lee un n�mero entero n desde teclado. Devuelve 1 si ha habido un error de lectura y 0 en caso contrario.
int leer_entero(int *n)
{
    int resultado = scanf( "%d", n );
    despejarEntrada();

    if( resultado == 1 ) return 0;
    return 1;
}

//Lee un n�mero entero n desde teclado mayor o igual que a. Devuelve 1 si ha habido un error de lectura, 2 si el n�mero es menor que a, y 0 si en otro caso.
int leer_entero_mayorIgual(int *n, int a)
{
    int dato;
    int resultado = scanf( "%d", &dato );
    despejarEntrada();

    if( resultado == 0 ) return 1;
    else if( dato < a ) return 2;

    *n = dato;
    return 0;
}

//Lee un n�mero entero n desde teclado en el rango [a,b]. Devuelve 1 si ha habido un error de lectura, 2 si el n�mero es menor que a, 3 si el n�mero es mayor que b, y 0 si ha habido �xito.
int leer_entero_rango(int * n, int a, int b)
{
    int dato;
    int resultado = scanf( "%d", &dato );
    despejarEntrada();

    if ( resultado == 0) return 1;
    else if ( dato < a ) return 2;
    else if ( dato > b ) return 3;

    *n = dato;
    return 0;
}

//Devuelve un n�mero entero aleatorio entre a y b.
int entero_aleatorio_rango(int a, int b)
{
    srand(time(NULL));
    return( a + ( rand() % (b-a+1) ) );
}

//Pausa el programa hasta que se pulse una tecla.
void pausa(void)
{
    printf("\nPulse una tecla para terminar");
    getchar();
}

//Lee un n�mero real n desde teclado. Devuelve 1 si ha habido un error de lectura y 0 en caso contrario.
int leer_real(double *n)
{
    int resultado = scanf("%lf", n);
    despejarEntrada();

    if( resultado == 0 ) return 1;
    return 0;
}

//Devuelve un n�mero real aleatorio entre a y b.
double real_aleatorio_rango(double a, double b)
{
    srand(time(NULL));
    return( a + rand() * (b - a) / RAND_MAX );
}

int main()
{
    //Activar la consola con caracteres Espa�oles
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int resultado, n, m, r, aleatorio;
    double p, k, aleatorioReal;

    do
    {
        printf("Introduzca un entero: ");
        resultado = leer_entero(&n);

        if( resultado == 1)
            printf("Formato incorrecto. Introduzca un entero: \n");
    } while (resultado != 0);

    do
    {
        printf("Introduzca un entero mayor o igual que %d: ", n);
        resultado = leer_entero_mayorIgual(&m, n);

        if( resultado == 1)
            printf("Formato incorrecto. Introduzca un entero: \n");
        else if ( resultado == 2 )
            printf("El numero debe ser mayor o igual que %d \n", n);
    } while (resultado != 0);

    do
    {
        printf("Introduzca un entero entre %d y %d: ", n, m);
        resultado = leer_entero_rango(&r, n, m);

        if( resultado == 1)
            printf("Formato incorrecto. Introduzca un entero: \n");
        else if ( resultado == 2 )
            printf("El numero debe ser mayor que %d \n", n);
        else if ( resultado == 3 )
            printf("El numero debe ser numero menor que %d \n", m);
    } while (resultado != 0);

    aleatorio = entero_aleatorio_rango(n, m);
    printf("Entero aleatorio entre %d y %d: %d \n", n, m, aleatorio);

    do
    {
        printf("Introduzca un real: ");
        resultado = leer_real(&p);

        if( resultado == 1)
            printf("Formato incorrecto. Introduzca un real: \n");
    } while (resultado != 0);

    do
    {
        printf("Introduzca otro real: ");
        resultado = leer_real(&k);

        if( resultado == 1)
            printf("Formato incorrecto. Introduzca un real: \n");
    } while (resultado != 0);

    aleatorioReal = real_aleatorio_rango(p, k);
    printf("Entero aleatorio entre %g y %g: %g \n", p, k, aleatorioReal);

    pausa();
    return 0;
}
