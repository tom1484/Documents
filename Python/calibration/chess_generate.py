from vpython import *


scene = canvas(width=600, height=600, background=vec(0.6, 0.6, 0.6))

for i in range(8):
    for j in range(8):
        box(pos=vec(i * 10 - 40, j * 10 - 40, 0), width=0.1, height=10, length=10, color=vec(1, 1, 1) * ((i + j) % 2))
# box(pos=vec(10, 0, 0), width=10, height=10, length=10, color=vec(1, 1, 1))

scene.capture('chess')
