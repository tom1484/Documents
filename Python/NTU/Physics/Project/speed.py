import time
import numpy as np
import cupy as cp

cp.cuda.Device(0).use()

### Numpy and CPU
s = time.time()
x_cpu = np.ones((500,500,500)) * np.ones((500,500,500)) * np.ones((500,500,500)) * np.ones((500,500,500))
e = time.time()
print(e - s)### CuPy and GPU
s = time.time()
x_gpu = cp.ones((500,500,500)) * cp.ones((500,500,500)) * cp.ones((500,500,500)) * cp.ones((500,500,500))
e = time.time()
print(e - s)