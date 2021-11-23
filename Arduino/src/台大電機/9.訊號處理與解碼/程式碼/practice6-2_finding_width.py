from PIL import Image
import numpy as np
import cv2
import scipy.misc


with Image.open('111.jpg') as img:
 	img = np.array(img)
 	picture = img[:,:,0]
my_list=[]
axiss=[]
print(picture.shape)
pixel=1
maxi=0

test=1
while test<50:
	one = np.ones((test,10),np.float32)
	minusone=one*-1
	lap=np.vstack((one,minusone))/test/10
	lap2=np.vstack((lap,lap))/2
	lap3=np.vstack((lap,lap2))/2
	result = cv2.filter2D(picture,-1,lap3)
	maxx=np.max(result)
	if maxx>maxi:
		pixel=test
		maxi=maxx
	my_list.append(maxx)
	axiss.append(test)
	print (maxx,test)
	#scipy.misc.imsave('img'+str(test)+'.jpg',result)
	test=test+1

print (pixel)



