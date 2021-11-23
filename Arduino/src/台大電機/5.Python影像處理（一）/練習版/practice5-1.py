from PIL import Image
import numpy as np

with Image.open('lenna.png') as img:
	lenna = np.array(img)
	print(lenna.shape)

import scipy.misc

lenna_r = np.zeros(lenna.shape)
lenna_b = np.zeros(lenna.shape)
lenna_pink = np.zeros(lenna.shape)

lenna_r[:,:,0] = lenna[:,:,0]
lenna_b[:,:,2] = lenna[:,:,2]
lenna_pink = lenna_r + lenna_b
#Write your code here

scipy.misc.imsave('lenna_pink.jpg',lenna_pink)