#include "lib.h"
#include <stdlib.h>
#include <math.h>


int compute_sieve(bool s[], unsigned n){
    if(s == NULL) return 1;
    if(n < 2) return 1;

    unsigned i, j;
    for (i = 2; i <= n; i++) s[i] = true;
    for (i = 2; i <= n; i++)
        if (s[i])
            for (j = i + i; j <= n; j += i)
                s[j] = false;
    return 0;
}

int sqrt_compute_sieve(bool s[], unsigned n){
    if(s == NULL) return 1;
    if(n < 2) return 1;

    unsigned i, j;
    for (i = 2; i <= n; i++) s[i] = true;
    for (i = 2; i * i <= n; i++)
        if (s[i])
            for (j = i + i; j <= n; j += i)
                s[j] = false;
    return 0;
}
unsigned count_primes(bool s[], unsigned n){
    unsigned i, c = 0;
    for (i = 2; i <= n; i++)
        if(s[i]) c++;
    return c;
}

unsigned prime_numbers(unsigned n){
    bool* s = NULL;
    s = malloc((n + 1) * sizeof(bool));
    if(!s){
    }
    compute_sieve(s, n);
    unsigned c = count_primes(s, n);
    free(s);
    return c;
}
unsigned prime(unsigned n){

    unsigned* arr = malloc(sizeof(unsigned) * (n + 1));
    bool flag = false;
    arr[1] = 2;
    arr[2] = 3;
    unsigned licz = 5, k = 2;

    while (k < n) {
        flag = true;
        for (unsigned i = 1; i <= k; i++){
            if (arr[i] > floor(sqrt(licz))) break;
            if (licz % arr[i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            k++;
            arr[k] = licz;
        }
        licz += 2;
    }

    unsigned ret = arr[n];

    free(arr);
    return ret;
}
bool is_prime(unsigned n){
    bool* s = NULL;
    s = malloc((n + 1) * sizeof(bool));
    if(!s){
    }
    sqrt_compute_sieve(s, n);
    bool w = s[n];
    free(s);
    return w;
}
