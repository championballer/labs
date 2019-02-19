import cv2
import numpy as np

img=cv2.imread('flower1.jpg',0)
out=np.copy(img)

i=1

while i<out.shape[0]:
	out=np.delete(out,(i),axis=0)
	i=i+1
j=1

while j<out.shape[1]:
	out=np.delete(out,(j),axis=1)
	j=j+1

out=np.array(out, dtype = np.uint8)

cv2.imshow('image', img)
cv2.imshow('shrinked', out)
cv2.waitKey(0)
cv2.destroyAllWindows()