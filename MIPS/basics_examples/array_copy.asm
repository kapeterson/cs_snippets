.text

la $s0, arr
addi $sp, $sp,  -16

add $s1, $sp, $0  # destinationARray
li $a2, 4    # size
move $s2, $a2  # store the size

move $a0, $s0 # set arg0 to call
move $a1, $s1 # set arg0 to call

jal copyArray

# set paraements for printArray()
move $a0, $s1  # array 
move $a1, $s2  # size

jal printArray
j bye

copyArray:
addu $t3, $a0, $0  # store sarray pointer
addu $t4, $a1, $0  # store darray pointer
li $t0, 0    # i = 0

CopyLoop:
beq $t0, $a2, exitCopy  # exit if i = size
lw $t1, 0($a0)  # move nth index of array 1 to temp
sw $t1, 0($a1)  # load into the destination array
addi $a0, $a0, 4
addi $a1, $a1, 4
addi $t0, $t0, 1 # i++
j CopyLoop

exitCopy:
jr $ra


printArray:
add $t0, $a0, 0
li $t1, 0   # i = 0

printLoop:
beq $t1, $a1, exitPrint
lw $a0, 0($t0)  # load the array value in
li $v0, 1       # prepare the print instruction
syscall    # print the number
li $v0, 4   # load the printstring instruction
la $a0, nl  # load newline string
syscall     # call the printstring instruction
addi $t1, $t1, 1  # i++
addi $t0, $t0, 4   # move to next array item
j printLoop

exitPrint:
jr $ra


bye:
addi $sp, $sp, 16
li $v0, 10
syscall

.data
arr: .word 2, 4, 6, 8
nl: .asciiz "\n"