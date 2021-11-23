import copy

## Generate a contour plot
# Import some other libraries that we'll need
# matplotlib and numpy packages must also be installed
import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import random
import math

# define objective function
def f(x):
    x1 = x.xs[0]
    x2 = x.xs[1]
    obj = 0.2 + x1**2 + x2**2 - 0.1*math.cos(6.0*3.1415*x1) - 0.1*math.cos(6.0*3.1415*x2)
    return obj

# Start location
x_start = [0.8, -0.5]

# Design variables at mesh points
i1 = np.arange(-1.0, 1.0, 0.01)
i2 = np.arange(-1.0, 1.0, 0.01)
x1m, x2m = np.meshgrid(i1, i2)
fm = np.zeros(x1m.shape)
for i in range(x1m.shape[0]):
    for j in range(x1m.shape[1]):
        fm[i][j] = 0.2 + x1m[i][j]**2 + x2m[i][j]**2 \
             - 0.1*math.cos(6.0*3.1415*x1m[i][j]) \
             - 0.1*math.cos(6.0*3.1415*x2m[i][j])

# Create a contour plot
plt.figure()
# Specify contour lines
#lines = range(2,52,2)
# Plot contours
CS = plt.contour(x1m, x2m, fm)#,lines)
# Label contours
plt.clabel(CS, inline=1, fontsize=10)
# Add some text to the plot
plt.title('Non-Convex Function')
plt.xlabel('x1')
plt.ylabel('x2')

##################################################
#(1+1)-ES
##################################################
WINDOW_SIZE = 50

class ES_1p1:
    def __init__(self, state, func, stepSize):
        self.func = func
        self.state = state
        self.stepSize = stepSize
        self.nfe = 0
        self.record = [0] * WINDOW_SIZE
        self.recordIndex = 0
        self.generation = 0

        self.evaluate(self.state)
    
    def evaluate(self, state):
        self.nfe += 1
        state.fitness = self.func(state)
    
    def oneRun(self):
        newstate = self.state.mutation(self.stepSize)
        self.evaluate(newstate)
        
        if newstate.fitness < self.state.fitness:
            self.state = newstate
            self.record[self.recordIndex] = 1
        else:
            self.record[self.recordIndex] = 0
        
        count = sum(self.record)
        if count * 5 > WINDOW_SIZE:
            self.stepSize /= 0.817
        elif count * 5 < WINDOW_SIZE:
            self.stepSize *= 0.817

        self.generation += 1
        self.recordIndex = (self.recordIndex + 1) % WINDOW_SIZE

class XS:
    def __init__(self, xs):
        self.xs = xs          # xs is a list
        #self.fitness = 0
    
    def mutation(self, var):
        new_xs = copy.deepcopy(self.xs)
        for i in range(len(new_xs)):
            new_xs[i] += var * random.gauss(0, 2)
            # Clip to upper and lower bounds
            new_xs[i] = max(min(new_xs[i],1.0),-1.0)
        
        return XS(new_xs)

def test_func(s):
    return sum([x ** 2 for x in s.xs])

# number of iterations
m = 500

if __name__ == "__main__":
    xs = x_start
    s = XS(xs)

    record = np.zeros((m+1,2))
    record[0] = x_start

    fs = np.zeros(m+1)

    es = ES_1p1(s, f, 1.0)
    for t in range(m):
        es.oneRun()
        record[t+1] = es.state.xs
        fs[t] = es.state.fitness

    #    print(es.state.fitness, es.stepSize, es.recordIndex, sum(es.record))

    # print solution
    print('Best solution: ' + str(es.state.xs))
    print('Best objective: ' + str(es.state.fitness))
    plt.plot(record[:,0],record[:,1],'y-o')
    plt.plot(record[m,0],record[m,1],'r-o')
    plt.savefig('contour.png')


    fig = plt.figure()
    ax1 = fig.add_subplot(211)
    ax1.plot(fs,'r.-')
    ax1.legend(['Objective'])
    ax2 = fig.add_subplot(212)
    ax2.plot(record[:,0],'b.-')
    ax2.plot(record[:,1],'g--')
    ax2.legend(['x1','x2'])

# Save the figure as a PNG
#plt.savefig('iterations.png')

plt.show()

