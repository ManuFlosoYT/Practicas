#include <windows.h>
#include <stdio.h>

int main()
{
    char nombre[10];
    static int numero = (rand()%10)+1; //Numero entre 1 y 10

    //Activar la consola con caracteres Españoles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    printf("Hola Mundo!\n");
    printf("¿Como te llamas?: ");

    scanf("%s", nombre);
    printf("Hola %s\n", nombre);

    printf("Elije un numero aleatorio entre 1 y 10\n");
    printf("El número es: ");
    


    printf("\n Pulse una tecla para terminar");
    getchar();
    return 0;
}
