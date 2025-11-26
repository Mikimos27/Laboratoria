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

    if(inter < 0){
        printf("liczby ujemne nie działają\n");
        return 1;
    }
    n = inter;
    s = malloc((n + 1) * sizeof(bool));
    if(!s){
        printf("malloc fail\n");
        return 1;
    }
    compute_sieve(s, n);
    for(unsigned long i = 0; i <= n; i++){
        c = count_primes(s, i);
        printf("%lu\n", c);
    }
    free(s);

    return 0;
}
