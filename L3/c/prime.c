#include "prime.h"
#include <stddef.h>

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

unsigned count_primes(bool s[], unsigned n){
    int i, c = 0;
    for (i = 2; i <= n; i++)
        if(s[i]) c++;
    return c;
}
