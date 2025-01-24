#include <windows.h>
#include <stdio.h>

const int _distancia_tierra_luna = 384.400;
int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    double velocidadT, velocidadL;
    double distancia;
    double tiempo;
    int resultado;

    do
    {
        printf("Introduce la velocidad de la nave de la tierra en km/h: ");
        resultado = scanf("%lf", &velocidadT);
        while(getchar() != '\n');
        if(resultado != 1)
            printf("Error de formato. Introduzca un numero.\n");
        else if (velocidadT <= 0)
            printf("La velocidad debe ser mayor que 0\n");
    } while( (resultado != 1) || (velocidadT <= 0) );

    do
    {
        printf("Introduce la velocidad de la nave de la luna en km/h: ");
        resultado = scanf("%lf", &velocidadL);
        while(getchar() != '\n');
        if(resultado != 1)
            printf("Error de formato. Introduzca un numero.\n");
        else if (velocidadL <= 0)
            printf("La velocidad debe ser mayor que 0\n");
    } while( (resultado != 1) || (velocidadL <= 0) );

    tiempo = _distancia_tierra_luna / (velocidadT + velocidadL);
    

    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
