from PIL import Image
import numpy as np
import cv2
import scipy.misc
import matplotlib.pyplot as plt

with Image.open('25_18.jpg') as img:
 	img = np.array(img)
 	picture = img[:,:,0]

w = 18

one = np.ones((w, 10))
minusone = one * -1

def stack(a, n):
    global w
    res = a
    for i in range(n - 1):
        res = np.vstack((res, a))
    return res

kernel = stack(np.vstack((one, minusone)), 3) / w / 10 / 3

res = cv2.filter2D(picture, -1, kernel)
scipy.misc.imsave('res.jpg', res)