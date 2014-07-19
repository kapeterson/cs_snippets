# The helloWorld.s file contains the source for a linux-x86_64 hello world
# example using the new 64 bit system call ABI.
# 2014 John Wassilak
#
# Compile with :
#     as -o helloWorld.o helloWorld.s
#     ld -e main -o helloWorld -s -Os helloWorld.o
.section .rodata                       # The rodata section contains the
                                       #     constants used by the program.
string: .ascii "Hello, world!\n"       # The string constant contains the
                                       #     string to be printed.
length: .quad . - string               # The length constant contains the
                                       #     length of the string constant.
.section .text                         # The text section contains the
                                       #     executable instructions of the
                                       #     program.
.globl main                            # Declare the main symbol as global so
                                       #     that the linker can see it.
main:                                  # The main symbol is the entry point of
                                       #     the program.
mov   $1, %rax                         # Move 1(sys_write) into rax.
mov   $1, %rdi                         # Move 1(fd stdOut) into rdi.
mov   $string, %rsi                    # Move the location of the string
                                       #     constant into rsi.
mov   length, %rdx                     # Move the length of the string
                                       #     constant into rdx.
syscall                                # Print the string constant to stdOut by
                                       #     making a system call.
                                       #     written = sys_write(
                                       #         stdOut, string, length
                                       #     )
mov   %rax, %rdi                       # Move the number of bytes written to
                                       #     rdi.
mov   $60, %rax                        # Move 60(sys_exit) into rax.
syscall                                # Terminate the process, returning the
                                       #     number of bytes written by
                                       #     sys_write as the exit status.
                                       #     sys_exit(written)
