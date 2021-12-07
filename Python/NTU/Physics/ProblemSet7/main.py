from vpython import *
import numpy as np

scene = canvas(title='Atom Oscillation', width=800, height=800, background=vec(0.5,0.5,0), center=vec(0, 0, 0))
ballA = sphere(radius=0.01, color=color.blue, pos=vec(1/6, 0, 0))
ballB = sphere(radius=0.01, color=color.red, pos=vec(-1/6, 0, 0))

dx = 0.001
ballA.pos += vec(dx, 0, 0)
ballB.pos -= vec(dx, 0, 0)
ballA.v, ballB.v = vec(0, 0, 0), vec(0, 0, 0)

m = 0.5
a, b = 3, 1

prev_r, curr_r = 0, 0
c = 0

t, dt = 0, 0.0002
while True:
    rate(1000)

    r = mag(ballA.pos - ballB.pos)
    if prev_r > curr_r and r > curr_r:
        print(t * 2 / (2 * c + 1))
        c += 1
    prev_r, curr_r = curr_r, r

    ballA.a = ((-a / r**2 + b / r**3) * (ballA.pos - ballB.pos) / r) / m
    ballB.a = ((-a / r**2 + b / r**3) * (ballB.pos - ballA.pos) / r) / m

    ballA.v += ballA.a * dt
    ballB.v += ballB.a * dt

    ballA.pos += ballA.v * dt
    ballB.pos += ballB.v * dt

    t += dt
