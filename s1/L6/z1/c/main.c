#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int* begin, int size){
    for(int i = 0; i < size / 2; i++){
        swap(begin + i, begin + size - i - 1);
    }
}

void permute(int* arr, int size){
    int i = size - 1;
    for(; i >= 1; i--){
        if(arr[i] > arr[i - 1]) break;
    }
    if(i == 0) return;
    i--;

    int min = size + 1;
    int min_index = 0;
    for(int j = i + 1; j < size; j++){
        if(min > arr[j] && arr[j] > arr[i]) {
            min = arr[j];
            min_index = j;
        }
    }

    swap(arr + min_index, arr + i);
    reverse(arr + i + 1, size - i - 1);
    
}
void print_arr(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int fact(int n){
    if(n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}
int abs(int n){
    return n > 0 ? n : -n;
}

bool check_safe(int* arr, int size){
    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++){
            if(abs(arr[i] - arr[j]) == abs(i - j)) return false;
        }
    return true;
}

int main(int argc, char** argv){
    if(argc < 2) return 1;
    int len = 12;
    if(sscanf(argv[1], "%d", &len) != 1) return 2;

    int* arr = malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++) arr[i] = i + 1;
    


    int perms = fact(len);
    int sols = 0;
    for(int i = 0; i < perms; i++){
        if(check_safe(arr, len)){
            sols++;
            print_arr(arr, len);
        }
        permute(arr, len);
    }
    printf("Num of solutions: %d\n", sols);
    free(arr);
    return 0;
}
