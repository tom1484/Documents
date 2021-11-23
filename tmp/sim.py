from matplotlib import pyplot as plt

a_x1 = []
a_x2 = []

x1 = 1
x2 = 1

v1 = 0
v2 = 0

a1 = 0
a2 = 0

dt = 0.001

m = 1
k = 1

for i in range(100000):
    x1 += dt * v1
    x2 += dt * v2

    v1 += a1 * dt
    v2 += a2 * dt

    a1 = (-3 * x1 + 2 * x2) * k / m
    a2 = (2 * x2 - 5 * x2) * k / m

    a_x1.append(x1)
    a_x2.append(x2)

time = [i * dt for i in range(100000)]

plt.plot(time, a_x1)
