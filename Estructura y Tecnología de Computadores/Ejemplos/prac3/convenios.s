        .data
msg1:   .asciiz "Introduce un número entre 1 y 99 (cualquier otro para salir):"
msg2:   .asciiz "El número "
msg3:   .asciiz " es par."
msg4:   .asciiz " es impar."
msg5:   .asciiz "Iteración: " 

        .text
	.globl	main
main:   
        li      $at, 0                  # Almacena los enteros que hemos pedido hasta ahora
        li      $t0, 1                  # Cota inferior para los enteros válidos
        li      $t1, 99                 # Cota superior para los enteros válidos	
otro:   beq     $at, 10, fin            # Acabamos cuando se hayan introducido 10 enteros
        la      $a0, msg5               # Imprimos la iteración por la que vamos
        jal     print_string
        move    $a0, $at
        jal     print_integer
        jal     print_cr
        move    $a0, $t0                
        move    $a1, $t1     
	jal     pide_entero_rango       # Se pide un número entero en el rango [$t0, $t1] 
        beqz    $v0, fin                # Si el número no es válido, se acaba.
        move    $t2, $v0                # Guardamos el valor del número leído
        move    $a0, $v0                
        jal     es_par                  # Comprobamos si el número es par
        la      $a0, msg2               
        jal     print_string            # Imprimimos: "El número "
        move    $a0, $t2
        jal     print_integer           # Imprimimos el número
        beqz    $v0, impar              # El número es impar
        la      $a0, msg3
        j       sigue
impar:  la      $a0, msg4
sigue:  jal     print_string
        jal     print_cr
        addi    $at, $at, 1
        j       otro        	
fin:    li      $v0, 10                 # Código syscall de exit
        syscall         
	jr      $ra
	
pide_entero_rango: # Obtiene un entero por teclado y devuelve 0 si <= 1er argumento o >= 2do argumento
                                # En otro caso, devuelve el entero leído.
	la      $a0, msg1       # Mensaje para pedir el entero
	jal     print_string    # Imprime el mensaje
	jal     read_integer    # Lee un entero
	jal     print_cr        # Imprime retorno de carro
	blt     $v0, $a0, per1  # Si el valor leído <= $a0, devuelve 0 
	bgt     $v0, $a1, per1  # Si el valor leído >= $a1, devuelve 0
	j       per2            # En otro caso, devuelve el entero leído
per1:   move    $v0,$zero
per2:   jr      $ra

es_par: # Recibe un número y devuelve 0 si impar y 1 si par
	not     $v0, $a0        # Negamos para que el bit menos significativo quede con el resultado buscado
	andi    $v0, $v0, 0x01  # Nos quedamos con el bit menos significativo 
	jr      $ra
		
print_integer: # Recibe un entero y lo imprime por consola
	li      $v0, 1          # Código de la llamada al sistema de imprimir entero
	syscall
	jr      $ra
					
print_string: # Recibe una cadena asciiz y la imprime por consola
	li      $v0, 4          # Código de la llamada al sistema de imprimir cadena
	syscall
	jr      $ra
	
print_cr: # Imprime un retorno de carro
	li      $a0, '\n'       # Cargamos el código ascii del retorno de carro
	li      $v0, 11         # Imprimimos el retorno de carro
	syscall                 # Llamada al sistema
	jr      $ra		
	
read_integer: # Devuelve un número entero leído por teclado
	li      $v0, 5          # Código de la llamada al sistema de leer entero
	syscall
	jr      $ra

