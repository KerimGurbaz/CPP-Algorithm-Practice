#include <iostream>
#include <iomanip>
#include <vector>
#include <span>
#include <array>


// using namespace std;
// template<typename U, typename T, typename N>
// vector<U> concat_tab(T v1, T v2, N a1, N a2) {
//     vector<U> r;
//
//     for(T it = v1; it != v2; ++it) {
//         r.push_back(*it);
//     }
//
//     for(auto it = a1; it != a2; ++it) {
//         r.push_back(*it);
//     }
//     r.shrink_to_fit();
//     return r;
// }
// template<typename T, size_t N>
// ostream& operator<<(ostream& os, span<T, N>s) {
//     for(size_t i = 0; i<s.size(); ++i) {
//         if(i)os<<",";
//         os<<s[i];
//     }
//     return os;
// }
//
//
//
// int main() {
//
//     vector v {11, 12, 13};
//     array  a {21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     vector r = concat_tab<int>(v.begin(), v.end(),
//                                a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }


// template <typename T, typename T1, typename T2>
// vector<T> concat_tab(T1 v1, T1 v2, T2 a1, T2 a2 ) {
//     vector<T> res(v1, v2);
//
//     res.insert(res.end(), a1, a2);
//     return res;
// }
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s) {
//     os<<"[";
//     for(size_t i = 0; i <s.size(); ++i) {
//         os<<s[i];
//         if(i <s.size()-1) {
//             os<<",";
//         }
//     }
//     os<<"]";
//     return os;
// }
//
//
// int main() {
//     vector v {11, 12, 13};
//     array  a {21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     // Appel explicite du template <int>
//     vector r = concat_tab<int>(v.begin(), v.end(),
//                                a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <span>
#include <array>
using namespace std;

template<typename T1, typename T2, typename T3>
vector<T1> merge(T2 first1, T2 last1, T3 first2, T3 last2) {
    vector<T1> result;
    int d1 = distance(first1, last1);
    int d2 = distance(first2, last2);
    result.reserve(d1 + d2);
    int minVal = min(d1, d2);
    while (minVal > 0) {
        result.push_back(*first1++);
        result.push_back(*first2++);
        --minVal;
    };

    if (first1 != last1) {
        result.insert(result.end(), first1, last1);
    }
    if (first2 != last2) {
        result.insert(result.end(), first2, last2);
    }
    return result;
}

template<typename T>
ostream& operator<<(ostream& os, span<T>s) {
    os<<"[";
    for(size_t i = 0; i<s.size(); ++i) {
        os<<s[i];
        if(i<s.size()-1)os<<",";
    }
    return os<<"]";
}


int main() {
    vector v{11, 12, 13};
    array a{21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = merge<int>(v.begin(), v.end(),
                          a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}
