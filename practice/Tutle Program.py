from turtle import Turtle
dina = Turtle()
def circle_area(dia):
    return 3.14*(1/4)*dia*dia
def draw_circle(name, dia, col):
    name.color(col)
    name.dot(dia)
def rectangle(name, w, h, c):
    name.penup()
    name.goto(300,-100)
    name.pendown()
    name.fillcolor(c)
    name.begin_fill()
    name.forward(w)
    name.left(90)
    name.forward(h)
    name.left(90)
    name.forward(w)
    name.left(90)
    name.forward(h)
    name.end_fill()
draw_circle(dina,400,"yellow")
draw_circle(dina,300,"red")
draw_circle(dina,200,"green")
draw_circle(dina,100,"blue")
rectangle(dina,150,200,"red")