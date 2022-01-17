from vpython import *


scene = canvas(width=800, height=800, background=vec(1, 1, 1))


# lines = open('curve.txt', 'r').read().split('\n')

# cnt = 0
# for line in lines:
# 	loc = line.split()
# 	if len(loc) < 3:
# 		continue
# 	pos = vec(float(loc[0]), float(loc[1]), float(loc[2]))
# 	if cnt == 0:
# 		sphere(pos=pos, radius=2, color=color.red)
# 	else:
# 		sphere(pos=pos, radius=0.5, color=color.black)
# 	cnt += 1

# sphere(pos=vec(-68.959, -57.022, 31.12), radius=5, color=color.red)

# sphere(pos=vec(0, 0, 0), radius=5, color=color.blue)

yv = vec(1, 1, 1) / (3 ** 0.5)
xv = norm(cross(yv, vec(0, 0, 1)))
zv = cross(xv, yv)

arrow(axis=vec(0, 0, 1), width=1, color=color.red)
arrow(axis=zv, width=1, color=color.red)
arrow(axis=yv, width=1, color=color.blue)
arrow(axis=xv, width=1, color=color.yellow)

