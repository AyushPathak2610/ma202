#include<stdio.h>

double func(double x,double lambda){
    
    return ;
}

int main(){
    double h = 0.01;
    double y0 = 10;
    double x0 = 0;
    double lambda = 0.01;
	int count = 0;
    while(x0<=10){
        x0 = x0+h;
        double k1 = h*func(y0,lambda);
        double k2 = h*func(y0+0.5*k1,lambda);
        double k3 = h*func(y0+0.5*k2,lambda);
        double k4 = h*func(y0+k3,lambda);
        y0 = y0 + (k1 + 2*k2+2*k3+k4)/6;
		printf("%lf, ",y0);
        count++;
    }
    printf("\n");
    printf("count=%d",count);
    return 0;
}