from vpython import *
import numpy as np

m = 0.5
a, b = 3, 1
r_eq = b / a

scene = canvas(title='Atom Oscillation', width=800, height=800, background=vec(0.5, 0.5, 0), center=vec(0, 0, 0))
ballA = sphere(radius=0.01, color=color.blue, pos=vec(0, 0, 0))
ballB = sphere(radius=0.01, color=color.red, pos=vec(0, 0, 0))

ballA_pos_eq = vec(r_eq / 2, 0, 0)
ballB_pos_eq = vec(-r_eq / 2, 0, 0)

dr = 0.001
ballA_pos = ballA_pos_eq + vec(dr / 2, 0, 0)
ballB_pos = ballB_pos_eq + vec(-dr / 2, 0, 0)

ballA.v, ballB.v = vec(0, 0, 0), vec(0, 0, 0)

period = label(pos=vec(0, 0, 0), height=16)

prev_r, curr_r = 0, 0
c = 0

t, dt = 0, 0.0002
while True:
    rate(1000)

    r = mag(ballA_pos - ballB_pos)
    if prev_r > curr_r and r > curr_r:
        T = t * 2 / (2 * c + 1)
        print(T)
        period.text = f'Period: {T} second'
        c += 1
    prev_r, curr_r = curr_r, r

    ballA.a = ((-a / r**2 + b / r**3) * (ballA_pos - ballB_pos) / r) / m
    ballB.a = ((-a / r**2 + b / r**3) * (ballB_pos - ballA_pos) / r) / m

    ballA.v += ballA.a * dt
    ballB.v += ballB.a * dt

    ballA_pos += ballA.v * dt
    ballB_pos += ballB.v * dt

    ballA.pos = (ballA_pos - ballA_pos_eq) * 30 + ballA_pos_eq
    ballB.pos = (ballB_pos - ballB_pos_eq) * 30 + ballB_pos_eq

    t += dt
