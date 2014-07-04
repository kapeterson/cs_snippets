.text

# adds the previous two $tX registers for 0-7 and prints out the sum
li $s0, 1
li $s1, 2

move $t0, $s0
move $t1, $s1
add $t2, $t0, $t1
add $t3, $t1, $t2
add $t4, $t3, $t2
add $t5, $t4, $t3
add $t6, $t5, $t4
add $t7, $t6, $t6

move $a0, $t7
li $v0, 1   # load the print instruction
syscall   # print value of $v0
li $v0, 10
syscall


