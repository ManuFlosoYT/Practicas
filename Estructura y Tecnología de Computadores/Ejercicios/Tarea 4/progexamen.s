
	.data	
str000:
	.asciiz		"Serie Fibonacci: "
str001:
	.asciiz		" "
str002:
	.asciiz		"\n"
str004:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Serie de Fibonacci\n 2. Hacer cuenta\n 0. Salir\n\nElige una opción: "
str005:
	.asciiz		"\n\n"
str006:
	.asciiz		"Introduce el número para calcular la serie de Fibonacci: "
str007:
	.asciiz		"Límite máximo de gasto permitido: "
str008:
	.asciiz		"El total gastado es: "
str009:
	.asciiz		"¡Adiós!\n"
str010:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"
str011:
	.asciiz		"Introduce cantidades gastadas: "
gasto:
	.word		0

	.text	

# Ejercicio 1
# Imprime x elementos de la serie de Fibonnaci 
# Recibe por $a0 el parametro x
serie_fibonacci:
	addiu	$sp, $sp, -24
	sw	$ra, 4($sp)
	sw	$s0, 8($sp)
	sw	$s1, 12($sp)
	sw	$s2, 16($sp)
	sw	$s3, 20($sp)
	sw	$s4, 24($sp)
	
	blez	$a0, salir_fib	#if (x <= 0) salir
	
	move	$s0, $a0	# Parametro X
	
	la	$a0, str000
	jal	print_string
	
	li	$s1, 0		#f0
	li	$a0, 0
	jal	print_integer
	
	bgt	$s0, 1, if	#Si es mayor que 1 entramos al bucle, si no salimos directamente
	j	salir_fib
	
	if:
		li	$s2, 1		#f1
		add	$s3, $s1, $s2	#siguiente = f0 + f1
		
		la	$a0, str001
		jal	print_string
		
		la	$a0, 1
		jal	print_integer
		
		li	$s4, 2
		for_fib:
			bge	$s4, $s0, fin_for_fib
			
			la	$a0, str001
			jal	print_string
			
			move	$a0, $s3
			jal	print_integer
			
			move	$s1, $s2	#f0 = f1
			move	$s2, $s3	#f1 = siguiente
			add	$s3, $s1, $s2	#siguiente = f0 + f1
			
			
			add	$s4, $s4, 1
			j	for_fib
		fin_for_fib:
	salir_fib:
	
	la	$a0, str002
	jal	print_string
	
	lw	$ra, 4($sp)
	lw	$s0, 8($sp)
	lw	$s1, 12($sp)
	lw	$s2, 16($sp)
	lw	$s3, 20($sp)
	lw	$s4, 24($sp)
	addiu	$sp, $sp, 24
	
	jr	$ra


# Ejercicio 2
# Devuelve la cuenta total del dinero gastado
# Recibe por $a0 el maximo
hacer_cuenta:
	addiu	$sp, $sp, -16
	sw	$ra, 4($sp)
	sw	$s0, 8($sp)	#max
	sw	$s1, 12($sp)	#total
	sw	$s2, 16($sp)	#gasto
	
	move	$s0, $a0
	li	$s1, 0
	
	la	$a0, str011
	jal	print_string
	
	jal	read_integer
	move	$s2, $v0
	
	blez	$s2, cuenta_return_zero	#if(gasto <= 0) return 0
	
	bucle:
		bge	$s2, $s0, fin_bucle	#while(gasto <= max), salir si gasto >= max
		blez	$s2, fin_bucle
		
		add	$s1, $s1, $s2
		
		jal	read_integer
		move	$s2, $v0	
	
		j	bucle
	fin_bucle:
		j	cuenta_return
	
	cuenta_return_zero:
	li	$v0, 0
	cuenta_return:
	move	$v0, $s1
	
	sw	$s1, gasto	#Guardar en la variable global
	
	lw	$ra, 4($sp)
	lw	$s0, 8($sp)
	lw	$s1, 12($sp)
	lw	$s2, 16($sp)
	addiu	$sp, $sp, 16
	
	jr	$ra

	.globl	main
main:
	addiu	$sp, $sp, -72
	sw	$ra, 68($sp)
	sw	$fp, 64($sp)
	sw	$s7, 60($sp)
	sw	$s6, 56($sp)
	sw	$s5, 52($sp)
	sw	$s4, 48($sp)
	sw	$s3, 44($sp)
	sw	$s2, 40($sp)
	sw	$s1, 36($sp)
	sw	$s0, 32($sp)
	jal	clear_screen
	la	$s0, str004
	la	$s1, str005
	lui	$s2, 12288
	la	$t1, str009
	sw	$t1, 28($sp)
	lui	$s3, 12800
	la	$t1, str007
	sw	$t1, 24($sp)
	la	$t1, str008
	sw	$t1, 20($sp)
	la	$s5, str002
	lui	$s4, 12544
	la	$s6, str006
	la	$s7, str010
	j	B2_2
B2_1:	lw	$a0, 24($sp)
	jal	print_string
	jal	read_integer
	move	$a0, $v0
	jal	hacer_cuenta
	lw	$a0, 20($sp)
	move	$fp, $v0
	jal	print_string
	move	$a0, $fp
	jal	print_integer
	move	$a0, $s5
	jal	print_string
B2_2:	move	$a0, $s0
	jal	print_string
	jal	read_character
	move	$fp, $v0
	move	$a0, $s1
	jal	print_string
	sll	$v0, $fp, 24
	beq	$v0, $s2, B2_6
	beq	$v0, $s3, B2_1
	bne	$v0, $s4, B2_7
	move	$a0, $s6
	jal	print_string
	jal	read_integer
	move	$a0, $v0
	jal	serie_fibonacci
	la	$a0, str002
	jal	print_string
	j	B2_2
B2_6:	lw	$a0, 28($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
	j	B2_2
B2_7:	move	$a0, $s7
	jal	print_string
	jal	read_character
	j	B2_2

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
