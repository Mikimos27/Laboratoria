#include "figures.hpp"
#include <iostream>
#include <vector>

using std::cout;

std::vector<std::string> split(std::string s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

bool eq(double a, double b){
    return std::abs(a - b) < 0.0000001;
}

int main(int argc, char** argv){
	if(argc < 2){
        cout << "Za mało argumentów\n";
        return 1;
    }
    std::vector<figure*> list;
    int count = 0;
    for(int i = 1; i < argc; i++){
        std::string fig = argv[i];
        count++;
        auto arr = split(fig, " ");
        switch(arr[0][0]){
            case 'q':
                if(arr.size() == 3){
                    double s1, angle;
                    try{
                        s1 = std::stod(arr[1]);
                        angle = std::stod(arr[2]);
                        if(s1 < 0 || angle < 0){
                            cout << "Argumenty muszą być niemniejsze od 0 : " << count << '\n';
                            continue;
                        }
                        if(eq(angle, 90.0)) list.push_back(new square(s1));
                        else list.push_back(new diamond(s1, angle));
                    }
                    catch(...){
                        cout << "Parse error : " << count << '\n';
                        continue;
                    }
                }
                else if(arr.size() == 6){
                    double s1, s2, s3, s4, angle;
                    try{
                        s1 = std::stod(arr[1]);
                        s2 = std::stod(arr[2]);
                        s3 = std::stod(arr[3]);
                        s4 = std::stod(arr[4]);
                        angle = std::stod(arr[5]);

                        if(s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0 || angle < 0){
                            cout << "Argumenty muszą być niemniejsze od 0 : " << count << '\n';
                            continue;
                        }
                        if(eq(angle, 90.0)){
                            if(s1 == s3 && s2 == s4){
                                if(s1 == s2) list.push_back(new square(s1));
                                else list.push_back(new rectangle(s1, s2));
                            }
                            else{
                                cout << "Nieobsługiwana figura\n";
                                continue;
                            }
                        }
                        else if(s1 == s2 && s2 == s3 && s3 == s4){
                            list.push_back(new diamond(s1, angle));
                        }
                        else{
                            cout << "Nieobsługiwana figura\n";
                            continue;
                        }
                    }
                    catch(...){
                        cout << "Parse error : " << count << '\n';
                        continue;
                    }
                }
                else{
                    cout << "Zła liczba argumentów : " << count << '\n';
                    continue;
                }
                break;
            case 'c':
                if(arr.size() != 2){
                    cout << "Zła liczba argumentów : " << count << '\n';
                    continue;
                }
                double rad;
                try{
                    rad = std::stod(arr[1]);
                    if(rad < 0){
                        cout << "Argumenty muszą być niemniejsze od 0 : " << count << '\n';
                        continue;
                    }
                    list.push_back(new circle(rad));
                }
                catch(...){
                    cout << "Parse error : " << count << '\n';
                    continue;
                }
                break;
            case 'p':
                if(arr.size() != 2){
                    cout << "Zła liczba argumentów : " << count << '\n';
                    continue;
                }
                try{
                    rad = std::stod(arr[1]);
                    if(rad < 0){
                        cout << "Argumenty muszą być niemniejsze od 0 : " << count << '\n';
                        continue;
                    }
                    list.push_back(new pentagon(rad));
                }
                catch(...){
                    cout << "Parse error : " << count << '\n';
                    continue;
                }
                break;
            case 'h':
                if(arr.size() != 2){
                    cout << "Zła liczba argumentów : " << count << '\n';
                    continue;
                }
                try{
                    rad = std::stod(arr[1]);
                    if(rad < 0){
                        cout << "Argumenty muszą być niemniejsze od 0 : " << count << '\n';
                        continue;
                    }
                    list.push_back(new hexagon(rad));
                }
                catch(...){
                    cout << "Parse error : " << count << '\n';
                    continue;
                }
                break;
            default:
                cout << "Figura nie jest obsługowana : " << count << '\n';
                break;
        }
    }
    for(auto f : list){
        cout << '\n';
        cout << f->name() << '\n';
        cout << f->area() << '\n';
        cout << f->perm() << '\n';
    }
    return 0;
}

