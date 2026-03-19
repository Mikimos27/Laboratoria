#include <stdio.h>
#include <stdint.h>
#include <math.h>


int test();
int prime(uint32_t);


int main(){
    uint32_t n = 17;
    return test() + printf("\n%u %sjest liczbą pierwszą\n", n, prime(n) ? "" : "nie ");
}


int test(){
    //uint32_t to_check[] = {0,2,24,17,3,1023,1204,1203};
    for(int i = 0; i < 300; i++){//sizeof(to_check) / sizeof(to_check[0]); i++){
        printf("%d %sjest liczbą pierwszą\n", i, prime(i) ? "" : "nie ");
    }
    return 0;
}



int prime(uint32_t n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(uint32_t i = 3; i * i <= n; i += 2){
        if(n % i == 0) return 0;
    }
    return 1;
}
