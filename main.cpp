#include <iostream>
#include <string>
#include <cctype> // isdigit için
using namespace std;
#include <algorithm>


string filtrer_chiffres(const string& s) {
    string n_string = s;

/*
    *  auto flt_str = remove_if(n_string.begin(), n_string.end(), [](char c) {
          return (!isdigit(c));
      });
        n_string.erase(flt_str, n_string.end());
    return n_string;
 */
    erase_if(n_string,[](char c) {
      return  !isdigit(c);
    });
    return n_string;
}
int main() {
    cout << filtrer_chiffres("a1b2c3d4e5") << endl;
    cout << filtrer_chiffres("HEIG-VD 2025") << endl;
    cout << filtrer_chiffres("No digits here") << endl;

    string s("HEIG-VD");
    string k = s.substr(0, 3).append("X");
    cout << k;
}


