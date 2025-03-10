#include "Practica7.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

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

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));

    int boleto;
    printf( "Introduzca su numero de boleto: ");
    scanf( "%d", &boleto );

    Bombo b1 = BomboCrea(TAM_B1);
    Bombo b2 = BomboCrea(TAM_B2);

    if ( b1 == NULL )
    {
        fprintf(stderr, BomboMensajeError(b1, error));
        return EXIT_FAILURE;
    }

    if ( b2 == NULL )
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < TAM_B1; i++)
    {
        if( BomboInserta(b1, i) == -1 )
        {
            fprintf(stderr, BomboMensajeError(b1, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return EXIT_FAILURE;
        }
    }
    
    if( BomboInserta(b2, 4000000) == -1)
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        BomboLibera(b2);
        return EXIT_FAILURE;
    }
    
    if( BomboInserta(b2, 1250000) == -1)
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        BomboLibera(b2);
        return EXIT_FAILURE;
    }
    

    if( BomboInserta(b2, 500000) == -1)
    {
        fprintf(stderr, BomboMensajeError(b2, error));
        BomboLibera(b1);
        BomboLibera(b2);
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < 2; i++)
    {
        if( BomboInserta(b2, 200000) == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if( BomboInserta(b2, 60000) == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return EXIT_FAILURE;
        }  
    }

    for (int i = 0; i < 1794; i++)
    {
        if( BomboInserta(b2, 1000) == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return EXIT_FAILURE;
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
            return EXIT_FAILURE;
        }

        premio[i] = BomboExtrae(b2);
        if (premio[i] == -1)
        {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            BomboLibera(b2);
            return EXIT_FAILURE;
        }
    }

    FILE *f = fopen("premios.txt", "w");
    if(f == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo premios.txt\n");
        BomboLibera(b1);
        BomboLibera(b2);
        return EXIT_FAILURE;
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

    printf("\nPulse una tecla para terminar");
    getchar();
    return 0;
}