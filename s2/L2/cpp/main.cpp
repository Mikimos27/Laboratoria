#include <iostream>
#include <string>
#include "pascaltrianglerow.hpp"


int main(int argc, char** argv){
    if(argc < 3) return 1;
    int n = 0;
    try{ n = std::stoi(argv[1]); }
    catch(...){
        std::cout << argv[1] << " - Nieprawidłowa dana\n";
        return 1;
    }
    if(n < 0){
        std::cout << argv[1] << " - Nieprawidłowy zakres\n";
        return 1;
    }

    pascaltrianglerow p = n;
    p.Create(n);
    for(int i = 2; i < argc; i++){
        try{
            n = std::stoi(argv[i]);
            int k = p.Elem(n);
            if(k == -1){
                std::cout << argv[i] << " - liczba spoza zakresu\n";
                continue;
            }
            std::cout << argv[i] << " - " << k << '\n';
        }
        catch(...){
            std::cout << argv[i] << " - nieprawidłowa dana\n";
        }

    }
    return 0;
}
