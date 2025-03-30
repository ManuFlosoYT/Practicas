/**
 * @file Practica2 v2.c
 * @brief This program calculates the meeting point of two spaceships, one starting from Earth and the other from the Moon.
 *
 * The program prompts the user to enter the speeds of the two spaceships in km/h.
 * It then calculates the distance from Earth where the spaceships will meet, the time it will take for them to meet,
 * and displays the results in kilometers, hours, minutes, and seconds.
 *
 * @author [Your Name]
 * @date [Current Date]
 */

#include <windows.h>
#include <stdio.h>

const int _distancia_tierra_luna = 384400;
int main()
{
    //Activar la consola con caracteres Espa�oles
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double velocidadT, velocidadL, distancia, horas, minutos, segundos;
    double i_segundos, i_minutos, i_horas;
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

    horas = _distancia_tierra_luna / (velocidadT + velocidadL);
    distancia = velocidadT * horas;
    minutos = horas * 60;
    segundos = minutos * 60;

    printf("Distancia de encuentro: %g km\n", distancia);
    printf("Horas de encuentro: %g h\n", horas);

    i_horas = floor(horas);
    i_minutos = floor( (minutos - floor(minutos)) * 60);
    i_segundos = floor( (segundos - floor(segundos)) * 60);

    printf("Ha tardado: %g horas, %g minutos, %g segundos\n", i_horas, i_minutos, i_segundos);


    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
