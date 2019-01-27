#!/usr/bin/env python
# coding: utf-8

# In[1]:

#Import libraries to be used in the program
import cv2 #Opencv 
import numpy as np #For fast arrays and other mathematical uses, used because in the end images are a set of images
import matplotlib.pyplot as plt #For visualising the image pixel (point) by pixel


# In[2]:


shp = (25,25) #Tuple stating the size of the image, we want to make
img = np.floor(np.random.random(shp) + 0.5) #We are creating our own image as a collection of random 1s and 0s cloned together. np.floor gives the floor value (1.7->1), np.random gives a random value between 0 and 1 (1 not inclusive), hence +0.5


# In[3]:

#4 way connectivity of a pixel
def four_way(out, i, j, color):
    
    if i < 0 or i>= shp[0]:
        return
    if j < 0 or j >= shp[1]:
        return 
    if vis[i][j] or img[i][j] ==0:
        return
    
    vis[i][j] = True
    out[i][j] = color
    
    four_way(out, i - 1, j, color)
    four_way(out, i + 1, j, color)
    four_way(out, i, j - 1, color)
    four_way(out, i, j + 1, color)


# In[4]:

#8 way connectivity helper function similar to 4 way
def eight_way(out, i, j, color):
    if i < 0 or i >= shp[0]: 
        return
    if j < 0 or j >= shp[1]:
        return
    if vis[i][j] or img[i][j] == 0: 
        return
    
    vis[i][j] = True 
    out[i][j] = color
    
    eight_way(out, i - 1, j, color)
    eight_way(out, i + 1, j, color)
    eight_way(out, i, j - 1, color)
    eight_way(out, i, j + 1, color)
    eight_way(out, i - 1, j - 1, color)
    eight_way(out, i - 1, j + 1, color)
    eight_way(out, i + 1, j - 1, color)
    eight_way(out, i + 1, j + 1, color)


# In[5]:

#m way connectivity of helper function similar to 4 way
def m_way(out, i, j, color):
    if i<0 or i>= shp[0]:
        return
    if j<0 or j>= shp[1]:
        return
    if vis[i][j] or img[i][j] == 0:
        return
    
    vis[i][j] = True
    out[i][j] = color
    
    m_way(out, i - 1, j, color)
    m_way(out, i + 1, j, color)
    m_way(out, i, j - 1, color)
    m_way(out, i, j + 1, color)
    m_way(out, i - 1, j - 1, color)
    m_way(out, i - 1, j + 1, color)
    m_way(out, i + 1, j - 1, color)
    m_way(out, i + 1, j + 1, color)


# In[6]:

#To plot the main img (the one we created our self)
fig = plt.figure(100)
fig.canvas.set_window_title('Main')
plt.imshow(img, cmap="Greys")


# In[11]:

#So what we are doing essentially is like DFS : We start at the top of the image, check if it is already visited or not, if it is, we move on to the next else, we apply DFS for 4-way, then 8-way and then m-way. The component formed for each DFS is a component.
vis = np.zeros(shp,dtype=bool) #Visited array of the same size as our image
out = np.zeros(shp + (3, ), dtype=int) #Our output array with 3 channels (shp + (3, )). 
for i in range(shp[0]):
    for j in range(shp[1]): 
        if vis[i][j]:
            continue
            
        color = np.random.randint(0, 255, 3) #Random color chosen
        four_way(out, i, j, color) #Call to 4 way
fig = plt.figure(200)
fig.canvas.set_window_title('4-Way')
plt.imshow(out) #Plotting the function


# In[13]:

#Similar to the above but just 8 way.

vis = np.zeros(shp, dtype=bool)
out = np.zeros(shp + (3, ), dtype=int)
for i in range(shp[0]):
    for j in range(shp[1]):
        
        if vis[i][j]:
            continue
        color = np.random.randint(0,255,3)
        
        eight_way(out, i, j, color)
fig = plt.figure(300)
fig.canvas.set_window_title('8-Way')
plt.imshow(out)


# In[14]:


vis = np.zeros(shp, dtype=bool)
out = np.zeros(shp + (3, ), dtype=int) 
for i in range(shp[0]):
    for j in range(shp[1]): 
        if vis[i][j]:
            continue
    color = np.random.randint(0, 255, 3)
    m_way(out, i, j, color)
fig = plt.figure(400)
fig.canvas.set_window_title('m-Way')
plt.imshow(out)
plt.show()


# In[ ]:




