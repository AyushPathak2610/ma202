// #include <stdio.h>
// #include<math.h>

// double f(double t, double x, double z)
// {
//     return 0.1*sin(0.6*t) -x -0.1*z;
// }

// void RK4(double *y, double *yp, double t, double h)
// {
//     double k1, k2, k3, k4, m1, m2, m3, m4;

//     k1 = h * (*yp);
//     m1 = h * f(t, *y, *yp);

//     k2 = h * (*yp + m1 / 2);
//     m2 = h * f(t + h / 2, *y + k1 / 2, *yp + m1 / 2);

//     k3 = h * (*yp + m2 / 2);
//     m3 = h * f(t + h / 2, *y + k2 / 2, *yp + m2 / 2);

//     k4 = h * (*yp + m3);
//     m4 = h * f(t + h, *y + k3, *yp + m3);

//     *y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
//     *yp += (m1 + 2 * m2 + 2 * m3 + m4) / 6;
// }

// int main()
// {
//     double t, x, z, h;
//     int n;
//     int i;

//     printf("Enter the initial value of x: ");
//     scanf("%lf", &x);

//     printf("Enter the initial value of x': ");
//     scanf("%lf", &z);

//     printf("Enter the value of h: ");
//     scanf("%lf", &h);

//     n=100/h;
//     FILE*f = fopen("num.txt","w");
//     FILE*f2 = fopen("num2.txt","w");

//     printf("\n");
//     fprintf(f,"[");
//     fprintf(f2,"[");
//     for (i = 0, t = 0; i <= n; i++, t += h)
//     {
//         fprintf(f,"%.36lf, ", x);
//         fprintf(f2,"%.36lf, ", z);
//         RK4(&x, &z, t, h);
//     }
//     fprintf(f,"]");
//     fprintf(f2,"]");

//     return 0;
// }


// numerical evolution OF DYNAMICAL system
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// #define f 0.1
// #define A 0
// #define alpha 0.1

// double dvdt(double x, double v, double omega, double var_omega, double t)
// {
//     return -1 * omega * omega * x + f * sin(var_omega * t) - alpha * v;
// }

// void func(double x0, double v0, double t, double h, double omega, double var_omega)
// {
//     double t0 = 0;
//     int n = (int)(t - t0) / h;
//     FILE *ptr = NULL;
//     ptr = fopen("q10.txt", "w");
//     // FILE *ptr2 = NULL;
//     // ptr2 = fopen("q11.txt", "w");
//     FILE *ptr3 = NULL;
//     ptr3 = fopen("q12.txt", "w");
//     fprintf(ptr, "%.20lf     %.20lf\n", t0, x0);
//     // fprintf(ptr2, "%.20lf     %.20lf\n", t0, v0);
//     fprintf(ptr3, "%.20lf     %.20lf\n", x0, v0);
    
//     printf("\t   x\t\t   v\n");
//     printf("0\t%lf\t%lf\n", x0, v0);
//     fprintf(ptr, '[');
//     fprintf(ptr3, '[');
//     for (int i = 1; i <= n; i++)
//     {
//         double k1x = h * v0;
//         double k1v = h * dvdt(x0, v0, omega, var_omega, t);
//         double k2x = h * (v0 + k1v / 2);
//         double k2v = h * dvdt(x0 + k1x / 2, v0 + k1v / 2, omega, var_omega, t);
//         double k3x = h * (v0 + k2v / 2);
//         double k3v = h * dvdt(x0 + k2x / 2, v0 + k2v / 2, omega, var_omega, t);
//         double k4x = h * (v0 + k3v);
//         double k4v = h * dvdt(x0 + k3x, v0 + k3v, omega, var_omega, t);
//         v0 = v0 + (k1v / 6) + (k2v / 3) + (k3v / 3) + (k4v / 6);
//         x0 = x0 + (k1x / 6) + (k2x / 3) + (k3x / 3) + (k4x / 6);
//         t0 = t0 + h;
//         printf("%d\t%lf\t%lf\n", i, x0, v0);

//         fprintf(ptr, "%.20lf," , t0);
//         // fprintf(ptr2, "%.20lf     %.20lf\n", t0, v0);
//         fprintf(ptr3, "%.20lf,", v0);
//     }
//     fprintf(ptr, ']');
//     fprintf(ptr3, ']');
// }
// int main()
// {
//     double x0, v0, omega, dt, t, var_omega;

//     x0 = 1;
//     v0 = 0;
//     omega = 1;
//     var_omega = 0.6;
//     t = 100;
//     dt = 1;

//     // printf("Enter the \ninitial displacement, initial velocity, angular velocity, dt (increments of time), time limit, var omega : \n");
//     // scanf("%lf %lf %lf %lf %lf %lf", &x0, &v0, &omega, &dt, &t, &var_omega);

//     func(x0, v0, t, dt, omega, var_omega);
// }

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359


double alpha = 0.1;
double w0 = 1.0;
double f = 0.1;
double w=1;

double func(double x, double v, double t) {
    return -alpha*v - w0*w0*x + f*sin(w*t);
}

void RangeKuttaMethod_4th(double *x, double *v, double t, double h) {
    double k1v = h*func(*x, *v, t);
    double k1x = h*(*v);
    double k2v = h*func(*x + k1x/2.0, *v + k1v/2.0, t + h/2.0);
    double k2x = h*(*v + k1v/2.0);
    double k3v = h*func(*x + k2x/2.0, *v + k2v/2.0, t + h/2.0);
    double k3x = h*(*v + k2v/2.0);
    double k4v = h*func(*x + k3x, *v + k3v, t + h);
    double k4x = h*(*v + k3v);
    *v = *v + (k1v + 2.0*k2v + 2.0*k3v + k4v)/6.0;
    *x = *x + (k1x + 2.0*k2x + 2.0*k3x + k4x)/6.0;
}

int main() {
    FILE *f;
    f=fopen("lab9.dat","w");
    double x0 = 5;
    double v0 = 0.0;
    double t = 0.0;
    double h = 0.1;
    fprintf(f,"[");
    for (int i=0; i<500; i++) {
        RangeKuttaMethod_4th(&x0, &v0, t, h);
        t += h;
        printf("%lf %lf %lf\n", t, x0, v0);
        fprintf(f,"%lf,",v0);
    }
    fprintf(f,"]");
    fclose(f);
    
    return 0;
}