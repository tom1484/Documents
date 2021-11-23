from PIL import Image
import numpy as np
import scipy.misc

with Image.open('Lenna.png') as img:
 	img = np.array(img)
 	#lennaGray = img[:,:,0]

lennaGrayHalf = np.zeros(img.shape)
#lennaGrayHist = cv2.equalizeHist(lennaGrayHalf)
scipy.misc.imsave('lenna_gray_half.jpg',lennaGrayHalf)
#scipy.misc.imsave('lenna_gray_hist.jpg',lennaGrayHist)