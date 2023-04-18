import matplotlib.pyplot as plt
import numpy as np

def f(x):
    # Function to be evaluated
    return np.exp(x)

def taylor_approximation(x, n):
    result = 0
    term = 1

    for i in range(n):
        result += term
        term *= (x - X_0) / (i + 1)

    return result

X_0 = 1
x = 10
errors = []

for N in range(1, 20):
    approx = taylor_approximation(x, N)
    errors.append(np.abs(approx - f(x)))

plt.semilogy(range(1, 20), errors)
plt.xlabel("Number of terms in Taylor expansion")
plt.ylabel("Error")
plt.show()
