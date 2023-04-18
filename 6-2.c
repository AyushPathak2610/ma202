#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define e 2.718

double func(double x){
    return (sin(x*x))/x;
}

void trap(){
    double h=0.2;
    double sum=0;
    for(int i=0; i<=100; i++){
        if(i==0 || i==100){
            sum+=func(-10+i*h);
        }
        else sum+=2*func(-10+i*h);
    }
    printf("By trapzoidal rule, value of integration is = %lf",h*sum/2);

}

void simpson13(){
    double h=0.2;
    double sum=0;
    for(int i=0; i<=100; i++){
        if(i==0 || i==100){
            sum+=func(-10+i*h);
        }
        else if(i%2==0){
            sum+=2*func(-10+i*h);
        }
        else sum+=4*func(-10+i*h);
    }
    printf("By Simpson13 rule, value of integration is = %lf",h*sum/3);
}

void simpson38(){
    double h=0.2;
    double sum=0;
    for(int i=0; i<=100; i++){
        if(i==0 || i==100){
            sum+=func(-10+i*h);
        }
        else if(i%3==0){
            sum+=2*func(-10+i*h);
        }
        else sum+=3*func(-10+i*h);
    }
    printf("By Simpson38 rule, value of integration is = %lf",3*h*sum/8);
}

int main(){
    trap();
    printf("\n");
    simpson13();
    printf("\n");
    simpson38();
    return 0;
}
