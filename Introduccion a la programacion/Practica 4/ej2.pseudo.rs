# Procedimiento para convertir un número binario a decimal
Procedimiento BinDec(b1: Entero, b2: Entero, b3: Entero, b4: Entero, decimal: Entero):
    decimal <- b1 * 1 + b2 * 2 + b3 * 4 + b4 * 8;
Fin BinDec

# Procedimiento para intercambiar el valor de dos variables
Procedimiento Intercambio(a: Caracter, b: Caracter):
    aux: Caracter;
    aux <- a;
    a <- b;
    b <- aux;
Fin Intercambio

principal():

    # Declarar variables
    b1, b2, decimal1, decimal2: Entero;
    x, y, z: Caracter;

    # Inicializar variables
    b1 <- 0;
    b2 <- 1;
    x <- 'O';
    y <- 'P';
    z <- 'Q';

    # Intercambiar valores de variables
    Intercambio(x, y);
    Intercambio(y, z);

    # Convertir números binarios a decimales
    BinDec(b1, b2, b1, b2, decimal1);
    BinDec(0, 1, b1, b1, decimal2);

    # Mostrar resultados
    Escribir("Valor de las variables x, y, z es: ", x, y, z);
    Escribir("El valor del numero 1 es: ", decimal1);
    Escribir("El valor del numero 2 es: ", decimal2);

Fin principal()