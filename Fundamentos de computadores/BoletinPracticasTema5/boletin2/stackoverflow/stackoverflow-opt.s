	.file	"stackoverflow.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"ping: parametro=%d\n\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"En el otro terminal, observa el tama\303\261o de la pila con pmap en este punto.\n"
	.section	.rodata.str1.1
.LC2:
	.string	"Pulsa INTRO para continuar..."
	.text
	.globl	ping
	.type	ping, @function
ping:
	endbr64
	pushq	%rbx
	movl	%edi, %ebx
	movslq	%edi, %rax
	imulq	$351843721, %rax, %rax
	sarq	$44, %rax
	movl	%edi, %edx
	sarl	$31, %edx
	subl	%edx, %eax
	imull	$50000, %eax, %eax
	cmpl	%eax, %edi
	je	.L4
.L2:
	leal	1(%rbx), %edi
	call	pong
	popq	%rbx
	ret
.L4:
	movl	$10, %edi
	call	putchar@PLT
	movl	%ebx, %edx
	leaq	.LC0(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	stdin(%rip), %rdi
	call	getc@PLT
	jmp	.L2
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
	.section	.rodata.str1.8
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
	.section	.rodata.str1.1
.LC8:
	.string	"pmap %d\n\n"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	subq	$8, %rsp
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	movl	$50000, %edx
	leaq	.LC6(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %edx
	leaq	.LC8(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %edi
	call	ping
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
