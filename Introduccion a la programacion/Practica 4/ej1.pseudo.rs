# Programa para calcular la fecha del día siguiente

# Definir un tipo de dato Fecha
TIPO Fecha = REGISTRO
    dia: Entero;
    mes: Entero;
    ano: Entero;
FIN_REGISTRO

# Declarar variables
f: Fecha;
largoMes: Entero;

# Inicializar la fecha
f.dia <- 1;
f.mes <- 1;
f.ano <- 1;

# Obtener la fecha del usuario
Escribir("Inserta una fecha en formato (DD MM AAAA): ");
Leer(f.dia, f.mes, f.ano);

# Validar la fecha
SI (f.dia > 31) O (f.dia <= 0) ENTONCES
    Escribir("Formato inválido");
    Terminar programa;
FIN_SI

SI (f.mes > 12) O (f.mes <= 0) ENTONCES
    Escribir("Formato inválido");
    Terminar programa;
FIN_SI

SI f.ano < 1 ENTONCES
    Escribir("Formato inválido");
    Terminar programa;
FIN_SI

# Determinar el número de días del mes
SEGÚN f.mes
    CASO 2:  # Febrero
        largoMes <- 28;
    CASO 4, 6, 9, 11:  # Meses de 30 días
        largoMes <- 30;
    CASO 1, 3, 5, 7, 8, 10, 12:  # Meses de 31 días
        largoMes <- 31;
    EN_OTRO_CASO:
        Escribir("Formato inválido");
        Terminar programa;
FIN_SEGÚN

# Calcular la fecha del día siguiente
SI f.dia < largoMes ENTONCES
    f.dia <- f.dia + 1;
EN_OTRO_CASO:
    f.dia <- 1;
    f.mes <- f.mes + 1;

    SI f.mes > 12 ENTONCES
        f.mes <- 1;
        f.ano <- f.ano + 1;
    FIN_SI
FIN_SI

# Mostrar la fecha del día siguiente
Escribir("La fecha del día siguiente es: ", f.dia, "/", f.mes, "/", f.ano);

# Fin del programa