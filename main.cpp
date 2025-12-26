//
//
// template<typename T, typename it1, typename it2>
//
// // vector<T>concat_tab(it1 first1, it1 last1, it2 first2, it2 last2) {
// //     vector<T>result {first1, last1};
// //     result.insert(result.end(), first2, last2);
// //     return result;
// // }
//
// vector<T> concat_tab(it1 first1, it1 last1, it2 first2, it2 last2) {
//     vector<T> result;
//     size_t n1 = distance(first1, last1);
//     size_t n2 = distance(first2, last2);
//     result.resize(n1 + n2);
//     for (size_t i = 0; i < n1; ++i) {
//         result[i] = *(first1++);
//     }
//     for (size_t i = 0; i < n2; ++i) {
//         result[n1+i] = (*first2++);
//     }
//     return result;
// }
//
// template<typename T>
// ostream &operator<<(ostream &os, span<T> s) {
//     os << "[";
//     for (auto it = s.begin(); it != s.end(); ++it) {
//         os << *it << " ";
//     }
//     os << "]";
//     return os;
// }
//
// int main() {
//     vector v{11, 12, 13};
//     array a{21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     vector r = concat_tab<int>(v.begin(), v.end(),
//                                a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }


#include <vector>
#include <iostream>
#include <array>
#include <span>
using namespace std;

// template<typename T, typename it1, typename it2>
// vector<T> merge(it1 first1, it1 last1, it2 first2, it2 last2) {
//     vector<T> result;
//     result.reserve(distance(first1, last1) + distance(first2, last2));
//     while (first1 != last1 && first2 != last2) {
//         result.push_back(*first1++);
//         result.push_back(*first2++);
//     }
//
//     while (first1 != last1) {
//         result.push_back(*first1++);
//     }
//     while (first2 != last2) {
//         result.push_back(*first2++);
//     }
//
//     return result;
// }
//
// template<typename T>
// ostream&operator<<(ostream&os, span<T>s) {
//     os<<"[";
//     for(auto it = s.begin(); it!= s.end(); ++it) {
//         os<<*it;
//         if(it!=s.end()-1)os<<",";
//     }
//     os<<"]";
//     return os;
// }
//
// int main() {
//     vector v{11, 12, 13};
//     array a{21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     vector r = merge<int>(v.begin(), v.end(),
//                           a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }

// #include <algorithm>
//
// template<typename T>
// struct entre {
//     T min;
//     T max;
//
//     bool operator()(const T& n)const  {
//         return n>=min && n<=max;
//     }
//
// };
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s){
//     for(size_t i = 0; i<s.size(); ++i) {
//         if(i)os<<",";
//         os<<s[i];
//     }
//     return os;
// }
//
// int main() {
//
//     vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     cout << span(v) << endl;
//
//     cout << count_if(v.begin(), v.end(), entre<int>{3, 6});
// }

// template<typename T, typename it>
//
// vector<T> vect_iter_val(const vector<T> &v, const T &n) {
//     using valueType = typename iterator_traits<it>::value_type;
//     vector<valueType> result;
//
//     for (size_t i = 0; i < v.size(); ++i) {
//         if (v[i] == n) {
//             result.push_back(&(v[i]));
//         }
//     }
//     return result;
// }
//
// template<typename T>
// void afficher_vect_iter(const vector<T> &v) {
//     for (auto it = v.begin(); it != v.end(); ++it) {
//         cout << *it;
//     }
// }
//
// template<typename T>
// ostream &operator<<(ostream &os, span<T> s) {
//     for (size_t i = 0; i < s.size(); ++i) {
//         if (i)os << ",";
//         os << s[i];
//     }
//     return os;
// }
//
// int main() {
//     vector v{1, 2, 3, 2, 4, 2, 2, 6, 2};
//
//     using it_int = vector<int>::const_iterator;
//
//     cout << "vecteur d'entiers     : " << span(v) << endl;
//     vector vect_int_ref = vect_iter_val<int, it_int>(v, 2);
//     cout << "vecteur d'iterateurs  : ";
//     afficher_vect_iter(vect_int_ref);
// }
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

// sen bunu yazacaksın
template<typename C1, typename C2>
bool meme_elements(const C1 &c1, const C2 &c2) {
    vector<typename C1::value_type> eq1{c1.begin(), c1.end()};
    vector<typename C2::value_type> eq2{c2.begin(), c2.end()};
    sort(eq1.begin(), eq1.end());
    sort(eq2.begin(), eq2.end());

    eq1.erase(unique(eq1.begin(), eq1.end()), eq1.end());
    eq2.erase(unique(eq2.begin(), eq2.end()), eq2.end());

    return eq1 == eq2;
}

int main() {
    array<int, 10> a{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};

    cout << boolalpha;
    cout << "Mêmes éléments ? "
            << meme_elements(a, v)
            << endl;

    return 0;
}
