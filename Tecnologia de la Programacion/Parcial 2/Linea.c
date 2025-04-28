//Implementar Linea.h
#include <stdio.h>
#include <stdlib.h>
#include "Linea.h"

typedef struct LineaRep {
    double x1, y1, x2, y2;
} LineaRep;

// Crea y devuelve una nueva línea desde el punto (x1,y1) hasta (x2,y2)
Linea LineaCrea(double x1, double y1, double x2, double y2)
{
    Linea nuevaLinea = (Linea)malloc(sizeof(LineaRep));
    if (nuevaLinea == NULL) 
    {
        printf("Error al asignar memoria para la línea\n");
        return NULL;
    }
    nuevaLinea->x1 = x1;
    nuevaLinea->y1 = y1;
    nuevaLinea->x2 = x2;
    nuevaLinea->y2 = y2;
    return nuevaLinea;
}

// Libera la memoria asignada a la línea l
void LineaLibera(Linea l)
{
    free(l);
}

// Mueve la línea l con desplazamientos dx y dy en las coordenadas x e y respectivamente. Es decir, incrementa los valores x1 y x2 en una cantidad dx y los valores y1 e y2 en una cantidad dy.
void LineaMueve(Linea l, double dx, double dy)
{
    if (l != NULL) {
        l->x1 += dx;
        l->x2 += dx;
        l->y1 += dy;
        l->y2 += dy;
    }
}