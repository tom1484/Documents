from PIL import Image
import numpy as np
import opencv
import scipy.misc
import cv2
from numpy import savetxt


with Image.open('111.jpg') as img:
 	img = np.array(img)
 	picture = img[:,:,0]
my_list=[]	#for debug
axiss=[]	#for debug
pixel=1
maxi=0

#finding how many pixels in each line
pixel=18

#Find the brightest line to decode
bright=0
total=0
keep=0
for i in range(0,3264,1):
	for j in range(0,2448):
		total+=picture[j,i]
	if(total>keep):
		bright=i
		keep=total
	total=0
print ('The brightes line is',bright,'.')

pic = cv2.equalizeHist(picture)

#Decode 0 or 1
a=""
for i in range(0,2448,pixel):
	#print(pic[i,bright])
	if pic[i,bright]<150:
		a+=str(0)
	else :
		a+=str(1)
print('Right ans  0010101000011111011000101010000111110110001010100001111101100010101000011111011000101010000111110110001010100001111101100010101000011111')
print('You decode',a)
