import cv2
import numpy as np

img=cv2.imread('flower1.jpg',cv2.IMREAD_COLOR)

out=np.zeros(img.shape)

for k in range(img.shape[2]):
	int_min=np.amin(img[:,:,k])
	int_max=np.amax(img[:,:,k])
	x1=int_min
	y1=0
	x2=int_max
	y2=255
	m=float(y2-y1)/float(x2-x1)
	out[:,:,k]=img[:,:,k]*m
	out[:,:,k]=out[:,:,k]-(x1*m)


out=np.array(out, dtype = np.uint8)
print(img)
print(out)
cv2.imshow('sample_image', img)
cv2.imshow('sample_image_contrast', out)
cv2.waitKey(0)
cv2.destroyAllWindows()