from random import random as rn

N = 2400
print(N)

R = 1000000000

for i in range(N):
    print(f"{int((rn() - 0.5) * 2 * R)} {int((rn() - 0.5) * 2 * R)}")
