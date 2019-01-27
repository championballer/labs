import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()

min_val, max_val = 0, 25

intersection_matrix = np.random.randint(0, 10, size=(max_val, max_val))


fig = ax.figure
fig.canvas.set_window_title('4-Way')
ax.matshow(intersection_matrix, cmap=plt.cm.Blues)

for i in range(25):
    for j in range(25):
        c = intersection_matrix[j,i]
        ax.text(i, j, str(c), va='center', ha='center')