#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

uint32_t nta(uint32_t n){

    uint32_t* arr = malloc(sizeof(uint32_t) * (n + 1));
    bool flag = false;
    arr[1] = 2;
    arr[2] = 3;
    uint32_t licz = 5, k = 2;

    while (k < n) {
        flag = true;
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


    for(uint32_t i = 1; i <= n; i++){
        printf("arr[%u] = %u\n", i, arr[i]);
    }

    uint32_t ret = arr[n];

    free(arr);
    return ret;
}

int main(int argc, char** argv){
    nta(100);
    return 0;
}
