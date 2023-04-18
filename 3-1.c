#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x)
{
    // return (x - 4) * (x - 2) * (x + 3) * (x + 7);
    return tan(x)-x;
}

void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        printf("You have not assumed right a and b\n");
        return;
    }

    double c = a;
    int i, flag = 0;
    for (i = 0; i < 100; i++)
    {
        c = (a + b) / 2;
        if (func(c) == 0.0)
        {
            flag = 1;
            break;
        }
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }

    printf("Root is : %lf\n", c);
}

void falsePosition(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        printf("You have not assumed right a and b\n");
        return;
    }

    double c = a;
    int i, flag = 0;
    for (i = 0; i < 100; i++)
    {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));
        if (func(c) == 0.0)
        {
            flag = 1;
            break;
        }
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }

    printf("Root is : %lf\n", c);
}

void secant(double x0, double x1)
{
    int i, flag = 0;
    double x2;
    for (i = 0; i < 100; i++)
    {
        x2 = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));
        x0 = x1;
        x1 = x2;
        if (func(x2) == 0.0)
        {
            flag = 1;
            break;
        }
    }

    printf("Root is : %lf\n", x2);
}

int main()
{
    bisection(-1.57,1.57);
    bisection(2.37,4.71);
    bisection(5.495,7.85);
    bisection(8.635,10.99);
    bisection(11.778,14.137);
    bisection(14.9185,17.2785);
    bisection(18.064,20.420);
    
    return 0;
}
