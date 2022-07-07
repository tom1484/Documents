from vpython import *
from random import random


scene = canvas(width=800, height=800, align='left', background=vector(0.2, 0.2, 0))

back = box(canvas=scene, length=300, height=158, width=0.9, pos=vec(150, 79, 0), color=color.white)

aruco = [
    box(canvas=scene, length=50, height=50, width=1, pos=vec(12.5+25, 12.5+25, 0), color=color.black),
    box(canvas=scene, length=50, height=50, width=1, pos=vec(12.5+25, 12.5+25+83, 0), color=color.black),
    box(canvas=scene, length=50, height=50, width=1, pos=vec(12.5+25+225, 12.5+25, 0), color=color.black),
    box(canvas=scene, length=50, height=50, width=1, pos=vec(12.5+25+225, 12.5+25+83, 0), color=color.black)
]

target = cylinder(canvas=scene, radius=50, pos=vec(150+(random()-0.5)*50, 79+(random()-0.5)*50, -0.5), axis=vec(0, 0, 1), color=color.green)

scene.center = vec(150, 79, 0)
