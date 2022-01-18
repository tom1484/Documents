from vpython import *

lines = open('curve.txt', 'r').read().split('\n')

points = []
for line in lines:
	loc = line.split()
	if len(loc) < 3:
		continue
	points.append(vec(float(loc[0]), float(loc[1]), float(loc[2])))


f = vec(-0.68959, -0.57022, 0.3112)
# print(points)


res = ""
file = open('angular_velocity.txt', 'w')

N = len(points)
for i in range(N):
	j = (i + 1) % N
	yv = norm(f - points[i])
	xv = norm(cross(yv, vec(0, 0, 1)))
	zv = cross(xv, yv)
	v = norm(f - points[j])

	x = dot(v, xv)
	y = dot(v, yv)
	z = dot(v, zv)

	xa = atan2(z, y) / (1 / 200)
	ya = 0
	za = -atan2(x, y) / (1 / 200)

	res += f"{xa: 4.6f} {ya: 4.6f} {za: 4.6f}\n"

file.write(res)