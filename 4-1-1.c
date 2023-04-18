#include<stdio.h>

double func(double x,double lambda){
    
    return -1*lambda * x;
}

int main(){
    double h = 0.001;
    double y0 = 10;
    double x0 = 0;
    double lambda = 0.01;
    int count = 0;
    // iterations can be calculated as x-x0/h = 1000
    while(x0<=10){
        x0 = x0+h;
        double k1 = h*func(y0,lambda);
        double k2 = h*func(y0+0.5*k1,lambda);
        y0 = y0 + 0.5*(k1 + k2);
        printf("%lf, ",y0);
        count++;
    }
    printf("\n");
    printf("count=%d",count);
    return 0;
}