#include<stdio.h>

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

int main() {
    int n = 4;
    float x[] = {654, 658, 659, 661};
    float y[] = {2.8156, 2.8182, 2.8189, 2.8202};

    float x0 = 656;
    float nddResult = newtonDividedDifference(n, x, y, x0);
    printf("Using Newton divided difference method, the value of log(%f) is: %f\n", x0, nddResult);

    float lagrangeResult = lagrange(n, x, y, x0);
    printf("Using Lagrange interpolation method, the value of log(%f) is: %f\n", x0, lagrangeResult);

    return 0;
}
