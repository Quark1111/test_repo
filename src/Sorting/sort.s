	.file	"sort.c"
# GNU C17 (Ubuntu 13.3.0-6ubuntu2~24.04) version 13.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 13.3.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.globl	sorting
	.type	sorting, @function
sorting:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)	# arr, arr
	movl	%esi, -28(%rbp)	# len, len
# sort.c:4:     for (int i = 0; i < len; i++) {
	movl	$0, -12(%rbp)	#, i
# sort.c:4:     for (int i = 0; i < len; i++) {
	jmp	.L2	#
.L6:
# sort.c:5:         for (int j = i + 1; j < len; j++) {
	movl	-12(%rbp), %eax	# i, tmp106
	addl	$1, %eax	#, tmp105
	movl	%eax, -8(%rbp)	# tmp105, j
# sort.c:5:         for (int j = i + 1; j < len; j++) {
	jmp	.L3	#
.L5:
# sort.c:6:             if (arr[i] > arr[j]) {
	movl	-12(%rbp), %eax	# i, tmp107
	cltq
	leaq	0(,%rax,4), %rdx	#, _2
	movq	-24(%rbp), %rax	# arr, tmp108
	addq	%rdx, %rax	# _2, _3
	movl	(%rax), %edx	# *_3, _4
# sort.c:6:             if (arr[i] > arr[j]) {
	movl	-8(%rbp), %eax	# j, tmp109
	cltq
	leaq	0(,%rax,4), %rcx	#, _6
	movq	-24(%rbp), %rax	# arr, tmp110
	addq	%rcx, %rax	# _6, _7
	movl	(%rax), %eax	# *_7, _8
# sort.c:6:             if (arr[i] > arr[j]) {
	cmpl	%eax, %edx	# _8, _4
	jle	.L4	#,
# sort.c:7: 		int tmp = arr[j];
	movl	-8(%rbp), %eax	# j, tmp111
	cltq
	leaq	0(,%rax,4), %rdx	#, _10
	movq	-24(%rbp), %rax	# arr, tmp112
	addq	%rdx, %rax	# _10, _11
# sort.c:7: 		int tmp = arr[j];
	movl	(%rax), %eax	# *_11, tmp113
	movl	%eax, -4(%rbp)	# tmp113, tmp
# sort.c:8: 		arr[j] = arr[i];
	movl	-12(%rbp), %eax	# i, tmp114
	cltq
	leaq	0(,%rax,4), %rdx	#, _13
	movq	-24(%rbp), %rax	# arr, tmp115
	addq	%rdx, %rax	# _13, _14
# sort.c:8: 		arr[j] = arr[i];
	movl	-8(%rbp), %edx	# j, tmp116
	movslq	%edx, %rdx	# tmp116, _15
	leaq	0(,%rdx,4), %rcx	#, _16
	movq	-24(%rbp), %rdx	# arr, tmp117
	addq	%rcx, %rdx	# _16, _17
# sort.c:8: 		arr[j] = arr[i];
	movl	(%rax), %eax	# *_14, _18
# sort.c:8: 		arr[j] = arr[i];
	movl	%eax, (%rdx)	# _18, *_17
# sort.c:9: 		arr[i] = tmp;
	movl	-12(%rbp), %eax	# i, tmp118
	cltq
	leaq	0(,%rax,4), %rdx	#, _20
	movq	-24(%rbp), %rax	# arr, tmp119
	addq	%rax, %rdx	# tmp119, _21
# sort.c:9: 		arr[i] = tmp;
	movl	-4(%rbp), %eax	# tmp, tmp120
	movl	%eax, (%rdx)	# tmp120, *_21
.L4:
# sort.c:5:         for (int j = i + 1; j < len; j++) {
	addl	$1, -8(%rbp)	#, j
.L3:
# sort.c:5:         for (int j = i + 1; j < len; j++) {
	movl	-8(%rbp), %eax	# j, tmp121
	cmpl	-28(%rbp), %eax	# len, tmp121
	jl	.L5	#,
# sort.c:4:     for (int i = 0; i < len; i++) {
	addl	$1, -12(%rbp)	#, i
.L2:
# sort.c:4:     for (int i = 0; i < len; i++) {
	movl	-12(%rbp), %eax	# i, tmp122
	cmpl	-28(%rbp), %eax	# len, tmp122
	jl	.L6	#,
# sort.c:13: }
	nop	
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	sorting, .-sorting
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
