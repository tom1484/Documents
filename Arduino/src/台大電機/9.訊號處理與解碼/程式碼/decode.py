from PIL import Image
import numpy as np
import cv2
import scipy.misc
import csv
from numpy import savetxt


with Image.open('111.jpg') as img:
 	img = np.array(img)
 	picture = img[:,:,0]

pixel=1
maxi=0

#finding how many pixels in each line
test=5
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
	test=test+1

print ('Pixel width is:',pixel)

#pixel=36

#Finding the bightest line to decode
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
print ('The brightes row is',bright)


pic = cv2.equalizeHist(picture)

#Decode 0 or 1
a=""
for i in range(0,2448,pixel):
	if pic[i,bright]<150:
		a+=str(0)
	else :
		a+=str(1)
print ('Decode number:',a)

#Decode header and find the answer
k=0
j=0
tenth=0
oneth=0
ans=0
RLL = {
	'11001' : 0, '11010' : 1, '11101' : 2, '11110' : 3,
	'10010' : 4, '01010' : 5, '10110' : 6, '01110' : 7,
	'11011' : 8, '01001' : 9, '10101' : 10, '01101' :11,
	'10011' : 12, '01011' : 13, '10111' : 14, '01111' : 15
};
while k>=0:

	k=a.find('10101000',j)
	if k==-1:
		break;
	if k+18>len(a):
		break;
	try:
		ans=RLL[a[k+8:k+13]]+16*RLL[a[k+13:k+18]]
		print (ans)
	except:
		print ('RLL error')
	j=k+1