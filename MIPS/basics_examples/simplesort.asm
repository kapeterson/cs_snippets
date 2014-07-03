.text
la $a0, arry
li $a1, 6
jal insertionStart
j bye


# array = address of array
# size = integer size of array
insertionStart:
addiu $sp, $sp, 20	# push 5 words on stack
sw $s0, 0($sp)
sw $s1, 4($sp)
sw $s2, 8($sp)
sw $s3, 12($sp)
sw $ra, 16($sp)
move $s2, $a0		# array
move $s3, $a1		# size
li $s0, 1	# i = 1

forLoopBody:
slt $t0, $s0, $s3
beq $t0, $zero, forLoopEnd

move $s1, $s0	# j = i

whileLoop:

sgt $t0, $s1, 0  # check if j > 0
beq $t0, $zero, exitWhileLoop  # if not greater than zero, exit while loop


sll $t0, $s1, 2  		# multipy j by 4 so we can have the right address
addu $t1, $s2, $t0   		# array + j
lw $t0, 0($t1)			# load two items
lw $t1, -4($t1)			# load the two items
slt $t0, $t0, $t1 		# if current index is greater, swap them
beq $t0, $zero, exitWhileLoop	# exit loop if the current value is not less
move $a0, $s2
move $a1, $s1
add $a2, $s1, -1

jal swap	#call swap
add $s1, $s1, -1 	# j--
j whileLoop		# Loop


exitWhileLoop:
addiu $s0, $s0, 1	# i++
j forLoopBody  		# Loop


forLoopEnd:
lw $ra, 16($sp)
lw $s3, 12($sp)
lw $s2, 8($sp)
lw $s1, 4($sp)
lw $s0, 0($sp)
addiu $sp, $sp, 20
jr $ra


swap:
sll $a1, $a1, 2
sll $a2, $a2, 2
add $t0, $a0, $a1   	# i1 address
add $t1, $a0, $a2	# i2 address
lw $a0, 0($t0)  # temp1
lw $a1, 0($t1) # tmep
sw $a0, 0($t1)
sw $a1, 0($t0)
jr $ra

bye:

.data

arry: .word  6, 5, 4, 3, 2, 1
