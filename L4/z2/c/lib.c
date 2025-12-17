#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void swap(uint32_t* A, uint32_t* B){
    uint32_t temp = *A;
    *A = *B;
    *B = temp;
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

uint32_t* factors(unsigned num, uint32_t* len){
    uint32_t* arr = nullptr;
    *len = 0;

    if(prime(num)){
        return NULL;
    }

    *len = num / 2 + 1;
    arr = (uint32_t*)calloc(*len, sizeof(uint32_t));

    while(num % 2 == 0){
        arr[1]++;
        num /= 2;
    }
    for(uint32_t i = 3; i <= *len; i += 2){
        if(num % i == 0){
            arr[i - 1]++;
            num /= i;
            i = 1;
        }
    }

    return arr;
}

unsigned totient(unsigned n){
    uint32_t len1;
    uint32_t* arr = factors(n, &len1);
    if(arr == NULL) return n - 1;
    printf("%u\n", len1);

    uint32_t res = n;
    for(int i = 1; i < len1 - 2; i++){
        if(arr[i - 1] == 0) continue;
        printf("%u\n", res);
        res = res - res / i;
    }
    free(arr);
    return res;
}
