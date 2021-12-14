import numpy as np
from vpython import *
A, N = 0.10, 50
size, m, k, d = 0.06, 0.1, 10.0, 0.4
# scene = canvas(title='Spring Wave', width=800, height=300, background=vec(0.5,0.5,0), center = vec((N-1)*d/2, 0, 0))
# balls = [sphere(radius=size, color=color.red, pos=vector(i*d, 0, 0), v=vector(0,0,0)) for i in range(N)] #3
# springs = [helix(radius = size/2.0, thickness = d/15.0, pos=vector(i*d, 0, 0), axis=vector(d,0,0)) for i in range(N-1)] #3
#1

# c = curve([vector(i*d, 1.0, 0) for i in range(N)], color=color.black)
# ball_pos, ball_orig, ball_v, spring_len = np.arange(N)*d, np.arange(N)*d, np.zeros(N), np.ones(N)*d #5

oscillation = graph(height=400, width=1000, align='left')
funct1 = gcurve(graph=oscillation, color=color.blue, width=4)

def calculation(n):

    Unit_K = 2 * pi/(N*d)
    Wavevector = n * Unit_K
    phase = Wavevector * arange(N) * d
    ball_pos, ball_orig, ball_v, spring_len = np.arange(N)*d + A*np.sin(phase), np.arange(N)*d, np.zeros(N), np.ones(N)*d

    prev_A, curr_A, counter = 0, 0, 0

    t, dt = 0, 0.0003
    while True:
        rate(10000)
        t += dt
        # ball_pos[0] = A * sin(omega * t ) #4

        spring_len[:-1] = ball_pos[1:] - ball_pos[:-1]
        spring_len[-1] = (ball_pos[0] + N * d) - ball_pos[-1]

        ball_v[1:] += ((spring_len[1:] - d) * k/m - (spring_len[:-1] - d) * k/m) * dt
        ball_v[0] += ((spring_len[0] - d) * k/m - (spring_len[-1] - d) * k/m) * dt
        ball_pos += ball_v*dt
        # for i in range(N): balls[i].pos.x = ball_pos[i] #3
        # for i in range(N-1): #3
            # springs[i].pos = balls[i].pos #3
            # springs[i].axis = balls[i+1].pos - balls[i].pos #3
        ball_disp = ball_pos - ball_orig

        # for i in range(N):
        #     c.modify(i, y=ball_disp[i] * 4 + 1)

        max_cnt = 2
        next_A = np.sum(ball_disp ** 2)
        if prev_A > curr_A and next_A > curr_A:
            counter += 1
            if counter == max_cnt:
                # for i in range(N):
                #     c.modify(i, y=1)
                return Wavevector, 2 * pi / (t * 4 / (2 * max_cnt - 1))
        prev_A, curr_A = curr_A, next_A


# funct1.plot(pos=(0, 0))
for n in range(1, N // 2):
    wave_vec, ang_freq = calculation(n)
    funct1.plot(pos=(wave_vec, ang_freq))

