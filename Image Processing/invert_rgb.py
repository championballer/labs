import cv2
import numpy as np

def invertor(value):
	return 255-value

img=cv2.imread('flower1.jpg',cv2.IMREAD_COLOR)
out=np.zeros(img.shape)
for i in range(img.shape[0]):
	for j in range(img.shape[1]):
		for k in range(img.shape[2]):
			out[i,j,k]=invertor(img[i,j,k])

out=np.array(out, dtype = np.uint8)

cv2.imshow('sample_image', img)
cv2.imshow('sample_image_inverted', out)
cv2.waitKey(0)
cv2.destroyAllWindows()


