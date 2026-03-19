#include "primenumbers.hpp"
#include <cmath>
#include <iostream>

template<typename T>
void print_arr(T* arr, int size){
    for(int i = 0; i < size; i++)
        std::cout << i << " : " << arr[i] << '\n';
    std::cout << "=================\n";
}

prime_numbers::prime_numbers(int n){
    bool* sieve = new bool[n + 1];
    for(int i = 2; i <= n; i++)
        sieve[i] = true;
    for(int i = 2; i <= std::sqrt(n); i++)
        if(sieve[i])
            for(int j = i * i; j <= n; j += i)
                sieve[j] = false;

    int32_t* raw = new int32_t[n + 1];
    uint16_t count = 0;
    for(int i = 2; i <= n; i++)
        if(sieve[i]){
            raw[count] = i;
            count++;
        }

    this->data = new int32_t[count];
    this->length = count;
    for(int i = 0; i < count; i++)
        this->data[i] = raw[i];

    //print_arr(sieve, n + 1);
    //print_arr(raw, n + 1);
    //print_arr(data, count);
    
    delete[] sieve;
    delete[] raw;
}

prime_numbers::~prime_numbers(){
    delete[] data;
    length = 0;
}

int prime_numbers::get_number(int n){
    if(n < 0 || n >= this->length) return -1;
    return data[n];
}
