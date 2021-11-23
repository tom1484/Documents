from random import random as rd

N = 1000
M = 80

print(f"{N} {M}")

char = ['A', 'U', 'G', 'C']

def getRna():
    s = ""
    for _ in range(M):
        r = int(rd() * 5) - 1
        if r >= 0:
            s += char[r]
        else:
            s += '@'

    return s

prt = [i for i in range(N)]

def find(x):
    if x != prt[x]:
        prt[x] = find(prt[x])
        return prt[x]
    else:
        return x

def union(x, y):
    prt[find(x)] = find(y)

for i in range(N):
    if i > 0:
        cand = []
        for j in range(N):
            if find(j) != find(i):
                cand.append(j)
        p = cand[int(rd() * len(cand))]
        union(p, i)
    else:
        p = i

    print(f"{i + 1} {p + 1} {getRna()}")
