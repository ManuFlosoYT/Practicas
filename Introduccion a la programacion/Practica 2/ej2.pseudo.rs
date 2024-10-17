principal():

    # Declarar variables
    cantidad, resto, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco: Entero

    # Obtener la cantidad de dinero del usuario
    Escribir("Introduce cantidad de dinero: ")
    Leer(cantidad)

    # Calcular la cantidad de billetes de cada tipo
    quinientos <- cantidad / 500
    resto <- cantidad MOD 500

    doscientos <- resto / 200
    resto <- resto MOD 200

    cien <- resto / 100
    resto <- resto MOD 100

    cincuenta <- resto / 50
    resto <- resto MOD 50

    veinte <- resto / 20
    resto <- resto MOD 20

    diez <- resto / 10
    resto <- resto MOD 10

    cinco <- resto / 5
    resto <- resto MOD 5

    # Mostrar la cantidad de billetes de cada tipo y el resto
    Escribir("Billetes de 500: ", quinientos)
    Escribir("Billetes de 200: ", doscientos)
    Escribir("Billetes de 100: ", cien)
    Escribir("Billetes de 50: ", cincuenta)
    Escribir("Billetes de 20: ", veinte)
    Escribir("Billetes de 10: ", diez)
    Escribir("Billetes de 5: ", cinco)
    Escribir("Resto: ", resto)

    # Mostrar la descomposición de la cantidad en billetes
    Escribir("500 * ", quinientos, " +")
    Escribir(" 200 * ", doscientos, " +")
    Escribir(" 100 * ", cien, " +")
    Escribir(" 50 * ", cincuenta, " +")
    Escribir(" 20 * ", veinte, " +")
    Escribir(" 10 * ", diez, " +")
    Escribir(" 5 * ", cinco, " + ")
    Escribir(resto)
    Escribir(" = ", cantidad)

Fin principal()