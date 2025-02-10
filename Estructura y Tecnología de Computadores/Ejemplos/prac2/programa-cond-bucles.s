
	.data	
	.align	2
MAX_LINEAS:
	.word 44
str000:
	.asciiz		"\Práctica 2 de ensamblador de ETC\n"
str001:
	.asciiz		"\n 1 - ¿Es primo? \n 2 - Dibujar triángulo \n 3 - Contar letras \n 4 - Calcular potencias \n 5 - Salir\n\nElige una opción: "
str002:
	.asciiz 	"\n"
str003: 
	.asciiz 	"Introduce un número: "
str004: 
	.asciiz 	"El número es primo."
str005: 
	.asciiz 	"El número no es primo."
str006:
	.asciiz 	"Introduce número de líneas: "
str007:
	.asciiz 	" "
str008:
	.asciiz 	"#"
str009:
	.asciiz 	"Introduce el caracter a contar: "
str010:
	.asciiz		"\nIntroduce el caracter de fin: "
str011:
	.asciiz		"\nEl caracter se ha introducido "
str012:
	.asciiz		"¡Adiós!\n"
str013:
	.asciiz		" veces.\n"
str014: 
	.asciiz		"\nIntroduce caracteres: "
str015: 
	.asciiz		"Introduce un número base: "
str016: 
	.asciiz		"Introduce hasta que potencia calcular: "
str017: 
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"
 
	.text	
# Opción 1. Devuelve true (1) si el número es primo, false (0) en caso contrario
es_primo:                                       # $a0 es num
        # TODO
        break
        
# Opción 2. Dibuja el triángulo, no devuelve ningún valor
dibujar_triangulo:                              # a0 es num_lineas
        # TODO
        break


# Opción 3. Devuelve el número de veces que se ha pulsado una tecla
contar_letras:                                  # a0 es contar_c, a1 es fin_c
        # TODO
        break

# Opcion 4
calcular_potencias:                             # a0 es base y $a1 num_potencias
        # TODO
        break

	.globl	main
main:
	addiu	$sp, $sp, -12
	sw	$ra, 8($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	jal	clear_screen
	la	$a0, str000
	jal	print_string
B4_2:	
	la	$a0, str001
	jal	print_string
	jal	read_character
	move	$s1, $v0
	la	$a0, str002
	jal	print_string
	beq	$s1, '5', B4_7
	bne	$s1, '4', B4_8
	la 	$a0, str015
	jal 	print_string
	jal 	read_integer
	move 	$s0, $v0
	la 	$a0, str016
	jal 	print_string
	jal 	read_integer
	move 	$a1, $v0
	move 	$a0, $s0
	jal	calcular_potencias
	j	B4_2
B4_7:	la	$a0, str012
	jal	print_string
	li	$a0, 0
	jal	mips_exit
	j	B4_2
B4_8:	bne	$s1, '3', B4_11
	la 	$a0, str009
	jal 	print_string
	jal 	read_character
	move 	$s0, $v0
	la 	$a0, str010
	jal 	print_string
	jal 	read_character
	move 	$a1, $v0
	move 	$a0, $s0
	jal 	contar_letras
	move 	$s0, $v0
	la 	$a0, str011
	jal	print_string
	move 	$a0, $s0
	jal 	print_integer
	la 	$a0, str013
	jal	print_string
	j B4_2
B4_11:	bne	$s1, '2', B4_10
	la	$a0, str006
	jal	print_string
	jal	read_integer
	move	$a0, $v0 
	jal	dibujar_triangulo
	j 	B4_2 
B4_10:  bne	$s1, '1', B4_14
	la 	$a0, str003
	jal 	print_string
	jal	read_integer
	move 	$a0, $v0
	jal 	es_primo
	beqz 	$v0, B4_13
	la 	$a0, str004
	jal 	print_string
	j 	B4_2
B4_13:  la 	$a0, str005
	jal 	print_string
	j 	B4_2
B4_12:	la	$a0, str013
	jal	print_string
	jal	read_character	# 121 read_character(); 
	j	B4_2
B4_14:  la      $a0, str017
        jal     print_string
        jal     read_character
	j	B4_2        
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$ra, 8($sp)
	addiu	$sp, $sp, 12
	jr $ra

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

