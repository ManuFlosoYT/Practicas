.data
 	string_entrada: 	.asciiz "Introduzca un número: "
 	string_entrada2: 	.asciiz "Introduzca otro número: "
    	string_salida: 		.asciiz "El mínimo común múltiplo es: "
.text
.globl main

main:
	addi 	$sp, $sp, -4
	sw 	$s0, 4($sp)

    	la 	$a0, string_entrada
    	jal 	imprimir_string
    	
    	jal 	leer_entero
    	move 	$s0, $v0
    	
    	la 	$a0, string_entrada2
    	jal 	imprimir_string
    	jal 	leer_entero
    	move 	$a1, $v0
    	
	move	$a0, $s0
	jal	minimo_comun_multiplo
	move	$s0, $v0
	
	la 	$a0, string_salida
    	jal 	imprimir_string
	
	move	$a0, $s0
	jal 	imprimir_entero

	lw 	$s0, 4($sp)
	addi 	$sp, $sp, 4
	
    	# Salir del programa
    	li 	$v0, 10
	syscall

#Recibe 2 enteros por los registros $a0 y $a1
#Devuelve el mínimo común múltiplo de ambos por $v0
# int limite = $s0
# int x = $s1
# int y = $s2
# int salir = $t1
# int mcm = $v0
minimo_comun_multiplo:
	#Almacenar la posicion de retorno
	addi 	$sp, $sp, -16
	sw 	$ra, 4($sp)
	sw 	$s0, 8($sp)
	sw 	$s1, 12($sp)
	sw 	$s2, 16($sp)
	
	#Guarda "x" e "y" de los parametros a registros permanentes
	move	$s1, $a0
	move	$s2, $a1
	
	#Hace la multiplicacion y la almacena en registro permanente
	mul	$s0, $a0, $a1
	
	#Busca el mayor de "x" e "y" y lo almacena en $v0
	jal	mayor
	
	#Guarda el valor guardia de salida
	li	$t1, 0 
	
	bucle:
		bgtz	$t1, fin_bucle
		bgt	$v0, $s0, fin_bucle
	
		rem	$t0, $v0, $s1
		bnez	$t0, if
		rem	$t0, $v0, $s2
		bnez	$t0, else_if
		j	else
		if:	
			add	$v0, $v0, 1
			j	bucle
		else_if:
			add	$v0, $v0, 1
			j	bucle
		else:
			add	$t1, $t1, 1
			j 	bucle	
	fin_bucle:
	
	#Leer el puntero de retorno
	lw 	$ra, 4($sp)
	lw 	$s0, 8($sp)
	lw 	$s1, 12($sp)
	lw 	$s2, 16($sp)
	addi 	$sp, $sp, 16
	
	jr	$ra
      	 	
       	 	
#Recibe 2 enteros por los registros $a0 y $a1.
#Devuelve el entero mayor por $v0
mayor:
	bge	$a0, $a1, esMayor
	
	esMenor:
		move	$v0, $a1
		j 	devolver_mayor
	esMayor:
		move 	$v0, $a0
		j 	devolver_mayor
	devolver_mayor:
		jr	$ra

imprimir_string:
    	# Imprimir una cadena
    	li $v0, 4
	syscall
    	jr $ra

imprimir_entero:
    	# Imprimir un entero
    	li $v0, 1
    	syscall
    	jr $ra

imprimir_char:
    	# Imprimir un carácter
    	li $v0, 11
    	syscall
    	jr $ra

leer_entero:
    	# Leer un entero desde teclado
    	li $v0, 5
    	syscall
    	jr $ra
