#include <stdio.h>
#include <stdint.h>

void swap(uint32_t* A, uint32_t* B){
    uint32_t temp = *A;
    *A = *B;
    *B = temp;
}

uint32_t eukl1(uint32_t a, uint32_t b){
    while(b != 0){
        if(a < b) swap(&a, &b);
        else a -= b;
    }
    return a;
}


uint32_t eukl2(uint32_t a, uint32_t b){
    if(a < b) swap(&a, &b);

    while(b != 0){
        a = a % b;
        swap(&a, &b);
    }
    return a;
}


int main(){
    uint32_t a = 0, b = 0;

    scanf("%u", &a);
    scanf("%u", &b);
    if(a == 0 || b == 0) {
        printf("NWD(%d, %d) = %d\n", a, b, a + b);
        return 1;
    }
    printf("Euk1 = %d\nEuk2 = %d\n", eukl1(a, b), eukl2(a, b));

    return 0;
}
