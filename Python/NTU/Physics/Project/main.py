from vpython import *
import numpy as np
import numba as nb

# import matplotlib.pyplot as plt
import time


G = 6.6743e-11

n = 3
N = 2 * n + 1
mu = 5000
# mu = 0

sun_m = 1.989e30
sun_r = 6.95E8

planet_r = 6.371e6
planet_m = 5.972e24
planet_R = sun_r * 0.8
planet_v = sqrt(G * sun_m / planet_R)
planet_T = 2 * pi * sqrt((planet_R ** 3) / (G * sun_m))

slice_r = planet_r / n / 2


scene = canvas(width=800, height=800, background=vec(1, 1, 1))


slice_pos = np.zeros((N, N, N, 3))
slice_v = np.zeros((N, N, N, 3))
slice_a = np.zeros((N, N, N, 3))
slice_valid = np.zeros((N, N, N))


slices = []
valid_slices = []
for ix, iy, iz in np.ndindex(N, N, N):
    x, y, z = ix - n, iy - n, iz - n
    if x * x + y * y + z * z > n * n:
        continue
    pos = vec(x, y, z) * planet_r / n
    slice_pos[ix, iy, iz] = np.array([pos.x, pos.y, pos.z])
    slice_valid[ix, iy, iz] = 1
    slice = sphere(pos=pos, radius=slice_r, color=color.green)
    slice.id = (ix, iy, iz)
    valid_slices.append((ix, iy, iz))
    slices.append(slice)

slice_valid_op = slice_valid.reshape((N, N, N, 1))


slice_N = len(slices)
slice_m = planet_m / slice_N


@nb.jit(nopython=True)
def collision(b1p, b1v, b2p, b2v):
    v1 = b1v - (b1p - b2p) * np.sum((b1v - b2v) * (b1p - b2p)) / np.sum((b1p - b2p) ** 2)
    v2 = b2v - (b2p - b1p) * np.sum((b2v - b1v) * (b2p - b1p)) / np.sum((b2p - b1p) ** 2)
    return v1, v2


@nb.jit(nopython=True)
def inner_gravity(pos, valid):
    acc = np.zeros((N, N, N, 3))
    for ix0, iy0, iz0 in np.ndindex(N, N, N):
        if valid[ix0, iy0, iz0] == 0:
            continue
        obj = pos[ix0, iy0, iz0]
        for ix1, iy1, iz1 in np.ndindex(N, N, N):
            if valid[ix1, iy1, iz1] == 0:
                continue
            if ix0 == ix1 and iy0 == iy1 and iz0 == iz1:
                continue
            src = pos[ix1, iy1, iz1]
            r = obj - src
            acc[ix0, iy0, iz0] += -G * slice_m / (np.sum(r * r) ** 1.5) * r

    return acc


@nb.jit(nopython=True)
def gravity(pos, valid):
    acc = np.zeros((N, N, N, 3))
    for ix0, iy0, iz0 in np.ndindex(N, N, N):
        if valid[ix0, iy0, iz0] == 0:
            continue
        obj = pos[ix0, iy0, iz0]
        acc[ix0, iy0, iz0] += -G * sun_m / (np.sum(obj * obj) ** 1.5) * obj

    return acc


@nb.jit(nopython=True)
def viscosity(pos, v, valid):
    acc = np.zeros((N, N, N, 3))
    for ix0, iy0, iz0 in np.ndindex(N, N, N):
        if valid[ix0, iy0, iz0] == 0:
            continue
        id0 = ix0 * N * N + iy0 * N + iz0
        obj_pos = pos[ix0, iy0, iz0]
        obj_v = v[ix0, iy0, iz0]
        for ix1, iy1, iz1 in np.ndindex(N, N, N):
            if ix1 * N * N + iy1 * N + iz1 >= id0:
                break
            if valid[ix1, iy1, iz1] == 0:
                continue
            src_pos = pos[ix1, iy1, iz1]
            src_v = v[ix1, iy1, iz1]

            r = obj_pos - src_pos
            if (np.sum(r * r) ** 0.5) > (4 * slice_r):
                continue

            dv = obj_v - src_v
            dv_proj = np.sum(dv * r) / np.sum(r * r) * r
            dv_orth = dv - dv_proj

            acc[ix0, iy0, iz0] += -mu * (dv_orth / (np.sum(r * r) ** 0.5))
            acc[ix1, iy1, iz1] -= -mu * (dv_orth / (np.sum(r * r) ** 0.5))

    return acc


@nb.jit(nopython=True)
def dispersity(pos, valid):
    dispersities = []
    for ix0, iy0, iz0 in np.ndindex(N, N, N):
        if valid[ix0, iy0, iz0] == 0:
            continue
        obj = pos[ix0, iy0, iz0]
        D = -1
        for ix1, iy1, iz1 in np.ndindex(N, N, N):
            if valid[ix1, iy1, iz1] == 0:
                continue
            if ix0 == ix1 and iy0 == iy1 and iz0 == iz1:
                continue
            src = pos[ix1, iy1, iz1]
            d = (np.sum((obj - src) * (obj - src)) ** 0.5) / (2 * slice_r)
            D = d if D < 0 else min(D, d)

        dispersities.append(D)

    dispersities.sort()

    return sum(dispersities[:int(slice_N * 0.95)]) / (slice_N * 0.95)


@nb.jit(nopython=True)
def planet_collision(pos, v, valid):
    v_prime = v
    for ix0, iy0, iz0 in np.ndindex(N, N, N):
        if valid[ix0, iy0, iz0] == 0:
            continue
        id0 = ix0 * N * N + iy0 * N + iz0
        obj_pos = pos[ix0, iy0, iz0]
        obj_v = v_prime[ix0, iy0, iz0]
        for ix1, iy1, iz1 in np.ndindex(N, N, N):
            if ix1 * N * N + iy1 * N + iz1 >= id0:
                break
            if valid[ix1, iy1, iz1] == 0:
                continue
            src_pos = pos[ix1, iy1, iz1]
            src_v = v_prime[ix1, iy1, iz1]

            r = obj_pos - src_pos
            delta_v = obj_v - src_v
            if (np.sum(r * r) ** 0.5) > (2 * slice_r) or np.sum(r * delta_v) >= 0:
                continue

            v_prime1, v_prime2 = collision(obj_pos, obj_v, src_pos, src_v)
            v_prime[ix0, iy0, iz0], v_prime[ix1, iy1, iz1] = v_prime1, v_prime2

    return v_prime


sun = sphere(pos=vec(0, 0, 0), radius=sun_r * 0.1, color=color.orange)
# sun.visible = False
display_scale = 1
slice_pos += np.array([planet_R, 0, 0])
slice_v += np.array([0, planet_v, 0])


t = 0
dt = 5
cnt = 0
while True:
    rate(5000)
    s = time.time()

    acc = inner_gravity(slice_pos, slice_valid)
    acc += gravity(slice_pos, slice_valid)

    acc += viscosity(slice_pos, slice_v, slice_valid)
    slice_v = planet_collision(slice_pos, slice_v, slice_valid)

    slice_a = acc
    slice_v += slice_a * dt
    slice_pos += slice_v * dt

    cm = np.sum(slice_pos * slice_valid_op, axis=(0, 1, 2)) / len(slices)  # center of mass of planet
    scene.center = vec(cm[0], cm[1], cm[2])
    scene.forward = vec(0, 0, -1)

    for b in slices:
        ix, iy, iz = b.id
        pos = slice_pos[ix, iy, iz]
        b.pos = vec(pos[0], pos[1], pos[2])
        b.radius = slice_r * display_scale

    t += dt
    cnt += 1

    # print(time.time() - s)
    print(dispersity(slice_pos, slice_valid), t)
