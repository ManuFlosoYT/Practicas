        .data
msg1:   .asciiz "Introduce un número entre 1 y 99 (cualquier otro para salir):"
msg2:   .asciiz "El número "
msg3:   .asciiz " es par."
msg4:   .asciiz " es impar."
msg5:   .asciiz "Iteración: " 

        .text
	.globl	main
main:   
	#Gestionar pila
	addi 	$sp, $sp, -20
	sw	$s3, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s4, 16($sp)
	
        li      $s3, 0                  # Almacena los enteros que hemos pedido hasta ahora
        li      $s0, 1                  # Cota inferior para los enteros válidos
        li      $s1, 99                 # Cota superior para los enteros válidos	
otro:   beq     $s3, 10, fin            # Acabamos cuando se hayan introducido 10 enteros
        la      $a0, msg5               # Imprimos la iteración por la que vamos
        jal     print_string
        move    $a0, $s3
        jal     print_integer
        jal     print_cr
        move    $a0, $s0                
        move    $a1, $s1     
	jal     pide_entero_rango       # Se pide un número entero en el rango [$s0, $s1] 
        beqz    $v0, fin                # Si el número no es válido, se acaba.
        move    $s2, $v0                # Guardamos el valor del número leído
        move    $a0, $v0                
        jal     es_par                  # Comprobamos si el número es par
        move	$s4, $v0		#Guardamos el retorno
        la      $a0, msg2               
        jal     print_string            # Imprimimos: "El número "
        move    $a0, $s2
        jal     print_integer           # Imprimimos el número
        beqz    $s4, impar              # El número es impar
        la      $a0, msg3
        j       sigue
impar:  la      $a0, msg4
sigue:  jal     print_string
        jal     print_cr
        addi    $s3, $s3, 1
        j       otro        	
fin:    li      $v0, 10                 # Código syscall de exit
        syscall         
	jr      $ra
	
pide_entero_rango: # Obtiene un entero por teclado y devuelve 0 si <= 1er argumento o >= 2do argumento
                   # En otro caso, devuelve el entero leído.
                   
        #Guarda en pila los registros que habia antes
        addi 	$sp, $sp, -16
	sw	$s0, 0($sp)
	sw	$s1, 4($sp)
	sw	$s2, 8($sp)  
	sw	$ra, 12($sp)          
        
      	move	$s0, $a0
      	move	$s1, $a1
      	
	la      $a0, msg1       # Mensaje para pedir el entero
	jal     print_string    # Imprime el mensaje
	jal     read_integer    # Lee un entero
	
	move 	$s2, $v0	#Guardar el resultado de leer el entero
	
	jal     print_cr        # Imprime retorno de carro
	blt     $s2, $s0, per1  # Si el valor leído <= $s0, devuelve 0 
	bgt     $s2, $s1, per1  # Si el valor leído >= $s1, devuelve 0
	
	move	$v0, $s2	#Poner el valor en el registro de retorno
	
	j       per2            # En otro caso, devuelve el entero leído
per1:   move    $s2,$zero
per2:   
	#Saca de pila los registros que habia antes
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$ra, 12($sp)
	addi 	$sp, $sp, 16 
	jr      $ra

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

