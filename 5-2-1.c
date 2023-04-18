#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

float newtonDividedDifference(int n, float x[], float y[], float x0) {
    float result = y[0];
    for (int i = 1; i < n; i++) {
        float temp = 1;
        for (int j = 0; j < i; j++) {
            temp *= (x0 - x[j]);
        }
        float dividedDiff = 0;
        for (int j = 0; j <= i; j++) {
            float numerator = y[j];
            for (int k = 0; k < j; k++) {
                numerator -= y[k];
            }
            float denominator = x[j];
            for (int k = 0; k < j; k++) {
                denominator -= x[k];
            }
            dividedDiff += (numerator / denominator);
        }
        result += (temp * dividedDiff);
    }
    return result;
}

float lagrange(int n, float x[], float y[], float x0) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x0 - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    

    printf("The random numbers are: ");
    int i;
    int n = 5;
    double x[5], sinx[5], approx[5], error[5], sum;
    
    // Generate n random values between 0 and 2pi
    for (i = 0; i < n; i++) {
        x[i] = ((double) rand() / RAND_MAX) * 2 * PI;
        sinx[i] = sin(x[i]);
    }

    float x0 = 0.2;
    float Result = newtonDividedDifference(5, x, approx, x0);
    printf("Using Newton divided difference method, the value of sin(%f) is: %f\n", x0, Result);

    return 0;
}