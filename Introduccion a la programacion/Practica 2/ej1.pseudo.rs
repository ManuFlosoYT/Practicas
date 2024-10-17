principal():

    # Declarar variables
    a, b, c, aux: Carácter

    # Obtener los caracteres del usuario
    Escribir("Introduce las variables a, b y c: ")
    Leer(a, b, c)

    # Desplazar los caracteres
    aux <- b
    b <- a
    a <- c
    c <- aux

    # Mostrar los caracteres desplazados
    Escribir("Los valores de a, b y c desplazados son: ", a, " ", b, " ", c)

Fin principal()