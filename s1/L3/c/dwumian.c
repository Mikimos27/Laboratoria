#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t min64(uint64_t a, uint64_t b){
    return a < b ? a : b;
}

uint64_t dwumian(uint64_t n, uint64_t k){
    k = min64(k, n - k);
    uint64_t* C = calloc((k + 1), sizeof(uint64_t));

    C[0] = 1;
    for(uint64_t i = 0; i <= n; i++){
        if(i <= k) C[i] = 1;
        for(uint64_t j = min64(k, i - 1); j > 0; j--){
            C[j] = C[j] + C[j - 1];
            printf("%lu ", C[j]);
        }
        printf("\n");
    }
    uint64_t ret = C[k];
    free(C);
    return ret;
}

int main(int argc, char** argv){
    if(argc < 3) return 1;
    uint64_t n = 0, k = 0;
    if(sscanf(argv[1], "%lu", &n) != 1){
        printf("sscanf fail\n");
        return 1;
    }
    if(sscanf(argv[2], "%lu", &k) != 1){
        printf("sscanf fail\n");
        return 1;
    }
    if((int32_t)n < 0 || (int32_t)k < 0){
        printf("liczby ujemne nie działają\n");
        return 1;
    }
    if(n < k){
        printf("n musi być niemniejsze od k\n");
        return 1;
    }
    printf("d(%lu, %lu) = %lu\n", n , k, dwumian(n, k));
    return 0;
}
