// #include<stdio.h>

// double dydx(double x, double y)
// {
// 	return (-1.00*y) + 1.001*(y*y);
// }

// double rungeKutta(double x0, double y0, double x, double h)
// {
// 	int n = (int)((x - x0) / h);

// 	double k1, k2, k3, k4, k5;

// 	double y = y0;
// 	for (int i=1; i<=100; i++)
// 	{
// 		k1 = h*dydx(x0, y);
// 		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
// 		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
// 		k4 = h*dydx(x0 + h, y + k3);

// 		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;

// 		x0 = x0 + h;
// 	}

// 	return y;
// }




#include<stdio.h>

// we are given values of epsilon and lambda as 1.001 and 1 respectively

double func(double y){
    
    return (-1.00*y) + 1.001*(y*y);
}

int main(){
    double h = 0.01;
    double y0 = 10;
    double x0 = 0;
    double lambda = 1;
	int count = 0;
	// iterations can be calculated as x-x0/h
    while(x0<=10){
        x0 = x0+h;
        double k1 = h*func(y0);
        double k2 = h*func(y0+0.5*k1);
        double k3 = h*func(y0+0.5*k2);
        double k4 = h*func(y0+k3);
        y0 += (k1 + 2*k2+2*k3+k4)/6;
		printf("%lf, ",y0);
        count++;
    }
    printf("count=%d",count);// for 1000 iterations
    return 0;
}