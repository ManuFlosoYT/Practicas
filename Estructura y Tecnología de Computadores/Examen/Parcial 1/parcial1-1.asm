.data
	pedir_numeros:	.asciiz "Introduce 10 números enteros: \n"
	sacar_mayor:	.asciiz "El mayor de los números introducidos es: "
	dos_puntos:	.asciiz ": "

.text
.globl main

main:
	addi 	$sp, $sp, -8
	sw 	$s0, 4($sp)
	sw	$s1, 8($sp)
	
	li	$s0, 0	#Iterador
	
	la 	$a0, pedir_numeros
	jal 	imprimir_string
	
	
	for:
		add	$s0, $s0, 1
		move	$a0, $s0
		jal 	imprimir_entero
		
		la	$a0, dos_puntos
		jal	imprimir_string
		
		jal 	leer_entero
		bne	$s0, 1, no_primera_vez
		
		
		#Si es la primera vez pide el segundo
		move 	$s1, $v0
		j	for	
		
		no_primera_vez:
			
			#Mueve ambos numeros a los registros de parametro
			move 	$a0, $s1
			move 	$a1, $v0
			
			#Llama a la funcion y almacena el segndo
			jal 	mayor
			move	$s1, $v0
			
			beq	$s0, 10, fin_for
			j 	for
			
		fin_for:
			la	$a0, sacar_mayor
			jal	imprimir_string
		
			move	$a0, $s1
			jal	imprimir_entero
	
	lw 	$s0, 4($sp)
	lw	$s1, 8($sp)
	addi 	$sp, $sp, 8
	
	#Exit
	li $v0, 10
	syscall

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
	li	$v0, 4
	syscall
	jr	$ra

imprimir_entero:
	li	$v0, 1
	syscall
	jr	$ra

imprimir_char:
	li	$v0, 11
	syscall
	jr	$ra
	
leer_entero:
	li	$v0, 5
	syscall
	jr	$ra