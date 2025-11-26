#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t min32(uint32_t a, uint32_t b){
    return a < b ? a : b;
}

uint32_t dwumian(uint32_t n, uint32_t k){
    k = min32(k, n - k);
    uint32_t* C = malloc(sizeof(uint32_t) * (k + 1));

    C[0] = 1;
    for(uint32_t i = 0; i <= n; i++){
        if(i <= k) C[i] = 1;
        for(uint32_t j = min32(k, i - 1); j > 0; j--){
            C[j] = C[j] + C[j - 1];
            printf("%u ", C[j]);
        }
        for(int i = 0; i <= k; i++){

        }
        printf("\n");
    }
    uint32_t ret = C[k];
    free(C);
    return ret;
}

int main(int argc, char** argv){
    if(argc < 3) return 1;
    uint32_t n = 0, k = 0;
    if(sscanf(argv[1], "%u", &n) != 1){
        printf("sscanf fail\n");
        return 1;
    }
    if(sscanf(argv[2], "%u", &k) != 1){
        printf("sscanf fail\n");
        return 1;
    }
    if(n < k){
        printf("n musi być niemniejsze od k\n");
        return 1;
    }
    printf("d(%u, %u) = %u\n", n , k, dwumian(n, k));
    return 0;
}
