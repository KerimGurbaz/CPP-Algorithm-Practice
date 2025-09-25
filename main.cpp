
#include <iostream>
#include <string>
using namespace std;


char min_car(string& s) {
    char min_index = 0;
    for(size_t i = 1;i<s.size(); i++) {
        if(s[i] < s[min_index]) {
            min_index = i;
        }
    }
    return s[min_index];
}

int main() {
    std::string str("98716234");
    std::cout << "str : " << str << std::endl;
    std::cout << "min : " << min_car(str) << std::endl;
   //min_car(str) = '5'; // Fonksiyonun dönüş değeriyle string'in içini değiştiriyoruz
    std::cout << "str : " << str << std::endl;
    return 0;
}