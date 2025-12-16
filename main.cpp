#include <iostream>
#include <vector>
#include <span>
#include <algorithm>
using namespace std;

// template <typename T>
// struct entre {
//     const int min;
//     const int max;
//
//     bool operator()(const T& e) {
//         return e>= min && e<=max;
//     }
// };
//
// template<typename T>
// ostream&operator<<(ostream& os, span<T>s) {
//     for(const auto& el: s) {
//         os<<el<<" ";
//     }
//     return os;
// }
// int main() {
//
//     vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     cout << span(v) << endl;
//
//     cout << count_if(v.begin(), v.end(), entre<int>{3, 6});
// }

template<typename T, typename T2>
vector<T2> vect_iter_val(const vector<T>&v, T n) {
    vector<T2> res;
    for(auto it = v.begin(); it != v.end(); ++it) {
        if(*it == n) {
            res.push_back(it);
        }
    }
return res;
}

template<typename T>
void afficher_vect_iter(const T& s)  {
    for(const auto& el :s) {
        cout<<*el<<" ";
    }
}

template<typename T>
ostream& operator<<(ostream& os, span<T>s) {
for(const auto& el :s) {
    os<<el<<" ";
}
    return os;
}


int main() {

    vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};

    using it_int = vector<int>::const_iterator;

    cout << "vecteur d'entiers     : " << span(v) << endl;
    vector vect_int_ref = vect_iter_val<int, it_int>(v, 2);
    cout << "vecteur d'iterateurs  : ";
    afficher_vect_iter(vect_int_ref);
}