# Función para calcular el máximo de dos números
Función Max2(a: Entero, b: Entero) -> Entero:
    mayor: Entero;
    SI a > b ENTONCES
        mayor <- a;
    SI_NO
        mayor <- b;
    FIN_SI
    Devolver mayor;
Fin Max2

principal():

    # Declarar variables
    primero, segundo: Entero;

    # Introducir datos
    Escribir("Introduce 2 numeros: ");
    Leer(primero, segundo);

    # Mostrar el máximo de los dos números
    Escribir("El numero mas grande es: ", Max2(primero, segundo));

Fin principal()