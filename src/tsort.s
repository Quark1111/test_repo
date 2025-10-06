	.file	"tsort.c"
	.text
	.globl	quicksort
	.type	quicksort, @function
quicksort:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
.L7:
	addl	$1, -16(%rbp)
	jmp	.L2
.L3:
	addl	$1, -16(%rbp)
.L2:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jg	.L3
	subl	$1, -12(%rbp)
	jmp	.L4
.L5:
	subl	$1, -12(%rbp)
.L4:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L5
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jg	.L6
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	addl	$1, -16(%rbp)
	subl	$1, -12(%rbp)
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	leal	2(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
.L6:
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jle	.L7
	movl	-28(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	.L8
	movq	-40(%rbp), %rcx
	movl	-12(%rbp), %edx
	movl	-28(%rbp), %esi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	quicksort
.L8:
	movl	-16(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.L10
	movq	-40(%rbp), %rcx
	movl	-32(%rbp), %edx
	movl	-16(%rbp), %esi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	quicksort
.L10:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	quicksort, .-quicksort
	.globl	g
	.type	g, @function
g:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	%rdx, -24(%rbp)
	movl	-12(%rbp), %eax
	leal	-1(%rax), %esi
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rcx
	movl	%esi, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	quicksort
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	g, .-g
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	" "
.LC2:
	.string	"%d %s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$432, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -428(%rbp)
	leaq	-432(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -424(%rbp)
	jmp	.L13
.L14:
	leaq	-416(%rbp), %rax
	movl	-424(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	addl	$1, -424(%rbp)
.L13:
	movl	-432(%rbp), %eax
	cmpl	%eax, -424(%rbp)
	jl	.L14
	movl	-432(%rbp), %ecx
	leaq	-428(%rbp), %rdx
	leaq	-416(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	g
	movl	$0, -420(%rbp)
	jmp	.L15
.L16:
	movl	-420(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	leaq	.LC1(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -420(%rbp)
.L15:
	movl	-432(%rbp), %eax
	cmpl	%eax, -420(%rbp)
	jl	.L16
	movl	$10, %edi
	call	putchar@PLT
	movl	-428(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-428(%rbp), %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L18
	call	__stack_chk_fail@PLT
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
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
