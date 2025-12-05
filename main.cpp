#include <iostream>
#include <vector>
using namespace std;

// template<typename InputIt, typename OutputIt, typename Pred, typename Transform >
// void transfert_conditionnel(InputIt first, InputIt last,OutputIt dest,  Pred pred, Transform transform) {
//         while(first != last) {
//             if(pred(*first)) {
//                 *dest = transform(*first);
//             }
//             ++first;
//         }
//     }
//
// int main() {
//     std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8};
//     std::vector<int> destination;
//
//
//     transfert_conditionnel(
//         source.begin(), source.end(),
//         std::back_inserter(destination), // İpucu: output iterator
//         [](int n) { return n % 2 == 0; }, // Predicate
//         [](int n) { return n * n; } // Transform
//     );
//
//     // Çıktı: 4 16 36 64 olmalı
//     for (int x: destination) std::cout << x << " ";
//     std::cout << std::endl;
//
//     return 0;
// }

#include <list>
// template<typename T, typename U>
// size_t max_consecutive_count(T first, T last, U n) {
//     size_t count = 0;
//     size_t mVal = 0 ;
//     for(T it = first; it != last; ++it) {
//         if(*it == n) {
//             count++;
//             if(count>mVal) {
//                 mVal=count;
//             }
//
//         }else {
//             count =0;
//         }
//     }
//     return mVal;
// }
//
// int main() {
//     std::vector<int> v = {1, 2, 2, 3, 2, 2, 2, 4, 4};
//     std::list<char> l = {'a', 'b', 'b', 'a', 'a', 'a', 'b'};
//
//
//     std::cout << max_consecutive_count(v.begin(), v.end(), 2) << std::endl; // Çıktı: 3
//
//
//     std::cout << max_consecutive_count(l.begin(), l.end(), 'a') << std::endl; // Çıktı: 3
//
//     return 0;
// }


// template<typename T, typename It>
// It partitionner_manuel( It first,It last, const T& n ) {
//
//  while(first != last) {
//   if(*first < n) {
//    ++first;
//   }else {
//    --last;
//    T temp  = *last;
//    *last = *first;
//    *first = temp;
//   }
//  }
//  return first;
// }
//
// int main() {
//  std::vector<int> v = {10, 5, 20, 3, 8, 25};
//  int pivot = 10;
//
//  // Pivot (10)'tan küçükler sola, büyük/eşitler sağa geçsin.
//  // Sıra önemli değil, sadece gruplama önemli.
//  auto it_pivot = partitionner_manuel(v.begin(), v.end(), pivot);
//
//  std::cout << "Kucukler: ";
//  for(auto it = v.begin(); it != it_pivot; ++it) std::cout << *it << " ";
//
//  std::cout << "\nBuyukler: ";
//  for(auto it = it_pivot; it != v.end(); ++it) std::cout << *it << " ";
//
//  return 0;
// }
// #include <iostream>
// using namespace std;
//
// template<typename T>
// class Intervalle {
// private:
//  T x, y;
// public:
//  Intervalle(T x_val = T() ,T y_val = T()) : x(x_val), y(y_val) {
//   if(x > y) {
//    T temp = x;
//    x = y;
//    y = temp;
//   }
//  }
//
//  friend ostream& operator<<(ostream& os, const Intervalle& v) {
//   os<<"("<<v.x<<","<<v.y<<")";
//   return os;
//  }
// Intervalle operator+(const Intervalle& other) const{
//   return Intervalle(min(this->x , other.x), max(this->y, other.y));
//  }
//
//  Intervalle operator&(const Intervalle& other) const{
//   return Intervalle(max(this->x , other.x), min(this->y, other.y));
//  }
//
// };
//
//
// int main() {
//  Intervalle a(1, 5);
//  Intervalle b(8, 6); // Dikkat: Constructor bunu [6, 8] yapmalı!
//
//  std::cout << "A: " << a << " / B: " << b << std::endl;
//
//  Intervalle c = a + b; // [1, 8] olmalı (en geniş kapsayan)
//  std::cout << "Union (Kapsayan): " << c << std::endl;
//
//  Intervalle d(4, 10);
//  Intervalle e = a & d; // [1,5] ve [4,10] kesisimi -> [4,5] olmalı
//  std::cout << "Intersection: " << e << std::endl;
//
//  return 0;
// }


// #include <iostream>
// #include <vector>
// #include <list>
// #include <functional> // less, greater
//
// using namespace std;
//
// template<typename Iterator, typename Compare = std::less<typename Iterator::value_type> >
// std::pair<Iterator, Iterator>
// plus_long_sequence_croissante(Iterator first, Iterator last, Compare comp = Compare{}) {
//     if (first == last) {
//         return {last, last};
//     }
//
//     Iterator best_start = first;
//     size_t max_len = 1;
//
//     Iterator curr_start = first;
//     size_t curr_len = 1;
//
//     Iterator it = first;
//     Iterator next_it = next(first);
//
//     while (next_it != last) {
//         if (comp(*it, *next)) {
//             curr_len++;
//         } else {
//             if (curr_len > max_len) {
//                 max_len = curr_len;
//                 best_start = curr_start;
//             }
//             curr_start = next_it;
//             curr_len = 1;
//         }
//           ++next_it;
////     }
////     if(curr_len > max_len) {
////         max_len = curr_len;
////         best_start = curr_start;
////     }
////
////     return {best_start, next(best_start, max_len)}
//// }
////
//// int main() {
////     vector<int> v{6, 3, 4, 5, 4, 3, 1, 2, 2, 3, 4, 3, 7};
////
////     cout << "Test 1 (vector, croissante strict): ";
////     auto r1 = plus_long_sequence_croissante(v.begin(), v.end()); // default : less<>
////     for (auto it = r1.first; it != r1.second; ++it)
////         cout << *it << ' ';
////     cout << '\n';
////
////     cout << "Test 2 (vector, decroissante strict): ";
////     auto r2 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
////     for (auto it = r2.first; it != r2.second; ++it)
////         cout << *it << ' ';
////     cout << '\n';
////
////     list<double> l{1.0, 1.1, 0.9, 1.2, 1.3, 0.5, 0.6};
////
////     cout << "Test 3 (list<double>, croissante strict): ";
////     auto r3 = plus_long_sequence_croissante(l.begin(), l.end());
////     for (auto it = r3.first; it != r3.second; ++it)
////         cout << *it << ' ';
////     cout << '\n';
//// }
//
//// #include <iostream>
//// #include <vector>
//// #include <array>
//// using namespace std;
//// template<typename T, typename U>
//// U somme_intervalle(T first, T last, const U& n) {
////      U somme = U{n};
////
////      for(auto it =first; it != last; ++it ) {
////           somme += *it;
////      }
////      return somme;
//// }
////
//// int main() {
////     vector<int> v{10, 20, 30, 40, 50};
////     array<double, 4> a{1.5, 2.5, 3.5, 4.5};
////
////     cout << "Somme v[1..4) + init=100 = "
////          << somme_intervalle(v.begin() + 1, v.end() - 1, 100) << '\n';
////     // attendu: 100 + 20 + 30 + 40 = 190
////
////     cout << "Somme a[0..4) + init=0.0 = "
////          << somme_intervalle(a.begin(), a.end(), 0.0) << '\n';
////     // attendu: 1.5+2.5+3.5+4.5 = 12.0
////
////     cout << "Somme a[1..3) + init=1.0 = "
////          << somme_intervalle(a.begin()+1, a.end()-1, 1.0) << '\n';
////     // attendu: 1.0 + 2.5 + 3.5 = 7.0
//// }   it = next_it;
//
