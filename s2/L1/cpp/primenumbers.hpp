#ifndef PRIMENUMBERS_H
#define PRIMENUMBERS_H

#include <cstdint>

class prime_numbers{
public:
    prime_numbers(int);
    ~prime_numbers();
    int get_number(int);
private:
    int32_t* data;
    uint16_t length;
};

#endif
