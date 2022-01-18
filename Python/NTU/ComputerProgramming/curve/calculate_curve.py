from vpython import *
import numpy as np

lines = open('curve-1.txt', 'r').read().split('\n')
points = []
slices = []


for line in lines:
	loc = line.split()
	points.append(vec(-float(loc[1]), float(loc[0]), float(loc[2])))


N = len(points)
L = 0
for i in range(N):
	L += mag(points[(i + 1) % N] - points[i])
# print(L)

for i in range(N):
	j = (i + 1) % N
	for t in range(10):
		slices.append((points[j] - points[i]) * (t / 10) + points[i])

N = len(slices)

dis = []
for i in range(1, N):
	j = (i + 1) % N
	dis.append(mag(slices[j] - slices[i]))

dL = L / 20000
q = 0
l = 0

res = ""
f = open('curve.txt', 'w')
for T in range(100):
	for dt in range(200):
		d = (T * 200 + dt) * dL
		while l < d:
			l += dis[q]
			q += 1

		# print(d, l, q)
		p = slices[q]
		res += f"{p.x: 4.6f} {p.y: 4.6f} {p.z: 4.6f}\n"
f.write(res)