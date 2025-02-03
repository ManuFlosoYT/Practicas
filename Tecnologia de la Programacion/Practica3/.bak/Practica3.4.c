#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void despejarEntrada(void)
{
    while( getchar() != '\n' );
}

int leer_entero(int *n)
{
    int resultado = scanf( "%d", n );
    despejarEntrada();

    if( resultado == 1 ) return 0;
    return 1;
}

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

int entero_aleatorio_rango(int a, int b)
{
    srand(time(NULL));
    return( a + ( rand() % (b-a+1) ) );
}

void pausa(void)
{
    printf("\nPulse una tecla para terminar");
    getchar();
}

int leer_real(double *n)
{
    int resultado = scanf("%lf", &n);
    despejarEntrada();

    if( resultado == 0 ) return 1;
    return 0;
}

double real_aleatorio_rango(double a, double b)
{
    srand(time(NULL));
    int random = a + rand() * ( b - a)  / RAND_MAX;
    return( random );
}

int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

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
