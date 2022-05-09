from turtle import Turtle
from random import randint
laura = Turtle()
laura.shape('turtle')
laura.color('red')
laura.penup()
laura.goto(-160,100)
laura.pendown()

ron = Turtle()
ron.shape('turtle')
ron.color('blue')
ron.penup()
ron.goto(-160,70)
ron.pendown()


andy = Turtle()
andy.shape('turtle')
andy.color('yellow')
andy.penup()
andy.goto(-160,40)
andy.pendown()

kat = Turtle()
kat.shape('turtle')
kat.color('pink')
kat.penup()
kat.goto(-160,10)
kat.pendown()


for movement in range(100):
    laura.forward(randint(1,5))
    ron.forward(randint(1,5))
    andy.forward(randint(1,5))
    kat.forward(randint(1,5))