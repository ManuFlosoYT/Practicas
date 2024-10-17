# Procedimiento para realizar la división entera de dos números
Procedimiento divisionEntera(dividendo: Entero, divisor: Entero, cociente: Entero, resto: Entero):
    cociente <- dividendo / divisor;
    resto <- dividendo MOD divisor;
Fin divisionEntera

principal():

    # Declarar variables
    cantidad, resto, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco: Entero;

    # Introducir cantidad de dinero
    Escribir("Introduce cantidad de dinero: ");
    Leer(cantidad);

    # Calcular la cantidad de billetes de cada tipo
    divisionEntera(cantidad, 500, quinientos, resto);
    divisionEntera(resto, 200, doscientos, resto);
    divisionEntera(resto, 100, cien, resto);
    divisionEntera(resto, 50, cincuenta, resto);
    divisionEntera(resto, 20, veinte, resto);
    divisionEntera(resto, 10, diez, resto);
    divisionEntera(resto, 5, cinco, resto);

    # Mostrar la cantidad de billetes de cada tipo y el resto
    Escribir("Billetes de 500: ", quinientos);
    Escribir("Billetes de 200: ", doscientos);
    Escribir("Billetes de 100: ", cien);
    Escribir("Billetes de 50: ", cincuenta);
    Escribir("Billetes de 20: ", veinte);
    Escribir("Billetes de 10: ", diez);
    Escribir("Billetes de 5: ", cinco);
    Escribir("Resto: ", resto);

    # Mostrar la descomposición de la cantidad en billetes
    Escribir("500 * ", quinientos, " +");
    Escribir("200 * ", doscientos, " +");
    Escribir("100 * ", cien, " +");
    Escribir("50 * ", cincuenta, " +");
    Escribir("20 * ", veinte, " +");
    Escribir("10 * ", diez, " +");
    Escribir("5 * ", cinco, " + ");
    Escribir(resto);
    Escribir("= ", cantidad);

Fin principal()