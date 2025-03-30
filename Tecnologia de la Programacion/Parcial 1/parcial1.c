/**
 * @file parcial1.c
 * @brief This file contains the implementation of several functions for a menu-driven program.
 *
 * The program includes functionalities for:
 *   - Generating a random number and guessing it.
 *   - Calculating the travel time to the sun.
 *   - Checking if a number is within a given range.
 *   - Handling arrays, strings, dynamic arrays, and files.
 *   - Simulating a lottery system with two 'Bombo' structures.
 *   - Handling linked lists, including creation, printing, removing duplicates, concatenation, and freeing memory.
 *
 * The file includes functions for creating, manipulating, and freeing memory for linked lists and 'Bombo' structures.
 * It also includes functions for reading user input, performing calculations, and displaying results.
 *
 * @author GitHub Copilot
 * @date [Date]
 */


#include "parcial1.h"   // Incluir el fichero cabezera
#include <windows.h>    // Incluir la librería de Windows para poder usar SetConsoleCP y SetConsoleOutputCP
#include <stdio.h>      // Incluir la librería estándar de entrada y salida
#include <stdlib.h>     // Incluir la librería estándar de C
#include <time.h>       // Incluir la librería de tiempo para la semilla del rand
#include <math.h>       // Incluir la librería de matemáticas para poder usar floor
#include <errno.h>      // Incluir la librería de errores
#include <string.h>     // Incluir la librería de cadenas de caracteres

struct EstructuraRep
{
    int elem;
    Estructura sig;
};

Estructura EstructuraCrea(int n, int a, int b)
{
    Estructura e = malloc(sizeof(struct EstructuraRep));
    Estructura aux = e;

    for(int i = 0; i < n; i++)
    {
        aux->sig = malloc(sizeof(struct EstructuraRep));
        aux = aux->sig;
        aux->elem = rand() % (b - a + 1) + a;
    }

    aux->sig = NULL;
    return e;
}

void EstructuraImprime(Estructura e)
{
    for(e = e->sig; e != NULL; e = e->sig)
    {
        printf("%d ", e -> elem);
    }
    printf("\n");
}

void PedirEntrada(int* n, int* a, int* b)
{
    int resultado;
    do
    {
        printf("Introduce el largo de la estructura enlazada: ");
        resultado = scanf("%d", n);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
    } while (resultado != 1);

    do
    {
        printf("Introduce el límite inferior del rango: ");
        resultado = scanf("%d", a);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
    } while (resultado != 1);

    do
    {
        printf("Introduce el límite superior del rango: ");
        resultado = scanf("%d", b);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (*a > *b)
            printf("El límite superior tiene que ser mayor que el límite inferior\n");
    } while (resultado != 1 || *a > *b);
}

void EstructuraLibera(Estructura e) 
{
    Estructura aux;
    while (e != NULL) 
    {
        aux = e;
        e = e->sig;
        free(aux);
    }
}

void EstructuraEliminaRepetidos(Estructura e) 
{
    for(e = e->sig; e != NULL; e = e->sig)
    {
        Estructura aux = e;
        while(aux->sig != NULL)
        {
            if(e->elem == aux->sig->elem)
            { 
                //Eliminar elemento repetido
                Estructura temp = aux->sig;
                aux->sig = temp->sig;
                free(temp);
            }
            else
            {
                aux = aux->sig;
            }
        }
    }
}

Estructura EstructuraConcatena(Estructura e1, Estructura e2)
{
    Estructura e3 = malloc(sizeof(struct EstructuraRep));
    Estructura aux = e3;

    for(e1 = e1->sig; e1 != NULL; e1 = e1->sig)
    {
        aux->sig = malloc(sizeof(struct EstructuraRep));
        aux = aux->sig;
        aux->elem = e1->elem;
    }
    for(e2 = e2->sig; e2 != NULL; e2 = e2->sig)
    {
        aux->sig = malloc(sizeof(struct EstructuraRep));
        aux = aux->sig;
        aux->elem = e2->elem;
    }

    aux -> sig = NULL;
    return e3;
}

void TratarListaEnlazada()
{
    int n, a, b;

    printf("Estructura 1:\n");
    PedirEntrada(&n, &a, &b);
    Estructura e1 = EstructuraCrea(n, a, b);

    printf("Estructura 2:\n");
    PedirEntrada(&n, &a, &b);
    Estructura e2 = EstructuraCrea(n, a, b);

    printf("Estructura 1:\n");
    EstructuraImprime(e1);
    printf("Estructura 1 sin repeticiones:\n");
    EstructuraEliminaRepetidos(e1);
    EstructuraImprime(e1);

    printf("Estructura 2:\n");
    EstructuraImprime(e2);
    printf("Estructura 2 sin repeticiones:\n");
    EstructuraEliminaRepetidos(e2);
    EstructuraImprime(e2);

    Estructura e3 = EstructuraConcatena(e1, e2);
    printf("Estructura concatenada:\n");
    EstructuraImprime(e3);
    printf("Estructura concatenada sin repetidos:\n");
    EstructuraEliminaRepetidos(e3);
    EstructuraImprime(e3);

    EstructuraLibera(e1);
    EstructuraLibera(e2);
    EstructuraLibera(e3);

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}



// Definir constantes para el ejercicio 7 de los bombos
#define TAM_B1 100000
#define TAM_B2 1807
int error;
char mensajeError[100];
struct BomboRep 
{
    int* bolas;
    int max; // tamaño máximo del bombo
    int n;  // nº de bolas que tenemos actualmente
};

// Construye y devuelve un bombo vacío que puede contener un
// máximo de max bolas. Si max<2 devuelve NULL y asigna
// error=1.
Bombo BomboCrea(int max) 
{

    if (max<2) 
    {
        error = 1;
        return NULL;
    }

    Bombo b = malloc(sizeof(struct BomboRep));
    b->bolas = malloc(max*sizeof(int));
    b->max = max;
    b->n = 0;
    return b;
}

// Inserta una bola en el bombo b.
// Si el bombo b está lleno devuelve -1 y asigna error=2,
// en caso contrario devuelve 0.
int BomboInserta(Bombo b, int bola)
{
    
    if (b->n == b->max) 
    {
        error = 2;
        return -1;
    }
    
    b->bolas[b->n] = bola;
    b->n++;
    return 0;

}

// Libera el bombo b.
void BomboLibera(Bombo b) 
{
    free(b->bolas);
    free(b);
}

// Devuelve un número aleatorio entre 0 y 10^20-1
unsigned long long int large_rand() {
    const int digitos = 19; // Número de dígitos que admite un unsigned long long int
    unsigned long long int r = 0;
    
    for(int i = 0; i<digitos; i++) 
    {
        r *= 10;
        r += rand()%10;
    }
    
    return r;
}

// Extrae y devuelve una bola del bombo b.
// Si el bombo b está vacío devuelve -1 y asigna error=3.
int BomboExtrae(Bombo b) 
{
    if (b->n == 0) 
    {
        error = 3;
        return -1;
    }
    
    int indice_aleatorio = large_rand()%b->n;
    int bola = b->bolas[indice_aleatorio];
    b->n--;
    b->bolas[indice_aleatorio] = b->bolas[b->n];
    return bola;
}

// Devuelve 1 si el bombo b está vacío y 0 en caso contrario.
int BomboVacia(Bombo b)
{
    return b->n == 0;
}

// Devuelve el mensaje de error asociado a un código de error
// del bombo b.
char* BomboMensajeError(Bombo b, int codigoError) 
{
    switch(codigoError) 
    {
        case 1:
        {
            sprintf(mensajeError, "El número de bolas inicial del bombo debe ser >= 2.\n");
            return mensajeError;
        }
        case 2:
        {
            sprintf(mensajeError, "El bombo está lleno.\n");
            return mensajeError;
        }
        case 3:
        {
            sprintf(mensajeError, "El bombo está vacío.\n");
            return mensajeError;
        }
        return NULL;
    }
}

void TratarBombo()
{
    int boleto;
    printf( "Introduzca su numero de boleto: ");
    scanf( "%d", &boleto );

    Bombo b1 = BomboCrea(TAM_B1);
    Bombo b2 = BomboCrea(TAM_B2);

    if ( b1 == NULL )
    {
        fprintf(stderr, BomboMensajeError(b1, error));
        return;
    }

    if ( b2 == NULL )
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        return;
    }

    for (int i = 0; i < TAM_B1; i++)
    {
        if( BomboInserta(b1, i) == -1 )
        {
            fprintf(stderr, BomboMensajeError(b1, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return;
        }
    }
    
    if( BomboInserta(b2, 4000000) == -1)
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        BomboLibera(b2);
        return;
    }
    
    if( BomboInserta(b2, 1250000) == -1)
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        BomboLibera(b2);
        return;
    }
    

    if( BomboInserta(b2, 500000) == -1)
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        BomboLibera(b2);
        return;
    }
    
    for (int i = 0; i < 2; i++)
    {
        if( BomboInserta(b2, 200000) == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if( BomboInserta(b2, 60000) == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return;
        }  
    }

    for (int i = 0; i < 1794; i++)
    {
        if( BomboInserta(b2, 1000) == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return;
        }   
    }

    int numero[TAM_B1], premio[TAM_B2];

    for (int i = 0; i < TAM_B2; i++)
    {
        numero[i] = BomboExtrae(b1);
        if (numero[i] == -1)
        {
            fprintf(stderr, BomboMensajeError(b1, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return;
        }

        premio[i] = BomboExtrae(b2);
        if (premio[i] == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return;
        }
    }

    FILE *f = fopen("premios.txt", "w");
    if(f == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo premios.txt\n");
        BomboLibera(b1);
        BomboLibera(b2);
        return;
    }

    int ganador = 0;
    int cantidad = 0;
    for (int i = 0; i < TAM_B2; i++)
    {
        fprintf(f, "Número: %d, Premio: %d\n", numero[i], premio[i]);

        if( numero[i] == boleto )
        {
            ganador = 1;
            cantidad = premio[i];
        }
    }
    fclose(f);

    if( ganador )
    {
        printf("Tu boleto ha sido premiado con %d euros\n", cantidad);
    }
    else
    {
        printf("Tu boleto no ha sido premiado\n");
    }
    

    BomboLibera(b1);
    BomboLibera(b2);

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

int EscribirFichero(char* nombreArchivo)
{
    FILE* archivo;  // Puntero al fichero

    archivo = fopen("texto.txt", "w");  // Abrir el fichero en modo escritura

    if (archivo == NULL)
    {
        return -1;
    }

    int c = getc(stdin);    // Leer un caracter de la entrada estándar
    while( c != EOF )   // Mientras no se llegue al final del fichero
    {
        putc(c, archivo);   // Escribir el caracter en el fichero
        c = getc(stdin);    // Leer otro caracter de la entrada estándar
    }
    
    fclose(archivo);    // Cerrar el fichero
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

    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL)
    {
        return -1;
    }

    char* palabra = (char*)malloc(256 * sizeof(char)); // Inicialmente, asigna espacio para 255 caracteres + '\0'
    if (palabra == NULL) {
        fclose(archivo);
        return -1; // Error al asignar memoria
    }

    int capacidad = 256;
    int longitud = 0;

    while ((c = fgetc(archivo)) != EOF) 
    {
        if (c == ' ' || c == '\n' || c == '\t') 
        {
            if (longitud > 0) 
            {
                palabra[longitud] = '\0'; // Termina la palabra
                contador++;
                longitud = 0; // Reinicia la longitud para la siguiente palabra
            }
        } 
        else 
        {
            palabra[longitud++] = c;
            if (longitud >= capacidad - 1) 
            {
                capacidad *= 2; // Duplica la capacidad
                char* temp = (char*)realloc(palabra, capacidad * sizeof(char));
                if (temp == NULL) 
                {
                    free(palabra);
                    fclose(archivo);
                    return -1; // Error al reasignar memoria
                }
                palabra = temp;
            }
        }
    }

    // Verifica si hay una última palabra al final del archivo
    if (longitud > 0) 
    {
        palabra[longitud] = '\0';
        contador++;
    }

    free(palabra);
    fclose(archivo);
    return contador;
}

void TratarArchivo()
{
    char* nombreArchivo = "texto.txt";
    int opcion;
    printf("¿Qué desea hacer?\n");
    printf("1. Escribir un nuevo archivo\n");
    printf("2. Contar caracteres y palabras en un archivo existente\n");

    int resultado;
    do 
    {
        printf("Introduzca una opcion: ");
        resultado = scanf("%d", &opcion);
        VaciarBufferEntrada();

        if (resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (opcion < 1 || opcion > 2)
            printf("Opción no válida\n");
    } while (resultado != 1 || (opcion < 1 || opcion > 2));

    if (opcion == 1)
    {
        printf("Escriba el texto que desea guardar en el archivo %s [CTRL+Z RETURN] \n", nombreArchivo);

        if(EscribirFichero(nombreArchivo) == -1)
        {
            fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
            fprintf(stderr, "Error %d, ", errno);
            fprintf(stderr, "%s\n", strerror(errno));
            return;
        }
    }

    int caracteres = contarChars(nombreArchivo);
    if(caracteres == -1)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
        fprintf(stderr, "Error %d, ", errno);
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
    else
    {
        printf("El archivo %s tiene %d caracteres\n", nombreArchivo, caracteres);
    }

    int palabras = contarPalabras(nombreArchivo);
    if(palabras == -1)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
        fprintf(stderr, "Error %d, ", errno);
        fprintf(stderr, "%s\n", strerror(errno));
        return;
    }
    else
    {
        printf("El archivo %s tiene %d palabras\n", nombreArchivo, palabras);
    }

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

void TratarArrayDinamico()
{
    int n;
    int resultado;
    do
    {
        printf("Introduce el tamaño del array como un entero mayor o igual que 0: ");
        resultado = scanf("%d", &n);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (n < 0)
            printf("El tamaño del array tiene que ser mayor o igual que 0\n");
    } while (resultado != 1 || n < 0);

    int* array = (int*)malloc(n * sizeof(int));  // Crear un array de tamaño n

    if(array == NULL)
    {
        fprintf(stderr, "Error al reservar memoria\n");
        return;
    }

    // Rellenar el array con n números aleatorios
    for (int i = 0; i < n; i++)
    {
        array[i] = rand();
    }

    // Imprimir el array
    ImprimirArray(n, array);

    int num;
    int resultado2;
    do
    {
        printf("Introduce un nuevo tamaño para el array: ");
        resultado2 = scanf("%d", &num);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado2 != 1)
            printf("Error de formato. Introduzca un número.\n");
    } while (resultado2 != 1);

    int* temp_array = (int*)realloc(array, num * sizeof(int));  // Redimensionar el array

    if (temp_array == NULL && num != 0)
    {
        fprintf(stderr, "Error al redimensionar la memoria\n");
        return;
        free(array);
    }
    else
    {
        array = temp_array;
    }

    // Rellenar las posiciones nuevas del array con num números aleatorios sin perder los que habia
    if(num > n)
    {
        for (int i = n; i < num; i++)
        {
            array[i] = rand();
        }
    }

    // Imprimir el array
    ImprimirArray(num, array);

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

int CadenasIguales(char cadena1[256], char cadena2[256])
{
    int i = 0;
    while( (cadena1[i] != '\0') && (cadena2[i] != '\0') && (cadena1[i] == cadena2[i]) )
    {
        i++;
    }
    return cadena1[i] == cadena2[i];
}

void TratarCadenas()
{
    // Crear dos cadenas de 256 caracteres
    char cadena1[256]; 
    char cadena2[256];

    // Leer la primera cadena
    printf("Introduzca una cadena de menos de 256 caracteres: ");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")] = 0; // Eliminar el salto de línea al final

    // Leer la segunda cadena
    printf("Introduzca una cadena de menos de 256 caracteres: ");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena2[strcspn(cadena2, "\n")] = 0; // Eliminar el salto de línea al final

    printf("La cadena 1 es: %s\n", cadena1);
    printf("La cadena 2 es: %s\n", cadena2);

    if( CadenasIguales(cadena1, cadena2) )
    {
        printf("Las cadenas son iguales\n");
    }
    else
    {
        printf("Las cadenas no son iguales\n");
    }

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

int PerteneceArray(int n, int array[n], int num)
{
    for (int i = 0; i < n; i++)
    {
        if(array[i] == num)
            return 1;
    }
    return 0;
}

void ImprimirArray(int n, int array[n])
{
    printf("El array es: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
        if (i < n - 1) // Si no es el último elemento del array imprimir una coma y un espacio
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void TratarArray()
{
    int n;
    int resultado;
    do
    {
        printf("Introduce el tamaño del array como un entero mayor o igual que 0: ");
        resultado = scanf("%d", &n);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (n < 0)
            printf("El tamaño del array tiene que ser mayor o igual que 0\n");
    } while (resultado != 1 || n < 0);

    int array[n];  // Crear un array de tamaño n
    // Leer los valores del array
    for (int i = 0; i < n; i++)
    {
        int resultado;
        do
        {
            printf("Introduce el valor de la posición %d: ", i);
            resultado = scanf("%d", &array[i]);   // Guarda el resultado de la lectura de la opción para tratar errores
            VaciarBufferEntrada();
            if(resultado != 1)
                printf("Error de formato. Introduzca un número.\n");
        } while (resultado != 1);
    }

    // Imprimir el array
    ImprimirArray(n, array);

    int num;
    int resultado2;
    do
    {
        printf("Introduce un entero a buscar en el array: ");
        resultado2 = scanf("%d", &num);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado2 != 1)
            printf("Error de formato. Introduzca un número.\n");
    } while (resultado2 != 1);

    if(PerteneceArray(n, array, num))
    {
        printf("El %d pertenece al array\n", num);
    }
    else
    {
        printf("El %d no pertenece al array\n", num);
    }

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

int LeerEnteroRango(int* min, int* max, int* numero)
{
    int resultado;
    int numEnRango = 1;
    do
    {
        printf("Introduce el valor mínimo: ");
        resultado = scanf("%d", min);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
    } while (resultado != 1);

    do
    {
        printf("Introduce el valor máximo: ");
        resultado = scanf("%d", max);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        numEnRango = 1;
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (*max <= *min)
        {
            numEnRango = 0;
            printf("El valor máximo tiene que ser mayor que el mínimo\n");
        }
    } while (resultado != 1 || numEnRango == 0);

    do
    {
        printf("Introduce un número: ");
        resultado = scanf("%d", numero);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();
        numEnRango = 1;
        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (*numero < *min || *numero > *max)
        {
            numEnRango = 0;
            printf("El número tiene que estar entre %d y %d\n", *min, *max);
        }
    } while (resultado != 1 || numEnRango == 0);

    if(*numero >= *min && *numero <= *max)
        return 0;
    else
        return -1;
}

void ComprobarRango()
{
    int min, max, numero;
    int resultado = LeerEnteroRango(&min, &max, &numero);

    if(resultado == 0)
        printf("El número %d está dentro del rango [%d, %d]\n", numero, min, max);
    else
        printf("El número %d está fuera del rango [%d, %d]\n", numero, min, max);

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

void TiempoViajeSol()
{
    const double _TIEMPO_LUZ = _DISTANCIA_TIERRA_SOL / _VELOCIDAD_LUZ;
    double velocidad;

    int resultado;
    do
    {
        printf("Introduce la velocidad de la nave en km/h: ");
        resultado = scanf("%lf", &velocidad);   // Guarda el resultado de la lectura de la opción para tratar errores
        VaciarBufferEntrada();

        if(resultado != 1)
            printf("Error de formato. Introduzca un número.\n");
        else if (velocidad <= 0 || velocidad > _VELOCIDAD_LUZ)
            printf("La velocidad no puede ser =< 0 ni mayor que la velocidad de la luz\n");
    } while (resultado != 1);

    printf("La distancia de la tierra al sol es de %d km\n", _DISTANCIA_TIERRA_SOL);
    printf("La velocidad de la luz es de %d km/s\n", _VELOCIDAD_LUZ);
    printf("La luz tarda %g segundos en llegar al sol\n", _TIEMPO_LUZ);

    // Calcular el tiempo en segundos que tardaría en llegar al sol
    double segundos = _DISTANCIA_TIERRA_SOL / velocidad;

    // Calcular el tiempo en minutos, horas, días y años
    double minutos = segundos / 60.0;
    double horas = minutos / 60.0;
    double dias = horas / 24.0;
    double anos = dias / 365.0;

    printf("El tiempo en segundos es: %g\n", segundos);
    printf("El tiempo en minutos es: %g\n", minutos);
    printf("El tiempo en horas es: %g\n", horas);
    printf("El tiempo en días es: %g\n", dias);
    printf("El tiempo en años es: %g\n", anos);

    // Aunque son numeros enteros, trabajamos con double para evitar desbordamientos en casos extremos
    double _horas = floor(horas);
    double _minutos = floor( (minutos - floor(minutos)) * 60);
    double _segundos = floor( (segundos - floor(segundos)) * 60);

    printf("Ha tardado: %g horas, %g minutos, %g segundos\n", _horas, _minutos, _segundos);

    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

// Vacía el buffer de entrada.
void VaciarBufferEntrada()
{
    while( getchar() != '\n' );
}

void ElejirNumeroAleatorio()
{
    // Genera un número entre 1 y 10
    // Genera un número aleatorio
    // Le hace el módulo 10 para que esté entre 0 y 9
    // Le suma 1 para que esté entre 1 y 10
    int numGenerado = ( rand() % 10) + 1; 
    
    int numUsuario;
    int intentos = 0;
    
    do
    {
        int resultado;
        int numEnRango = 1;
        do
        {
            printf("Introduce un número entre 1 y 10: ");
            resultado = scanf("%d", &numUsuario);   // Guarda el resultado de la lectura de la opción para tratar errores
            VaciarBufferEntrada();
            numEnRango = 1;
            if(resultado != 1)
                printf("Error de formato. Introduzca un número.\n");
            else if (numUsuario < 1 || numUsuario > 10)
            {
                numEnRango = 0;
                printf("El numero tiene que estar entre 1 y 10\n");
            }
        } while (resultado != 1 || numEnRango == 0);

        intentos++;

        if(numUsuario < numGenerado)
        {
            printf("El número es mayor\n");
        }
        else if(numUsuario > numGenerado)
        {
            printf("El número es menor\n");
        }
    } while(numUsuario != numGenerado);

    printf("Lo has adivinado en %d intentos\n", intentos);
    printf("\n");
    printf("Pulse una tecla para volver\n");
    getchar();
}

void ImprimirMenu()
{
    printf("1. Numero Aleatorio\n");
    printf("2. Tiempo de viaje al sol\n");
    printf("3. Comprobar entero rango\n");
    printf("4. Tratar Array\n");
    printf("5. Tratar Cadenas\n");
    printf("6. Tratar Array Dinamico\n");
    printf("7. Tratar archivo\n");
    printf("8. Bombo\n");
    printf("9. Tratar Lista Enlazada\n");
    printf("0. Salir\n");
}

int main()
{
    // Configurar la terminal para que acepte caracteres especiales del español
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));  // Semilla para el rand
    const int LIMITE_OPCIONES = 9;
    int salir = 0;

    while(!salir)
    {
        ImprimirMenu();
        int opcion, resultado;

        
        do
        {
            printf("Introduzca una opcion: ");
            resultado = scanf("%d", &opcion);   // Guarda el resultado de la lectura de la opción para tratar errores
            VaciarBufferEntrada();

            if(resultado != 1)
                printf("Error de formato. Introduzca un número.\n");
            else if (opcion < 0 || opcion > LIMITE_OPCIONES)
                printf("Opción no válida\n");
        } while (resultado != 1);

        switch(opcion)
        {
            case 0:
            {
                salir = 1;
                break;
            }
            case 1:
            {
                ElejirNumeroAleatorio();
                break;
            }
            case 2:
            {
                TiempoViajeSol();
                break;
            }
            case 3:
            {
                ComprobarRango();
                break;
            }
            case 4:
            {
                TratarArray();
                break;
            }
            case 5:
            {
                TratarCadenas();
                break;
            }
            case 6:
            {
                TratarArrayDinamico();
                break;
            }
            case 7:
            {
                TratarArchivo();
                break;
            }
            case 8:
            {
                TratarBombo();
                break;
            }
            case 9:
            {
                TratarListaEnlazada();
                break;
            }
        }
    }

    return 0;
}