// #ifndef  TRI_H
// #define TRI_H
//
// #include <span>
// #include <utility>
// using namespace std;

//
// template <typename T, size_t N>
// size_t ind_min(span<T, N>s) {
//     size_t min_idx = 0;
//     for(size_t i = 1; i<s.size(); ++i) {
//         if(s[i] < s[min_idx]) {
//             min_idx = i;
//         }
//     }
//     return min_idx;
// }
//
// template <typename T, size_t N>
// size_t m_idx(span<T, N> s) {
//     size_t min_idx =0;
//     for(size_t i = 1; i<s.size(); ++i) {
//         if(s[i] < s[min_idx]) {
//             min_idx = i;
//         }
//     }
//     return min_idx;
// }
//
// template<typename T, size_t N>
// void tri(span<T, N>tab) {
//     for(size_t i = 0; i<tab.size()-1; ++i) {
//         size_t min_relatif = m_idx(tab.subspan(i));
//         size_t min_absolu = i +min_relatif;
//         if(i != min_absolu) {
//             swap(tab[i], tab[min_absolu]);
//         }
//     }
// }
//
// #endif


// template <typename T, size_t N>
//
// size_t m_idx(span<T, N>s) {
//     size_t min_idx =0;
//     for(size_t i = 0; i<s.size();++i) {
//         if(s[i] < s[min_idx]) {
//             min_idx = i;
//         }
//     }
//     return min_idx;
// }
// // template <typename T, size_t N>
// // void tri(span<T, N>s) {
// //     for(size_t i= 0; i<s.size()-1 ;  ++i) {
// //         size_t i_min = i+ m_idx(s.subspan(i));
// //     swap(s[i] , s[i_min]);
// //     }
// // }
//
// #endif
// template<typename T, size_t N>
// void tri(span<T, N>s) {
//     for(size_t i =0 ; i<s.size()-1; ++i) {
//         size_t min_idx =i;
//         for(size_t j = i+1; j<s.size(); ++j) {
//             if(s[j] < s[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         if(i != min_idx)
//         swap(s[i], s[min_idx]);
//     }
// }

#include <iostream>
#include <array>
using namespace std;

// template<typename T, size_t N>
// using Ligne = array<T, N>;
//
// template<typename T, size_t N, size_t M>
// using Matrice = array<Ligne<T, N>, M>;
//
// template<typename T, size_t N, size_t M>
// T somme(const Matrice<T, N, M>& m) {
//     T total = T{};
//     for(size_t i = 0; i<M; ++i) {
//         for(size_t j = 0; j<N; ++j) {
//             total += m[i][j];
//         }
//     }
//     return total;
// }

template<typename T, size_t N>
using Ligne = array<T, N>;

template<typename T, size_t N, size_t M>
using Matrice = array<Ligne<T, N>, M>;

template<typename T, size_t N, size_t M>

T somme (const Matrice<T, N, M>&m) {
    T total =T{};

    for(const auto& el : m) {
        for(const auto& e : el) {
            total += e;
        }
    }
    return total;
}