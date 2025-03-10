main:                    # ($a0, $a1) = (argc, argv) 
    addiu $sp, $sp, -4
    sw    $ra, 0($sp)

    # prueba de imagen_init, imagen_clean e imagen_set_pixel
    la    $a0, pantalla
    li    $a1, 10
    li    $a2, 8
    li    $a3, 'x'
    jal   imagen_init        

    # prueba imagen_dibuja_imagen
    #la    $a0, pantalla
    #la    $a1, pieza_ese
    #li    $a2, 2
    #li    $a3, 3
    #jal   imagen_dibuja_imagen
            
    la     $a0, pantalla
    jal    imagen_print

    jal    mips_exit

    lw     $ra, 0($sp)
    addiu  $sp, $sp, 4
    jr     $ra
    
