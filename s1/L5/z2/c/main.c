#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double f(long double x){
    return x*x - 2*x;
}
long double halfcos(long double x){
    return cos(x / 2);
}

long double findzero(long double (*f)(long double), long double a, long double b, long double eps){
    long double c = (a + b) / 2;
    while(b - a > eps){
        if(f(c) * f(a) < 0) b = c;
        else a = c;
        c = (a + b) / 2;
    }
    return c;
}


int main(){
    printf("findzero(halfcos, 2, 4) = %10Lf\n", findzero(halfcos, 2, 4, 0.00000001));
    return 0;
}
