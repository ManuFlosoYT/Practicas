#include <windows.h>
#include <stdio.h>

int main()
{
    char nombre[10];
    int numero;
    srand()
    int _numero = (rand()%10)+1; //Numero entre 1 y 10

    //Activar la consola con caracteres Españoles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    printf("Hola Mundo!\n");
    printf("¿Como te llamas?: ");

    scanf("%s", nombre); //%s para cadena de caracteres
    printf("Hola %s\n", nombre);

    do
    {
        printf("Elije un numero aleatorio entre 1 y 10\n");
        printf("El número es: ");
        scanf("%d", &numero); //%d para numero entero, y & para pasar variable como referencia

        if(numero == _numero)
        {
            printf("Lo has adivinado");
        }
        else
        {
            printf("No lo has adivinado");
        }
    } while(numero!=_numero);


    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
