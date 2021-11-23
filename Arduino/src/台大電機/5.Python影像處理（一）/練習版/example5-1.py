from PIL import Image
import numpy as np

with Image.open('lenna.png') as img:
	lenna = np.array(img)
	print(lenna.shape)