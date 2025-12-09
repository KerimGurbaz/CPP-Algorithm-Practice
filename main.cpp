#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <span>
#include <utility>

using namespace std;

template<typename T, size_t N>
void tri_selection(span<T, N>s) {
    for(size_t i = 0; i<s.size()-1; ++i) {
        size_t min_idx = i;
        for(size_t j = i+1; j<s.size(); ++j) {
            if(s[j] < s[min_idx]) {
               min_idx = j;
            }
        }
        if(i != min_idx) {
            swap(s[i], s[min_idx]);
        }
    }
}

template<typename T, size_t N>
void afficher(span<T, N>s) {
    for(T el : s) {
        cout<<el<<" ";
    }
    cout<<endl;
}



int main() {
    // 1. Vector (Dynamic Extent)
    vector v {6, 2, 8, 7, 1, 3};
    afficher(span(v));
    tri_selection(span(v));
    afficher(span(v));
    cout << endl;

    // 2. Array (Static Extent - PATLAYAN KISIM ARTIK ÇALIŞIR)
    // "chien"s kullanımı için literal
    using namespace std::string_literals;
    array a {"chien"s, "chat"s, "souris"s, "poisson"s};

    // span(a) -> span<string, 4> üretir.
    // Fonksiyonumuz artık <string, 4> kabul ediyor.
    afficher(span(a));
    tri_selection(span(a));
    afficher(span(a));
    cout << endl;

    // 3. C-Style Array (Static Extent)
    double t[] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};

    // span(t) -> span<double, 6> üretir.
    afficher(span(t));
    tri_selection(span(t));
    afficher(span(t));

    return 0;
}