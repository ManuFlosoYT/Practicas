	.file	"funcion.c"
	.text
	.globl	funcion_resta
	.type	funcion_resta, @function
funcion_resta:
	endbr64
	movl	%edi, %eax
	subl	%esi, %eax
	ret
	.size	funcion_resta, .-funcion_resta
	.globl	main
	.type	main, @function
main:
	endbr64
	movl	$121, %eax
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
