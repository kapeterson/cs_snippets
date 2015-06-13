import turtle
import time


pen = turtle.Turtle()

pen.pencolor("red")
pen.penup()
pen.dot()

for i in range(4):
	pen.forward(30)
	pen.dot()

pen.left(90)

for i in range(4):
	pen.forward(30)
	pen.dot()
time.sleep(2)
turtle.done()


