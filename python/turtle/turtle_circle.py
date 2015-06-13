import turtle
import time
import math

pen = turtle.Turtle()

pen.pencolor("red")
pen.penup()

turn = (math.pi/2)/80
print turn

for i in range(300):
	pen.dot()
	pen.penup()
	pen.left(1)
	pen.forward(2)

pen.dot()

turtle.done()
