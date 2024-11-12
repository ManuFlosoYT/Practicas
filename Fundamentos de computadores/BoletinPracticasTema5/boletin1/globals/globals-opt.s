	.file	"globals.c"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	leaq	array(%rip), %rax
	leaq	40(%rax), %rdx
.L2:
	movl	$-1, (%rax)
	addq	$4, %rax
	cmpq	%rdx, %rax
	jne	.L2
	movl	$0, %eax
	ret
	.size	main, .-main
	.globl	array
	.data
	.align 32
	.type	array, @object
	.size	array, 40
array:
	.long	10
	.long	9
	.long	8
	.long	7
	.long	6
	.long	5
	.long	4
	.long	3
	.long	2
	.long	1
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
