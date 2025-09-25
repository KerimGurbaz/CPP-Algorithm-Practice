
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char& min_car(string& str) {
    size_t min_pos = 0;
    for(size_t i = 1 ; i<str.size(); i++) {
        if(str[i] < str[min_pos]) {
            min_pos = i;
        }
    }
    return str[min_pos];
}
int count=0;
int majuscule(string& text) {
    for(size_t i =0; i<text.size(); i++) {
        if(isupper(text[i])) {
            count++;
        }
    }
    cout<<count;
}


char& premier_e(string& s ) {
    size_t pos = s.find_first_of('e');

    return pos!=string::npos ? s[pos] : s[s.size()-1];
}

int main() {
    std::string s = "Hello";
    premier_e(s) = 'X';
    std::cout << s << std::endl;

    std::string s2 = "abracadabra";
    premier_e(s2) = 'X';
    std::cout << s2 << std::endl;



    std::string str("98716234");
    std::cout << "str : " << str << std::endl;
    std::cout << "min : " << min_car(str) << std::endl;
    min_car(str) = '5'; // Fonksiyonun dönüş değeriyle string'in içini değiştiriyoruz
    std::cout << "str : " << str << std::endl;
}