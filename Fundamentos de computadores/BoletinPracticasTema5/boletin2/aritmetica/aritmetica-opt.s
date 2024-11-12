	.file	"aritmetica.c"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	movl	myVar(%rip), %eax
	leal	39(,%rax,8), %eax
	movl	%eax, myVar(%rip)
	ret
	.size	main, .-main
	.globl	myVar
	.data
	.align 4
	.type	myVar, @object
	.size	myVar, 4
myVar:
	.long	3
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
