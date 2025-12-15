// #include <iostream>
// #include <cstring>
// #include <string_view>
// using namespace std;
//
// template<typename T>
// T trouver_max(const T& a, const T& b) {
//     return a > b ? a : b;
// }
//
// // const char* trouver_max(const char* a, const char* b) {
// //     if(strcmp(a,b)>0) {
// //         return  a;
// //     }else {
// //         return b;
// //     }
// // }
//
// string_view trouver_max(string_view a, string_view b) {
//     return a>b ? a:b;
// }
//
// int main() {
//     cout << trouver_max(10, 20) << endl; // Affiche 20
//      cout << trouver_max("Avion", "Zebre") << endl; // Affiche "Zebre" (Ordre alphabétique)
// }

// #include <iostream>
// using namespace std;
//
// // Ecrivez la fonction 'convertir' ici.
// // Elle prend un paramètre de type U et retourne un type T.
// // ...
//
// template<typename T, typename T2>
// T convertir(const T2 & val) {
//     return T(val);
// }
//
// int main() {
//     double pi = 3.14159;
//
//     // Doit retourner 3
//     int ent = convertir<int>(pi);
//
//     // Doit retourner 'A' (ASCII 65)
//     char c = convertir<char>(65);
//
//     cout << ent << " / " << c << endl;
// }


// #include <iostream>
// using namespace std;
//
// class A {
// public:
//     A() { cout << "A+ "; }
//     ~A() { cout << "A- "; }
// };
//
// class B {
//     A a; // Membre de type A
// public:
//     B() { cout << "B+ "; }
//     ~B() { cout << "B- "; }
// };
//
// int main() {
//     cout << "Start ";
//     {
//         B b;
//     }
//     cout << "End";
//     return 0;
// }

// class Buffer {
//     int* data;
//     int size;
// public:
//     Buffer(int s) : size(s) {
//         data = new int[size];
//     }
//     ~Buffer() {
//         delete[] data;
//     }
//  Buffer(const Buffer&other ): size(other.size) {
//         data = new int[other.size];
//         for(int i = 0; i<size; ++i) {
//             data[i] = other.data[i];
//         }
//     }
//
//     Buffer& operator=(const Buffer& other) {
//         if(this ==&other) {
//             return *this;
//         }
//
//         delete[] data;
//
//         this->size = other.size;
//         this->data = new int[this->size];
//
//         for(int i = 0; i<size; ++i) {
//             this->data[i] = other.data[i];
//         }
//
//         return *this;
//     }
// };

#include <iostream>
using namespace std;
#include <vector>
#include <array>
#include <iterator>
#include <span>
#include <algorithm>

template<typename T, typename U, typename U2>

vector<T> alterne(U first1, U last1, U2 first2, U2 last2 ) {
    vector<T> v;
    v.reserve(distance(first1, last1) + distance(first2, last2));

    while(first1 != last1 and first2 != last2) {
        v.push_back(*first1++);
        v.push_back(*first2++);
    }
    while(first1 != last1) {
        v.push_back(*first1++);
    }

    while(first2 != last2) {
        v.push_back(*first2++);
    }

    return v;

}

template<typename T>
ostream& operator<<(ostream& os, span<T>s) {
    for(size_t i  =0; i<s.size(); ++i) {
        os<<s[i]<< " ";
    }
    return os;
}



int main() {

    vector v {11, 12, 13};
    array  a {21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = alterne<int>(v.begin(), v.end(),
                               a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}

