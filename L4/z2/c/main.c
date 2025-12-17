#include "lib.h"
#include <stdio.h>

int main(){
    unsigned num = 0;

    scanf("%u", &num);
    printf("totient(num) = %u\n", totient(num));

    return 0;
}
