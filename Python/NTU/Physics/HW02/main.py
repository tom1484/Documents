from vpython import *

g = 9.8
size, m = 0.2, 1
L, k = 2, 150000
v = [1, 2, 2.2]
d = [-0.06, 0, -0.1]


def af_col_v(m1, m2, v1, v2, x1, x2):  # function after collision velocity
    v1_prime = v1 + 2 * (m2 / (m1 + m2)) * (x1 - x2) * dot(v2 - v1, x1 - x2) / dot(x1 - x2, x1 - x2)
    v2_prime = v2 + 2 * (m1 / (m1 + m2)) * (x2 - x1) * dot(v1 - v2, x2 - x1) / dot(x2 - x1, x2 - x1)
    return (v1_prime, v2_prime)


scene = canvas(width=500, height=500, center=vec(0, -0.2, 0), background=vec(0.5, 0.5, 0), align='left')
ceiling = box(length=1.6, height=0.005, width=0.8, color=color.blue)

oscillation1 = graph(width=600, align='left', title='energy')
oscillation2 = graph(width=600, align='left', title='average energy')

kinetic_plot = gcurve(graph=oscillation1, color=color.blue, width=2, label='kinetic energy')
potential_plot = gcurve(graph=oscillation1, color=color.orange, width=2, label='potential energy')

average_kinetic_plot = gcurve(graph=oscillation2, color=color.blue, width=2, label='kinetic energy')
average_potential_plot = gcurve(graph=oscillation2, color=color.orange, width=2, label='potential energy')

balls = []
for i in range(2):
    ball = sphere(pos=vec((i - 2) * 2 * size - (2 ** 2 - 1.95 ** 2) ** 0.5, -1.95, 0), radius=size, color=color.red)
    balls.append(ball)
for i in range(2, 5):
    ball = sphere(pos=vec((i - 2) * 2 * size, -L, 0), radius=size, color=color.red)
    balls.append(ball)

for i in range(5):
    balls[i].v = vec(0, 0, 0)

springs = []
for i in range(5):
    spring = cylinder(pos=vec((i - 2) * 2 * size, 0, 0), radius=0.005, thickness=0.01)
    spring.axis = balls[i].pos - spring.pos
    springs.append(spring)

t = 0
dt = 0.0002
total_kinetic_energy = 0
total_potential_energy = 0
while True:
    rate(5000)
    t += dt
    kinetic_energy = 0
    potential_energy = 0
    for i in range(5):
        springs[i].axis = balls[i].pos - springs[i].pos  # spring extended from endpoint to ball
        springs_force = - k * (mag(springs[i].axis) - L) * springs[i].axis.norm()  # to get spring force vector
        balls[i].a = vector(0, - g, 0) + springs_force / m
        balls[i].v += balls[i].a * dt
        balls[i].pos += balls[i].v * dt

    for i in range(5):
        kinetic_energy += m * mag(balls[i].v) ** 2 / 2
        potential_energy += m * g * (balls[i].pos.y - (-2))
    total_kinetic_energy += kinetic_energy * dt
    total_potential_energy += potential_energy * dt

    for n in range(4):
        if 2 * size >= mag(balls[n].pos - balls[n + 1].pos):
            (balls[n].v, balls[n + 1].v) = af_col_v(m, m, balls[n].v, balls[n + 1].v, balls[n].pos, balls[n + 1].pos)

    kinetic_plot.plot(pos=(t, kinetic_energy))
    potential_plot.plot(pos=(t, potential_energy))
    average_kinetic_plot.plot(pos=(t, total_kinetic_energy / t))
    average_potential_plot.plot(pos=(t, total_potential_energy / t))