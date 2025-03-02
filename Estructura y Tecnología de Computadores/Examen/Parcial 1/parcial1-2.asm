.data
 	string_entrada: .asciiz "Introduzca un número: "
    	string_salida: 	.asciiz "La parte entera de la raíz cúbica del número introducido es: "
.text
.globl main

main:

    	# Imprimir string_entrada
    	la $a0, string_entrada
    	jal imprimir_string

    	# Leer entero desde teclado
    	jal leer_entero
    	move $a0, $v0

    	# Calcular la raíz cúbica
    	jal raizcubica
    	move $s0, $v0
    	

    	# Imprimir string_salida
    	la $a0, string_salida
    	jal imprimir_string

    	# Imprimir resultado
    	move $a0, $s0
    	jal imprimir_entero

    	# Salir del programa
    	li $v0, 10
	syscall

cubo:
    	# Calcular el cubo de un número
    	mul $v0, $a0, $a0
    	mul $v0, $v0, $a0
    	jr $ra

raizcubica:
    	addi $sp, $sp, -12  	# Reservar espacio en pila para $ra, $s0, $s1
    	sw $ra, 8($sp)      	# Apilar $ra
    	sw $s0, 4($sp)      	# Apilar $s0
    	sw $s1, 0($sp)      	# Apilar $s1

    	# Calcular la parte entera de la raíz cúbica de un número
    	li $s1, 0           	# r = 0
   	move $s0, $a0       	# n = $a0 (parámetro de entrada) 

    	raizcubica_loop:
        	# Calcular el cubo de r
        	move $a0, $s1
        	jal cubo

        	# Verificar si potencia < n
        	blt $v0, $s0, raizcubica_incrementar

        	# Verificar si potencia > n
        	bgt $v0, $s0, raizcubica_decrementar

        	# Si potencia == n, devolver r
        	move $v0, $s1
        	

    	raizcubica_fin:		#Etiqueta para tener un único punto de salida de la función
    		
        	lw $s1, 0($sp)      	# Desapilar $s1
        	lw $s0, 4($sp)      	# Desapilar $s0
        	lw $ra, 8($sp)      	# Desapilar $ra
        	addi $sp, $sp, 12  	# Liberar memoria reservada de pila

        	jr $ra

    	raizcubica_incrementar:
        	addi $s1, $s1, 1    	# r++
        	j raizcubica_loop

    	raizcubica_decrementar:
        	addi $s1, $s1, -1   	# r--
        	move $v0, $s1
       	 	j raizcubica_fin   	# Salta al fin de la funcion

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