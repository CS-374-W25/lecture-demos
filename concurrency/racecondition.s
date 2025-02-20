	.file	"racecondition.c"
	.text
.Ltext0:
	.globl	perform_work
	.type	perform_work, @function
perform_work:
.LFB2:
	.file 1 "racecondition.c"
	.loc 1 10 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	.loc 1 11 0
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	.loc 1 13 0
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	.loc 1 14 0
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	8(%rdx), %rdx
	movsd	(%rdx), %xmm2
	cvtsi2sd	-12(%rbp), %xmm0
	movsd	.LC0(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	cvtsi2sd	-12(%rbp), %xmm0
	mulsd	%xmm0, %xmm1
	cvtsi2sd	-12(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	addsd	%xmm2, %xmm0
	movsd	%xmm0, (%rax)
	.loc 1 16 0
	movl	$0, %eax
	.loc 1 17 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	perform_work, .-perform_work
	.section	.rodata
	.align 8
.LC2:
	.string	"The sum of sphere volumes is: %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.loc 1 19 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$2432, %rsp
	.loc 1 20 0
	movl	$0, %eax
	movq	%rax, -16(%rbp)
	.loc 1 25 0
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	.loc 1 26 0 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	leaq	-2416(%rax), %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	.loc 1 27 0 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	leaq	-2408(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rax, (%rdx)
	.loc 1 28 0 discriminator 2
	leaq	-2416(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	leaq	-816(%rbp), %rax
	movl	-4(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rax
	movq	%rdx, %rcx
	movl	$perform_work, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create
	.loc 1 25 0 discriminator 2
	addl	$1, -4(%rbp)
.L4:
	.loc 1 25 0 is_stmt 0 discriminator 1
	cmpl	$99, -4(%rbp)
	jle	.L5
	.loc 1 32 0 is_stmt 1
	movl	$0, -4(%rbp)
	jmp	.L6
.L7:
	.loc 1 33 0 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	movq	-816(%rbp,%rax,8), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join
	.loc 1 32 0 discriminator 2
	addl	$1, -4(%rbp)
.L6:
	.loc 1 32 0 is_stmt 0 discriminator 1
	cmpl	$99, -4(%rbp)
	jle	.L7
	.loc 1 36 0 is_stmt 1
	movq	-16(%rbp), %rax
	movq	%rax, -2424(%rbp)
	movsd	-2424(%rbp), %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	.loc 1 37 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	4256301137
	.long	1074839889
	.text
.Letext0:
	.file 2 "/usr/include/bits/pthreadtypes.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x183
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF16
	.byte	0x1
	.long	.LASF17
	.long	.LASF18
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x4
	.byte	0x8
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x5
	.long	.LASF19
	.byte	0x2
	.byte	0x3c
	.long	0x2d
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF9
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF10
	.uleb128 0x6
	.long	.LASF20
	.byte	0x10
	.byte	0x1
	.byte	0x5
	.long	0xb3
	.uleb128 0x7
	.long	.LASF11
	.byte	0x1
	.byte	0x6
	.long	0x57
	.byte	0
	.uleb128 0x8
	.string	"sum"
	.byte	0x1
	.byte	0x7
	.long	0xb3
	.byte	0x8
	.byte	0
	.uleb128 0x9
	.byte	0x8
	.long	0xb9
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.long	.LASF12
	.uleb128 0xa
	.long	.LASF21
	.byte	0x1
	.byte	0xa
	.long	0x6c
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x10a
	.uleb128 0xb
	.string	"arg"
	.byte	0x1
	.byte	0xa
	.long	0x6c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.long	.LASF13
	.byte	0x1
	.byte	0xb
	.long	0x10a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xd
	.string	"r"
	.byte	0x1
	.byte	0xd
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x9
	.byte	0x8
	.long	0x8e
	.uleb128 0xe
	.long	.LASF22
	.byte	0x1
	.byte	0x13
	.long	0x57
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x16a
	.uleb128 0xd
	.string	"sum"
	.byte	0x1
	.byte	0x14
	.long	0xb9
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.long	.LASF14
	.byte	0x1
	.byte	0x15
	.long	0x16a
	.uleb128 0x3
	.byte	0x91
	.sleb128 -832
	.uleb128 0xc
	.long	.LASF15
	.byte	0x1
	.byte	0x16
	.long	0x17a
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2432
	.uleb128 0xd
	.string	"i"
	.byte	0x1
	.byte	0x18
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xf
	.long	0x75
	.long	0x17a
	.uleb128 0x10
	.long	0x65
	.byte	0x63
	.byte	0
	.uleb128 0x11
	.long	0x8e
	.uleb128 0x10
	.long	0x65
	.byte	0x63
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF10:
	.string	"long long int"
.LASF3:
	.string	"unsigned int"
.LASF21:
	.string	"perform_work"
.LASF22:
	.string	"main"
.LASF17:
	.string	"racecondition.c"
.LASF0:
	.string	"long unsigned int"
.LASF14:
	.string	"worker_threads"
.LASF9:
	.string	"long long unsigned int"
.LASF11:
	.string	"thread_idx"
.LASF15:
	.string	"thread_args"
.LASF1:
	.string	"unsigned char"
.LASF8:
	.string	"char"
.LASF6:
	.string	"long int"
.LASF13:
	.string	"casted_arg"
.LASF18:
	.string	"/nfs/stak/users/guyera/instructor/w25/cs374/lecture-demos/concurrency"
.LASF12:
	.string	"double"
.LASF2:
	.string	"short unsigned int"
.LASF4:
	.string	"signed char"
.LASF20:
	.string	"worker_thread_arg"
.LASF19:
	.string	"pthread_t"
.LASF5:
	.string	"short int"
.LASF7:
	.string	"sizetype"
.LASF16:
	.string	"GNU C 4.8.5 20150623 (Red Hat 4.8.5-44) -mtune=generic -march=x86-64 -g"
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
