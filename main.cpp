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

// #include <iostream>
// #include <span>
// #include <vector>
// #include <algorithm>
// using namespace std;
//
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s) {
//     for(size_t i  =0; i<s.size(); ++i) {
//         os<<s[i]<< " ";
//     }
//     return os;
// }
//
// template<typename T>
// struct entre {
//
//     T min;
//     T max;
//
//     entre(T a, T b): min(a), max(b){}
//
//     bool operator()(const T& v)const {
//         return v>= min && v<=max;
//     }
// };
//
//
//
//
// int main() {
//         vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//         cout << span(v) << endl;
//
//         cout << count_if(v.begin(), v.end(), entre<int>{3, 6});
//     }
//
//
#include <iostream>
#include <vector>
#include <array>
#include <set>       // std::set için GEREKLİ
#include <span>
using namespace std;

// template <typename C1, typename C2>
// bool meme_elements(const C1& cont1, const C2& cont2) {
//     using T1  = typename C1::value_type;
//
//     // using T2 = typename C2::value_type;
//
//     set<T1> s1(cont1.begin(), cont1.end());
//     set<T1> s2 (cont2.begin(), cont2.end());
//
//     return s1 == s2;
// }
//
//
//
// int main() {
//     // Örnek Veriler
//     array<int, 10> a {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     vector<int>    v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2}; // Fazladan 1 ve 2 var
//
//     cout << "Array a ile Vector v ayni elemanlara sahip mi?" << endl;
//
//     // Test
//     if (meme_elements(a, v)) {
//         cout << " -> TRUE (Evet, ayni kumesel icerige sahipler)" << endl;
//     } else {
//         cout << " -> FALSE (Hayir, farklilar)" << endl;
//     }
//
//     // Farklı bir test
//     vector<int> v2 {1, 2, 3};
//     vector<int> v3 {1, 2, 4}; // 3 yerine 4 var
//
//     cout << "\nv2 {1,2,3} ile v3 {1,2,4} ayni mi?" << endl;
//     cout << " -> " << boolalpha << meme_elements(v2, v3) << endl;
//
//     return 0;
// }

#include <vector>
#include <algorithm>

template<typename T1, typename T2>
bool meme_elements(const T1& c1, const T2& c2) {
    using V = typename T1::value_type;

    std::vector<V> v1(c1.begin(), c1.end());
    std::vector<V> v2(c2.begin(), c2.end());

    // Sırala
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    // Tekilleştir
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

    return v1 == v2;
}
#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
    array<int,10> a {10,9,8,7,6,5,4,3,2,1};
    vector<double> v {1.1,2,3,4,5,6,7,8,9,10,1,2};

    cout << boolalpha << meme_elements(a, v) << endl; // true
}
