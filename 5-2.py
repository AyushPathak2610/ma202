import random
import math
import numpy as np
import matplotlib.pyplot as plt

x = [random.uniform(0, 1) for i in range(5)]

y1 = [math.sin(xi) for xi in x]

y2 = np.sin(x)

x_actual = np.linspace(0, 1, 100)
y_actual = np.sin(x_actual)
plt.plot(x_actual, y_actual, label='Actual Sine Curve')
plt.plot(x, y1, 'o', label='Generated Values')
plt.plot(x, y2, 'o', label='Approximated Sine')
plt.legend()
plt.show()
