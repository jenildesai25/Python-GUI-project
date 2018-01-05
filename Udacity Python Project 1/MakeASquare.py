__author__ = 'jenil'
import turtle
def draw_square(some_turtle):
    for i in range(1,5):
        some_turtle.forward(50)
        some_turtle.right(90)



def draw_shapes():
    window = turtle.Screen()
    window.bgcolor("red")
    brad = turtle.Turtle()
    brad.shape("turtle")
    brad.color("yellow")
    brad.speed(0)
    for i in range(1,37):
        draw_square(brad)
        brad.right(10)
    brad.right(90)
    brad.forward(100)
    window.exitonclick()

draw_shapes()