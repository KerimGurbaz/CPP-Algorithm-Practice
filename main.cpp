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
//Exercice 3 — total_size & concat (version simple)
// #include <vector>
// #include <utility>
// #include <iostream>
// #include <algorithm>
// using namespace std;
//
// template <typename T> using Iterateur = typename vector<T>::const_iterator;
// template <typename T> using Plage     = pair<Iterateur<T>, Iterateur<T>>;
// template <typename T> using vPlages   = vector<Plage<T>>;
//
// template<typename InputIterator>
// size_t total_size(InputIterator first, InputIterator last) {
//     size_t sum = 0;
//
//     for(auto it = first; it != last; ++it) {
//         sum += distance(it->first, it->second);
//     }
//     return sum;
// }
//
//
// template<typename InputIterator, typename OutputIterator>
// OutputIterator concat(InputIterator first, InputIterator last, OutputIterator result) {
//     for(auto it =first; it!= last; ++it) {
//         //result = copy(it->first, it->second, result);
//         auto sub_it = it->first;
//         auto sub_end =it-> second;
//
//         while(sub_end != sub_it) {
//             *result = *sub_it;
//             result++;
//             sub_it++;
//         }
//     }
//     return result;
// }
//
//
// int main() {
//     const vector<int> v1 {11, 12, 13, 14, 15, 16};
//     const vector<int> v2 {21, 22, 23, 24};
//     vector<int>       v3 {31, 32};
//
//     const vPlages<int> plages {
//             {v1.cbegin()+3, v1.cend()},   // 14,15,16
//             {v1.cbegin(),   v1.cend()-3}, // 11,12,13
//             {v2.cbegin(),   v2.cend()},   // 21,22,23,24
//             {v3.cbegin(),   v3.cend()}    // 31,32
//     };
//
//     size_t n = total_size(plages.begin(), plages.end());
//     cout << "total_size = " << n << '\n';
//
//     vector<int> v4(n);
//     concat(plages.cbegin(), plages.cend(), v4.begin());
//
//     cout << "v4 : ";
//     for (int x : v4) cout << x << ' ';
//     cout << '\n';
// }


// Exercice 4 — supprimer_si


// template<typename T, typename Predicate>
// void supprimer_si(vector<T>& v, Predicate pred) {
//     size_t write = 0;
// for(size_t read =0; read<v.size();++read) {
//     if(pred(v[read])) {
//         v[write++] = v[read];
//     }
// }
//     v.resize(write);
//
// }

// template<typename T, typename Predicate>
// void supprimer_si(vector<T>& v, Predicate pred) {
//     auto write = v.begin();
//     for(auto read = v.begin(); read != v.end(); ++read ) {
//         if(!pred(*read)) {
//             *write++ =*read;
//         }
//     }
//     v.erase(write, v.end());
// }
// bool est_pair(int a) { return a % 2 == 0; }
//
// int main() {
//     string s = "C++17 is awesome! 1234";
//
//     // string'i vector<char>'a kopyala
//     vector<char> v(s.begin(), s.end());
//
//     // tüm digit'leri sil
//     supprimer_si(v, ::isdigit);
//
//     // yeniden string'e dönüştür
//     string result(v.begin(), v.end());
//
//     cout << result << endl;
// }

// #include <iostream>
// using namespace std;
//
// template<typename T, typename U>
// void h(T, U)      { cout << "1"; }   // genel
//
// template<typename T, typename U>
// void h(T*, U*)    { cout << "2"; }   // pointer versiyonu
//
// template<typename T>
// void h(T, T)      { cout << "3"; }   // iki parametre aynı tip
// template<typename T>
// void h(T*, T*)      { cout << "4"; }
//
//
// int main() {
//   int i = 5;
//   int* ptr = &i;
//   h(ptr, ptr);
//
// }

#include <iostream>
#include <vector>
#include <array>
using namespace std;

// template<typename T, size_t N = 100>
//
// class Stack {
// private:
//     array<T, N> data;
//     size_t currentSize;
//
// public:
//     Stack() : currentSize(0) {
//     }
//
//     bool full() const {
//         return currentSize == N;
//     }
//
//     bool empty() const {
//         return currentSize == 0;
//     }
//
//     size_t size() const {
//         return currentSize;
//     }
//
//     void push(const T &el) {
//         if (!full()) {
//             data[currentSize] = el;
//             currentSize++;
//         }
//     }
//
//     void pop() {
//         if (!empty()) {
//             currentSize--;
//         }
//     }
//
//     const T &top() const {
//         return data[currentSize - 1];
//     }
//
//     void display() const {
//         cout << "size : " << currentSize << endl;
//         cout << "data : [";
//         for (size_t i = 0; i < currentSize; ++i) {
//             if (i)cout << ",";
//             cout << data[i];
//         }
//         cout << "]" << endl;
//     }
// };
//
// int main() {
//     // Stack d'entiers avec capacité 10
//     Stack<int, 10> s;
//     int i = 1;
//
//     s.display();
//     cout << endl;
//
//     while (not s.full()) {
//         s.push(i *= 2);
//     }
//
//     cout << "top  : " << s.top() << endl;
//     cout << "size : " << s.size() << endl;
//     cout << endl;
//
//     s.display();
//     cout << endl;
//
//     while (not s.empty()) {
//         s.pop();
//     }
//
//     s.display();
//     cout << endl;
//
//     return 0;
// }
