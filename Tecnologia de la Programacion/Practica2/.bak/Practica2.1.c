#include <windows.h>
#include <stdio.h>
#include <math.h>

#define printf __mingw_printf

static long double _distancia_sol = 149.6E6;
int main()
{
    //Activar la consola con caracteres Espa�oles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    double velocidad
    long double segundos, minutos, horas, dias, meses, anos;
    long double i_segundos, i_minutos, i_horas, i_dias, i_meses, i_anos;
    int resultado;


    do
    {
        printf("Introduce la velocidad en Km/h: ");
        resultado = scanf("%lf", &velocidad);
        while(getchar() != '\n');
        if(resultado != 1)
            printf("Error de formato. Introduzca un numero.\n");
        else if (velocidad <= 0)
            printf("La velocidad debe ser mayor que 0\n");
    } while( (resultado != 1) || (velocidad <= 0) );
    printf("Velocidad: %g km/h\n", velocidad);
    printf("Distancia: %e km\n", _distancia_sol); //%e = notacion cientifica, %f doble con ceros, %g elige automaticamente

    horas = _distancia_sol / (long double)velocidad;
    dias = horas / 24;
    meses = dias / 12;
    anos = dias / 365;
    minutos = horas * 60;
    segundos = minutos * 60;

    printf("A�os: %Lg\n", anos);
    printf("Meses: %Lg\n", meses);
    printf("Dias: %Lg\n", dias);
    printf("Horas: %Lg\n", horas);
    printf("Minutos: %Lg\n", minutos);
    printf("Segundos: %Lg\n", segundos);

    i_anos = lfloor(anos);
    i_meses = lfloor( (meses - lfloor(meses)) * 12);
    i_dias = lfloor( (dias - lfloor(dias)) * 30);
    i_horas = lfloor( (horas - lfloor(horas)) * 24);
    i_minutos = lfloor( (minutos - lfloor(minutos)) * 60);
    i_segundos = lfloor( (segundos - lfloor(segundos)) * 60);

    printf("Ha tardado: %Lg a�os, %Lg meses, %Lg dias, %Lg horas, %Lg minutos, %Lg segundos\n", i_anos, i_meses, i_dias, i_horas, i_minutos, i_segundos);

    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
