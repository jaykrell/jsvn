	.section .text

.globl _GetDS
_GetDS:
    xor %eax,%eax
	movw %ds,%ax
	ret

.globl _GetContext
_GetContext:
    movl 4(%esp),%eax
    movl %ebx,4(%eax)
    movl (%esp),%ebx
    movl %ebx,(%eax)
    movl %ecx,8(%eax)
    movl %edx,12(%eax)
    movl %ebp,16(%eax)
    movl %edi,20(%eax)
    movl %esi,24(%eax)
    movl %esp,28(%eax)
    movw %fs,32(%eax)
    xorl %eax,%eax
    ret

.globl _SetContext
_SetContext:
    movl 4(%esp),%eax
    movl 28(%eax),%esp
    movl (%eax),%ebx
    movl %ebx,(%esp)
    movl 4(%eax),%ebx
    movl 8(%eax),%ecx
    movl 12(%eax),%edx
    movl 16(%eax),%ebp
    movl 20(%eax),%edi
    movl 24(%eax),%esi
    movw 32(%eax),%fs
    xorl %eax,%eax
    incl %eax
    ret
