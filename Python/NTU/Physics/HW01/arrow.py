# import vpython as vp
from vpython import scene, canvas
from vpython import vec, arrow, color


scene = canvas(width=800, height=800, 
        background=vec(0.5, 0.5, 0))
a = arrow(color=color.green, shaftwidth=0.05)
b = arrow(color=color.blue, shaftwidth=0.05)

a.pos = vec(1, 1, 0)
a.axis = vec(1, -1, 0)
b.pos = a.pos + a.axis
b.axis = vec(2, 1, 0)

c = arrow(color=color.yellow, shaftwidth=0.05)
c.pos = a.pos
c.axis = a.axis + b.axis

