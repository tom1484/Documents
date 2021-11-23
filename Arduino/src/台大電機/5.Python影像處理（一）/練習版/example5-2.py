from PIL import Image
import numpy as np

with Image.open('lenna.png') as img:
	lenna = np.array(img)
	print(lenna.shape)

import scipy.misc

lenna_r = np.zeros(lenna.shape)
lenna_r[:,:,0] = lenna[:,:,0]

lenna_g = np.zeros(lenna.shape)
lenna_g[:,:,1] = lenna[:,:,1]

lenna_b = np.zeros(lenna.shape)
lenna_b[:,:,2] = lenna[:,:,2]

scipy.misc.imsave('lenna_r.jpg',lenna_r)
scipy.misc.imsave('lenna_g.jpg',lenna_g)
scipy.misc.imsave('lenna_b.jpg',lenna_b)