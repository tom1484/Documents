# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import vpython as vp
import numpy as np

import matplotlib.pyplot as plt


def vec(v0, v1, v2) -> np.ndarray:
    return np.array([v0, v1, v2])


def mag(V) -> np.ndarray:
    return np.sqrt(np.sum(V * V, axis=-1, keepdims=True))


def mag2(V) -> np.ndarray:
    return np.sum(V * V, axis=-1, keepdims=True)


def norm(V) -> np.ndarray:
    return V / mag(V)


def dot(V1, V2) -> np.ndarray:
    return np.sum(V1 * V2, axis=-1, keepdims=True)


def project(V1, V2) -> np.ndarray:
    return dot(V1, V2) / mag2(V2) * V2


def G_acc(src_pos, obj_pos, src_m) -> np.ndarray:
    return -(G * src_m / (mag(obj_pos - src_pos) ** 3)) * (obj_pos - src_pos)


def G_acc_inner(src_pos, obj_pos, src_m, src_r) -> np.ndarray:
    return -(G * src_m / (src_r ** 3)) * (obj_pos - src_pos)


def Y_acc_x(obj_pos, origin_axis, obj_m):
    spring_axis_ = np.concatenate((obj_pos[1:], obj_pos[:1]), axis=0) - obj_pos
    spring_axis_px = project(spring_axis_, origin_axis)
    spring_axis_py = spring_axis_ - spring_axis_px

    force_x = Y_modulus * spring_L * (mag(spring_axis_px) - spring_L) * norm(origin_axis) + \
              G_modulus * spring_L * spring_axis_py

    return force_x / obj_m


def Y_acc_y(obj_pos, origin_axis, obj_m):
    spring_axis_ = np.concatenate((obj_pos[:, 1:], obj_pos[:, :1]), axis=1) - obj_pos
    spring_axis_px = project(spring_axis_, origin_axis)
    spring_axis_py = spring_axis_ - spring_axis_px

    force_y = Y_modulus * spring_L * (mag(spring_axis_px) - spring_L) * norm(origin_axis) + \
              G_modulus * spring_L * spring_axis_py

    return force_y / obj_m


def Y_acc_z(obj_pos, origin_axis, obj_m):
    spring_axis_ = np.concatenate((obj_pos[:, :, 1:], obj_pos[:, :, :1]), axis=2) - obj_pos
    spring_axis_px = project(spring_axis_, origin_axis)
    spring_axis_py = spring_axis_ - spring_axis_px

    force_z = Y_modulus * spring_L * (mag(spring_axis_px) - spring_L) * norm(origin_axis) + \
              G_modulus * spring_L * spring_axis_py

    return force_z / obj_m


G = 6.6743e-11
# Y_modulus = 2e8
Y_modulus = 2e12
# G_modulus = 1e8
G_modulus = 1e12

N = 5
r_N = 2 * N + 1

sun_m = 1.989e30
sun_r = 6.95E8

planet_r = 6.371e6 * 1.0605
planet_m = 5.972e24
# planet_R = 1.496e11
planet_R = sun_r
# planet_v = 2.9783E4
planet_v = np.sqrt(G * sun_m / planet_R)

slice_valid = np.ndarray((r_N, r_N, r_N, 1), dtype=np.int8)

slice_N = 0
for ix, iy, iz in np.ndindex(r_N, r_N, r_N):
    x, y, z = ix - N, iy - N, iz - N
    if x * x + y * y + z * z <= N * N:
        slice_valid[ix, iy, iz, 0] = 1
        slice_N += 1
    else:
        slice_valid[ix, iy, iz, 0] = 0

slice_r = planet_r / N
slice_m = planet_m / slice_N

slice_pos = np.ndarray((r_N, r_N, r_N, 3))
slice_v = np.ndarray((r_N, r_N, r_N, 3))
slice_a = np.ndarray((r_N, r_N, r_N, 3))

for ix, iy, iz in np.ndindex(r_N, r_N, r_N):
    x, y, z = ix - N, iy - N, iz - N

    slice_pos[ix, iy, iz] = vec(x, y, z) * planet_r / N
    slice_v[ix, iy, iz] = vec(0, 0, 0)
    slice_a[ix, iy, iz] = vec(0, 0, 0)

spring_L = slice_r
spring_axis = np.ndarray((3, r_N, r_N, r_N, 3))
for ix, iy, iz in np.ndindex(r_N, r_N, r_N):
    x, y, z = ix - N, iy - N, iz - N

    spring_axis[0] = np.concatenate((slice_pos[1:], slice_pos[:1]), axis=0) - slice_pos
    spring_axis[1] = np.concatenate((slice_pos[:, 1:], slice_pos[:, :1]), axis=1) - slice_pos
    spring_axis[2] = np.concatenate((slice_pos[:, :, 1:], slice_pos[:, :, :1]), axis=2) - slice_pos

spring_valid_x_p = np.concatenate((slice_valid[1:], np.zeros(((1, r_N, r_N, 1)))), axis=0)
spring_valid_x_n = np.concatenate((np.zeros(((1, r_N, r_N, 1))), slice_valid[:-1]), axis=0)

spring_valid_y_p = np.concatenate((slice_valid[:, 1:], np.zeros(((r_N, 1, r_N, 1)))), axis=1)
spring_valid_y_n = np.concatenate((np.zeros(((r_N, 1, r_N, 1))), slice_valid[:, :-1]), axis=1)

spring_valid_z_p = np.concatenate((slice_valid[:, :, 1:], np.zeros(((r_N, r_N, 1, 1)))), axis=2)
spring_valid_z_n = np.concatenate((np.zeros(((r_N, r_N, 1, 1))), slice_valid[:, :, :-1]), axis=2)


def launch():
    global slice_pos, slice_v

    slice_pos += vec(planet_R, 0, 0)
    slice_v += vec(0, 0, planet_v)


cnt = 0

t = 0
dt = 10
while True:
    vp.rate(5000)

    cm = np.sum(slice_pos * slice_valid, axis=(0, 1, 2)) / slice_N
    slice_a = G_acc_inner(cm, slice_pos, planet_m, planet_r) * slice_valid

    # calculate spring force
    spring_a = np.zeros(slice_a.shape)

    spring_ax = Y_acc_x(slice_pos, spring_axis[0], slice_m)
    spring_ay = Y_acc_y(slice_pos, spring_axis[1], slice_m)
    spring_az = Y_acc_z(slice_pos, spring_axis[2], slice_m)

    slice_a += spring_ax * spring_valid_x_p
    slice_a -= np.concatenate((np.zeros(((1, r_N, r_N, 3))), spring_ax[:-1]), axis=0) * spring_valid_x_n

    slice_a += spring_ay * spring_valid_y_p
    slice_a -= np.concatenate((np.zeros(((r_N, 1, r_N, 3))), spring_ay[:, :-1]), axis=1) * spring_valid_y_n

    slice_a += spring_az * spring_valid_z_p
    slice_a -= np.concatenate((np.zeros(((r_N, r_N, 1, 3))), spring_az[:, :, :-1]), axis=2) * spring_valid_z_n

    if cnt < 10000:
        slice_a -= 0.1 * slice_v
    elif cnt == 10000:
        launch()
    else:
        slice_a += G_acc(vec(0, 0, 0), slice_pos, sun_m)

    if cnt % 1000 == 0:
        plt.scatter((slice_pos[:, 5, :, 0] - cm[0]) * slice_valid[:, 5, :, 0], (slice_pos[:, 5, :, 2] - cm[2]) * slice_valid[:, 5, :, 0])
        plt.xlim(-planet_r * 1.2, planet_r * 1.2)
        plt.ylim(-planet_r * 1.2, planet_r * 1.2)
        plt.draw()
        plt.pause(0.01)
        plt.clf()

    slice_v += slice_a * dt
    slice_pos += slice_v * dt

    t += dt
    cnt += 1

    if cnt % 1000 == 0:
        print(slice_pos[N, N, 2 * N], t)
