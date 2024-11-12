	.file	"locales.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"En otro terminal, ejecuta la siguiente orden:\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"pmap %d\n\n"
	.section	.rodata.str1.8
	.align 8
.LC2:
	.string	"En la informaci\303\263n mostrada por el comando pmap anterior, busca:"
	.align 8
.LC3:
	.string	" - El tama\303\261o en memoria destinado a la pila"
	.align 8
.LC4:
	.string	" - A qu\303\251 zonas de memoria corresponden las direcciones de 'magicNum' y 'inputNum'\n"
	.align 8
.LC5:
	.string	"Finalmente, pulsa INTRO para continuar este programa..."
	.text
	.globl	ayuda_pulsa_intro
	.type	ayuda_pulsa_intro, @function
ayuda_pulsa_intro:
	endbr64
	subq	$8, %rsp
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %edx
	leaq	.LC1(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	stdin(%rip), %rdi
	call	getc@PLT
	movq	stdin(%rip), %rdi
	call	getc@PLT
	addq	$8, %rsp
	ret
	.size	ayuda_pulsa_intro, .-ayuda_pulsa_intro
	.globl	doble_mult
	.type	doble_mult, @function
doble_mult:
	endbr64
	pushq	%rbx
	movl	%edi, %ebx
	call	ayuda_pulsa_intro
	leal	(%rbx,%rbx), %eax
	popq	%rbx
	ret
	.size	doble_mult, .-doble_mult
	.globl	doble_array
	.type	doble_array, @function
doble_array:
	endbr64
	pushq	%rbp
	pushq	%rbx
	leaq	-2097152(%rsp), %r11
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	subq	$24, %rsp
	movq	%fs:40, %rax
	movq	%rax, 2097160(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rbx
	leaq	2097152(%rsp), %rbp
	movq	%rbx, %rax
.L6:
	movl	%edi, (%rax)
	addq	$4, %rax
	cmpq	%rbp, %rax
	jne	.L6
	call	ayuda_pulsa_intro
	movl	$0, %eax
.L7:
	movl	(%rbx), %edx
	leal	(%rax,%rdx,2), %eax
	addq	$4, %rbx
	cmpq	%rbp, %rbx
	jne	.L7
	leal	524287(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$19, %eax
	movq	2097160(%rsp), %rdx
	subq	%fs:40, %rdx
	jne	.L12
	addq	$2097176, %rsp
	popq	%rbx
	popq	%rbp
	ret
.L12:
	call	__stack_chk_fail@PLT
	.size	doble_array, .-doble_array
	.section	.rodata.str1.1
.LC6:
	.string	"N\303\272mero m\303\241gico: %d\n"
	.section	.rodata.str1.8
	.align 8
.LC7:
	.string	"Direcci\303\263n de memoria de la variable 'magicNum' = %#lx\n"
	.align 8
.LC8:
	.string	"Direcci\303\263n de memoria de la variable 'inputNum' = %#lx\n"
	.section	.rodata.str1.1
.LC9:
	.string	"Introduce un n\303\272mero: "
.LC10:
	.string	"%d"
.LC11:
	.string	"Error al leer de teclado"
.LC12:
	.string	"El doble de %d es: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbx
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	magicNum(%rip), %edx
	leaq	.LC6(%rip), %rsi
	movl	$2, %edi
	call	__printf_chk@PLT
	leaq	magicNum(%rip), %rdx
	leaq	.LC7(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	leaq	4(%rsp), %rbx
	movq	%rbx, %rdx
	leaq	.LC8(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	leaq	.LC9(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	cmpl	$1, %eax
	jne	.L20
	movl	4(%rsp), %ebx
	cmpl	$1234, %ebx
	je	.L21
	call	ayuda_pulsa_intro
	leal	(%rbx,%rbx), %ecx
.L17:
	movl	4(%rsp), %edx
	leaq	.LC12(%rip), %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
.L13:
	movq	8(%rsp), %rdx
	subq	%fs:40, %rdx
	jne	.L22
	addq	$16, %rsp
	popq	%rbx
	ret
.L20:
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
	movl	$1, %eax
	jmp	.L13
.L21:
	movl	$1234, %edi
	call	doble_array
	movl	%eax, %ecx
	jmp	.L17
.L22:
	call	__stack_chk_fail@PLT
	.size	main, .-main
	.globl	magicNum
	.data
	.align 4
	.type	magicNum, @object
	.size	magicNum, 4
magicNum:
	.long	1234
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
