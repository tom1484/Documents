# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import vpython as vp
# import numba as nb
import numpy as np


def vec(v0, v1, v2) -> np.ndarray:
    return np.array([v0, v1, v2])


def mag(V) -> np.ndarray:
    return np.sqrt(np.sum(V * V, axis=-1, keepdims=True))


def norm(V) -> np.ndarray:
    return V / mag(V)


def G_acc(src_pos, obj_pos, src_m) -> np.ndarray:
    return -(G * src_m / (mag(obj_pos - src_pos) ** 3)) * (obj_pos - src_pos)


def G_acc_inner(src_pos, obj_pos, src_m, src_r) -> np.ndarray:
    return -(G * src_m / (src_r ** 3)) * (obj_pos - src_pos)

# S_y_force = Y_modulus * s.L * (s.L - mag(s.axis)) * norm(s.b0.pos - s.b1.pos)
# def Y_acc(obj) -> np.ndarray:
#     Y_modulus


G = 6.6743e-11
# Y_modulus = 2e8
Y_modulus = 2e12
# G_modulus = 1e8
G_modulus = 1e12

N = 5
r_N = 2 * N + 1

planet_r = 6.371e6
planet_R = 1.496e11
planet_m = 5.972e24
planet_v = 2.9783E4

sum_m = 1.989e30
sun_r = 6.95E8

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

    spring_axis[0] = np.concatenate((slice_pos[1:], slice_pos[-1:]), axis=0) - slice_pos
    spring_axis[1] = np.concatenate((slice_pos[:, 1:], slice_pos[:, -1:]), axis=1) - slice_pos
    spring_axis[2] = np.concatenate((slice_pos[:, :, 1:], slice_pos[:, :, -1:]), axis=2) - slice_pos


# t = 0
# dt = 10
# while True:
#     vp.rate(5000)
#
#     slice_a = G_acc_inner(vec(0, 0, 0), slice_pos, planet_m, planet_r) * slice_valid
#     slice_v += slice_a * dt
#     slice_pos += slice_v * dt
#
#     t += dt
#
#     # print(slice_pos[5, 5, 6])
#     print(t)

#
# class Planet:
#     def __init__(self, pos, v, radius, m, N_slice):
#         self.pos = pos
#         self.v = v
#         self.radius = radius
#         self.m = m
#         self.N_slice = N_slice
#
#         self.balls = []
#         self.balls_index = []
#         dis_ball = radius / N_slice
#
#         self.balls_display = []
#
#         for x in range(-N_slice, N_slice + 1):
#             self.balls_index.append([])
#             for y in range(-N_slice, N_slice + 1):
#                 self.balls_index[-1].append([])
#                 for z in range(-N_slice, N_slice + 1):
#                     if (x*x + y*y + z*z) > N_slice * N_slice:
#                         self.balls_index[x + N_slice][y + N_slice].append(None)
#                         continue
#                     self.balls.append(obj(pos=pos + vec(x, y, z) * dis_ball))
#                     self.balls_display.append(sphere(pos=vec(0, 0, 0), radius=dis_ball * 0.3 * scale, color=color.blue))
#                     self.balls_index[x + N_slice][y + N_slice].append(self.balls[-1])
#         for b in self.balls:
#             b.m = m / len(self.balls)
#             b.v = vec(0, 0, 0)
#
#         self.springs = []
#         self.springs_display = []
#         for x in range(2 * N_slice + 1):
#             for y in range(2 * N_slice + 1):
#                 for z in range(2 * N_slice + 1):
#                     for dir in [(1, 0, 0), (0, 1, 0), (0, 0, 1)]:
#                         x_, y_, z_ = x + dir[0], y + dir[1], z + dir[2]
#                         if x_ > 2 * N_slice or y_ > 2 * N_slice or z_ > 2 * N_slice:
#                             continue
#                         b0, b1 = self.balls_index[x][y][z], self.balls_index[x_][y_][z_]
#                         if b0 is None or b1 is None:
#                             continue
#
#                         s = obj(pos=b0.pos)
#                         s.b0, s.b1 = b0, b1
#                         s.axis_origin = b1.pos - b0.pos
#                         s.L = dis_ball
#                         s.alive = True
#                         self.springs.append(s)
#
#                         self.springs_display.append(cylinder(pos=vec(0, 0, 0), axis=vec(0, 0, 0),
#                                                              radius=dis_ball * 0.03 * scale, color=vec(1, 0, 0)))
#
#     def launch(self):
#         for b in self.balls:
#             b.v = self.v
#
#     def time_lapse(self, dt):
#         for b in self.balls:
#             # b.a = G_acc_inner(self, b)
#             b.a = vec(0, 0, 0)
#             if stable:
#                 b.a += G_acc(sun, b)
#
#         for i, s in enumerate(self.springs):
#             if not s.alive:
#                 continue
#             s.pos = s.b0.pos
#             s.axis = s.b1.pos - s.b0.pos
#
#             S_y_force = Y_modulus * s.L * (s.L - mag(s.axis)) * norm(s.b0.pos - s.b1.pos)
#
#             s_axis_proj = dot(s.axis, s.axis_origin) / s.L * norm(s.axis_origin)
#             s_axis_orth = s.axis - s_axis_proj
#             S_g_force = G_modulus * mag(s_axis_proj) * s_axis_orth
#             # if i == 690:
#             #     print(S_g_force / (s.L ** 2))
#
#             if (s.L - mag(s.axis) < 0 and mag(S_y_force) / (s.L ** 2) > 1e5) or mag(S_g_force) / (s.L ** 2) > 1e5:
#                 pass
#                 # s.alive = False
#                 # self.springs_display[i].visible = False
#
#             s.b0.a += S_y_force / s.b0.m
#             s.b1.a -= S_y_force / s.b1.m
#             s.b0.a += S_g_force / s.b0.m
#             s.b1.a -= S_g_force / s.b1.m
#
#         for i, s in enumerate(self.springs_display):
#             s.pos = (self.springs[i].pos - self.pos) * scale + self.pos
#             s.axis = self.springs[i].axis * scale
#
#         self.pos = vec(0, 0, 0)
#         for i, b in enumerate(self.balls):
#             if not stable:
#                 b.a -= 0.005 * b.v
#             b.v += b.a * dt
#             b.pos += b.v * dt
#
#             self.pos += b.pos / len(self.balls)
#         print(self.pos)
#
#         for i, b in enumerate(self.balls_display):
#             b.pos = (self.balls[i].pos - self.pos) * scale + self.pos
#
#         # print(mag(self.balls[0].a) - a)
#         # print(mag(self.balls_index[5][5][4].a) / mag(self.balls_index[5][5][4].v * 0.0005))
#         # print(self.springs[690].axis_origin - self.springs[690].axis)
#
#
# # Press the green button in the gutter to run the script.
# if __name__ != '__main__':
#     N = 5
#     scale = 5000
#
#     G = 6.6743e-11
#
#     r_earth = 6.371e6
#     m_earth = 5.972e24
#     R_earth = 1.496e11
#     v_earth = 2.9783E4
#
#     m_sun = 1.989e30
#     r_sun = 6.95E8
#
#     # Y_modulus = 2e8
#     Y_modulus = 2e12
#     # G_modulus = 1e8
#     G_modulus = 1e12
#
#     scene = canvas(width=800, height=800, align='left', background=vec(1, 1, 1))
#     planet = Planet(vec(R_earth, 0, 0), vec(0, 0, v_earth), r_earth, m_earth, N)
#     # planet = Planet(vec(0, 0, 0), vec(0, 0, v_earth), r_earth, m_earth, N)
#     sun = sphere(pos=vec(0, 0, 0), m=m_sun, radius=r_sun * 20, color=color.orange)
#     # earth = sphere(pos=vec(R_earth, 0, 0), radius=r_earth * 100, color=color.blue)
#
#     time_label = label(pos=vec(0, 0, 0), xoffset=-300, yoffset=-300)
#     stable = False
#
#     dt = 10
#     t = 0
#     # c = 10
#     while True:
#         # rate(100000)
#         planet.time_lapse(dt)
#         t += dt
#
#         if not stable and t > 2000:
#             stable = True
#             planet.launch()
#             # planet.balls_index[5][5][5].v = vec(1, 0, 0)
#
#         time_label.text = f"{t}"
#         scene.center = (planet.pos + sun.pos) / 2
#         # scene.center = sun.pos / 2
#         # sleep(0.01)
#         # print(t)
#
#
# # See PyCharm help at https://www.jetbrains.com/help/pycharm/
