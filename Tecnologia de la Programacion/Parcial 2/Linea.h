#ifndef __LINEA_H
#define __LINEA_H
    typedef struct LineaRep* Linea;

    // Crea y devuelve una nueva línea desde el punto (x1,y1) hasta
    // (x2,y2)
    Linea LineaCrea(double x1, double y1, double x2, double y2);

    // Libera la memoria asignada a la línea l
    void LineaLibera(Linea l);

    // Mueve la línea l con desplazamientos dx y dy en las
    // coordenadas x e y respectivamente. Es decir, incrementa los
    // valores x1 y x2 en una cantidad dx y los valores y1 e y2
    // en una cantidad dy.
    void LineaMueve(Linea l, double dx, double dy);

#endif // __LINEA_H