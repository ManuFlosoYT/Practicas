/**
 * @file Practica6.c
 * @brief This program allows the user to write text to a file, and then counts the number of characters and words in the file.
 *
 * The program defines three main functions:
 * - `writeFile`: Writes the content from standard input to a file.
 * - `contarChars`: Counts the number of characters (excluding spaces, newlines, and tabs) in a file.
 * - `contarPalabras`: Counts the number of words in a file.
 *
 * The `main` function prompts the user to enter text, writes it to a file named "archivo.txt",
 * and then prints the number of characters and words in the file.  It also configures the console
 * to support Spanish characters.
 */


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int writeFile(char* nombreArchivo)
{
    FILE* archivo;

    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL)
    {
        return -1;
    }

    int c = getc(stdin);
    while( c != EOF )
    {
        putc(c, archivo);
        c = getc(stdin);
    }
    
    fclose(archivo);
    return 0;
}

int contarChars(char* nombreArchivo)
{
    FILE* archivo;
    char c;
    int contador = 0;

    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL)
    {
        return -1;
    }

    c = getc(archivo);
    while( c != EOF )
    {
        if(c != ' ' && c != '\n' && c != '\t')
        {
            contador++;
        }
        c = getc(archivo);
    }

    fclose(archivo);
    return contador;
}

int contarPalabras(char* nombreArchivo)
{
    FILE* archivo;
    char c;
    int contador = 0;
    //int palabra = 0;

    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL)
    {
        return -1;
    }

/*  
    c = getc(archivo);
    while( c != EOF )
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            palabra = 0;
        }
        else if(palabra == 0)
        {
            palabra = 1;
            contador++;
        }
        c = getc(archivo);
    } 
*/

    char palabra[256]; //Asume que la palabra no tendrá más de 255 caracteres
    while (fscanf(archivo, "%99s", palabra) == 1) 
    {
        contador++;
    }

    
    fclose(archivo);
    return contador;
}

int main()
{
    //Activar la consola con caracteres Españoles
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    char* nombreArchivo = "archivo.txt";
    printf("Escriba el texto que desea guardar en el archivo %s [CTRL+Z RETURN] \n", nombreArchivo);
    
    if(writeFile(nombreArchivo) == -1)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
        fprintf(stderr, "Error %d, ", errno);
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }

    int caracteres = contarChars(nombreArchivo);
    if(caracteres == -1)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
        fprintf(stderr, "Error %d, ", errno);
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("\nEl archivo %s tiene %d caracteres\n", nombreArchivo, caracteres);
    }

    int palabras = contarPalabras(nombreArchivo);
    if(palabras == -1)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
        fprintf(stderr, "Error %d, ", errno);
        fprintf(stderr, "%s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("El archivo %s tiene %d palabras\n", nombreArchivo, palabras);
    }

    printf("\nPulse una tecla para terminar");
    getchar();
    return 0;
}

