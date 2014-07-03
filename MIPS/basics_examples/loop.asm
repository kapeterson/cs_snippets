.text

li $t0, 10
li $t1, 0

LoopStart:
beq $t1, $t0, bye
addi $t1, $t1, 1
j LoopStart

bye:

.data

