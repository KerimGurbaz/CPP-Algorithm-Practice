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

// template<typename T, typename T2>
// vector<T2> vect_iter_val(const vector<T>&v, T n) {
//     vector<T2> res;
//     for(auto it = v.begin(); it != v.end(); ++it) {
//         if(*it == n) {
//             res.push_back(it);
//         }
//     }
// return res;
// }
//
// template<typename T>
// void afficher_vect_iter(const T& s)  {
//     for(const auto& el :s) {
//         cout<<*el<<" ";
//     }
// }
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s) {
// for(const auto& el :s) {
//     os<<el<<" ";
// }
//     return os;
// }
//
//
// int main() {
//
//     vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};
//
//     using it_int = vector<int>::const_iterator;
//
//     cout << "vecteur d'entiers     : " << span(v) << endl;
//     vector vect_int_ref = vect_iter_val<int, it_int>(v, 2);
//     cout << "vecteur d'iterateurs  : ";
//     afficher_vect_iter(vect_int_ref);
// }
// #include <set>
// using namespace std;
//
// template<typename Cont>
// bool meme_elements(span<int>s, span<int>s2) {
//
//     set<int>my1 {s.begin(), s.end()};
//     set<int>my2 {s2.begin(), s2.end()};
//
//     return my1 ==my2;
// }
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s) {
//     for(size_t i =0; i<s.size(); ++i) {
//         os<<s[i]<<" ";
//     }
//     return os;
// }
//
//
// template<typename T>
// bool operator<<(span<T> tab1, span<T> tab2) {
//
// }
// int main() {
//
//     array  a {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
//
//     cout << span<int>(a) << endl;
//     cout << span<int>(v) << endl;
//
//     cout << meme_elements<int>(span<int>(a), span<int>(v));
// }

// #include <iostream>
// #include <vector>
// #include <array>
// #include <set>
// #include <algorithm> // Eğer std::set_intersection kullanacaksan
// #include <span>
//
// using namespace std;
//
// // ---------------------------------------------------------
// // YARDIMCI: Ekrana Yazdırma
// // ---------------------------------------------------------
// template <typename T>
// ostream& operator<<(ostream& os, span<T> s) {
//     os << "[ ";
//     for (size_t i = 0; i < s.size(); ++i) {
//         if (i) os << ", ";
//         os << s[i];
//     }
//     return os << "]";
// }
//
// // ---------------------------------------------------------
// // SENİN KODUN BURAYA GELECEK
// // Fonksiyon İmzasını: intersection(...) olarak ayarla
// // ---------------------------------------------------------
//
// template<typename T>
// vector<T> intersection(span<T>s1, span<T>s2) {
//     set<T> myset1 {s1.begin(), s1.end()};
//     set<T> myset2 {s2.begin(), s2.end()};
//
//     vector<T> res ;
//
//     for(const auto& el : myset1) {
//         if(myset2.count(el)) {
//             res.push_back(el);
//         }
//     }
// return res;
// }
//
// // ---------------------------------------------------------
// // MAIN (Test Ortamı - Değiştirme)
// // ---------------------------------------------------------
// int main() {
//     // Test Verileri (Karışık ve tekrar eden sayılar var)
//     vector v {1, 5, 2, 1, 9, 5};
//     array  a {2, 9, 3, 4, 2, 9};
//
//     cout << "Kume A (Vector): " << span<int>(v) << endl;
//     cout << "Kume B (Array) : " << span<int>(a) << endl;
//
//     // Fonksiyon Çağrısı
//     // T tipi 'int' olarak dedüke edilecek
//     vector<int> sonuc = intersection(span<int>(v), span<int>(a));
//
//     cout << "Kesisim (A n B): " << span<int>(sonuc) << endl;
//
//     // Beklenen Çıktı: [ 2, 9 ]
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm> // Algoritmalar burada
// #include <iterator>  // back_inserter için gerekli
// #include <span>
//
// using namespace std;
//
// // ------------------------------------------------------------------
// // GÖREV: Aşağıdaki 3 fonksiyonu doldur
// // ------------------------------------------------------------------
//
// // 1. Kesişim (Intersection): v1 ve v2'nin ortak elemanlarını döndür
// template<typename T>
// vector<T> trouver_intersection(const vector<T> &v1, const vector<T> &v2) {
//     vector<T> res;
//
//     set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(res));
//     return res;
// }
//
// // 2. Alt Küme (Subset): v_sub içindeki TÜM elemanlar v_main'de var mı?
// template<typename T>
// bool est_sous_ensemble(const vector<T> &v_main, const vector<T> &v_sub) {
//     for (const auto &el: v_sub) {
//         if (!(v_main.count(el))) {
//             return false;
//         }
//         return true;
//     }
// }
//
// // 3. Blok Arama (Sequence): v_seq, v_main içinde BLOK (bitişik) olarak var mı?
// template<typename T>
// bool contient_sequence(const vector<T> &v_main, const vector<T> &v_seq) {
//     return search(v_main.begin(), v_main.end(), v_seq.begin(), v_seq.end());
// }
//
// // ------------------------------------------------------------------
//
// template<typename T>
// ostream &operator<<(ostream &os, span<T> s) {
//     os << "[ ";
//     for (const auto &el: s) os << el << " ";
//     return os << "]";
// }
//
// int main() {
//     // Veriler SIRALI (Sorted)
//     vector<int> v_ana{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     vector<int> v_parca_1{2, 3, 4}; // Yan yana (Sequence)
//     vector<int> v_parca_2{2, 5, 9}; // Ayrık ama içinde (Subset)
//     vector<int> v_baska{5, 6, 7, 11, 12}; // Ortak elemanları var
//
//     cout << "Ana Vektor: " << span(v_ana) << endl;
//
//     // Test 1: Intersection
//     cout << "\n--- Kesisim (Intersection) ---" << endl;
//     vector<int> ortak = trouver_intersection(v_ana, v_baska);
//     cout << "Ortak Elemanlar (5, 6, 7 olmali): " << span(ortak) << endl;
//
//     // Test 2: Includes (Subset)
//     cout << "\n--- Alt Kume (Includes) ---" << endl;
//     cout << "{2, 5, 9} alt kume mi? (Evet olmali): "
//             << (est_sous_ensemble(v_ana, v_parca_2) ? "EVET" : "HAYIR") << endl;
//
//     // Test 3: Search (Sequence)
//     cout << "\n--- Blok Arama (Search) ---" << endl;
//     cout << "{2, 3, 4} blok olarak var mi? (Evet olmali): "
//             << (contient_sequence(v_ana, v_parca_1) ? "EVET" : "HAYIR") << endl;
//
//     cout << "{2, 5, 9} blok olarak var mi? (Hayir olmali): "
//             << (contient_sequence(v_ana, v_parca_2) ? "EVET" : "HAYIR") << endl;
//
//     return 0;
// }


// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// void tri_insertion(vector<int>& v) {
//     for(size_t i = 0; i<v.size();++i) {
//         size_t min_idx = i;
//         for(size_t j =i+1 ; j < v.size(); ++j) {
//             if(v[j] < v[min_idx]) {
//                 min_idx =j;
//             }
//         }
//         if(i != min_idx) {
//             swap(v[i], v[min_idx]);
//         }
//     }
// }
//
// void affichage(const vector<int> v) {
//     for(const auto& el : v) {
//         cout<<el<<" ";
//     }
//
// }
//
// int main() {
//     vector<int> v = {7, 5, 3, 9, 6};
//     tri_insertion(v);
//
//     affichage(v);
// }

// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// void tri_insertion(vector<int>& v) {
//     for(size_t i =1; i<v.size(); ++i) {
//         int key = v[i];
//         int j = i;
//
//
//         while(j>0 && v[j-1] > key) {
//             v[j] = v[j-1];
//             j--;
//         }
//         v[j] = key;
//     }
// }
//
// int main() {
//     vector<int> v = {7, 5, 3, 9, 6};
//     tri_insertion(v);
//
//
// }
// #include <set>
// #include <cctype>
// template<typename T>
// ostream &operator<<(ostream &os, span<T> s) {
//     for(const auto& el: s) {
//         os<<el<<" ";
//     }
//     return os;
// }
//
// template<typename T>
// bool meme_elements(span<T> s1, span<T> s2) {
//
//     set<T> mySet1 {s1.begin(), s1.end()};
//     set<T> mySet2 {s2.begin(), s2.end()};
//
//
//     return (mySet1 == mySet2);
// }
//
//
//
// int main() {
//     array a{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
//
//     cout << span<int>(a) << endl;
//     cout << span<int>(v) << endl;
//
//     cout << meme_elements<int>(span<int>(a), span<int>(v));
// }

// #include <iostream>
// #include <vector>
// #include <span>
// using namespace std;
//
//
// template<typename Iter, typename Out>
// vector<Out> vect_iter_val(const vector<Iter>& v ,Iter num ) {
//     vector<Out> res;
//     for(auto it = v.begin(); it != v.end(); ++it) {
//         if(*it == num) {
//             res.push_back(it);
//         }
//     }
//     return res;
// }
//
// template<typename T>
// ostream& operator<<(ostream & os, span<T> s) {
//     for(const auto& el: s) {
//         os<<el<<" ";
//     }
//     return os;
// }
//
// template<typename T>
// void afficher_vect_iter(const vector<T>& s) {
//     for(T el : s) {
//         cout<<*el<<" ";
//     }
// }
//
// int main() {
//
//     vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};
//
//     using it_int = vector<int>::const_iterator;
//
//     cout << "vecteur d'entiers     : " << span(v) << endl;
//     vector vect_int_ref = vect_iter_val<int, it_int>(v, 2);
//     cout << "vecteur d'iterateurs  : ";
//     afficher_vect_iter(vect_int_ref);
// }

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <algorithm>

using namespace std;
template<typename T, typename T2>
auto n_plus_petits_elements_distincts(T first, T last, T2 n) {
using valueType = typename iterator_traits<T>::value_type;

    vector<valueType> result(first, last) ;
    sort(result.begin(), result.end());
    auto it = unique(result.begin(), result.end());
        result.erase(it, result.end());

    if(result.size() > size_t(n)) {
        result.resize(n);
    }
    return result;
}

template<typename T>
auto n_plus_petits_elements_distincts(T first, T last) {
    using valueType = typename iterator_traits<T>::value_type;

    vector<valueType> result  (first, last);
    sort(result.begin(), result.end());
    auto it =unique(result.begin(), result.end());
    result.erase(it, result.end());

    return result;
    }


int main() {
    cout << fixed;

    vector<int> v1{1, 2, 5, 3, 7, 5, 0, 3, 4};
    auto v1r = n_plus_petits_elements_distincts(v1.begin(), v1.end(), 4);
    for(auto e : v1r)
        cout << e << " ";
    cout << endl;

    vector<double> v2{5, 2, 5, 0, 7, 5, 0, 3, 2};
    auto v2r = n_plus_petits_elements_distincts(v2.begin(), v2.end(), 5);
    for(auto e : v2r)
        cout << e << " ";
    cout << endl;

    const array<long, 11> a3{5, 2, -1, 3, 5, 0, 2, 5, 2, 3, 2};
    auto v3r = n_plus_petits_elements_distincts(a3.begin(), a3.end(), 3);
    for(auto e : v3r)
        cout << e << " ";
    cout << endl;

    const list<unsigned> l4{3, 3, 3, 4, 5, 4, 5, 3, 4};
    auto v4r = n_plus_petits_elements_distincts(l4.begin(), l4.end(), 5);
    for(auto e : v4r)
        cout << e << " ";
    cout << endl;

    auto v5r = n_plus_petits_elements_distincts(a3.begin(), a3.end());
    for(auto e : v5r)
        cout << e << " ";
    cout << endl;

}