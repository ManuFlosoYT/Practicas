        .data
num1:   .word 1000, 2000, 3000, 4000        # Cuatro palabras con valores 1000,
                                            # 2000, 3000 y 4000 respectivamente
num2:   .half 100, 200, 300, 400            # Cuatro medias palabras con valores
                                            # 100, 200, 300 y 400 respectivamente
num3:   .byte 10, 20, 30, 40                # Cuatro bytes con valores 10, 20, 30,
                                            # y 40 respectivamente
retcar: .byte '\n'                          # Carácter de retorno de carro
msg:    .asciiz "El elemento buscado es:"   # Cadena para imprimir
i:      .space 4                            # 4 bytes para guardar el nº de
                                            # elemento a buscar 

        .text
# Procedimiento principal
	.globl	main
main:   

	li      $t0, 2          # Pone en $t0 el nº de elemento a cargar

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

        li      $v0, 10         # Código syscall de exit
        syscall         
	jr 	$ra
