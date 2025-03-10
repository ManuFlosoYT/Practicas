main:                    # ($a0, $a1) = (argc, argv) 
    addiu $sp, $sp, -4
    sw    $ra, 0($sp)

    la     $a0, pieza_ele
    jal    imagen_print

    la     $a0, pieza_ele
    li     $a1, 1    
    li     $a2, 2    
    li     $a3, 'W'
    jal    imagen_set_pixel
        
    la     $a0, pieza_ele
    jal    imagen_print

    jal    mips_exit

    lw     $ra, 0($sp)
    addiu  $sp, $sp, 4
    jr     $ra
    
