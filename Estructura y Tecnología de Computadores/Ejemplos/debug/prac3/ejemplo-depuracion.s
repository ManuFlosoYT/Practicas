
	.data	
	.align	2
dummy:	.word	0
str000:
  	.asciiz "\nTUTORIAL DE DEPURACIÓN EN LENGUAJE ENSAMBLADOR DE MIPS"
str007:
	.asciiz		" "
str008:
	.asciiz		"\n"
str009:
	.asciiz		"\n 1 - Contar dígitos\n 2 - Salir\n\nElige una opción: "
str010:
	.asciiz		"Introduce el carácter de fin: "
str011:
	.asciiz		"\nEl número de dígitos introducidos es: "
str012:
	.asciiz		"¡Adiós!\n"
str013:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"
str014:
	.asciiz		"Introduce caracteres: "
        
	.text	

# es_digito(caracter): Devuelve true si el carácter es un dígito
es_digito_tempregs:
        li      $t0, '0'
        li      $t1, '9'
        move	$v0, $zero
        blt	$a0,  $t0, ED1_fin  # salta si caracter < '0'
        bgtu    $a0, $t1, ED1_fin  # salta si caracter > '9'
        addiu	$v0, $v0, 1
ED1_fin:
        jr      $ra

# es_digito(caracter): Devuelve true si el carácter es un dígito
es_digito:
es_digito_notempregs:
        move	$v0, $zero
        bltu	$a0, '0', ED2_fin  # salta si caracter < '0'
        bgtu    $a0, '9', ED2_fin  # salta si caracter > '9'
        addiu	$v0, $v0, 1
ED2_fin:
        jr      $ra

# contar_digitos(fin_c): Devuelve la cuenta de caracteres 
# introducidos hasta el carácter de fin (inclusive), 
# que corresponden a dígitos
# NOTA: ESTA IMPLEMENTACIÓN ES ERRÓNEA PESE A QUE EN 
# DETERMINADOS ESCENARIOS(*) DEVUELVA RESULTADOS CORRECTOS,
# YA QUE NO SIGUE LA CONVENCIÓN DE USO DE REGISTROS
# (*) Siempre y cuando es_digito no modifique los registros temporales
contar_digitos:
contar_digitos_noconvention:
	# Prólogo
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	move	$t0,$a0
	la	$a0,str014
	jal	print_string
CD_1_inicio_dowhile:
	jal	read_character
	move	$t1, $v0
	move	$a0, $v0
	jal	es_digito
	beqz	$v0, CD_1_fin_dowhile
	addiu	$t2,$t2,1
CD_1_fin_dowhile:
	bne	$t0,$t1,CD_1_inicio_dowhile
	move	$v0, $t2
	# Epílogo
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr      $ra

contar_digitos_buggy1:
	# Prólogo
	addiu	$sp, $sp, -16
	sw	$ra, 12($sp)
	sw	$s2, 8($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	
	move	$s2,$a0
	la	$a0,str014
	jal	print_string
CD_3_inicio_dowhile:
	jal	read_character
	move	$s1, $v0
	move	$a0, $v0
	jal	es_digito
	beqz	$v0, CD_3_fin_dowhile
	addiu	$s0,$s0,1
CD_3_fin_dowhile:
	bne	$s1,$s2,CD_3_inicio_dowhile
	move	$v0, $s0
	# Epílogo
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$ra, 12($sp)
	addiu	$sp, $sp, 16
	jr      $ra

contar_digitos_buggy2:
	# Prólogo
	addiu	$sp, $sp, -12
	sw	$ra, 8($sp)
	sw	$s2, 4($sp)
	sw	$s1, 0($sp)
	
	move	$s0,$zero
	move	$s2,$a0
	la	$a0,str014
	jal	print_string
CD_4_inicio_dowhile:
	jal	read_character
	move	$s1, $v0
	move	$a0, $v0
	jal	es_digito
	beqz	$v0, CD_4_fin_dowhile
	addiu	$s0,$s0,1
CD_4_fin_dowhile:
	bne	$s1,$s2,CD_4_inicio_dowhile
	move	$v0, $s0
	# Epílogo
	lw	$s1, 0($sp)
	lw	$s2, 4($sp)
	lw	$ra, 8($sp)
	addiu	$sp, $sp, 12
	jr      $ra

contar_digitos_correct:
	# Prólogo
	addiu	$sp, $sp, -16
	sw	$ra, 12($sp)
	sw	$s2, 8($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	
	move	$s0,$zero
	move	$s2,$a0
	la	$a0,str014
	jal	print_string
CD_5_inicio_dowhile:
	jal	read_character
	move	$s1, $v0
	move	$a0, $v0
	jal	es_digito
	beqz	$v0, CD_5_fin_dowhile
	addiu	$s0,$s0,1
CD_5_fin_dowhile:
	bne	$s1,$s2,CD_5_inicio_dowhile
	move	$v0, $s0
	# Epílogo
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$ra, 12($sp)
	addiu	$sp, $sp, 16
	jr      $ra

	.globl	main
main:
	addiu	$sp, $sp, -16
	sw	$ra, 12($sp)
	sw	$s2, 8($sp)
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	jal	clear_screen
	la	$a0, str000
	jal	print_string	
B0_2:	
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
	jal	read_character
	move	$s0, $v0
	la	$a0, str008
	jal	print_string
	move	$a0, $s0
	la	$s0, dummy
	jal	contar_digitos
	move	$s2, $v0 
	lw	$t0, 0($s0)	# Dummy load using pointer kept in callee-saved register
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

print_character:
	li	$v0, 11
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
