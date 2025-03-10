/**
 * @file Practica1.c
 * @brief A simple number guessing game.
 *
 * This program generates a random number between 1 and 10, prompts the user to guess the number,
 * and provides feedback until the user guesses correctly. It also keeps track of the number of attempts.
 *
 * @author [Your Name]
 * @date [Current Date]
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char nombre[10];
    int numero;
    int _numero = (rand()%10)+1; //Numero entre 1 y 10
    int contador = 0;

    //Activar la consola con caracteres Espa�oles
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);


    printf("Hola Mundo!\n");
    printf("�Como te llamas?: ");

    scanf("%s", nombre); //%s para cadena de caracteres
    while(getchar()!='\n'); //Vaciar buffer
    printf("Hola %s\n", nombre);

    do
    {
        printf("Elije un numero aleatorio entre 1 y 10\n");
        printf("El n�mero es: ");

        int res;
        do
        {
            res = scanf("%d", &numero); //%d para numero entero, y & para pasar variable como referencia
            while(getchar()!='\n'); //Vaciar buffer
        } while(res != 1);
        //Al salir del bucle el valor es correcto

        contador++;

        if(numero == _numero)
        {
            printf("Lo has adivinado en %d intentos", contador);
        }
        else
        {
            printf("No lo has adivinado\n");
            if(_numero > numero)
            {
                printf("El numero es mayor\n");
            }
            else
            {
                printf("El numero es menor\n");
            }
        }
    } while(numero!=_numero);

    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
