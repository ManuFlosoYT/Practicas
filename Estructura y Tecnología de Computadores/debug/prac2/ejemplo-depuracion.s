
	.data	
	.align	2
str007:
	.asciiz		" "
str008:
	.asciiz		"\n"
str009:
	.asciiz		"\n 1 - Cálculo de la función factorial\n 2 - Salir\n\nElige una opción: "
str010:
	.asciiz		"Introduce un número de 0 a 10: "
str011:
	.asciiz		"El resultado de la función factorial para dicho número es: "
str012:
	.asciiz		"¡Adiós!\n"
str013:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"
str014:
	.asciiz		"TUTORIAL DE DEPURACIÓN EN LENGUAJE ENSAMBLADOR DE MIPS\n"
strltz:
	.asciiz		"El número introducido es menor que 0\n"
strgt10:
	.asciiz		"El número introducido es mayor que 10\n"
        
	.text	


# factorial_max10(int numero): calcula la función factorial para números entre 0 y 10, 
# para números fuera de ese rango muestra un mensaje y devuelve -1
factorial_max10_buggy1: 	# Contiene un error en la traducción de condicionales
	bgez 	$a0, F0_elseif
	# Número es menor que 0

	# Imprimir cadena "menor que cero"
	la	$a0, strltz
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F0_endif
F0_elseif:
	bgtu	$a0,10,F0_else
	# Número es mayor que 10
	# Imprimir cadena "mayor que 10"
	la	$a0, strgt10
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F0_endif
F0_else:
	# Número es mayor o igual que 0 y menor o igual que 10	
	li	$v0, 1 		# product = 1
	# Bucle for
	li	$t1, 1		# i = 1
F0_forbegin:
	bgt	$t1,$a0,F0_forend # i<=n ?
	mul 	$v0,$v0,$t1	# product = product * i
	addiu	$t1,$t1,1	# i++
F0_forend:
	# v0 ya tiene product
F0_endif:
        jr      $ra

factorial_max10:
factorial_max10_buggy2: 	# Contiene un error en la traducción de bucles
	bgez 	$a0, F1_elseif
	# Número es menor que 0

	# Imprimir cadena "menor que cero"
	la	$a0, strltz
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F1_endif
F1_elseif:
	bleu	$a0,10,F1_else
	# Número es mayor que 10
	# Imprimir cadena "mayor que 10"
	la	$a0, strgt10
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F1_endif
F1_else:
	# Número es mayor o igual que 0 y menor o igual que 10	
	li	$v0, 1 		# product = 1
	# Bucle for
	li	$t1, 1		# i = 1
F1_forbegin:
	bgt	$t1,$a0,F1_forend # i<=n ?
	mul 	$v0,$v0,$t1	# product = product * i
	addiu	$t1,$t1,1	# i++
F1_forend:
	# v0 ya tiene product
F1_endif:
        jr      $ra

factorial_max10_buggy3: 	# Contiene un error en la traducción de bucles
	bgez 	$a0, F3_elseif
	# Número es menor que 0

	# Imprimir cadena "menor que cero"
	la	$a0, strltz
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F3_endif
F3_elseif:
	bleu	$a0,10,F3_else
	# Número es mayor que 10
	# Imprimir cadena "mayor que 10"
	la	$a0, strgt10
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F3_endif
F3_else:
	# Número es mayor o igual que 0 y menor o igual que 10	
	li	$v0, 1 		# product = 1
	# Bucle for
	li	$t1, 1		# i = 1
F3_forbegin:
	bgt	$t1,$a0,F3_forend # i<=n ?
	mul 	$v0,$v0,$t1	# product = product * i
	j	F3_forbegin
F3_forend:
	# v0 ya tiene product
F3_endif:
        jr      $ra

# Implementación correcta
factorial_max10_correct: 
	bgez 	$a0, F4_elseif
	# Número es menor que 0

	# Imprimir cadena "menor que cero"
	la	$a0, strltz
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F4_endif
F4_elseif:
	bleu	$a0,10,F4_else
	# Número es mayor que 10
	# Imprimir cadena "mayor que 10"
	la	$a0, strgt10
	li	$v0, 4
	syscall	
	li	$v0,-1		# Devolver -1
	j	F4_endif
F4_else:
	# Número es mayor o igual que 0 y menor o igual que 10	
	li	$v0, 1 		# product = 1
	# Bucle for
	li	$t1, 1		# i = 1
F4_forbegin:
	bgt	$t1,$a0,F4_forend # i<=n ?
	mul 	$v0,$v0,$t1	# product = product * i
	addiu	$t1,$t1,1	# i++
	j	F4_forbegin
F4_forend:
	# v0 ya tiene product
F4_endif:
        jr      $ra

	.globl	main
main:
	addiu	$sp, $sp, -16
	sw	$ra, 12($sp)
	sw	$s2, 8($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	jal	clear_screen
	la	$a0, str014
	jal	print_string
B0_2:	
	la	$a0, str008
	jal	print_string
	la	$a0, str009
	jal	print_string
	jal	read_character
	move	$s1, $v0
	la	$a0, str008
	jal	print_string
B0_8:	bne	$s1, '1', B0_10
	la	$a0, str010
	jal	print_string
	jal	read_integer
	move	$a0, $v0
	jal	factorial_max10
	bltz 	$v0, B0_2	
	move	$s2, $v0 
	la	$a0, str011
	jal	print_string
	move	$a0, $s2
	jal	print_integer
        j       B0_2
B0_10:
	bne	$s1, '2', B0_7
	la	$a0, str012
	jal	print_string
	li	$a0, 0
	jal	mips_exit
	j	B0_2
B0_7:	
	la	$a0, str013
	jal	print_string
	jal	read_character	# 121     read_character(); 
	j	B0_2
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$ra, 12($sp)
	addiu	$sp, $sp, 16
	jr      $ra

print_integer:
	li	$v0, 1
	syscall	
	jr	$ra

read_integer:
	li	$v0, 5
	syscall	
	jr	$ra

print_string:
	li	$v0, 4
	syscall	
	jr	$ra

read_character:
	li	$v0, 12
	syscall	
	jr	$ra

clear_screen:
	li	$v0, 39
	syscall	
	jr	$ra

mips_exit:
	li	$v0, 17
	syscall	
	jr	$ra

random_int_range:
	li	$v0, 42
	syscall	
	move	$v0, $a0
	jr	$ra
