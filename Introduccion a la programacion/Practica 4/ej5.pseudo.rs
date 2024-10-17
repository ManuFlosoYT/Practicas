# Definir un tipo de dato Punto
TIPO Punto = REGISTRO
    abscisa: Real;
    ordenada: Real;
FIN_REGISTRO

# Función para calcular el cuadrado de un número
Función sqr(x: Real) -> Real:
    Devolver x * x
Fin sqr

principal():

    # Declarar variables
    p1, p2: Punto;
    distancia: Real;

    # Introducir datos
    Escribir("Introduce el valor de abscisa: ");
    Leer(p1.abscisa);
    Escribir("Introduce el valor de la ordenada: ");
    Leer(p1.ordenada);
    Escribir("Introduce el valor de abscisa: ");
    Leer(p2.abscisa);
    Escribir("Introduce el valor de la ordenada: ");
    Leer(p2.ordenada);

    # Calcular la distancia entre los dos puntos
    distancia <- raiz_cuadrada(sqr(p1.abscisa - p2.abscisa) + sqr(p1.ordenada - p2.ordenada));

    # Mostrar el resultado
    Escribir("La distancia entre los dos puntos es: ", distancia);

Fin principal()