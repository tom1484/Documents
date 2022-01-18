from vpython import *


scene = canvas(width=400, height=400, background=vec(1, 1, 1))


lines = open('curve.txt', 'r').read().split('\n')

cnt = 0
points = []
for line in lines:
	loc = line.split()
	if len(loc) < 3:
		continue
	pos = vec(float(loc[0]), float(loc[1]), float(loc[2]))
	points.append(pos)
	if cnt == 0:
		sphere(pos=pos, radius=0.02, color=color.red)
	elif cnt % 100 == 0:
		sphere(pos=pos, radius=0.01, color=color.black)
	cnt += 1

sphere(pos=vec(-0.68959, -0.57022, 0.3112), radius=0.05, color=color.red)

N = len(points)

arx = arrow(axis=vec(0, 0, 0), width=1, color=color.red)
ary = arrow(axis=vec(0, 0, 0), width=1, color=color.blue)
arz = arrow(axis=vec(0, 0, 0), width=1, color=color.yellow)

f = vec(-0.68959, -0.57022, 0.3112)
for i in range(N):
	rate(100)
	yv = norm(f - points[i])
	xv = norm(cross(yv, vec(0, 0, 1)))
	zv = cross(xv, yv)

	arx.axis = xv
	ary.axis = yv
	arz.axis = zv
	arx.pos = points[i]
	ary.pos = points[i]
	arz.pos = points[i]

# sphere(pos=vec(0, 0, 0), radius=5, color=color.blue)

# yv = vec(1, 1, 1) / (3 ** 0.5)
# xv = norm(cross(yv, vec(0, 0, 1)))
# zv = cross(xv, yv)

# arrow(axis=vec(0, 0, 1), width=1, color=color.red)
# arrow(axis=zv, width=1, color=color.red)
# arrow(axis=yv, width=1, color=color.blue)
# arrow(axis=xv, width=1, color=color.yellow)

