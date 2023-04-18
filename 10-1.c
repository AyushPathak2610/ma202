#include <stdio.h> 
#include <math.h> 
 
#define dt 0.01 
#define N 100000 
double sigma = 10.0; // Parameter sigma
double b = 8.0 / 3.0; // Parameter b
double r = 99.0; // Parameter r
 
// Function to calculate dx/dt
double dxdt(double x, double y, double z) 
{     
    return sigma * (y - x); 
} 

// Function to calculate dy/dt
double dydt(double x, double y, double z) 
{     
    return r * x - y - x * z; 
} 

// Function to calculate dz/dt
double dzdt(double x, double y, double z) 
{     
    return -b * z + x * y; 
} 
 
int main() 
{     
    double x = -20.0, y = -15.0, z = 113.0;     
    double k1x, k1y, k1z, k2x, k2y, k2z, k3x, k3y, k3z, k4x, k4y, k4z;     
    int i; 

    FILE *file = fopen("output.txt", "w"); // Open a file for writing

    if (file == NULL) 
    {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (i = 0; i < N; i++) 
    {         
        k1x = dt * dxdt(x, y, z);         
        k1y = dt * dydt(x, y, z);         
        k1z = dt * dzdt(x, y, z); 

        k2x = dt * dxdt(x + k1x / 2, y + k1y / 2, z + k1z / 2);         
        k2y = dt * dydt(x + k1x / 2, y + k1y / 2, z + k1z / 2);         
        k2z = dt * dzdt(x + k1x / 2, y + k1y / 2, z + k1z / 2); 

        k3x = dt * dxdt(x + k2x / 2, y + k2y / 2, z + k2z / 2);         
        k3y = dt * dydt(x + k2x / 2, y + k2y / 2, z + k2z / 2);         
        k3z = dt * dzdt(x + k2x / 2, y + k2y / 2, z + k2z / 2); 

        k4x = dt * dxdt(x + k3x, y + k3y, z + k3z);         
        k4y = dt * dydt(x + k3x, y + k3y, z + k3z);         
        k4z = dt * dzdt(x + k3x, y + k3y, z + k3z); 

        x += (k1x + 2 * k2x + 2 * k3x + k4x) / 6;         
        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;
        z += (k1z + 2 * k2z + 2 * k3z + k4z) / 6;

        fprintf(file, "%lf, %lf, %lf\n", x, y, z); // Write the values to the file

    }

    fclose(file); // Close the file

    printf("Motion of the vector has been saved to output.txt\n");

    return 0;
}

