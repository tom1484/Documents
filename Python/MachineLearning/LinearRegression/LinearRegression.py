import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def normalize(X):
    [nr, nc] = X.shape
    scalar = np.matrix(np.zeros((2, nc)))
    for i in range(nc):
        m = X[:, i].min()
        M = X[:, i].max()
        r = M - m
        if r != 0:
            X[:, i] = (X[:, i] - m) / r
        else:
            m = 0
            r = 1
        scalar[0, i] = m
        scalar[1, i] = r
    return [X, scalar]

def mapFunction(X):
    X = np.concatenate(( \
                        X[:, 0], X[:, 1], np.power(X[:, 1], 2) \
                        ), axis = 1)
    return X

def h(theta, X):
    return X * theta.transpose()

def costFunction(theta, X, y, regRate):
    [nr, nc] = X.shape
    loss = ((h(theta, X) - y).sum() + \
            np.power(theta[1:nc], 2).sum() * regRate) / (2 * nr)
    
    gradient = np.zeros((1, nc))
    t = h(theta, X) - y
    
    gradient[0, 0] = np.multiply(t, X[:, 0]).sum() / nr
    gradient[0, 1:nc] = (t.transpose() * X[:, 1:nc] + theta[0, 1:nc] * regRate) / nr;
    
    return [loss, gradient]

def gradientDescent(theta, X, y, cycle, learningRate, regRate):
    for i in range(cycle):
        [loss, gradient] = costFunction(theta, X, y, regRate)
        theta -= learningRate * gradient
    return theta

def predict(x):
    theta = np.matrix(pd.read_excel('theta.xlsx'))
    inputScalar = np.matrix(pd.read_excel('inputScalar.xlsx'))
    outputScalar = np.matrix(pd.read_excel('outputScalar.xlsx'))
    
    x = np.matrix(x)
    [nr, nc] = x.shape
    
    x = np.concatenate((np.matrix(np.ones((nr, 1))), x), axis = 1)
    x = np.divide(x - inputScalar[0, :], inputScalar[1, :])
    x = mapFunction(x)
    
    return h(theta, x) * outputScalar[1] + outputScalar[0]

X = np.matrix(pd.read_excel('input.xlsx'))
[nr, nc] = X.shape

y = X[:, nc - 1:nc]
X = X[:, 0:nc - 1]
X = np.concatenate((np.ones((nr, 1)), X), axis = 1)

[_X, inputScalar] = normalize(X.copy())
_X = mapFunction(_X)
[_y, outputScalar] = normalize(y.copy())
[_nr, _nc] = _X.shape

cycle = 1000
learningRate = 0.5
regRate = 0

theta = gradientDescent(np.zeros((1, _nc)), _X, _y, cycle, learningRate, regRate)

pd.DataFrame(theta).to_excel('theta.xlsx')
pd.DataFrame(inputScalar).to_excel('inputScalar.xlsx')
pd.DataFrame(outputScalar).to_excel('outputScalar.xlsx')

r = np.matrix(np.arange(0, 100, 0.5)).transpose()
plt.plot(r, predict(r), X[:, 1], y, 'ro', markersize = 1)




