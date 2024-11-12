	.file	"stackoverflowsimple.c"
	.text
	.globl	ping
	.type	ping, @function
ping:
	endbr64
	subq	$8, %rsp
	addl	$1, %edi
	call	pong
	addq	$8, %rsp
	ret
	.size	ping, .-ping
	.globl	pong
	.type	pong, @function
pong:
	endbr64
	subq	$8, %rsp
	addl	$1, %edi
	call	ping
	addq	$8, %rsp
	ret
	.size	pong, .-pong
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"### Ejemplo de desbordamiento de pila ###"
	.align 8
.LC1:
	.string	"Este programa contiene en dos procedimientos (ping, pong) que se llaman mutuamente de forma recursiva sin que haya condici\303\263n de parada."
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	subq	$8, %rsp
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	addq	$8, %rsp
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
