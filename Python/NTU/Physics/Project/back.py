from vpython import *

G = graph(color=color.cyan, xmin=0)
g = gdots(color=color.cyan)

for x, y in zip([0, 2, 4, 6, 8, 10, 12, 14, 16], [1.51, 1.51, 1.49, 1.54, 1.52, 1.48, 1.52, 1.50, 1.54]):
    g.plot(x, y)
