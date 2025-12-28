
#include <iostream>
using namespace std;

// template<typename T>
// void permutationCirculaireDroite (T& x, T & y, T& z) {
//     T temp =z;
//     z = y;
//     y = x;
//     x = temp;
//
// }
//
// template<typename T>
// void afficher(const T&x,const T&y, const T&z) {
//     cout<<"x = "<<x<<", y = "<<y<<", z= "<<z<<endl;
// }
//
// int main() {
//     double x = 1, y = 2, z = 3;
//     for (int i = 1; i <= 3; ++i) {
//         permutationCirculaireDroite(x, y, z);
//         afficher(x, y, z);
//     }
//     return EXIT_SUCCESS;
// }

// #include <iostream>
// #include <cstring> // strcmp için
// #include <string_view>
// using namespace std;
//
// // GENEL TEMPLATE
// template<typename T>
// bool estEgal(T a, T b) {
//     return a == b;
// }
//
// template<>
// bool estEgal<char*>(char* a, char* b) {
//     cout<<"specialization ";
//     return strcmp(a, b) == 0;
// }
//
//
// int main() {
//     // Durum 1: Tamsayılar (Sorunsuz)
//     cout << "10 == 10 ? " << estEgal(10, 10) << endl;
//
//     // Durum 2: C-Stringler (TUZAK!)
//     char s1[] = "HEIG";
//     char s2[] = "HEIG";
//
//
//     cout << "HEIG == HEIG ? " << estEgal(s1, s2) << endl;
//
//     return 0;
// }


// template<typename T>
// void rotation_droite (T& x, T & y, T& z, T&t) {
//     T temp =t;
//     t = z;
//     z = y;
//     y = x;
//     x =temp;
//
// }
//
// template<typename T>
// void afficher(const T&x,const T&y, const T&z, const T&t) {
//     cout<<"x = "<<x<<", y = "<<y<<", z= "<<z<<", t= "<<t<<endl;
// }
//
// int main() {
//     double x = 1, y = 2, z = 3, t =4;
//     for (int i = 1; i <= 3; ++i) {
//         rotation_droite(x, y, z, t);
//         afficher(x, y, z, t);
//     }
//     return EXIT_SUCCESS;
// }

// template<typename T>
// T& min(T&a, T& b, T&c) {
//  return    a<b ? (a<c?a : c): b<c ?b:c ;
// }
//
// int main() {
//
//     int    a = 5;
//     int    b = 2;
//     int    c = 9;
//
//     double d = 5.0;
//     double e = 2.0;
//     double f = 9.0;
//
//     cout << min(a, b, c);
//     min(a, b, c) = 1;
//     int& min_abc = min(a, b, c);
//
//     cout << min(d, e, f);
//     min(d, e, f) = 1;
//     double& min_def = min(d, e, f);
// }
#include <iostream>

#include <vector>
#include <span>
#include <algorithm>

using namespace std;
template<typename T, size_t N>
void tri(span<T, N>s) {
    for(size_t i = 0; i<s.size(); ++i) {
        size_t idx = i;
        for(size_t j = i+1; j<s.size(); ++j) {
            if(s[j] < s[i]) {
                idx = j;
            }
        }
        if(i != idx) {
            swap_iterator(s[i], s[idx]);
        }
    }
}

template<typename T, size_t N>
ostream& operator<<(ostream& os, span<T, N>s) {
    os<<"[";
    for(size_t i  =0; i<s.size(); ++i) {
        if(i != 0) os<<",";
        os<<s[i];
    }
    os<<"]";
    return os;
}

int main() {
    vector v      {6, 2, 8, 7, 1, 3};
    afficher(span(v));
    tri(span(v));
    afficher(span(v));

    array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
    afficher(span(a)); tri(span(a)); afficher(span(v));

    double t[6] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
    afficher(span(t)); tri(span(t)); afficher(span(t));
}