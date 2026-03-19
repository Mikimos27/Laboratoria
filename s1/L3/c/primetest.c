#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char** argv){
    if(argc != 2){
        printf("Zła liczba argumentów\n");
        return 1;
    }
    unsigned long n, c;
    long inter = 0;
    bool* s;
    if(sscanf(argv[1], "%ld", &inter) != 1){
        printf("sscanf fail\n");
        return 1;
    }

    if(inter < 2){
        printf("0\n");
        return 0;
    }
    n = inter;
    s = malloc((n + 1) * sizeof(bool));
    if(!s){
        printf("malloc fail\n");
        return 1;
    }
    compute_sieve(s, n);
    c = count_primes(s, n);
    printf("%lu\n", c);
    free(s);

    return 0;
}
