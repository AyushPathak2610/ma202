import matplotlib.pyplot as plt
import numpy as np

w = 1.0 
t0 = 0.0 
tf = 10.0 
dt = 0.01 

x0 = 1.0 
v0 = 0.0 

t = np.arange(t0, tf+dt, dt)
x = np.zeros_like(t)
v = np.zeros_like(t)


x[0] = x0
v[0] = v0


for i in range(1, len(t)):
    v[i] = v[i-1] - w**2*x[i-1]*dt
    x[i] = x[i-1] + v[i]*dt

# plot position vs time
plt.figure()
plt.plot(t, x)
plt.xlabel('Time (s)')
plt.ylabel('Position (m)')
plt.title('Position vs. Time')

# Plot velocity vs. time
plt.figure()
plt.plot(t, v)
plt.xlabel('Time (s)')
plt.ylabel('Velocity (m/s)')
plt.title('Velocity vs. Time')

# Plot phase space diagram
plt.figure()
plt.plot(x, v)
plt.xlabel('Position (m)')
plt.ylabel('Velocity (m/s)')
plt.title('Phase Space Diagram')

plt.show()