        .data
num1:   .word 1000, 2000, 3000, 4000        # Cuatro palabras con valores 1000,
                                            # 2000, 3000 y 4000 respectivamente
num2:   .half 100, 200, 300, 400            # Cuatro medias palabras con valores
                                            # 100, 200, 300 y 400 respectivamente
num3:   .byte 10, 20, 30, 40                # Cuatro bytes con valores 10, 20, 30,
                                            # y 40 respectivamente
retcar: .byte '\n'                          # Carácter de retorno de carro
msg:    .asciiz "El elemento buscado es: "   # Cadena para imprimir
msg2:   .asciiz "Introduce el número de elemento a mostrar: "   # Cadena para imprimir
	.align 2
i:      .space 4                            # 4 bytes para guardar el nº de
                                            # elemento a buscar 

        .text
# Procedimiento principal
	.globl	main
main:   

        la      $a0, msg2        # Pone en $a0 la dirección de la cadena
        li      $v0, 4          # Código syscall para imprimir una cadena
        syscall                 # Imprime la cadena «Introduce el número de elemento a mostrar:»
	
	li	$v0, 5		#Carga el comando de leer entero
	syscall			#Llama al sistema
	move $t0, $v0		#Copia v0 a t0
	
	sw 	$t0, i

        la      $t1, num1       # Pone en $t1 la dirección de «num1»
        sll     $t4, $t0, 2     # Multiplica el nº elemento por 4
        add     $t4, $t1, $t4   # Suma el desplazamiento a la dirección de comienzo
        lw      $t5, 0($t4)     # Accede a memoria a leer el elemento 

        la      $a0, msg        # Pone en $a0 la dirección de la cadena
        li      $v0, 4          # Código syscall para imprimir una cadena
        syscall                 # Imprime la cadena «El elemento buscado es:»

        li      $v0, 1          # Código syscall para imprimir un entero
        move    $a0, $t5        # Pone en $a0 el entero a imprimir
        syscall                 # Imprime el entero

	li      $v0, 11         # Código syscall para imprimir un carácter
        lbu     $a0, retcar     # Carga en $a0 el carácter a imprimir (retcar)
        syscall                 # Imprime el caracter
        
        #NUM 2
        la      $t1, num2       # Pone en $t1 la dirección de «num2»
        sll     $t4, $t0, 1    	# Multiplica el nº elemento por 2
        add     $t4, $t1, $t4   # Suma el desplazamiento a la dirección de comienzo
        lh      $t5, 0($t4)     # Accede a memoria a leer el elemento 

        la      $a0, msg        # Pone en $a0 la dirección de la cadena
        li      $v0, 4          # Código syscall para imprimir una cadena
        syscall                 # Imprime la cadena «El elemento buscado es:»

        li      $v0, 1          # Código syscall para imprimir un entero
        move    $a0, $t5        # Pone en $a0 el entero a imprimir
        syscall                 # Imprime el entero

	li      $v0, 11         # Código syscall para imprimir un carácter
        lbu     $a0, retcar     # Carga en $a0 el carácter a imprimir (retcar)
        syscall                 # Imprime el caracter
        
        #NUM 3
        la      $t1, num3 	# Pone en $t1 la dirección de «num3»
        sll     $t4, $t0, 0     # Multiplica el nº elemento por 1
        add     $t4, $t1, $t4   # Suma el desplazamiento a la dirección de comienzo
        lb      $t5, 0($t4)     # Accede a memoria a leer el elemento 

        la      $a0, msg        # Pone en $a0 la dirección de la cadena
        li      $v0, 4          # Código syscall para imprimir una cadena
        syscall                 # Imprime la cadena «El elemento buscado es:»

        li      $v0, 1          # Código syscall para imprimir un entero
        move    $a0, $t5        # Pone en $a0 el entero a imprimir
        syscall                 # Imprime el entero

	li      $v0, 11         # Código syscall para imprimir un carácter
        lbu     $a0, retcar     # Carga en $a0 el carácter a imprimir (retcar)
        syscall                 # Imprime el caracter

        li      $v0, 10         # Código syscall de exit
        syscall         
	jr 	$ra
