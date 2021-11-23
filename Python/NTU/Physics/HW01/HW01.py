from vpython import *


# define physics constants
g = 9.8
C = 0.9
dt = 0.001

height = 15.0

# create scenes
scene_ball = canvas(width=800, height=800, align='left',
                    center=vec(-7.5, height / 2, 0),
                    background=vec(0.5, 0.5, 0))
oscillation = graph(width=1000, height=600, align='right')

# create floor
floor = box(pos=vec(-7.5, -0.01, 0), axis=vec(1, 0, 0),
            size=vec(20, 0.01, 10),
            color=color.blue)

# create ball
radius = 0.25
ball = sphere(radius=radius,
              canvas=scene_ball, color=color.red,
              make_trail=True, trail_radius=radius / 3)

theta = pi / 4
ball.pos = vec(-15, radius, 0)
ball.v = vec(20 * cos(theta), 20 * sin(theta), 0)

# create velocity arrow
arr = arrow(color=color.green, shaftwidth=0.10)

# create graph
func = gcurve(graph=oscillation,
              color=color.green, width=2)

# initialize variables
t = 0
hits = 0
dis = 0
h_pos = ball.pos * 1

while hits < 3:
    rate(1000)

    # update ball parameters
    ball.pos += ball.v * dt
    ball.v += vec(0, -g, 0) * dt - C * ball.v * dt

    # update velocity arrow
    arr.pos = ball.pos
    arr.axis = ball.v * 0.5

    if ball.pos.y < radius and ball.v.y < 0:
        hits += 1
        ball.v.y *= -1

    # update graph
    t += dt
    func.plot(pos=(t, ball.v.mag))

    # update highest position
    if ball.pos.y > h_pos.y:
        h_pos = ball.pos * 1

    # update distance
    dis += (ball.v * dt).mag

# create a label pointing the highest position
label(text=f"Highest Height = {h_pos.y: .3f}",
      pos=h_pos, yoffset=50, xoffset=0,
      font="sans", color=vector(1, 1, 1),
      linecolor=vector(0, 1, 1), linewidth=2)

# show displacement and distance travelled
displace = ball.pos - vec(-15, radius, 0)
label(text=f"Displacement = ({displace.x: .3f}, {displace.y: .3f}, {displace.z: .3f})",
      pos=vec(-7.5, height / 2, 0),
      yoffset=350, xoffset=-250,
      font="sans", color=vector(1, 1, 1),
      linecolor=vector(0, 1, 1), linewidth=0.0001)

label(text=f"Distance Travelled = {dis: .3f}",
      pos=vec(-7.5, height / 2, 0),
      yoffset=320, xoffset=-250,
      font="sans", color=vector(1, 1, 1),
      linecolor=vector(0, 1, 1), linewidth=0.0001)
