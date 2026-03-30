#include "pascaltrianglerow.hpp"

int min(int a, int b){
    return a >= b ? b : a;
}

pascaltrianglerow::pascaltrianglerow(int n)
    : n(n){
    Create(n);
}
pascaltrianglerow::~pascaltrianglerow(){
    delete[] data;
}
void pascaltrianglerow::Create(int n){
    data = new int[n + 1];
    data[0] = 1;
    for(int i = 0; i <= n; i++){
        if(i <= n) data[i] = 1;
        for(int j = min(n, i - 1); j > 0; j--)
            data[j] = data[j] + data[j - 1];
    }
}
int pascaltrianglerow::Elem(int m){
    if(m < 0 || m > n) return -1;
    return data[m];
}
