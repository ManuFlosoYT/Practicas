
	.data	
	.align	2
jump_table000:
	.word	B6_4
	.word	B6_5
	.word	B6_6
	.word	B6_9
	.word	B6_22
str000:
	.asciiz		"Contenido actual de la agenda:\n"
str001:
	.asciiz		" - Nombre: "
str002:
	.asciiz		", Edad: "
str003:
	.asciiz		", Email: "
str004:
	.asciiz		"\n"
str005:
	.asciiz		"Introduzca el nombre del nuevo contacto: "
str006:
	.asciiz		"Introduzca la edad del nuevo contacto: "
str007:
	.asciiz		"Introduzca el correo del nuevo contacto: "
str008:
	.asciiz		"\nPráctica 4 de ensamblador de ETC\n\n 1 - Estructuras\n 2 - Arrays y cadenas\n 3 - Arrays bidimensionales\n 4 - Estructuras\n 0 - Salir\n\nElige una opción: "
str009:
	.asciiz		"("
str010:
	.asciiz		","
str011:
	.asciiz		") + ("
str012:
	.asciiz		") = ("
str013:
	.asciiz		")\n"
str014:
	.asciiz		"\nFrecuencia de cada letra en el texto:\n"
str015:
	.asciiz		": "
str016:
	.asciiz		"matA:\n"
str017:
	.asciiz		" "
str018:
	.asciiz		"matB:\n"
str019:
	.asciiz		"matC = matA × matB:\n"
str020:
	.asciiz		"¡Adiós!\n"
str021:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

# variables del ejercicio 1
vb:
        # TODO
vc:
        # TODO
va:
        # TODO


# variables del ejercicio 2
texto:
        # TODO
cuentas_letras:
        # TODO

# variables del ejercicio 3
matA:   # 5*4 = 20 elementos; 4*4 = 16 bytes/fila; 16*5 = 80 bytes
        .word	3, 4, 5, 6
        .word	2, 1, 3, 0
        .word	7, 8, 7, 2
        .word	0, 1, 9, 5
        .word	8, 3, 6, 1
matB:   # 4*3 = 12 elementos; 4*3 = 12 bytes/fila; 12*4 = 48 bytes
        .word	7, 8, 2
        .word	3, 7, 1
        .word	9, 0, 1
        .word	1, 2, 4
matC:   
        .align	2	# Asegurar el alineamiento del word
        .space 	60	# 5*3 = 15 elementos; 3*4 = 12 bytes/fila; 12*5 = 60 bytes

# variables del ejercicio 4 y 5
# (añadir aquí)

        
	.text	

sumar_vb_vc:
        # TODO
        break

contar_letras:
        # TODO
        break

multiplicar_matA_matB:
        li	$t0, 0	# i = 0
  	for1Mul:
  		beq	$t0, 5, finFor1Mul
  		
  		li	$t1, 0	# j = 0
  		for2Mul:
  			beq	$t1, 3, finFor2Mul
  			
  			li	$t2, 0	# r = 0
  			li	$t3, 0	# k = 0	
  			for3Mul:
  				beq	$t3, 4, finFor3Mul
  			
  				mul	$t4, $t0, 16	# Calcular a que fila accede
  				mul	$t8, $t3, 4	# Alinear a 4 bytes
  				add	$t4, $t4, $t8	# Sumar offsets
  				la	$t5, matA	# Carga la direccion
  				add	$t5, $t5, $t4	# Suma todos los offsets
  				lw	$t6, ($t5)	# Leer la posicion
  				
  				mul	$t4, $t3, 12	# Calcular a que fila accede
  				mul	$t8, $t1, 4	# Alinear a 4 bytes
  				add	$t4, $t4, $t8	# Sumar offsets
  				la	$t5, matB	# Carga la direccion
  				add	$t5, $t5, $t4	# Suma todos los offsets
  				lw	$t7, ($t5)	# Leer la posicion
  				
  				# $t6 = matA[i][k]; $t7 = matB[k][j]
  				mul	$t4, $t6, $t7	# matA[i][k] * matB[k][j]
  				add	$t2, $t2, $t4	# r = r + matA[i][k] * matB[k][j];
  				
  				addi	$t3, $t3, 1
  				j	for3Mul
  			finFor3Mul:
  			
  			mul	$t4, $t0, 12	# Calcular a que fila accede
  			mul	$t8, $t1, 4	# Alinear a 4 bytes
  			add	$t4, $t4, $t8	# Sumar offsets
  			la	$t5, matC	# Carga la direccion
  			add	$t5, $t5, $t4	# Suma todos los offsets
  			sw	$t2, ($t5)	# matC[i][j] = r;
  			
  			addi	$t1, $t1, 1
  			j	for2Mul
  		finFor2Mul:
  		addi	$t0, $t0, 1
  		j for1Mul	
        finFor1Mul:
        jr	$ra

mostrar_agenda:
        # TODO
        break

read_line:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	move	$s0, $a1
	move	$s1, $a0
	jal	read_string
	slti	$t8, $s0, 1
	bnez	$t8, B4_6
	li	$v0, 0
	li	$v1, 10
B4_2:	addu	$a0, $s1, $v0
	lbu	$a1, 0($a0)
	beqz	$a1, B4_6
	bne	$a1, $v1, B4_5
	sb	$zero, 0($a0)
B4_5:	addiu	$v0, $v0, 1
	slt	$t8, $v0, $s0
	bnez	$t8, B4_2
B4_6:	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

anadir_contacto:
        # TODO
        break

	.globl	main
main:
	addiu	$sp, $sp, -112
	sw	$ra, 108($sp)
	sw	$fp, 104($sp)
	sw	$s7, 100($sp)
	sw	$s6, 96($sp)
	sw	$s5, 92($sp)
	sw	$s4, 88($sp)
	sw	$s3, 84($sp)
	sw	$s2, 80($sp)
	sw	$s1, 76($sp)
	sw	$s0, 72($sp)
	jal	clear_screen
	la	$t8, str008
	sw	$t8, 64($sp)
	la	$t8, str004
	sw	$t8, 60($sp)
	la	$t8, str021
	sw	$t8, 56($sp)
	la	$t8, str020
	sw	$t8, 52($sp)
	la	$t8, str009
	sw	$t8, 48($sp)
	la	$s2, str010
	la	$t8, str011
	sw	$t8, 44($sp)
	la	$t8, str012
	sw	$t8, 40($sp)
	la	$t8, str013
	sw	$t8, 36($sp)
	la	$t8, str014
	sw	$t8, 32($sp)
	la	$t8, str015
	sw	$t8, 68($sp)
	la	$t8, str016
	sw	$t8, 28($sp)
	la	$s4, str017
	li	$s1, 5
	la	$t8, str018
	sw	$t8, 24($sp)
	la	$t8, str019
	sw	$t8, 20($sp)
	j	B6_2
B6_1:	lw	$a0, 56($sp)
	jal	print_string
	jal	read_character
B6_2:	lw	$a0, 64($sp)
	jal	print_string
	jal	read_character
	move	$fp, $v0
	lw	$s3, 60($sp)
	move	$a0, $s3
	jal	print_string
	move	$a0, $s3
	jal	print_string
	sll	$t8, $fp, 24
	sra	$t8, $t8, 24
	addiu	$v0, $t8, -48
	li	$t8, 4
	sltu	$t8, $t8, $v0
	bnez	$t8, B6_1
	sll	$t8, $v0, 2
	lw	$t8, jump_table000($t8)
	jr	$t8
B6_4:	lw	$a0, 52($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
	j	B6_2
B6_5:	li	$t8, 7
	sw	$t8, vb
	la	$s6, vb
	li	$t8, 8
	sw	$t8, 4($s6)
	li	$t8, 9
	sw	$t8, 8($s6)
	li	$t8, 3
	sw	$t8, vc
	la	$fp, vc
	li	$t8, 4
	sw	$t8, 4($fp)
	li	$t8, 2
	sw	$t8, 8($fp)
	jal	sumar_vb_vc
	lw	$a0, 48($sp)
	jal	print_string
	lw	$a0, vb
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	lw	$a0, 4($s6)
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	lw	$a0, 8($s6)
	jal	print_integer
	lw	$a0, 44($sp)
	jal	print_string
	lw	$a0, vc
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	lw	$a0, 4($fp)
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	lw	$a0, 8($fp)
	jal	print_integer
	lw	$a0, 40($sp)
	jal	print_string
	lw	$a0, va
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	la	$s3, va
	lw	$a0, 4($s3)
	jal	print_integer
	move	$a0, $s2
	jal	print_string
	lw	$a0, 8($s3)
	jal	print_integer
	lw	$a0, 36($sp)
	jal	print_string
	j	B6_2
B6_6:	jal	contar_letras
	lw	$a0, 32($sp)
	jal	print_string
	la	$s6, cuentas_letras
	li	$fp, 97
B6_7:	sll	$t8, $fp, 24
	sra	$a0, $t8, 24
	jal	print_character
	lw	$a0, 68($sp)
	jal	print_string
	lw	$a0, 0($s6)
	jal	print_integer
	la	$a0, str004
	jal	print_string
	addiu	$fp, $fp, 1
	li	$t8, 123
	addiu	$s6, $s6, 4
	bne	$fp, $t8, B6_7
	j	B6_2
B6_9:	jal	multiplicar_matA_matB
	lw	$a0, 28($sp)
	jal	print_string
	la	$fp, matA
	li	$s6, 0
B6_10:	li	$s3, 4
	move	$s5, $fp
B6_11:	lw	$a0, 0($s5)
	jal	print_integer
	move	$a0, $s4
	jal	print_string
	addiu	$s3, $s3, -1
	addiu	$s5, $s5, 4
	bnez	$s3, B6_11
	la	$a0, str004
	jal	print_string
	addiu	$s6, $s6, 1
	addiu	$fp, $fp, 16
	bne	$s6, $s1, B6_10
	lw	$a0, 24($sp)
	jal	print_string
	la	$s5, matB
	li	$s6, 0
B6_14:	li	$s3, 3
	move	$fp, $s5
B6_15:	lw	$a0, 0($fp)
	jal	print_integer
	la	$a0, str017
	jal	print_string
	addiu	$s3, $s3, -1
	addiu	$fp, $fp, 4
	bnez	$s3, B6_15
	la	$a0, str004
	jal	print_string
	addiu	$s6, $s6, 1
	li	$t8, 4
	addiu	$s5, $s5, 12
	bne	$s6, $t8, B6_14
	lw	$a0, 20($sp)
	jal	print_string
	la	$fp, matC
	li	$s6, 0
B6_18:	li	$s3, 3
	move	$s5, $fp
B6_19:	lw	$a0, 0($s5)
	jal	print_integer
	la	$a0, str017
	jal	print_string
	addiu	$s3, $s3, -1
	addiu	$s5, $s5, 4
	bnez	$s3, B6_19
	la	$a0, str004
	jal	print_string
	addiu	$s6, $s6, 1
	addiu	$fp, $fp, 12
	bne	$s6, $s1, B6_18
	j	B6_2
B6_22:	jal	anadir_contacto
	jal	mostrar_agenda
	j	B6_2
	lw	$ra, 108($sp)
	lw	$fp, 104($sp)
	lw	$s7, 100($sp)
	lw	$s6, 96($sp)
	lw	$s5, 92($sp)
	lw	$s4, 88($sp)
	lw	$s3, 84($sp)
	lw	$s2, 80($sp)
	lw	$s1, 76($sp)
	lw	$s0, 72($sp)
	addiu	$sp, $sp, 112
        jr      $ra

print_integer:
	li	$v0, 1
	syscall	
	jr	$ra

read_integer:
	li	$v0, 5
	syscall	
	jr	$ra

read_string:
	li	$v0, 8
	syscall	
	jr	$ra

print_character:
	li	$v0, 11
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
