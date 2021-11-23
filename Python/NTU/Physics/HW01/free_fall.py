from vpython import *

g = 9.8
radius = 0.25
height = 15.0

scene = canvas(width=800, height=800, 
               center=vec(0, height / 2, 0), 
               background=vec(0.5, 0.5, 0))
floor = box(pos=vec(-15, -0.01, 0), axis=vec(1, 0, 0),
            size=(30, 0.01, 10),
            color=color.blue)
ball = sphere(radius=radius, color=color.red, 
              make_trail=True, trail_radius=0.05)
msg = text(text='Free Fall', pos=vec(-10, 10, 0))

ball.pos = vec(0, height, 0)
ball.v = vec(0, 0, 0)
dt = 0.001

while ball.pos.y >= radius:
    rate(1000)

    ball.pos = ball.pos + ball.v * dt
    ball.v.y = ball.v.y - g * dt

msg.visible = False
msg = text(text=str(ball.v.y), pos=vec(-10, 10, 0))
print(ball.v.y)

