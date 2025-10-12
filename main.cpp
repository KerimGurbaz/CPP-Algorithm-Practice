#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i < 5; ++i) {
        if (i == 1) continue;
        switch (i) {
            case 0: std::cout << "A";
            case 2: std::cout << "B"; break;
            case 3: std::cout << "C"; continue;
            case 4: std::cout << "D";
        }
        std::cout << "-";
    }
std::cout<<std::endl;
    int n = 0;
    while (n < 8) {
        n++;
        switch (n) {
            case 1: std::cout << "S";
            case 2: continue;
            case 3: std::cout << "T"; break;
            case 4: n++; // n'in değeri burada tekrar değişiyor
            case 5: std::cout << "U";
            case 6: std::cout << "V"; continue;
            default: std::cout << "W";
        }
        std::cout << n;
    }
    cout<<endl;

    int x = 7, y = -3;
    cout << x % y;
    return 0;
}