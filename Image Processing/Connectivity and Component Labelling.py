#!/usr/bin/env python
# coding: utf-8

# In[1]:


import cv2
import numpy as np
import matplotlib.pyplot as plt


# In[2]:


shp = (25,25)
img = np.floor(np.random.random(shp) + 0.5)


# In[3]:


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


fig = plt.figure(100)
fig.canvas.set_window_title('Main')
plt.imshow(img, cmap="Greys")


# In[11]:


vis = np.zeros(shp,dtype=bool)
out = np.zeros(shp + (3, ), dtype=int) 
for i in range(shp[0]):
    for j in range(shp[1]): 
        if vis[i][j]:
            continue
            
        color = np.random.randint(0, 255, 3)
        four_way(out, i, j, color)
fig = plt.figure(200)
fig.canvas.set_window_title('4-Way')
plt.imshow(out)


# In[13]:


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




