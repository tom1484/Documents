from random import random

N = 100000
Q = 1000000
R = 1000000000
R2 = 10000

s = str(N) + " " + str(Q) + "\n"
for i in range(N):
    s += str(int(random() * R + 1)) + " "

s += "\n"

for i in range(Q):
    com = int(random() * 3 + 1)
    t = str(com) + " "
    
    l = int(random() * N + 1)
    r = int(random() * N + 1)
    if r < l:
        l, r = r, l
    t += str(l) + " " + str(r) + " "

    if com == 1:
        t += str(int(random() * R2 + 1))        
    if com == 3:
        t += str(int(random() * R + 1))        

    s += t + "\n";

print(s)
