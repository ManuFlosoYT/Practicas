#include <windows.h>
#include <stdio.h>
#include <math.h>

#define printf __mingw_printf

static long double _distancia_sol = 149.6E6;
int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    long double velocidad, segundos, minutos, horas, dias, meses, anos;
    int i_segundos, i_minutos, i_horas, i_dias, i_meses, i_anos;
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
    printf("Velocidad: %Lg km/h\n", velocidad);
    printf("Distancia: %e km\n", _distancia_sol); //%e = notacion cientifica, %f doble con ceros, %g elige automaticamente

    horas = _distancia_sol / velocidad;
    dias = horas / 24;
    meses = dias / 12;
    anos = dias / 365;
    minutos = horas * 60;
    segundos = minutos * 60;

    printf("Años: %Lg\n", anos);
    printf("Meses: %Lg\n", meses);
    printf("Dias: %g\n", dias);
    printf("Horas: %g\n", horas);
    printf("Minutos: %g\n", minutos);
    printf("Segundos: %g\n", segundos);

    i_anos = floor(anos);
    i_meses = floor( (meses - floor(meses)) * 12);
    i_dias = floor( (dias - floor(dias)) * 30);
    i_horas = floor( (horas - floor(horas)) * 24);
    i_minutos = floor( (minutos - floor(minutos)) * 60);
    i_segundos = floor( (segundos - floor(segundos)) * 60);

    printf("Ha tardado: %d años, %d meses, %d dias, %d horas, %d minutos, %d segundos\n", i_anos, i_meses, i_dias, i_horas, i_minutos, i_segundos);

    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
