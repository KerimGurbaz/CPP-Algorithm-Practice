#include <iostream>
#include <vector>
#include <array>
#include <numeric>

#include "../../../../../../Program Files/JetBrains/CLion 2024.1.4/bin/mingw/x86_64-w64-mingw32/include/fenv.h"
using namespace std;


// template < typename T, typename T2>
// T2 somme_elements (T first, T last) {
//     // auto res = accumulate(first, last, 0.);
//     // return res;
//     T2 somme = T2{};
//     for(T it = first; it != last; ++it) {
//         somme+= *it;
//     }
// }

// template < typename T>
// auto somme_elements (T first, T last) {
//     using ValueType = typename iterator_traits<T>::value_type;
//     // auto res = accumulate(first, last,ValueType{});
//     // return res;
//
//     ValueType somme =ValueType{};
//     for(T it = first; it != last; ++it) {
//         somme+= *it;
//     }
//
//      return somme;
// }


// int main() {
//     vector<int> v {10, 20, 30, 40, 50};
//     cout << somme_elements(v.begin()+1, v.end()-1) << endl;
//
//     array<double, 5> a {1.5, 2.5, 3.0, 4.0, 5.0};
//     cout << somme_elements(a.begin()+2, a.end()) << endl;
//
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <cctype>
// #include <span>
// using namespace std;
//
//
// template<typename T, typename Fonk>
// void supprimer_si(vector<T>& v, Fonk fonk) {
//     int write =0;
//
//    for(size_t read = 0; read<v.size(); ++read) {
//        if(!fonk(v[read])) {
//            v[write++] = v[read];
//        }
//    }
//     v.resize(write);
// }
//
// bool est_pair(int x) {
//     return x % 2 == 0;
// }
//     int main() {
//         vector<int> v{1, 2, 3, 4, 5, 6, 7};
//         supprimer_si(v, est_pair);
//
//         for (int x: v) cout << x << " ";
//         cout << endl;
//
//         vector<char> c{'A', '1', 'B', '2', 'C', '3'};
//         supprimer_si(c, ::isdigit);
//
//         for (char ch: c) cout << ch;
//         cout << endl;
//
//         return 0;
//     }

// #include <iostream>
// #include <vector>
// #include <utility>
// #include <iterator>
// using namespace std;
//
// template<typename T>
// pair<T, T> plus_long_sequence_croissante(T first, T last) {
//     T bestStart = first;
//     T bestEnd = next(first);
//     size_t bestSeq = 1;
//
//     T curStart = first;
//     size_t curSeq = 1;
//
//     for (T it = next(first); it != last; ++it) {
//         if (*it >= *(prev(it))) {
//             ++curSeq;
//         } else {
//             if (curSeq > bestSeq) {
//                 bestStart = curStart;
//                 bestEnd = it;
//                 bestSeq = curSeq;
//             }
//             curStart = it;
//             curSeq = 1;
//         }
//     }
//     if (curSeq > bestSeq) {
//         bestStart = curStart;
//         bestEnd = last;
//         bestSeq = curSeq;
//     }
//
//     return {bestStart, bestEnd};
// }
//
// int main() {
//     vector<int> v{5, 1, 2, 3, 2, 3, 4, 5, 1};
//
//     auto res = plus_long_sequence_croissante(v.begin(), v.end());
//
//     for (auto it = res.first; it != res.second; ++it)
//         cout << *it << " ";
//     cout << endl;
//
//     return 0;
// }
