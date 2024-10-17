metodo1():

    # Declarar variables
    bit0, bit1, bit2, bit3: Entero
    cbit0, cbit1, cbit2, cbit3: Carácter
    decimal: Entero

    # Obtener los bits del usuario
    Escribir("Introduce 4 cifras en binario: ")
    Leer(cbit3, cbit2, cbit1, cbit0)

    # Convertir los caracteres a enteros
    bit0 <- Convertir_a_Entero(cbit0) - Convertir_a_Entero('0')
    bit1 <- Convertir_a_Entero(cbit1) - Convertir_a_Entero('0')
    bit2 <- Convertir_a_Entero(cbit2) - Convertir_a_Entero('0')
    bit3 <- Convertir_a_Entero(cbit3) - Convertir_a_Entero('0')

    # Calcular el valor decimal
    decimal <- bit0 + bit1 * 2 + bit2 * 4 + bit3 * 8

    # Mostrar el valor decimal
    Escribir("El valor decimal es: ", decimal)

Fin metodo1()

metodo2():

    # Declarar variables
    bit0, bit1, bit2, bit3: Entero
    decimal, binario: Entero

    # Obtener el número binario del usuario
    Escribir("Introduce 4 cifras en binario: ")
    Leer(binario)

    # Extraer los bits del número binario
    bit3 <- binario / 1000
    bit2 <- (binario MOD 1000) / 100
    bit1 <- (binario MOD 100) / 10
    bit0 <- binario MOD 10

    # Calcular el valor decimal
    decimal <- bit0 + bit1 * 2 + bit2 * 4 + bit3 * 8

    # Mostrar el valor decimal
    Escribir("El valor decimal es: ", decimal)

Fin metodo2()

principal():

    metodo2()

Fin principal()