#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char** argv){
    if(argc != 2){
        printf("Zła liczba argumentów\n");
        return 1;
    }
    unsigned long n, c;
    bool* s;
    if(sscanf(argv[1], "%lu", &n) != 1){
        printf("sscanf fail\n");
        return 1;
    }
    s = malloc((n + 1) * sizeof(bool));
    if(!s){
        printf("malloc fail\n");
        return 1;
    }
    compute_sieve(s, n);
    c = count_primes(s, n);
    free(s);
    printf("%lu\n", c);

    return 0;
}
