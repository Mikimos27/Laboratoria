#include <stdio.h>
#include <stdint.h>

void swap(uint32_t* A, uint32_t* B){
    uint32_t temp = *A;
    *A = *B;
    *B = temp;
}

uint32_t eukl(uint32_t a, uint32_t b){
    if(a < b) eukl(b, a);

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
        if(a + b == 0){
            printf("NWD(0, 0) nie istneje\n");
            return 1;
        }
        printf("NWD(%u, %u) = %u\n", a, b, a + b);
        return 1;
    }
    printf("NWD(%u, %u) = %u\n", a, b, eukl(a, b));

    return 0;
}
