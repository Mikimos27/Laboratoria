#include <stdio.h>
#include <stdlib.h>
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
int main2();

int main(){
    uint32_t num = 0;
    uint32_t* arr = nullptr;
    uint32_t len = 0;

    scanf("%u", &num);
    if(prime(num)){
        printf("%u\n", num);
        return 0;
    }

    len = num / 2 + 1;
    arr = (uint32_t*)calloc(len, sizeof(uint32_t));

    while(num % 2 == 0){
        arr[1]++;
        num /= 2;
    }
    printf("%u\n", num);
    for(uint32_t i = 3; i <= len; i += 2){
        if(num % i == 0){
            arr[i - 1]++;
            num /= i;
            i = 1;
        }
    }

    bool first = true;
    for(uint32_t i = 2; i < len; i++){
        if(arr[i - 1] == 0) continue;
        if(!first) printf(" * ");
        first = false;
        if(arr[i - 1] == 1) {
            printf("%u", i);
            continue;
        }
        printf("%u^%u", i, arr[i - 1]);
    }
    printf("\n");

    free(arr);
    return 0;
}

/*int main2(){
    uint32_t num = 0;
    uint32_t* arr = nullptr;

    scanf("%u", &num);
    uint32_t org = num / 2;
    if(prime(num)){
        printf("%u\n", num);
        return 0;
    }

    arr = (uint32_t*)calloc(num, sizeof(uint32_t));

    for(uint32_t i = 2; i <= num; i++){
        if(num % i == 0){
            arr[i - 1] = i;
            num /= i;
            i = 1;
        }
    }

    bool first = true;
    for(uint32_t i = 2; i <= org; i++){
        if(arr[i - 1] == 0) continue;
        if(!first) printf(" * ");
        first = false;

        printf("%u", arr[i-1]);
    }
    if(!first) printf(" * ");
    if(num > 1) printf("%u", num);
    printf("\n");

    free(arr);
    return 0;
}*/
