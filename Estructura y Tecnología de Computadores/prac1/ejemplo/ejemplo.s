        .data
msg:    .asciiz "¡Hola mundo!"  # Cadena para imprimir
numeros:.word 17, 0x17          # Dos palabras con valor 17 y 23 respectivamente
                                
retcar: .byte '\n'              # Carácter de retorno de carro

        .align 2                # Alineado a dirección de palabra a continuación
suma:   .space 4                # 4 bytes para guardar el resultado

        .text
# Procedimiento principal
	.globl	main
main:   
        la      $a0, msg        # Pone en $a0 la dirección de la cadena
        li      $v0, 4          # Código syscall para imprimir una cadena
        syscall                 # Imprime la cadena «¡Hola mundo!»

	li      $v0, 11         # Código syscall para imprimir un carácter
        lbu     $a0, retcar     # Carga en $a0 el carácter a imprimir (retcar)
        syscall                 # Imprime el caracter

	lw      $t0, numeros    # Carga el primer entero (17)
	lw      $t1, numeros+4  # Carga el segundo entero (23)
	add     $t2, $t0, $t1   # Calcula el resultado de la suma
	sw      $t2, suma       # Almacena el resultado en memoria
        li      $v0, 1          # Código syscall para imprimir un entero
        move    $a0, $t0        # Pone en $a0 el entero a imprimir (17)
        syscall                 # Imprime el entero
        li      $v0, 11         # Código syscall para imprimir un carácter
        li      $a0, '+'        # Pone en $a0 el carácter a imprimir («+»)
        syscall                 # Imprime el caracter
        li      $v0, 1          # Código syscall para imprimir un entero	
        move    $a0, $t1        # Pone en $a0 el entero a imprimir (23)
	syscall
        li      $v0, 11         # Código syscall para imprimir un carácter
        li      $a0, '='        # Pone en $a0 el carácter a imprimir («=»)
        syscall                 # Imprime el caracter
        li      $v0, 1          # Código syscall para imprimir un entero	
        move    $a0, $t2        # Pone en $a0 el entero a imprimir (40)
	syscall

        li      $v0, 10         # Código syscall de exit
        syscall        
	jr	$ra 
