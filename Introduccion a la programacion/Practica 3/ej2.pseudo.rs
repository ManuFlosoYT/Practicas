Función calcularInterés(cantidad, plazo, porcentajeInteres):
  # Calcula el interés simple
  Devolver cantidad * plazo * porcentajeInteres

Función calcularRecargo(cantidad, interes, riesgo):
  # Calcula el recargo si es cliente de riesgo
  Devolver (cantidad + interes) * 0.01 * riesgo 

Función calcularTotal(cantidad, interes, recargo):
  # Calcula el total a pagar
  Devolver cantidad + interes + recargo

Inicio del programa:

  # Declaración de variables
  plazo: Entero
  cantidad, porcentajeInteres: Real
  riesgo: Booleano
  _riesgo: Carácter
  interesCalculado, recargo, total, mensualidad: Real

  # Entrada de datos
  Escribir "Introduzca cantidad prestada: "
  Leer cantidad
  Escribir "Introduzca el plazo del préstamo en meses: "
  Leer plazo
  Escribir "Introduzca el porcentaje de interés: "
  Leer porcentajeInteres
  Escribir "Introduzca si es cliente de riesgo (s/n): "
  Leer _riesgo

  # Convertir la entrada de riesgo a booleano
  Según _riesgo:
    Caso 's', 'S':
      riesgo <- Verdadero
    Caso 'n', 'N':
      riesgo <- Falso
    Otro caso:
      Escribir "Entrada incorrecta, usando falso por defecto"
      riesgo <- Falso

  # Validar interés
  Si porcentajeInteres >= 1 Entonces
    porcentajeInteres <- porcentajeInteres / 100

  # Cálculos
  interesCalculado <- calcularInterés(cantidad, plazo, porcentajeInteres)
  recargo <- calcularRecargo(cantidad, interesCalculado, riesgo)
  total <- calcularTotal(cantidad, interesCalculado, recargo)
  mensualidad <- total / plazo

  # Salida de datos
  Escribir ""
  Escribir "El total a pagar es: " + total + " euros" 
  Escribir "El interés calculado es: " + interesCalculado + " euros" 
  Escribir "El recargo calculado es: " + recargo + " euros" 
  Escribir "Debe ser ingresado en " + plazo + " plazos de " + mensualidad + " euros cada una" 

Fin del programa