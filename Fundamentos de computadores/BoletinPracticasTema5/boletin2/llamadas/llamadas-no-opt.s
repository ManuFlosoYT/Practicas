	.file	"llamadas.c"
	.text
	.globl	funcion0
	.type	funcion0, @function
funcion0:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	popq	%rbp
	ret
	.size	funcion0, .-funcion0
	.globl	funcion1
	.type	funcion1, @function
funcion1:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	funcion0
	addl	$1, %eax
	popq	%rbp
	ret
	.size	funcion1, .-funcion1
	.globl	funcion2
	.type	funcion2, @function
funcion2:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	funcion1
	addl	$2, %eax
	popq	%rbp
	ret
	.size	funcion2, .-funcion2
	.globl	funcion3
	.type	funcion3, @function
funcion3:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	funcion2
	addl	$3, %eax
	popq	%rbp
	ret
	.size	funcion3, .-funcion3
	.globl	funcion4
	.type	funcion4, @function
funcion4:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	funcion3
	addl	$4, %eax
	popq	%rbp
	ret
	.size	funcion4, .-funcion4
	.globl	funcion5
	.type	funcion5, @function
funcion5:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	funcion4
	addl	$5, %eax
	popq	%rbp
	ret
	.size	funcion5, .-funcion5
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$0, %eax
	call	funcion5
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
