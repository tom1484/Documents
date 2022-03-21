import numpy as np
from math import sin, cos


def rotatation(v, x, y, z):
    R_x = np.array([[1, 0, 0],
                    [0, cos(x), -sin(x)],
                    [0, sin(x), cos(x)]])
    R_y = np.array([[cos(y), 0, sin(y)],
                    [0, 1, 0],
                    [-sin(y), 0, cos(y)]])
    R_z = np.array([[cos(z), -sin(z), 0],
                    [sin(z), cos(z), 0],
                    [0, 0, 1]])

    # print(R_x, R_y, R_z)

    v = np.matmul(R_x, v)
    v = np.matmul(R_y, v)
    v = np.matmul(R_z, v)

    return v



