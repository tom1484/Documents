from unionfind import UnionFind
import random as r
import sys

class PhysicalGrid:

    def __init__(self, size):
        self.size = size
        self.elements = UnionFind(size * (size + 2))
        self.matrix = [[1 for i in range(size)] for j in range(size + 2)]
        self.matrix[0][:] = [0] * size
        self.matrix[size + 1][:] = [0] * size
        for i in range(size):
            self.connect(0, 0, 0, i)
        for i in range(size):
            self.connect(self.size + 1, 0, self.size + 1, i)
  

    def getK(self, i, j):
        return i * self.size + j


    def connect(self, i1, j1, i2, j2):
        self.elements.union(self.getK(i1, j1), self.getK(i2, j2))


    def nearby(self, i, j):
        ijs = [{'i': i+1, 'j': j}, {'i': i-1, 'j': j}, {'i': i, 'j': j-1}, {'i': i, 'j': j+1}, {'i': i, 'j': j}]
        for e in ijs:
            if e['i'] < 0:
                e['i'] = 0
            if e['j'] < 0:
                e['j'] = 0
            if e['i'] >= self.size + 2:
                e['i'] = self.size + 1
            if e['j'] >= self.size:
                e['j'] = self.size - 1
        return ijs


    def find(self, i1, j1, i2, j2):
        return self.elements.find(self.getK(i1, j1), self.getK(i2, j2))


    def shoot(self, i, j):
        self.matrix[i][j] = 0
        for e in self.nearby(i, j):
            i1 = e['i']
            j1 = e['j']
            if self.matrix[i1][j1] == 0:
                self.connect(i, j, i1, j1)


    def toString(self):
        graph = []
        for row in self.matrix:
            elements = []
            for item in row:
                if item == 0:
                    elements.append('\u25a1')
                elif item == 1:
                    elements.append('\u25a0')
            graph.append(elements)

        print('\n'.join([' '.join([str(item) for item in row]) for row in graph]))
    
    def simulate(self, p):
        self.elements = UnionFind(self.size * (self.size + 2))
        for i in range(0, n + 2):
            for j in range(0, n):
                k = r.random()
                if (k < p):
                    self.shoot(i, j)
        return self.find(0, 0, n + 1, n - 1)

import numpy as np
import matplotlib.pyplot as plt

import time
import multiprocessing as mp

n = 30
its = 500

def calculate(p, perco):
    o = PhysicalGrid(n)
    perco[p] = 0
    for i in range(its):
        perco[p] += 1 if o.simulate(probs[p]) else 0
    perco[p] /= its

if __name__ == '__main__':
    
    manager = mp.Manager()
    probs = np.arange(0, 1, 0.01)
    perco = manager.dict()
    
    startTime = time.time()
    
    processes = []
    for p in range(probs.shape[0]):
        process = mp.Process(target=calculate, args=(p, perco))
        processes.append(process)
        process.start()
        
    for proc in processes:
        proc.join()
        
    perco = [perco.values()[i] for i in range(probs.shape[0])]
    
    endTime = time.time()  
    print("time :", endTime - startTime)
    
    plt.figure(figsize=(7, 5))
    plt.plot(probs, perco)
    
    plt.show()










