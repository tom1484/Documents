from PIL import Image
import numpy as np
import cv2
import scipy.misc

with Image.open('lenna_gray.jpg') as img:
 	img = np.array(img)
 	lennaGray = img[:,:,0]

sobelY = np.array([(-1,-2,-1),(0,0,0),(1,2,1)])
sobelX = np.array([(-1,0,1),(-2,0,2),(-1,0,1)])
laplacian2 = np.array([(1,1,1),(1,-8,1),(1,1,1)])
laplacian1 = np.array([(0,1,0),(1,-4,1),(0,1,0)])

lennaY = cv2.filter2D(lennaGray, -1, sobelY)
scipy.misc.imsave('lenna_sobel_y.jpg',lennaY)

lennaX = cv2.filter2D(lennaGray, -1, sobelX)
scipy.misc.imsave('lenna_sobel_x.jpg',lennaX)

lennaSobel = lennaX + lennaY
scipy.misc.imsave('lenna_sobel.jpg',lennaSobel)

lennaLap1 = cv2.filter2D(lennaGray, -1, laplacian1)
lennaLap1 = scipy.misc.imsave('lenna_laplacian1.jpg',lennaLap1)

lennaLap2 = cv2.filter2D(lennaGray, -1, laplacian2)
lennaLap2 = scipy.misc.imsave('lenna_laplacian2.jpg',lennaLap2)