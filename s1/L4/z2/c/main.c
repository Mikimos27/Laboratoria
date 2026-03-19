#include "lib.h"
#include <stdio.h>

int main(int argc, char** argv){
    if(argc < 2){
        printf("Za mało argumentów\n");
        return 1;
    }
    unsigned num = 0;

    for(int i = 1; i < argc; i++){
        sscanf(argv[i], "%u", &num);
        printf("totient(%u) = %u\n", num, totient(num));
    }

    return 0;
}
