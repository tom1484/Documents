import vpython as vp
import numpy as np

import matplotlib.pyplot as plt
import time


# create numpy array as 3D vector
def vec(v0, v1, v2) -> np.ndarray:
    return np.array([v0, v1, v2])


# magnitude of vector
def mag(V) -> np.ndarray:
    return np.sqrt(np.sum(V * V, axis=-1, keepdims=True))


# magnitude in square
def mag2(V) -> np.ndarray:
    return np.sum(V * V, axis=-1, keepdims=True)


# normalize vector to unit length
def norm(V) -> np.ndarray:
    return V / mag(V)


# dot of two vector
def dot(V1, V2) -> np.ndarray:
    return np.sum(V1 * V2, axis=-1, keepdims=True)


# project V1 on V2
def project(V1, V2) -> np.ndarray:
    return dot(V1, V2) / mag2(V2) * V2


# gravititional acceleration of two object
def G_acc(src_pos, obj_pos, src_m) -> np.ndarray:
    return -(G * src_m / (mag(obj_pos - src_pos) ** 3)) * (obj_pos - src_pos)


# gravititional acceleration inside a planet
def G_acc_inner(src_pos, obj_pos, src_m, src_r) -> np.ndarray:
    return -(G * src_m / (src_r ** 3)) * (obj_pos - src_pos)


# acceleration from spring
def spring_acc(obj_pos, origin_axis, obj_m) -> np.ndarray:
    spring_axis_new = np.stack((np.roll(obj_pos, -1, axis=0),
                                np.roll(obj_pos, -1, axis=1),
                                np.roll(obj_pos, -1, axis=2))) - obj_pos
    spring_axis_px = project(spring_axis_new, origin_axis)
    spring_axis_py = spring_axis_new - spring_axis_px

    force_Y = Y_modulus * spring_L * (mag(spring_axis_px) - spring_L) * norm(origin_axis)
    force_G = G_modulus * spring_L * spring_axis_py

    return force_Y / obj_m, force_G / obj_m


G = 6.6743e-11
Y_modulus = 2e8
# Y_modulus = 2e12
G_modulus = 1e8
# G_modulus = 1e12

N = 5
r_N = 2 * N + 1  # slice radius to N segments, therefore 2N+1 points are required

sun_m = 1.989e30
sun_r = 6.95E8

planet_r = 6.371e6 * 3.6138
planet_m = 5.972e24
# planet_R = 1.496e11
planet_R = sun_r * 3  # test extremely close distance
planet_v = np.sqrt(G * sun_m / planet_R)

# 1s for balls inside planet, 0s for others
slice_valid = np.ndarray((r_N, r_N, r_N, 1))

slice_N = 0
for ix, iy, iz in np.ndindex(r_N, r_N, r_N):
    x, y, z = ix - N, iy - N, iz - N
    if x * x + y * y + z * z <= N * N:
        slice_valid[ix, iy, iz, 0] = 1.0
        slice_N += 1
    else:
        slice_valid[ix, iy, iz, 0] = 0.0

slice_d = planet_r / N
slice_m = planet_m / slice_N

slice_pos = np.ndarray((r_N, r_N, r_N, 3))
slice_v = np.ndarray((r_N, r_N, r_N, 3))
slice_a = np.ndarray((r_N, r_N, r_N, 3))

for ix, iy, iz in np.ndindex(r_N, r_N, r_N):
    x, y, z = ix - N, iy - N, iz - N

    slice_pos[ix, iy, iz] = vec(x, y, z) * planet_r / N
    slice_v[ix, iy, iz] = vec(0, 0, 0)
    slice_a[ix, iy, iz] = vec(0, 0, 0)

spring_L = slice_d
# create springs on positive direction
spring_axis = np.stack((np.roll(slice_pos, -1, axis=0),
                        np.roll(slice_pos, -1, axis=1),
                        np.roll(slice_pos, -1, axis=2))) - slice_pos

padding = [[((0, 1), (0, 0), (0, 0), (0, 0)), ((1, 0), (0, 0), (0, 0), (0, 0))],
           [((0, 0), (0, 1), (0, 0), (0, 0)), ((0, 0), (1, 0), (0, 0), (0, 0))],
           [((0, 0), (0, 0), (0, 1), (0, 0)), ((0, 0), (0, 0), (1, 0), (0, 0))]]
# 1 if the ball has a spring in positive direction
spring_valid_x_p = np.pad(slice_valid, padding[0][0])[1:]
spring_valid_y_p = np.pad(slice_valid, padding[1][0])[:, 1:]
spring_valid_z_p = np.pad(slice_valid, padding[2][0])[:, :, 1:]
# 1 if the ball has a spring in negative direction
spring_valid_x_n = np.pad(slice_valid, padding[0][1])[:-1]
spring_valid_y_n = np.pad(slice_valid, padding[1][1])[:, :-1]
spring_valid_z_n = np.pad(slice_valid, padding[2][1])[:, :, :-1]

t = 0
dt = 10
cnt = 0
while True:
    vp.rate(5000)
    s = time.time()

    cm = np.sum(slice_pos * slice_valid, axis=(0, 1, 2)) / slice_N  # center of mass of planet
    slice_a = G_acc_inner(cm, slice_pos, planet_m, planet_r) * slice_valid

    spring_a_Y, spring_a_G = spring_acc(slice_pos, spring_axis, slice_m)

    
    spring_a = sprnig_a_Y + spring_a_G
    # spring forces are from both direction
    slice_a += spring_a[0] * spring_valid_x_p - \
               np.pad(spring_a[0], padding[0][1])[:-1] * spring_valid_x_n
    slice_a += spring_a[1] * spring_valid_y_p - \
               np.pad(spring_a[1], padding[1][1])[:, :-1] * spring_valid_y_n
    slice_a += spring_a[2] * spring_valid_z_p - \
               np.pad(spring_a[2], padding[2][1])[:, :, :-1] * spring_valid_z_n

    if t < 100000:
        slice_a -= 0.0005 * slice_v
    elif t == 100000:
        slice_pos += vec(planet_R, 0, 0)
        slice_v += vec(0, 0, planet_v)
    else:
        slice_a += G_acc(vec(0, 0, 0), slice_pos, sun_m)

    if cnt % 50 == 0:
        # plt.scatter((slice_pos[:, N, :, 0] - cm[0]) * slice_valid[:, N, :, 0],
        #             (slice_pos[:, N, :, 2] - cm[2]) * slice_valid[:, N, :, 0])
        # plt.xlim(-6.371e6 * 1.2, 6.371e6 * 1.2)
        # plt.ylim(-6.371e6 * 1.2, 6.371e6 * 1.2)
        plt.scatter(((slice_pos[:, N, :, 0] - cm[0]) * 10 + cm[0]) * slice_valid[:, N, :, 0],
                    ((slice_pos[:, N, :, 2] - cm[2]) * 10 + cm[2]) * slice_valid[:, N, :, 0])
        plt.xlim(-planet_R * 1.1, planet_R * 1.1)
        plt.ylim(-planet_R * 1.1, planet_R * 1.1)
        plt.draw()
        plt.pause(0.001)
        plt.clf()

    if cnt % 50 == 0:
        print(slice_pos[N, N, 2 * N] - cm, t)

    slice_v += slice_a * dt
    slice_pos += slice_v * dt

    t += dt
    cnt += 1

    # print(time.time() - s)
