
	.data	
	.align	2
enteros:
	.word	4
	.word	5
	.word	3344
	.word	655
	.word	4294967222
	.word	53
	.word	23
	.word	14
	.word	4294966291
	.word	34
	.word	25
	.word	26
	.word	7
	.word	8
	.word	4
	.word	83

str000:
	.asciiz		"\n Contenido del vector de enteros: "
str007:
	.asciiz		" "
str008:
	.asciiz		"\n"
str009:
	.asciiz		"\n 1 - Contar las apariciones de un escalar en un vector (for)\n 2 - Salir\n\nElige una opción: "
str010:
	.asciiz		"Introduce el escalar con el que quieres comparar: "
str011:
	.asciiz		"El número de apariciones es: "
str012:
	.asciiz		"¡Adiós!\n"
str013:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"
str014:
	.asciiz		"TUTORIAL DE DEPURACIÓN EN LENGUAJE ENSAMBLADOR DE MIPS\n"
        
	.text	


# contar_apariciones(escalar) compara los elementos del vector
# global «enteros», con respecto al escalar recibido en a0 y devuelve el
# número de apariciones de «escalar» en «enteros»*/

contar_apariciones:
contar_apariciones_buggy1:
        li      $t1, 0          # i
        li      $v0, 0          # apariciones
        li      $t2, 16         # NUM_DATOS_MAX
B2_1:  
	bge     $t1, $t2, B2_2
        lw      $t0, enteros
	add	$t4, $t0, $t1	# dirección de enteros[i] (?)
	lw	$t5, 0($t4)
	bne	$t5, $a0, B2_3
	addi	$v0, $v0, 1	# ++apariciones
B2_3:
	addi	$t1, $t1, 1	# ++i	
        j       B2_1
B2_2:
        jr      $ra

contar_apariciones_buggy2:
        li      $t1, 0          # i
        li      $v0, 0          # apariciones
        li      $t2, 16         # NUM_DATOS_MAX
B3_1:  
	bge     $t1, $t2, B3_2
        la      $t0, enteros
	add	$t4, $t0, $t1	# dirección de enteros[i] (?)
	lw	$t5, 0($t4)
	bne	$t5, $a0, B3_3
	addi	$v0, $v0, 1	# ++apariciones
B3_3:
	addi	$t1, $t1, 1	# ++i	
        j       B3_1
B3_2:
        jr      $ra


contar_apariciones_buggy3:
        li      $t1, 0          # i
        li      $v0, 0          # apariciones
        li      $t2, 16         # NUM_DATOS_MAX
B4_1:  
	bge     $t1, $t2, B4_2
        la      $t0, enteros
	sll	$t3, $t1, 3	# Desplazamiento: i*sizeof(int)
	add	$t4, $t0, $t3	# dirección de enteros[i] = (dir base) + i*sizeof(int) (desplazamiento)
	lw	$t5, 0($t4)
	bne	$t5, $a0, B4_3
	addi	$v0, $v0, 1	# ++apariciones
B4_3:
	addi	$t1, $t1, 1	# ++i	
        j       B4_1
B4_2:
        jr      $ra

contar_apariciones_correct:
        la      $t0, enteros
        li      $t1, 0          # i
        li      $v0, 0          # apariciones
        li      $t2, 16         # NUM_DATOS_MAX
B5_1:  
	bge     $t1, $t2, B5_2
	sll	$t3, $t1, 2	# Desplazamiento: i*sizeof(int)
	add	$t4, $t0, $t3	# dirección de enteros[i] = (dir base) + i*sizeof(int) (desplazamiento)
	lw	$t5, 0($t4)
	bne	$t5, $a0, B5_3
	addi	$v0, $v0, 1	# ++apariciones
B5_3:
	addi	$t1, $t1, 1	# ++i	
        j       B5_1
B5_2:
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
B0_2:	la	$a0, str000
	jal	print_string
	li	$s0, 0		# i = 0
B0_3:	li	$t0, 16
	bge	$s0, $t0, B0_4
	la	$t0, enteros	# Dir base
	sll	$t1, $s0, 2	# Desplazamiento: i*4
	add	$t2, $t1, $t0	# Base + desp
	lw	$a0, 0($t2)
	jal	print_integer
	la	$a0, str007
	jal	print_string
	addiu	$s0, $s0, 1
	j	B0_3
B0_4:	la	$a0, str008
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
	jal	contar_apariciones
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
