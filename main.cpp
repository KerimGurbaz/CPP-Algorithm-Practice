#include <vector>
#include <iostream>
#include <array>
#include <span>
using namespace std;


template<typename T, typename it1, typename it2>

// vector<T>concat_tab(it1 first1, it1 last1, it2 first2, it2 last2) {
//     vector<T>result {first1, last1};
//     result.insert(result.end(), first2, last2);
//     return result;
// }

vector<T> concat_tab(it1 first1, it1 last1, it2 first2, it2 last2) {
    vector<T> result;
    size_t n1 = distance(first1, last1);
    size_t n2 = distance(first2, last2);
    result.resize(n1 + n2);
    for (size_t i = 0; i < n1; ++i) {
        result[i] = *(first1++);
    }
    for (size_t i = 0; i < n2; ++i) {
        result[n1+i] = (*first2++);
    }
    return result;
}

template<typename T>
ostream &operator<<(ostream &os, span<T> s) {
    os << "[";
    for (auto it = s.begin(); it != s.end(); ++it) {
        os << *it << " ";
    }
    os << "]";
    return os;
}

int main() {
    vector v{11, 12, 13};
    array a{21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = concat_tab<int>(v.begin(), v.end(),
                               a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}
