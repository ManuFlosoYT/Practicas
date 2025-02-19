.data
    prompt1: .asciiz "Introduzca el primer número: "
    prompt2: .asciiz "Introduzca el segundo número: "
    suma:    .asciiz "Resultado de la suma: "
    resta:   .asciiz "\nResultado de la resta: "
    mult:    .asciiz "\nResultado de la multiplicación: "
    div:     .asciiz "\nResultado de la división: "
    barra:   .asciiz "/"
.text
.globl main

main:
    # Pedir el primer número
    li $v0, 4          	# syscall para imprimir cadena
    la $a0, prompt1
    syscall

    li $v0, 5          	# syscall para leer entero
    syscall
    move $t0, $v0      	# Guardar el primer número en $t0

    # Pedir el segundo número
    li $v0, 4          	# syscall para imprimir cadena
    la $a0, prompt2
    syscall

    li $v0, 5          	# syscall para leer entero
    syscall
    move $t1, $v0      	# Guardar el segundo número en $t1

    # Suma
    add $t2, $t0, $t1  	# $t2 = $t0 + $t1
    li $v0, 4          	# syscall para imprimir cadena
    la $a0, suma
    syscall

    li $v0, 1          	# syscall para imprimir entero
    move $a0, $t2
    syscall

    # Resta
    sub $t2, $t0, $t1  	# $t2 = $t0 - $t1
    li $v0, 4          	# syscall para imprimir cadena
    la $a0, resta
    syscall

    li $v0, 1         	# syscall para imprimir entero
    move $a0, $t2
    syscall

    # Multiplicación
    mult $t0, $t1      	# $lo, $hi = $t0 * $t1
    mflo $t2           	# $t4 = $lo (resultado)
    li $v0, 4          	# syscall para imprimir cadena
    la $a0, mult
    syscall

    li $v0, 1          	# syscall para imprimir entero
    move $a0, $t2
    syscall

    # División
    div $t0, $t1       	# $lo = $t0 / $t1, $hi = $t0 % $t1
    mflo $t2           	# $t2 = $lo (cociente)
    mfhi $t3           	# $t3 = $hi (resto)

    li $v0, 4          	# syscall para imprimir cadena
    la $a0, div
    syscall

    li $v0, 1          	# syscall para imprimir entero (cociente)
    move $a0, $t2
    syscall

    li $v0, 4          	# syscall para imprimir cadena (barra)
    la $a0, barra
    syscall

    li $v0, 1          	# syscall para imprimir entero (resto)
    move $a0, $t3
    syscall
    
    li $v0, 10         	# syscall para salir del programa
    syscall