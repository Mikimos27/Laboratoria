#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

uint32_t nta(uint32_t n) {
    if (n == 0) return 0;
    if (n == 1) return 2;
    if (n == 2) return 3;

    uint32_t* arr = malloc(sizeof(uint32_t) * (n + 1));
    arr[1] = 2;
    arr[2] = 3;
    uint32_t licz = 5;
    uint32_t k = 2;

    while (k < n) {
        bool flag = true;
        for (uint32_t i = 1; i <= k; i++){
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

    for (uint32_t i = 1; i <= n; i++) {
        printf("arr[%u] = %u\n", i, arr[i]);
    }

    uint32_t ret = arr[n];

    free(arr);
    return ret;
}

int main(int argc, char** argv) {
    uint32_t wynik = nta(15);
    printf("15. liczba pierwsza to: %u\n", wynik);
    return 0;
}
