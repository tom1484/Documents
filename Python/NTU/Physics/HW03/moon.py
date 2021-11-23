from vpython import *


G = 6.673E-11

mass = {'earth': 5.97E24, 'moon': 7.36E22, 'sun': 1.99E30}
radius = {'earth': 6.371E6 * 10, 'moon': 1.317E6 * 10, 'sun': 6.95E8 * 10}  # 10 times larger for better view
earth_orbit = {'r': 1.495E11, 'v': 2.9783E4}
moon_orbit = {'r': 3.84E8, 'v': 1.022E3}
theta = 5.145 * pi/180.0


# gravitational force
def G_force(m1, m2, pos_vec):
    return -G * m1 * m2 / mag2(pos_vec) * norm(pos_vec)


class as_obj(sphere):

    def kinetic_energy(self):
        return 0.5 * self.m * mag2(self.v)

    def potential_energy(self):
        return - G * mass['sun'] * self.m / mag(self.pos)


scene = canvas(width=800, height=800, background=vector(0.5, 0.5, 0))

cm_dis = (moon_orbit['r'] * mass['moon']) / (mass['earth'] + mass['moon'])
earth = as_obj(pos=vector(-cm_dis, 0, 0), m=mass["earth"], radius=radius["earth"], make_trail=False, color=color.blue)
moon = as_obj(pos=vector(moon_orbit['r'] - cm_dis, 0, 0), m=mass["moon"], radius=radius["moon"], make_trail=False)

# tilted orbiting
moon.pos.x *= cos(theta)
moon.pos.y = -sin(theta) * (moon_orbit['r'] - cm_dis)
earth.pos.x *= cos(theta)
earth.pos.y = sin(theta) * cm_dis

moon.v = vec(0, 0, -moon_orbit['v'])
earth.v = vec(0, 0, moon_orbit['v'] * moon.m / earth.m)

# start simulation
scene.center = vec(0, 0, 0)
dt = 60*60*6/12
t = 0

while True:
    rate(1000)
    moon.a = G_force(earth.m, moon.m, moon.pos - earth.pos) / moon.m
    earth.a = G_force(earth.m, moon.m, earth.pos - moon.pos) / earth.m

    moon.v += dt * moon.a
    earth.v += dt * earth.a
    moon.pos += dt * moon.v
    earth.pos += dt * earth.v


