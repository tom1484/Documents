from PIL import Image
import numpy as np
import cv2
import scipy.misc

with Image.open('lenna_gray.jpg') as img:
	lennaGray = np.array(img)[:,:,0]

with Image.open('eye.jpg') as img:
	kernel = np.array(img)[:,:,0].astype(float)

kernel = kernel/30000
kernel -= np.sum(kernel)/(kernel.shape[0]*kernel.shape[1])

findEye = cv2.filter2D(lennaGray,-1,kernel)
scipy.misc.imsave('find_eye.jpg',abs(findEye))