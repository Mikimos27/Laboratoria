#include <stdio.h>
#include <stdint.h>

int is_palindrome(uint32_t num, uint32_t base){
    uint32_t pal = 0;
    uint32_t rem = 0;
    uint32_t n = num;

    while(n != 0){
        rem = n % base;
        n /= base;

        pal = pal * base + rem;
    }

    return num == pal;
}

int main(){
    uint32_t num = 0;
    uint32_t base = 0;
    scanf("%u", &num);
    scanf("%u", &base);
    if(base == 0){
        printf("System liczbowy nie moze opierac sie na zerze\n");
        return 1;
    }
    if(base == 1){
        printf("Tak, wszystko w systemie 1 jest palindromem\n");
        return 1;
    }
    int pal = is_palindrome(num, base);
    printf("%u%s jest palindromem\n", num, pal == 0 ? " nie" : "");

    return 0;
}
