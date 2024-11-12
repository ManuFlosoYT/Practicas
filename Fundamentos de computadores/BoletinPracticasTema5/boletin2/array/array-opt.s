	.file	"array.c"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	movl	4+array(%rip), %eax
	addl	array(%rip), %eax
	addl	8+array(%rip), %eax
	addl	12+array(%rip), %eax
	addl	16+array(%rip), %eax
	ret
	.size	main, .-main
	.globl	array
	.data
	.align 16
	.type	array, @object
	.size	array, 20
array:
	.long	10
	.long	20
	.long	30
	.long	40
	.long	50
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
