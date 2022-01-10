# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

from vpython import *


def G_acc(source, obj):
    return -(G * source.m / (mag(obj.pos - source.pos) ** 3)) * norm(obj.pos - source.pos)


def G_acc_inner(source, obj):
    return -(G * source.m / (source.radius ** 3)) * norm(obj.pos - source.pos)


class Planet:
    def __init__(self, pos, radius, m, N_slice):
        self.pos = pos
        self.radius = radius
        self.m = m
        self.N_slice = N_slice
        # self.d_slice =

        self.balls = []
        self.balls_index = []
        dis_ball = radius / N_slice
        for x in range(-N_slice, N_slice + 1):
            self.balls_index.append([])
            for y in range(-N_slice, N_slice + 1):
                self.balls_index[-1].append([])
                for z in range(-N_slice, N_slice + 1):
                    if (x*x + y*y + z*z) > N_slice * N_slice:
                        self.balls_index[x + N_slice][y + N_slice].append(None)
                        continue
                    self.balls.append(sphere(pos=pos + vec(x, y, z) * dis_ball,
                                             radius=dis_ball * 0.3, color=color.blue))
                    self.balls_index[x + N_slice][y + N_slice].append(self.balls[-1])
        for b in self.balls:
            b.m = m / len(self.balls)
            b.v = vec(0, 0, 0)

        self.springs = []
        for x in range(2 * N_slice + 1):
            for y in range(2 * N_slice + 1):
                for z in range(2 * N_slice + 1):
                    for dir in [(1, 0, 0), (0, 1, 0), (0, 0, 1)]:
                        x_, y_, z_ = x + dir[0], y + dir[1], z + dir[2]
                        if x_ > 2 * N_slice or y_ > 2 * N_slice or z_ > 2 * N_slice:
                            continue
                        b0, b1 = self.balls_index[x][y][z], self.balls_index[x_][y_][z_]
                        if b0 is None or b1 is None:
                            continue

                        s = cylinder(pos=b0.pos, axis=b1.pos - b0.pos, radius=b0.radius * 0.1, color=vec(1, 0, 0))
                        s.b0, s.b1 = b0, b1
                        s.L = dis_ball
                        s.axis_origin = b1.pos - b0.pos

                        self.springs.append(s)

                        # if x == y == z == N_slice:
                        #     print(len(self.springs))

        # self.balls_index[0][N_slice][N_slice].pos -= vec(dis_ball * 0.05, 0, 0)
        # self.balls_index[0][N_slice][N_slice].color = vec(0, 1, 0)

    def time_lapse(self, dt):
        for b in self.balls:
            b.a = G_acc_inner(self, b)

        for s in self.springs:
            s.pos = s.b0.pos
            s.axis = s.b1.pos - s.b0.pos

            S_y_force = Y_modulus * s.L * (s.L - mag(s.axis)) * norm(s.b0.pos - s.b1.pos)
            s.b0.a += S_y_force / s.b0.m
            s.b1.a -= S_y_force / s.b1.m

            s_axis_proj = dot(s.axis, s.axis_origin) / s.L * norm(s.axis_origin)
            s_axis_orth = s.axis - s_axis_proj
            S_g_force = G_modulus * mag(s_axis_proj) * s_axis_orth
            s.b0.a += S_g_force / s.b0.m
            s.b1.a -= S_g_force / s.b1.m

        # print(G_acc_inner(self, self.balls[0]), end="")

        for b in self.balls:
            b.v += b.a * dt
            b.pos += b.v * dt

        # print(mag(self.balls[0].a) - a)
        print(self.springs[690].axis_origin - self.springs[0].axis)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    G = 6.6743e-11
    r_earth = 6.371e6
    m_earth = 5.972e24

    Y_modulus = 2e8
    G_modulus = 1e8

    scene = canvas(width=800, height=800, align='left', background=vec(1, 1, 1))
    planet = Planet(vec(0, 0, 0), r_earth, m_earth, 5)

    time_label = label(pos=vec(0, 0, 0), xoffset=-300, yoffset=-300)

    dt = 100
    t = 0
    # c = 10
    while True:
        # rate(100000)
        planet.time_lapse(dt)
        t += dt

        time_label.text = f"{t}"
        # sleep(0.01)
        # print(t)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
