from vpython import *


class Pendulum:
    def __init__(self, L, radius, m, pos):
        self.L = L
        self.pos = pos

        self.pivot = sphere(pos=pos, radius=radius / 5, color=color.white)
        self.string = cylinder(pos=pos, radius=radius / 8, color=color.white)
        self.ball = sphere(pos=pos - vec(0, L, 0), radius=radius, color=color.blue)
        self.string.axis = self.ball.pos - self.pivot.pos

        self.ball.m = m

        self.ball.a = vec(0, 0, 0)
        self.ball.v = vec(0, 0, 0)

    def update(self, dt):
        self.ball.v += self.ball.a * dt
        self.ball.pos += self.ball.v * dt
        self.string.axis = self.ball.pos - self.pivot.pos

        self.ball.a = vec(0, 0, 0)

    def applyGravity(self, g):
        self.ball.a += vec(0, -g, 0)

    def applySpringForce(self, k):
        self.ball.a += -k * (mag(self.string.axis) - self.L) * self.string.axis.norm() / self.ball.m

    def setHeight(self, h):
        theta = acos(h / self.L)
        self.ball.pos = self.pos - vec(self.L * sin(theta), h, 0)
        self.string.axis = self.ball.pos - self.pivot.pos

    def kinetic_energy(self):
        return (self.ball.m * mag(self.ball.v) ** 2) / 2

    def potential_energy(self, g, ground):
        return self.ball.m * g * (self.ball.pos.y - ground)


def overlapping(ball_1, ball_2):
    return mag(ball_1.pos - ball_2.pos) < ball_1.radius + ball_2.radius


def collide(ball_1, ball_2):
    v1_prime = ball_1.v + 2 * (ball_2.m / (ball_1.m + ball_2.m)) * (ball_1.pos - ball_2.pos) * dot(ball_2.v - ball_1.v, ball_1.pos - ball_2.pos) / dot(ball_1.pos - ball_2.pos, ball_1.pos - ball_2.pos)
    v2_prime = ball_2.v + 2 * (ball_1.m / (ball_1.m + ball_2.m)) * (ball_2.pos - ball_1.pos) * dot(ball_1.v - ball_2.v, ball_2.pos - ball_1.pos) / dot(ball_2.pos - ball_1.pos, ball_2.pos - ball_1.pos)
    ball_1.v = v1_prime
    ball_2.v = v2_prime


# constants
N = 2
g = 9.8
k = 150000
dt = 0.0001

L = 2
L_initial = 1.95
radius = 0.2
m = 1

scene = canvas(width=500, height=500, center=vec(0, -1, 0), background=vec(0.5, 0.5, 0), align='left')
oscillation1 = graph(width=600, align='left', title='energy')
oscillation2 = graph(width=600, align='left', title='averaged energy')

kinetic_curve = gcurve(graph=oscillation1, color=color.blue, width=2, label='<i>kinetic energy</i>')
potential_curve = gcurve(graph=oscillation1, color=color.orange, width=2, label='<i>potential energy</i>')

averaged_kinetic_curve = gcurve(graph=oscillation2, color=color.blue, width=2, label='<i>kinetic energy</i>')
averaged_potential_curve = gcurve(graph=oscillation2, color=color.orange, width=2, label='<i>potential energy</i>')


pendulums = []
for i in range(5):
    pendulums.append(Pendulum(L, radius, 1, vec(-0.8 + 0.4 * i, 0, 0)))
for i in range(N):
    pendulums[i].setHeight(L_initial)


t = 0
total_kinetic_energy = 0
total_potential_energy = 0

counts = 0

while True:
    rate(5000)

    # apply forces
    for i in range(5):
        pendulums[i].applyGravity(g)
        pendulums[i].applySpringForce(k)

    # update physical parameters
    for i in range(5):
        pendulums[i].update(dt)

    # simulate collision
    for i in range(4):
        if overlapping(pendulums[i].ball, pendulums[i + 1].ball):
            collide(pendulums[i].ball, pendulums[i + 1].ball)

    t += dt
    counts += 1

    # calculate kinetic and potential energy
    kinetic_energy = 0
    potential_energy = 0
    for i in range(5):
        kinetic_energy += pendulums[i].kinetic_energy()
        potential_energy += pendulums[i].potential_energy(g, -L)

    # calculate averaged kinetic and potential energy
    total_kinetic_energy += kinetic_energy * dt
    total_potential_energy += potential_energy * dt

    # plotting curves too frequently will cause slow simulation
    if counts % 10 == 0:
        # plot curves
        kinetic_curve.plot(pos=(t, kinetic_energy))
        potential_curve.plot(pos=(t, potential_energy))

        averaged_kinetic_curve.plot(pos=(t, total_kinetic_energy / t))
        averaged_potential_curve.plot(pos=(t, total_potential_energy / t))
