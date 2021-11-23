arr = []
file = open("test5.txt", 'r')

for i in range(200):
    arr.append(float(file.readline().split(' ')[2][:-1]))

import matplotlib
import matplotlib.pyplot as plt

font = {'family' : 'normal',
        'size'   : 20}
matplotlib.rc('font', **font)

plt.figure(figsize=(15, 10))

plt.plot(arr)

plt.xlabel('episode', fontsize=22)
plt.ylabel('reward', fontsize=22)