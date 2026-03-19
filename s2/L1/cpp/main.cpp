#include "primenumbers.hpp"
#include <iostream>
#include <string>

using std::cout;

int main(int argc, char** argv){
    if(argc < 2){
    }
    int l = 0;
    try{ l = std::stoi(argv[1]); }
    catch(...){
        cout << argv[1] << " - Nieprawidłowa dana\n";
        return 0;
    }
    if(l <= 1){
        cout << argv[1] << " - Nieprawidłowy zakres\n";
        return 0;
    }

    prime_numbers pn = l;
    for(int i = 2; i < argc; i++){
        int n = 0;
        bool fail = false;
        try{ n = std::stoi(argv[i]); }
        catch(...){
            cout << argv[i] << " - nieprawidłowa dana\n";
            fail = true;
        }
        if(fail) continue;

        int k = pn.get_number(n);
        if(k == -1){
            cout << argv[i] << " - liczba spoza zakresu\n";
            continue;
        }
        cout << argv[i] << " - " << k << '\n';
    }

    return 0;
}
