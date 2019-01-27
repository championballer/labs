#!/usr/bin/env python
# coding: utf-8

# In[1]:


import cv2
import numpy as np
import matplotlib.pyplot as plt


# In[2]:


shp = (25,25)
img = np.floor(np.random.random(shp) + 0.5)


# In[34]:


def plot(out):
    fig, ax = plt.subplots(figsize=(20,10))
    ax.canvas.set_window_title('4-Way')

    ax.imshow(out)
    for i in range(shp[0]):
        for j in range(shp[1]):
            c = out[j,i]
            ax.text(i, j, str(c), va='center', ha='center')


# In[4]:


fig = plt.figure(100)
fig.canvas.set_window_title('Main')
plt.imshow(img, cmap="Greys")


# In[14]:


def first_pass(img):
    
    
    label=1
    
    
    for i in range(shp[0]):
        for j in range(shp[1]):
            if img[i][j]==0:
                continue
            if i==0 and j==0:
                out[i][j] = label
                if label not in parents:
                    parents[label]=label
                label+=1
            elif i==0:
                if out[i][j-1]==0:
                    out[i][j] = label
                    if label not in parents:
                        parents[label]=label
                    label+=1
                else:
                    out[i][j] = out[i][j-1]
            elif j==0:
                if out[i-1][j-1]==0:
                    out[i][j] = label
                    if label not in parents:
                        parents[label]=label
                    label+=1
                else:
                    out[i][j] = out[i-1][j]
            else:
                if out[i-1][j]==0 and out[i][j-1]==0:
                    out[i][j] = label
                    if label not in parents:
                        parents[label]=label
                    label+=1
                elif out[i-1][j]==0:
                    out[i][j] = out[i][j-1]
                elif out[i][j-1]==0:
                    out[i][j] = out[i-1][j]
                else:
                    out[i][j] = min(out[i-1][j],out[i][j-1])
                    parents[max(out[i-1][j],out[i][j-1])] = parents[min(out[i-1][j],out[i][j-1])]


# In[19]:


def second_pass(out):
    
    for i in range(shp[0]):
        for j in range(shp[1]):
            if out[i][j]==0:
                continue
            else:
                if parents[out[i][j]]==out[i][j]:
                    continue
                else:
                    parent = parents[out[i][j]]
                    current = out[i][j]
                    while parent!=current:
                        current = parent
                        parent=parents[current]
                    parents[out[i][j]] = parent
                    out[i][j] = parent
                        


# In[20]:


parents = {
        1:1
    }
out = np.zeros(shp,dtype=int)
first_pass(img)
second_pass(out)


# In[21]:


plot(out)


# In[17]:


parents


# In[22]:


final_list = []

for key,value in parents.items():
    if key==value:
        final_list.append(key)
    else:
        continue


# In[23]:


final_list


# In[28]:


final_components = {}

for i in range(1,len(final_list)+1):
    final_components[final_list[i-1]] = i


# In[29]:


final_components


# In[30]:


def replace(out):
    
    for i in range(shp[0]):
        for j in range(shp[1]):
            if out[i][j]==0:
                continue
            out[i][j] = final_components[out[i][j]]


# In[32]:


replace(out)


# In[33]:


plot(out)


# In[ ]:




