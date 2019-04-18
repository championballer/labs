import numpy as np
import cv2

def pad(img,shp):
	p=np.zeros((shp[0]+2,shp[1]+2))
	p[1:-1,1:-1]=np.copy(img)
	p[0,1:-1],p[-1,1:-1]=img[0],img[-1]
	p[1:-1,0],p[1:-1,-1]=img[:,0],img[:,-1]
	p[0,0],p[0,-1]=img[0,0],img[0,-1]
	p[-1,0],p[-1,-1]=img[-1,0],img[-1,-1]
	return p

img=cv2.imread('Black_Circle.jpg',0)
shp=img.shape
shpm=(3,3)
prewitt_x=np.array([[-1,0,1],[-1,0,1],[-1,0,1]])
prewitt_y=np.array([[-1,-1,-1],[0,0,0],[1,1,1]])
e_list=[]
p=pad(img,shp)
out=np.zeros(shp)
for i in range(shp[0]):
	for j in range(shp[1]):
		temp=np.multiply(p[i:i+shpm[0],j:j+shpm[1]],prewitt_x)
		dx=temp.sum()
		temp=np.multiply(p[i:i+shpm[0],j:j+shpm[1]],prewitt_y)
		dy=temp.sum()
		if dy!=0 or dx!=0:
			out[i,j]=255
			if dx==0:
				rad=np.arctan(float("inf"))
			else:
				rad=np.arctan(dy/dx)
			e_list.append([i,j,rad])

for e in e_list:
	print("x: %d  y: %d  rad: %f" %(e[0],e[1],e[2]))

out=np.array(out, dtype = np.uint8)

cv2.imshow('image', img)
cv2.imshow('Detected Edges', out)
cv2.waitKey(0)
cv2.destroyAllWindows()