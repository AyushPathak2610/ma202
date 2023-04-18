import numpy as np

data = np.loadtxt('output.txt', delimiter=',') # Load data from "output.txt" file with comma as delimiter

x = data[:, 0] # Extract x values from the first column
y = data[:, 1] # Extract y values from the second column
z = data[:, 2] # Extract z values from the third column

# Plot x, y, z values
import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot(x, y, z)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
plt.show()
