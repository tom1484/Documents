from PIL import Image
import numpy as np
import cv2
import scipy.misc

with Image.open('lenna_gray.jpg') as img:
 	img = np.array(img)
 	lennaGray = img

kernel1 = np.ones((20,20),np.float32)/400
lennaBlur1 = cv2.filter2D(lennaGray,-2,kernel1)
lennaBlur2 = cv2.filter2D(lennaBlur1,-1,kernel1)
lennaBlur3 = cv2.filter2D(lennaBlur2,-1,kernel1)
scipy.misc.imsave('lenna_blur1.jpg',lennaBlur1)
scipy.misc.imsave('lenna_blur2.jpg',lennaBlur2)
scipy.misc.imsave('lenna_blur3.jpg',lennaBlur3)

