from vpython import *
import numpy as np


scene = canvas(width=900, height=900, background=color.white)

x_axis = arrow(pos=vec(0, 0, 0), axis=vec(1, 0, 0), shaftwidth=0.05, color=color.red)
y_axis = arrow(pos=vec(0, 0, 0), axis=vec(0, 1, 0), shaftwidth=0.05, color=color.green)
z_axis = arrow(pos=vec(0, 0, 0), axis=vec(0, 0, 1), shaftwidth=0.05, color=color.blue)


def rotatation(v, angle):
    x, y, z = angle
    R_x = np.array([[1, 0, 0],
                    [0, cos(x), -sin(x)],
                    [0, sin(x), cos(x)]])
    R_y = np.array([[cos(y), 0, sin(y)],
                    [0, 1, 0],
                    [-sin(y), 0, cos(y)]])
    R_z = np.array([[cos(z), -sin(z), 0],
                    [sin(z), cos(z), 0],
                    [0, 0, 1]])

    v = np.matmul(R_x, v)
    v = np.matmul(R_y, v)
    v = np.matmul(R_z, v)

    return v


def vp2np(v):
    return np.array([v.x, v.y, v.z])


def np2vp(v):
    return vec(v[0], v[1], v[2])


ball = sphere(pos=vec(1, 0, 0), radius=0.2, color=color.yellow)

omega = np.array([1, 1, 1], dtype=np.float32)
pos = np.array([1, 0, 0], dtype=np.float32)
angle = np.array([0, 0, 0], dtype=np.float32)

dt = 0.001
while True:
    rate(1000)

    # keep applying small rotation to object
    # d_omega = omega * dt
    # ball.pos = np2vp(rotatation(vp2np(ball.pos), d_omega))

    # calculate Euler angle by directly integrating angular velocity
    angle += omega * dt
    ball.pos = np2vp(rotatation(pos, angle))


