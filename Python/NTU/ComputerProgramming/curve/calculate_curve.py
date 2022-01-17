from vpython import vec
import numpy as np

lines = open('curve_o.txt', 'r').read().split('\n')
points = []
slices = []


for line in lines:
	loc = line.split()
	points.append(vec(float(loc[0]), -float(loc[2]), float(loc[1])))


N = len(points)
for i in range(N):
	j = (i + 1) % N
	for t in range(200):
		slices.append((points[j] - points[i]) * (t / 200) + points[i])


res = ""
f = open('curve.txt', 'w')
for T in range(100):
	for dt in range(200):
		t = T + dt / 200
		p = slices[int(t / 100 * 57600)]
		res += f"{p.x: 4.6f} {p.y: 4.6f} {p.z: 4.6f}\n"
f.write(res)