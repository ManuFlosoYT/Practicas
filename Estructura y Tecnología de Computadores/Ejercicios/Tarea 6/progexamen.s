
	.data	
	.align	2
jump_table000:
	.word	B6_1
	.word	B6_4
	.word	B6_6
	.word	B6_7
str000:
	.asciiz		"enero"
str001:
	.asciiz		"febrero"
str002:
	.asciiz		"marzo"
str003:
	.asciiz		"abril"
str004:
	.asciiz		"mayo"
str005:
	.asciiz		"junio"
str006:
	.asciiz		"julio"
str007:
	.asciiz		"agosto"
str008:
	.asciiz		"septiembre"
str009:
	.asciiz		"octubre"
str010:
	.asciiz		"noviembre"
str011:
	.asciiz		"diciembre"
	.align	2
meses:
	.word	str000
	.word	str001
	.word	str002
	.word	str003
	.word	str004
	.word	str005
	.word	str006
	.word	str007
	.word	str008
	.word	str009
	.word	str010
	.word	str011
	.align	2
viajesrealizados:
	.asciiz		"Pilar"
	.space	48
	.space	2
	.word	23
	.word	2024
	.word	5
	.word	10
	.word	2730
	.asciiz		"Gema"
	.space	49
	.space	2
	.word	28
	.word	2023
	.word	4
	.word	20
	.word	1130
	.asciiz		"Pilar"
	.space	48
	.space	2
	.word	8
	.word	2024
	.word	1
	.word	15
	.word	2130
	.asciiz		"Ricardo"
	.space	46
	.space	2
	.word	43
	.word	2023
	.word	12
	.word	7
	.word	5000
	.asciiz		"Juan"
	.space	49
	.space	2
	.word	16
	.word	2023
	.word	8
	.word	7
	.word	1840
	.asciiz		"Agustin"
	.word	35
	.word	2023
	.word	12
	.word	18
	.word	2410
	.asciiz		"Jesus"
	.word	15
	.word	2023
	.word	1
	.word	18
	.word	1400
	.space	7068
	.align	2
num_ventas:
	.word	7
	.align	2
viajes:
	.word	28
	.asciiz		"Tokio\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Japón\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	15
	.word	2000
	.word	2500
	.word	2300
	.word	1300
	.word	2130
	.word	2850
	.word	3300
	.word	3500
	.word	3100
	.word	2830
	.word	2550
	.word	3210
	.word	8
	.asciiz		"Kioto\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Japón\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	12
	.word	2200
	.word	1500
	.word	2100
	.word	1600
	.word	2730
	.word	2650
	.word	4300
	.word	4100
	.word	3400
	.word	1830
	.word	2450
	.word	3610
	.word	18
	.asciiz		"Sidney\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Australia\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	21
	.word	4200
	.word	3500
	.word	4100
	.word	5600
	.word	3730
	.word	3650
	.word	4300
	.word	5100
	.word	6400
	.word	5830
	.word	4450
	.word	6610
	.word	43
	.asciiz		"Melbourne\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Australia\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	28
	.word	4600
	.word	4550
	.word	5300
	.word	6600
	.word	4730
	.word	4750
	.word	6230
	.word	4140
	.word	5500
	.word	4730
	.word	5650
	.word	5710
	.word	23
	.asciiz		"Auckland\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Nueva Zelanda\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	19
	.word	2600
	.word	3550
	.word	3300
	.word	3600
	.word	2730
	.word	2750
	.word	3230
	.word	3140
	.word	2500
	.word	2730
	.word	2650
	.word	1710
	.word	35
	.asciiz		"Wellington\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Nueva Zelanda\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	19
	.word	3400
	.word	2350
	.word	2600
	.word	2900
	.word	2930
	.word	2950
	.word	2830
	.word	3440
	.word	3500
	.word	3730
	.word	3650
	.word	2410
	.word	15
	.asciiz		"Galway\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Irlanda\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	9
	.word	1400
	.word	1350
	.word	2600
	.word	2100
	.word	1130
	.word	2250
	.word	2230
	.word	2140
	.word	2500
	.word	3430
	.word	1650
	.word	2410
	.word	16
	.asciiz		"Cork\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.asciiz		"Irlanda\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	2
	.word	10
	.word	2500
	.word	1460
	.word	2700
	.word	1400
	.word	1310
	.word	1450
	.word	2730
	.word	3840
	.word	2450
	.word	2230
	.word	1400
	.word	2710
	.space	9568
	.align	2
num_viajes:
	.word	8
str012:
	.asciiz		" viajó a "
str013:
	.asciiz		" y pagó "
str014:
	.asciiz		" euros\n"
str015:
	.asciiz		"Viajar a "
str016:
	.asciiz		" dura "
str017:
	.asciiz		" días y cuesta:\n"
str018:
	.asciiz		" euros en el mes de "
str019:
	.asciiz		".\n"
str020:
	.asciiz		"\n"
str021:
	.asciiz		" es más barato en el mes de "
str022:
	.asciiz		" y cuesta "
str023:
	.asciiz		" euros.\n"
str024:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Listar viajes realizados\n 2. Viajes precio medio\n 3. Mostrar mes más barato por destino\n 0. Salir\n\nElige una opción: "
str025:
	.asciiz		"\n\n"
str026:
	.asciiz		"Listado de viajes realizados:\n"
str027:
	.asciiz		"Se han encontrado "
str028:
	.asciiz		" viajes con un precio entre 1000 y 2000 euros y una duración máxima de 18 días.\n\n"
str029:
	.asciiz		" viajes con un precio entre 2000 y 3000 euros y una duración máxima de 20 días.\n\n"
str030:
	.asciiz		" viajes con un precio entre 1000 y 1500 euros y una duración máxima de 12 días.\n"
str031:
	.asciiz		"¡Adiós!\n"
str032:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	

buscar_viaje_id:
	lw	$v1, num_viajes
	li	$v0, -1
	blez	$v1, B0_4
	la	$a2, viajes
	li	$a1, 0
B0_2:	lw	$t1, 0($a2)
	beq	$t1, $a0, B0_5
	addiu	$a1, $a1, 1
	addiu	$a2, $a2, 104
	bne	$v1, $a1, B0_2
B0_4:	jr	$ra
B0_5:	move	$v0, $a1
	jr	$ra

print_ciudad_destino_viaje:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	lw	$v1, num_viajes
	blez	$v1, B1_6
	la	$t1, viajes
	addiu	$v0, $t1, 4
B1_2:	lw	$t1, -4($v0)
	beq	$t1, $a0, B1_5
	addiu	$v1, $v1, -1
	addiu	$v0, $v0, 104
	bnez	$v1, B1_2
	j	B1_6
B1_5:	move	$a0, $v0
	jal	print_string
B1_6:	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra

print_nombre_mes:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	sll	$t1, $a0, 2
	la	$v0, meses
	addu	$t1, $v0, $t1
	lw	$a0, 0($t1)
	jal	print_string
	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra

# EJERCICIO 1.
# Lista los viajes realizados, indicando cliente, ciudad y precio del viaje.
listar_viajes_realizados:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)        	# Guardar $ra
	sw	$s0, 16($sp)        	# Guardar $s0
	sw	$s1, 12($sp)        	# Guardar $s1
	sw	$s2, 8($sp)         	# Guardar $s2

        	li     	$s0, 0              	# Inicializar i (contador del bucle) a 0
	la	$s1, viajesrealizados 	# Cargar dirección base de viajesrealizados en $s1
        	lw      	$s2, num_ventas     	# Cargar num_ventas en $s2

B3_2:	
	bge	$s0, $s2, B3_5    		# Bucle for(i=0; i < num_ventas; i++)
					# Calcular dirección de viajesrealizados[i]: $t0 = $s1 + $s0 * 76 (tamaño de struct ViajeRealizado)
        	li      	$t5, 76         
	mul	$t0, $s0, $t5
	addu	$t0, $s1, $t0     		# $t0 tiene la dirección de viajesrealizados[i]

        	lw      	$a0, 56($t0)      		# Cargar viajesrealizados[i].id_viaje en $a0
        	jal     	buscar_viaje_id   		# Llamar a buscar_viaje_id(viajesrealizados[i].id_viaje) -> Devuelve índice en $v0
	bltz	$v0, B3_3         		# if (indice_viaje < 0) saltar
	# Bloque if (indice_viaje >= 0)
	move	$a0, $t0          		# Cargar dirección de viajesrealizados[i].cliente en $a0
	jal	print_string      		# print_string(viajesrealizados[i].cliente);
	la	$a0, str012       		# Cargar dirección de " viajó a "
	jal	print_string
	lw	$a0, 56($t0)      		# Cargar viajesrealizados[i].id_viaje en $a0
	jal	print_ciudad_destino_viaje 	# print_ciudad_destino_viaje(viajesrealizados[i].id_viaje);
	la	$a0, str013       		# Cargar dirección de " y pagó "
	jal	print_string
	lw	$a0, 72($t0)      		# Cargar viajesrealizados[i].precio_viaje en $a0
	jal	print_integer     		# print_integer(viajesrealizados[i].precio_viaje);
	la	$a0, str014       		# Cargar dirección de " euros\n"
	jal	print_string

B3_3:   	addiu   	$s0, $s0, 1       	# i++
	j	B3_2              	# Saltar al inicio del bucle

B3_5:	lw	$s2, 8($sp)         # Restaurar $s2
        	lw      	$s1, 12($sp)        # Restaurar $s1
        	lw      	$s0, 16($sp)        # Restaurar $s0
	lw	$ra, 20($sp)        # Restaurar $ra
	addiu	$sp, $sp, 24      	# Liberar espacio en la pila
	jr	$ra


# EJERCICIO 2. TRADUCIR.
# Busca todos los viajes cuyo precio y duración se ajusten a los valores
# pasados como parámetros y devuelve el total de viajes encontrados.
# Para cada viaje, lista todos los meses que el precio se ajuste al min y max
# pasados como parámetros.
buscar_viaje_precio_dias:
	# Argumentos: $a0 = min, $a1 = max, $a2 = duracion_max
	# Retorno: $v0 = total_destinos
	# Registros salvados: $s0-$s7
	addiu	$sp, $sp, -40       # Reservar espacio para $ra, $s0-$s7
	sw	$ra, 36($sp)
	sw	$s0, 32($sp)        # s0 = i (contador bucle externo)
	sw	$s1, 28($sp)        # s1 = j (contador bucle interno)
	sw	$s2, 24($sp)        # s2 = total_destinos
	sw	$s3, 20($sp)        # s3 = dirección base de viajes
	sw	$s4, 16($sp)        # s4 = num_viajes
	sw	$s5, 12($sp)        # s5 = min (parámetro $a0)
	sw	$s6, 8($sp)         # s6 = max (parámetro $a1)
	sw	$s7, 4($sp)         # s7 = duracion_max (parámetro $a2)

        	move    	$s5, $a0            # Guardar min en $s5
        	move    	$s6, $a1            # Guardar max en $s6
        	move    	$s7, $a2            # Guardar duracion_max en $s7

	li	$s2, 0              # int total_destinos = 0;
	li	$s0, 0              # int i = 0;
	la	$s3, viajes         # Puntero al inicio del array viajes
        	lw      	$s4, num_viajes     # Cargar número total de viajes

B_BUC_EXT_COND:
	bge	$s0, $s4, B_BUC_EXT_FIN 	# for (i = 0; i < num_viajes; ++i)

        	# Calcular dirección de viajes[i]: $t0 = $s3 + $s0 * 104 (tamaño struct Viaje)
        	li      	$t5, 104            	# Tamaño de struct Viaje (4 id + 23 ciudad + 1 pad + 23 pais + 1 pad + 4 duracion + 12*4 precios = 104)
        	mul     	$t0, $s0, $t5
        	addu    	$t0, $s3, $t0       	# $t0 = dirección de viajes[i]

        	lw      	$t1, 52($t0)        	# Cargar viajes[i].duracion en $t1
	bgt	$t1, $s7, B_SKIP_VIAJE 	# if (viajes[i].duracion > duracion_max) saltar

        	# Bloque if (viajes[i].duracion <= duracion_max)
	la	$a0, str015         	# "Viajar a "
	jal	print_string
	addiu	$a0, $t0, 4       		# Dirección de viajes[i].ciudad_destino
	jal	print_string
	la	$a0, str016         	# " dura "
	jal	print_string
	move	$a0, $t1          		# viajes[i].duracion
	jal	print_integer
	la	$a0, str017         	# " días y cuesta:\n"
	jal	print_string

        	# Bucle interno: for (j = 0; j < 12; ++j)
	li	$s1, 0              	# int j = 0;

B_BUC_INT_COND:
	bge	$s1, 12, B_BUC_INT_FIN 	# Condición j < 12

        	# Calcular dirección de viajes[i].precio_mes[j]: $t2 = $t0 + 56 + $s1 * 4
        	sll     	$t2, $s1, 2         	# $t2 = j * 4
        	addiu   	$t2, $t2, 56        	# $t2 = 56 (offset de precio_mes) + j * 4
        	addu    	$t2, $t0, $t2       	# $t2 = dirección de viajes[i] + offset de precio_mes[j]
        	lw      	$t3, 0($t2)         	# Cargar viajes[i].precio_mes[j] en $t3

        	# if (min <= viajes[i].precio_mes[j] && max >= viajes[i].precio_mes[j])
        	blt     	$t3, $s5, B_SKIP_MES  	# if (precio < min) saltar
        	bgt     	$t3, $s6, B_SKIP_MES  	# if (precio > max) saltar

        	# Bloque if interno
	addiu	$s2, $s2, 1       		# total_destinos++;
	move	$a0, $t3          		# viajes[i].precio_mes[j]
	jal	print_integer
	la	$a0, str018         	# " euros en el mes de "
	jal	print_string
	move	$a0, $s1          		# j (índice del mes)
	jal	print_nombre_mes
	la	$a0, str019         	# ".\n"
	jal	print_string

B_SKIP_MES:
	addiu	$s1, $s1, 1       		# j++
	j	B_BUC_INT_COND

B_BUC_INT_FIN:
	la	$a0, str020         	# "\n"
	jal	print_string

B_SKIP_VIAJE:
	addiu	$s0, $s0, 1       		# i++
	j	B_BUC_EXT_COND

B_BUC_EXT_FIN:
	move	$v0, $s2            	# return total_destinos;

        	# Restaurar registros
	lw	$s7, 4($sp)
        	lw	$s6, 8($sp)
        	lw	$s5, 12($sp)
        	lw      	$s4, 16($sp)
        	lw      	$s3, 20($sp)
        	lw      	$s2, 24($sp)
        	lw      	$s1, 28($sp)
        	lw      	$s0, 32($sp)
	lw	$ra, 36($sp)
	addiu	$sp, $sp, 40       		# Liberar espacio en la pila
	jr	$ra

# EJERCICIO 3. IMPLEMENTAR.
# Para cada viaje, busca el mes más barato y lo imprime junto con el precio.
# El mes se puede imprimir haciendo uso de la función auxiliar imprimir_mes
# ya implementada.
mostrar_mes_mas_barato_por_destino:
        	# Argumentos: ninguno
        	# Retorno: ninguno
        	# Registros salvados: $s0-$s5
	addiu	$sp, $sp, -28       	# Reservar espacio para $ra, $s0-$s5 (6 regs * 4 bytes = 24) -> 28 para alinear
	sw	$ra, 24($sp)
	sw	$s0, 20($sp)        	# s0 = i (contador bucle externo - viajes)
	sw	$s1, 16($sp)        	# s1 = j (contador bucle interno - meses)
	sw	$s2, 12($sp)        	# s2 = puntero a viajes[i]
	sw	$s3, 8($sp)         	# s3 = índice del mes más barato actual (mes_barato_idx)
	sw	$s4, 4($sp)         	# s4 = precio más barato actual (precio_barato)
        	sw      	$s5, 0($sp)         	# s5 = num_viajes

	la	$t0, viajes         	# Dirección base de viajes
        	lw      	$s5, num_viajes     	# Cargar num_viajes
	li	$s0, 0              	# int i = 0;

B_EX3_EXT_COND:
	bge	$s0, $s5, B_EX3_EXT_FIN 	# for (i = 0; i < num_viajes; i++)

        	# Calcular dirección de viajes[i]: $s2 = $t0 + $s0 * 104
        	li      	$t5, 104            	# Tamaño de struct Viaje
        	mul     	$t1, $s0, $t5
        	addu    	$s2, $t0, $t1       	# $s2 = dirección de viajes[i]

        	# Inicializar búsqueda del mes más barato para este viaje
	li	$s3, 0              	# int mes_barato_idx = 0;
        	addiu   	$t2, $s2, 56        	# Dirección de viajes[i].precio_mes[0]
        	lw      	$s4, 0($t2)         	# int precio_barato = viajes[i].precio_mes[0];

        # Bucle interno para encontrar el mes más barato (empezar desde j=1)
	li	$s1, 1              	# int j = 1;

B_EX3_INT_COND:
	bge	$s1, 12, B_EX3_INT_FIN 	# for (j = 1; j < 12; j++)

        	# Calcular dirección de viajes[i].precio_mes[j]: $t3 = $s2 + 56 + $s1 * 4
        	sll     	$t3, $s1, 2         	# $t3 = j * 4
        	addiu   	$t3, $t3, 56        	# $t3 = 56 + j * 4
        	addu    	$t3, $s2, $t3       	# $t3 = dirección de viajes[i].precio_mes[j]
       	lw      	$t4, 0($t3)         	# Cargar precio_mes[j] en $t4

        	# if (precio_mes[j] < precio_barato)
        	bge     	$t4, $s4, B_EX3_SKIP 	# Saltar si precio_mes[j] >= precio_barato

        	# Actualizar mes y precio más baratos
        	move    	$s4, $t4            	# precio_barato = precio_mes[j];
        	move    	$s3, $s1            	# mes_barato_idx = j;

B_EX3_SKIP:
	addiu	$s1, $s1, 1       		# j++
	j	B_EX3_INT_COND

B_EX3_INT_FIN:
        	# Imprimir resultado para el viaje actual
	la	$a0, str015         	# "Viajar a "
	jal	print_string
	addiu	$a0, $s2, 4       		# Dirección de viajes[i].ciudad_destino
	jal	print_string
	la	$a0, str021         	# " es más barato en el mes de "
	jal	print_string
	move	$a0, $s3          		# mes_barato_idx
	jal	print_nombre_mes
	la	$a0, str022         	# " y cuesta "
	jal	print_string
	move	$a0, $s4          		# precio_barato
	jal	print_integer
	la	$a0, str023         	# " euros.\n"
	jal	print_string

	addiu	$s0, $s0, 1       		# i++
	j	B_EX3_EXT_COND

B_EX3_EXT_FIN:
        	# Restaurar registros
        	lw      	$s5, 0($sp)
        	lw      	$s4, 4($sp)
        	lw      	$s3, 8($sp)
        	lw      	$s2, 12($sp)
        	lw      	$s1, 16($sp)
        	lw      	$s0, 20($sp)
	lw	$ra, 24($sp)
	addiu	$sp, $sp, 28       		# Liberar espacio en la pila
	jr	$ra



	.globl	main
main:
	addiu	$sp, $sp, -64
	sw	$ra, 60($sp)
	sw	$fp, 56($sp)
	sw	$s7, 52($sp)
	sw	$s6, 48($sp)
	sw	$s5, 44($sp)
	sw	$s4, 40($sp)
	sw	$s3, 36($sp)
	sw	$s2, 32($sp)
	sw	$s1, 28($sp)
	sw	$s0, 24($sp)
	jal	clear_screen
	la	$s0, str024
	la	$s1, str025
	la	$t1, str032
	sw	$t1, 20($sp)
	la	$t1, str031
	sw	$t1, 16($sp)
	la	$s4, str026
	la	$s5, str027
	la	$s6, str028
	la	$s7, str029
	la	$fp, str030
	j	B6_2
B6_1:	lw	$a0, 16($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
B6_2:	move	$a0, $s0
	jal	print_string
	jal	read_character
	move	$s2, $v0
	move	$a0, $s1
	jal	print_string
	andi	$t1, $s2, 255
	addiu	$v0, $t1, -48
	sltiu	$t1, $v0, 4
	beqz	$t1, B6_5
	sll	$t1, $v0, 2
	lw	$t1, jump_table000($t1)
	jr	$t1
B6_4:	move	$a0, $s4
	jal	print_string
	jal	listar_viajes_realizados
	la	$a0, str025
	jal	print_string
	j	B6_2
B6_5:	lw	$a0, 20($sp)
	jal	print_string
	jal	read_character
	j	B6_2
B6_6:	li	$a0, 1000
	li	$a1, 2000
	li	$a2, 18
	jal	buscar_viaje_precio_dias
	move	$s2, $v0
	move	$a0, $s5
	jal	print_string
	move	$a0, $s2
	jal	print_integer
	move	$a0, $s6
	jal	print_string
	li	$a0, 2500
	li	$a1, 3000
	li	$a2, 20
	jal	buscar_viaje_precio_dias
	move	$s2, $v0
	move	$a0, $s5
	jal	print_string
	move	$a0, $s2
	jal	print_integer
	move	$a0, $s7
	jal	print_string
	li	$a0, 1000
	li	$a1, 1500
	li	$a2, 12
	jal	buscar_viaje_precio_dias
	move	$s2, $v0
	move	$a0, $s5
	jal	print_string
	move	$a0, $s2
	jal	print_integer
	move	$a0, $fp
	jal	print_string
	j	B6_2
B6_7:	jal	mostrar_mes_mas_barato_por_destino
	j	B6_2

print_integer:
	li	$v0, 1
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

