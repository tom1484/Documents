from vpython import *

g = 9.8
radius = 0.25

scene = canvas(center=vec(0, 5, 0), width=600, 
               background=color.blue)
floor = box(length=30, height=0.01, width=4, 
            background=color.blue)
ball = sphere(radius=radius, color=color.red, 
              make_trail=True, trail_radius=radius / 3)

ball.pos = vec(-15, 10, 0)
ball.v = vec(2, 0, 0)
dt = 0.001


while ball.pos.x < 15:
    rate(1000)
    ball.pos += ball.v * dt
    ball.v.y -= g * dt

    if ball.pos.y <= radius and ball.v.y < 0:
        ball.v.y *= -1
