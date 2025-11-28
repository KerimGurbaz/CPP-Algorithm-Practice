#include <iostream>
#include <array>
#include <iomanip>
#include <cstdint>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// template<typename T>
//
// ostream &operator<<(ostream &os, const vector<T> &v) {
//     os << "[";
//     for (size_t i = 0; i < v.size(); ++i) {
//         os << v[i] << (i < v.size() - 1 ? ", " : "");
//     }
//     return os << "]";
// };
//
// template<typename T>
// ostream &operator<<(ostream &os, const vector<vector<T> > &m) {
//     os << "[";
//     for (size_t i = 0; i < m.size(); ++i) {
//         if (i) {
//             os << "\n";
//         }
//         os << m[i];
//     }
//     os << "]";
//     return os;
// }
//
// template<typename T>
// using Ligne = vector<T>;
// template<typename T>
// using Matrice = vector<Ligne<T> >;
//
// int main() {
//     Matrice<int> m{
//         {0},
//         {1, 2},
//         {3, 4, 5},
//         {6, 7, 8, 9}
//     };
//
//     cout << m << endl;
//     return 0;
// }


enum class Chiffre { ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF };

string to_string(Chiffre c) {
    switch (c) {
        case Chiffre::ZERO: return "ZERO";
        case Chiffre::UN: return "UN";
        case Chiffre::DEUX: return "DEUX";
        case Chiffre::TROIS: return "TROIS";
        case Chiffre::QUATRE: return "QUATRE";
        case Chiffre::CINQ: return "CINQ";
        case Chiffre::SIX: return "SIX";
        case Chiffre::SEPT: return "SEPT";
        case Chiffre::HUIT: return "HUIT";
        case Chiffre::NEUF: return "NEUF";
        default: return "incnnu";
    }
}

ostream &operator<<(ostream & os, const vector<Chiffre> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0) os << " ";
        os << to_string(v[i]);
    }
    return os;
}

vector<Chiffre> nbreToEnums(int n) {
    if (n == 0)return {Chiffre::ZERO};
    vector<Chiffre> result;
    n = abs(n);

    while (n > 0) {
        int digit = n % 10;
        result.push_back(static_cast<Chiffre>(digit));
        n /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}


int main() {
    cout << nbreToEnums(123) << endl; // UN DEUX TROIS
    cout << nbreToEnums(0) << endl;   // ZERO
    cout << nbreToEnums(905) << endl; // NEUF ZERO CINQ

    return 0;
}