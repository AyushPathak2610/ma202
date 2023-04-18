// #include <stdio.h>
// #include <math.h>

// #define X_0 1.0
// #define N 15
// #define TOLERANCE 1e-6

// double f(double x) {
//     // Function to be evaluated
//     return exp(x);
// }

// double taylor_approximation(double x) {
//     double result = 1.0;
//     double term = 1.0;

//     for (int i = 0; i < N; i++) {
//         result += term;
//         term *= (x - X_0) / (i + 1);
//     }

//     return result;
// }

// int main() {
//     double x;

//     printf("Enter the value of x: ");
//     scanf("%lf", &x);

//     double approx = taylor_approximation(x);
//     double error = fabs(approx - f(x));

//     if (error < TOLERANCE) {
//         printf("The Taylor approximation of exp(%lf) is %lf with an error of %lf\n", x, approx, error);
//     } else {
//         printf("The error of %lf is greater than the tolerance of %lf\n", error, TOLERANCE);
//     }

//     return 0;
// }

#include <stdio.h>
#include <math.h>
#include <conio.h>

double taylorexp(int x, int m)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        double term = (pow(x, 2 * i + 1)) / ((2 * i) + 1); // term in taylor expansion
        if (i % 2 == 0)
            sum += term;
        else
            sum -= term;
    }
    return sum;
}

int main()
{
    int x = 1;
    int m = 10;
    double s = taylorexp(x, m);
    double rn = (1.000000 / ((double)(2 * m) + 3));
    double fx = s + rn; // taylors equation for calculating errors
    printf("sum is %f\n", s);
    printf("error is %f\n", rn);

    printf("fx is %f\n", fx);
    double pi = (4.0) * (fx);
    printf("Value of pi is %f\n", pi);
    return 0;
}
