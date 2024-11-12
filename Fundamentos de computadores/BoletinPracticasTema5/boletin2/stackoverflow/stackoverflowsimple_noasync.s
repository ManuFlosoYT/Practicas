	.file	"stackoverflowsimple.c"
	.text
	.globl	pong
	.type	pong, @function
pong:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edi
	call	ping
	leave
	ret
	.size	pong, .-pong
	.globl	ping
	.type	ping, @function
ping:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edi
	call	pong
	leave
	ret
	.size	ping, .-ping
	.section	.rodata
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
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %edi
	call	ping
	movl	$0, %eax
	popq	%rbp
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
