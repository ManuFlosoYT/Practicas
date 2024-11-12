	.file	"locales.c"
	.text
	.globl	magicNum
	.data
	.align 4
	.type	magicNum, @object
	.size	magicNum, 4
magicNum:
	.long	1234
	.section	.rodata
	.align 8
.LC0:
	.string	"En otro terminal, ejecuta la siguiente orden:\n"
.LC1:
	.string	"pmap %d\n\n"
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
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getchar@PLT
	call	getchar@PLT
	nop
	popq	%rbp
	ret
	.size	ayuda_pulsa_intro, .-ayuda_pulsa_intro
	.globl	doble_mult
	.type	doble_mult, @function
doble_mult:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	call	ayuda_pulsa_intro
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	leave
	ret
	.size	doble_mult, .-doble_mult
	.globl	doble_array
	.type	doble_array, @function
doble_array:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	leaq	-2097152(%rsp), %r11
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	subq	$48, %rsp
	movl	%edi, -2097188(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -2097176(%rbp)
	movl	$0, -2097180(%rbp)
	jmp	.L5
.L6:
	movl	-2097180(%rbp), %eax
	cltq
	movl	-2097188(%rbp), %edx
	movl	%edx, -2097168(%rbp,%rax,4)
	addl	$1, -2097180(%rbp)
.L5:
	cmpl	$524287, -2097180(%rbp)
	jle	.L6
	call	ayuda_pulsa_intro
	movl	$0, -2097180(%rbp)
	jmp	.L7
.L8:
	movl	-2097180(%rbp), %eax
	cltq
	movl	-2097168(%rbp,%rax,4), %eax
	addl	%eax, %eax
	addl	%eax, -2097176(%rbp)
	addl	$1, -2097180(%rbp)
.L7:
	cmpl	$524287, -2097180(%rbp)
	jle	.L8
	movl	-2097176(%rbp), %eax
	leal	524287(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$19, %eax
	movl	%eax, -2097172(%rbp)
	movl	-2097172(%rbp), %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	ret
	.size	doble_array, .-doble_array
	.section	.rodata
.LC6:
	.string	"N\303\272mero m\303\241gico: %d\n"
	.align 8
.LC7:
	.string	"Direcci\303\263n de memoria de la variable 'magicNum' = %#lx\n"
	.align 8
.LC8:
	.string	"Direcci\303\263n de memoria de la variable 'inputNum' = %#lx\n"
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
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	magicNum(%rip), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	magicNum(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	je	.L12
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %eax
	jmp	.L16
.L12:
	movl	-20(%rbp), %eax
	cmpl	$1234, %eax
	jne	.L14
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	doble_array
	movl	%eax, -16(%rbp)
	jmp	.L15
.L14:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	doble_mult
	movl	%eax, -16(%rbp)
.L15:
	movl	-20(%rbp), %eax
	movl	-16(%rbp), %edx
	movl	%eax, %esi
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
.L16:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	leave
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
