#include <stdio.h>
#include <stdint.h>
#include <math.h>


int test();
int prime(uint32_t);


int main(){
    return test();
}


int test(){
    uint32_t to_check[] = {0,2,24,17,3,1023,1204,1203};
    for(int i = 0; i < sizeof(to_check) / sizeof(to_check[0]); i++){
        printf("%d is%s prime\n", to_check[i], prime(to_check[i]) ? "" : " not");
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
