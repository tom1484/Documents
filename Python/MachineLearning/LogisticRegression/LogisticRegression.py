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
                        X[:, 0], X[:, 1], X[:, 2], np.multiply(X[:, 1], X[:, 2]) \
                        ), axis = 1)
    return X

def multiClassifier(y):
    [nr, nc] = y.shape
    dataSetNum = int(y.max() + 1)
    _y = np.matrix(np.zeros((nr, dataSetNum)))
    
    for s in range(dataSetNum):
        _y[:, s] = y
        for i in range(nr):
            if y[i, 0] == s:
                _y[i, s] = 1
            else:
                _y[i, s] = 0

    return [dataSetNum, _y]

def h(theta, X):
    return 1 / (1 + np.exp(-X * theta.transpose()))

def costFunction(theta, X, y, regRate):
    [nr, nc] = X.shape
    dataSetNum = theta.shape[0]
    
    loss = (
            ( \
             np.multiply(np.log(h(theta, X)), y) + \
             np.multiply(np.log(1 - h(theta, X)), (1 - y))
            ).sum(axis = 0) * -1 + \
            np.power(theta[2:nc], 2).sum() * regRate / 2 \
           ) / nr
    
    gradient = np.zeros((dataSetNum, nc))
    t = h(theta, X) - y
    
    gradient[:, 0:1] = t.transpose() * X[:, 0] / nr
    gradient[:, 1:nc] = (t.transpose() * X[:, 1:nc] + theta[0, 1:nc] * regRate) / nr;
    
    return [loss, gradient]

def gradientDescent(theta, X, y, cycle, learningRate, regRate):
    for i in range(cycle):
        [loss, gradient] = costFunction(theta, X, y, regRate)
        theta -= learningRate * gradient
    return theta

def predict(x):
    theta = np.matrix(pd.read_excel('theta.xlsx'))
    inputScalar = np.matrix(pd.read_excel('inputScalar.xlsx'))
    
    x = np.matrix(x)
    [nr, nc] = x.shape
    
    x = np.concatenate((np.matrix(np.ones((nr, 1))), x), axis = 1)
    x = np.divide(x - inputScalar[0, :], inputScalar[1, :])
    x = mapFunction(x)
    
    p = h(theta, x)
    retval = p.argmax(axis = 1)
    
    return retval

X = np.matrix(pd.read_excel('input.xlsx'))
[nr, nc] = X.shape

y = X[:, nc - 1:nc]
X = X[:, 0:nc - 1]
_X = np.concatenate((np.ones((nr, 1)), X), axis = 1)

[_X, inputScalar] = normalize(_X)
_X = mapFunction(_X)
[_nr, _nc] = _X.shape

[dataSetNum, _y] = multiClassifier(y);

cycle = 1000
learningRate = 1
regRate = 0

theta = gradientDescent(np.zeros((dataSetNum, _nc)), _X, _y, cycle, learningRate, regRate)

pd.DataFrame(theta).to_excel('theta.xlsx')
pd.DataFrame(inputScalar).to_excel('inputScalar.xlsx')




