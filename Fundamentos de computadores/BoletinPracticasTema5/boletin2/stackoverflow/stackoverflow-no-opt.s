	.file	"stackoverflow.c"
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
	.section	.rodata
.LC0:
	.string	"ping: parametro=%d\n\n"
	.align 8
.LC1:
	.string	"En el otro terminal, observa el tama\303\261o de la pila con pmap en este punto.\n"
.LC2:
	.string	"Pulsa INTRO para continuar..."
	.text
	.globl	ping
	.type	ping, @function
ping:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edx
	movslq	%edx, %rax
	imulq	$351843721, %rax, %rax
	shrq	$32, %rax
	sarl	$12, %eax
	movl	%edx, %ecx
	sarl	$31, %ecx
	subl	%ecx, %eax
	imull	$50000, %eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	testl	%eax, %eax
	jne	.L4
	movl	$10, %edi
	call	putchar@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getchar@PLT
.L4:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edi
	call	pong
	leave
	ret
	.size	ping, .-ping
	.section	.rodata
	.align 8
.LC3:
	.string	"### Ejemplo de desbordamiento de pila ###"
	.align 8
.LC4:
	.string	"Este programa contiene en dos procedimientos (ping, pong) que se llaman mutuamente de forma recursiva sin que haya condici\303\263n de parada."
	.align 8
.LC5:
	.string	"ping(0)->pong(1)->ping(2)->pong(3)....\n"
	.align 8
.LC6:
	.string	"El programa se detendr\303\241 cada %d llamadas recursivas para poder visualizar el estado de la pila\n"
	.align 8
.LC7:
	.string	"En otro terminal, ejecuta la siguiente orden en cada pausa del programa:\n"
.LC8:
	.string	"pmap %d\n\n"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$50000, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
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
