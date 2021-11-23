from random import random

N = 10000
R = 1000000000

print(N)

def get():
    r = random() - 0.5
    return int(r * 2 * R)

for i in range(N):
    print(f"{get()} {get()}")
