from vpython import *

lines = open('curve.txt', 'r').read().split('\n')

points = []
for line in lines:
	loc = line.split()
	if len(loc) < 3:
		continue
	points.append(vec(float(loc[0]), float(loc[1]), float(loc[2])))

N = len(points)

dt = 1 / 200
velocity = []
for i in range(N):
	velocity.append((points[(i + 1) % N] - points[i]) / dt)

g = vec(0, 0, -9.81)
acc = []
for i in range(N):
	acc.append((velocity[(i + 1) % N] - velocity[i]) / dt + g)


res = ""
file = open('acceleration.txt', 'w')

f = vec(-0.68959, -0.57022, 0.3112)

for i in range(N):
	yv = norm(f - points[i])
	xv = norm(cross(yv, vec(0, 0, 1)))
	zv = cross(xv, yv)

	ax = dot(acc[i], xv)
	ay = dot(acc[i], yv)
	az = dot(acc[i], zv)

	res += f"{ax: 4.6f} {ay: 4.6f} {az: 4.6f}\n"
	# res += f"{acc[i].x: 4.6f} {acc[i].y: 4.6f} {acc[i].z: 4.6f}\n"

file.write(res)