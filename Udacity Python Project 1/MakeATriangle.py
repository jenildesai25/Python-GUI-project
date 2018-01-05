__author__ = 'jenil'
import turtle

def logic_triangle(name_turtle):
    name_turtle.forward(50)
    name_turtle.left(135)
    name_turtle.forward(100)
    name_turtle.left(90)
    name_turtle.forward(100)
    name_turtle.left(135)
    name_turtle.forward(100)


def draw_triangle():
    window = turtle.Screen()
    window.bgcolor("yellow")
    jenil = turtle.Turtle()
    jenil.shape("turtle")
    jenil.color("blue")
    jenil.speed(100)
    logic_triangle(jenil)
    window.exitonclick()



draw_triangle()


