
.section .text

.globl main
main:

mov    $10, %rax
mov    $2, %rdx
cmp   %rdx, %rax
jle lessthan
mov $0, %eax
lessthan:
mov $1, %eax

