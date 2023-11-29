#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

double f(double x);
double fa(double (*f)(double), float a);

int main(){
    float a = 3.14;
    printf("\nGia tri ham sin tai %lf la:\n\t %f",a,fa(sin,a));
    printf("\nGia tri ham f(x)=(1+x) tai %lf la:\n\t%lf",a,fa(f,a));
    getch();
    return 0;
}

double f(double x){
    return (1 + x);
}

double fa(double (*f)(double), float a){
    return f(a);
}

