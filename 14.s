	.file	"14.c"
	.globl	tsize
	.section	.rodata
	.align 4
	.type	tsize, @object
	.size	tsize, 4
tsize:
	.long	75000000
	.comm	t,300000000,32
.LC0:
	.string	"it took: %ld clocks\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %edi
	call	time
	movl	%eax, %edi
	call	srand
	movl	$0, -24(%rbp)
	jmp	.L2
.L3:
	call	rand
	movl	%eax, %edx
	movl	-24(%rbp), %eax
	cltq
	movl	%edx, t(,%rax,4)
	addl	$1, -24(%rbp)
.L2:
	cmpl	$74999999, -24(%rbp)
	jle	.L3
	movl	$0, -20(%rbp)
	call	clock
	movq	%rax, -8(%rbp)
	movl	$75000000, -16(%rbp)
	jmp	.L4
.L7:
	movl	-16(%rbp), %eax
	cltq
	movl	t(,%rax,4), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	andl	$1431655765, %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	andl	$-1431655766, %eax
	shrl	%eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	andl	$858993459, %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	andl	$-858993460, %eax
	shrl	$2, %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	andl	$252645135, %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	andl	$-252645136, %eax
	shrl	$4, %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	andl	$16711935, %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	andl	$-16711936, %eax
	shrl	$8, %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movzwl	%ax, %eax
	movl	-12(%rbp), %edx
	shrl	$16, %edx
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	jle	.L5
	movl	-20(%rbp), %eax
	addl	$1, %eax
	jmp	.L6
.L5:
	movl	-20(%rbp), %eax
.L6:
	movl	%eax, -20(%rbp)
.L4:
	subl	$1, -16(%rbp)
	cmpl	$0, -16(%rbp)
	jne	.L7
	call	clock
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
