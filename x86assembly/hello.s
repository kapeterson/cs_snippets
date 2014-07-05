/ compile with gcc <asm file> -o name
.data
.globl hello
hello:
.string "Hi World\n"

string2:
.string "This is the biz\n"

.text
.global main
main:
    pushq   %rbp
    movq    %rsp,       %rbp
    movq    $hello,     %rdi
    call    puts
    movq    $string2,   %rdi
    call    puts
    movq    $0,         %rax
    leave
    ret
