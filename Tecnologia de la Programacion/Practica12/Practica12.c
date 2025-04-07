#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "ABB.h"

int main()
{
    SetConsoleCP(65002);
    SetConsoleOutputCP(65002);

    ABB a = ABBCrea();
    int n;
    printf("Introduce un número entero >= 0: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Introduce un elemento %d: ", i+1);
        Elemento e;
        scanf("%d", &e);
        ABBInserta(&a, e);
    }

    char s[256];
    strcpy(s,"");
    


    ABB b = ABBCrea();
    int m;
    printf("Introduce un número entero >= 0: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        printf("Introduce un elemento %d: ", i+1);
        Elemento e;
        scanf("%d", &e);
        ABBInserta(&b, e);
    }

    char s2[256];
    strcpy(s2,"");

    printf("Arbol A: %s\n", ABBToString(s, a));
    printf("Arbol B: %s\n", ABBToString(s2, b));

    ABB cUnion = ABBUnion(a, b);
    char s3[256];
    strcpy(s3,"");
    printf("Union: %s\n", ABBToString(s3, cUnion));
    ABBLibera(cUnion);

    ABB cInterseccion = ABBInterseccion(a, b);
    char s4[256];
    strcpy(s4,"");
    printf("Interseccion: %s\n", ABBToString(s4, cInterseccion));
    ABBLibera(cInterseccion);

    ABB cDiferencia = ABBDiferencia(a, b);
    char s5[256];
    strcpy(s5,"");
    printf("Diferencia: %s\n", ABBToString(s5, cDiferencia));
    ABBLibera(cDiferencia);

    ABBLibera(a);
    ABBLibera(b);
    return 0;
}