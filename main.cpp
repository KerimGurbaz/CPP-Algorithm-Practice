#include <vector>
#include <iostream>
#include <string>
using namespace std;

// TODO: retourner les mots de longueur >= min_len
vector<string> filtrer_longueur(const vector<string>& mots, size_t min_len) {
    vector<string> new_str;
    new_str.reserve(mots.size());
    for(const auto& el : mots) {
        if(el.size() >= min_len ) {
            new_str.push_back(el);
        }
    }
    return new_str;
}



int main() {
    vector<string> v{"C++", "est", "genial", "HEIG-VD", "SYL"};
    auto r1 = filtrer_longueur(v, 4);
    auto r2 = filtrer_longueur(v, 6);
    auto r3 = filtrer_longueur(v, 10);

    for (auto& s : r1) cout << s << ' '; cout << '\n'; // genial HEIG-VD
    for (auto& s : r2) cout << s << ' '; cout << '\n'; // genial HEIG-VD
    for (auto& s : r3) cout << s << ' '; cout << '\n'; // (rien)
}
