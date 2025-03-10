#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct EstructuraRep* Estructura;

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
    printf("Introduce un numero n mayor o igual que 0: ");
    scanf("%d", n);

    printf("Introduce un numero entero a: ");
    scanf("%d", a);

    printf("Introduce un numero entero b >= a: ");
    scanf("%d", b);
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

int main()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    int n, a, b;

    PedirEntrada(&n, &a, &b);
    Estructura e1 = EstructuraCrea(n, a, b);

    PedirEntrada(&n, &a, &b);
    Estructura e2 = EstructuraCrea(n, a, b);

    printf("Estructura 1:\n");
    EstructuraImprime(e1);
    printf("Estructura 2:\n");
    EstructuraImprime(e2);

    Estructura e3 = EstructuraConcatena(e1, e2);
    printf("Estructura concatenada:\n");
    EstructuraImprime(e3);

    EstructuraEliminaRepetidos(e3);
    printf("Estructura sin repetidos:\n");
    EstructuraImprime(e3);

    EstructuraLibera(e1);
    EstructuraLibera(e2);
    EstructuraLibera(e3);

    return 0;
}