from PIL import Image
import numpy as np
import scipy.misc
import math

with Image.open('lenna.png') as img:
    lenna = np.array(img)

lennaReduceRed = lenna
lennaReduceRed[:,:,0] = lennaReduceRed[:,:,0] / 2
#Write your code here

scipy.misc.imsave('lenna_reduce_red.jpg',lennaReduceRed)

lennaGray = np.zeros(lenna.shape)
ave = np.zeros(lenna.shape[0:2])
for i in range(ave.shape[0]):
    for j in range(ave.shape[1]):
        ave[i,j] = math.floor((lenna[i,j,0] + lenna[i,j,1] + lenna[i,j,2]) / 3)
lennaGray[:,:,0] = ave
lennaGray[:,:,1] = ave
lennaGray[:,:,2] = ave
#Write your code here

scipy.misc.imsave('lenna_gray.jpg',lennaGray)

