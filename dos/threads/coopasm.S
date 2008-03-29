	.section .text

.globl _GetDS
_GetDS:
    xor %eax,%eax
	movw %ds,%ax
	ret

.globl _GetCurrentThread
_GetCurrentThread:
    xor %fs:0x18,%eax
	ret

.globl _GetContext
_GetContext:
    movl 4(%esp),%eax
    movl %ebx,(%eax)
    movl %esi,4(%eax)
    movl %edi,8(%eax)
    movl %ebp,12(%eax)
    movl %esp,16(%eax)
    movw %fs,20(%eax)
    xorl %eax,%eax
    ret

.globl _SetContext
_SetContext:
    movl 4(%esp),%eax
    movl (%eax),%ebx
    movl 4(%eax),%esi
    movl 8(%eax),%edi
    movl 12(%eax),%ebp
    movl 16(%eax),%esp
    movw 20(%eax),%fs
    xorl %eax,%eax
    incl %eax
    ret
