#include "lib.h"
#include <stdio.h>
#include <string.h>



int main(int argc, char** argv){
//    printf("%u\n%u\n%d\n", prime_numbers(100), prime(100), is_prime(100));
    if(argc != 3) return 1;

    unsigned num = 0;
    bool is_bool = false;
    unsigned (*fp)(unsigned) = NULL;
    if(sscanf(argv[2], "%u", &num) != 1) return 1;

    if(strcmp(argv[1], "pn") == 0){
        fp = prime_numbers;
    } else if(strcmp(argv[1], "pr") == 0){
        fp = prime;
    } else if(strcmp(argv[1], "ip") == 0){
        is_bool = true;
    }else return 1;

    if(is_bool) printf("%s\n", is_prime(num) == 0 ? "false" : "true");
    else printf("%u\n", fp(num));


    return 0;
}
