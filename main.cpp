// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// template<typename T>
//
// void tri_insertion(vector<T> &v) {
//   for(size_t i = 1; i<v.size(); ++i) {
//       int key = v[i];
//       size_t j = i;
//       while(j>0 && v[j-1]>key) {
//           v[j] = v[j-1];
//           --j;
//       }
//       v[j]=key;
//   }
// }
//
// template<typename T>
// void affichage(const vector<T> &v) {
//     for (const auto &el: v) {
//         cout << el << " ";
//     }
// }
//
//
// int main() {
//     vector<int> v = {7, 5, 3, 9, 6};
//     tri_insertion(v);
//
//     affichage(v);
// }

//
// #include <iostream>
// #include <vector>
// #include <iterator>
// #include <algorithm> // sort, unique
// #include <cmath>     // pow
//
// using namespace std;
//
// template<typename T>
// auto extraire_pairs_carres(T first, T last) {
//     using valueType = typename iterator_traits<T>::value_type;
//     vector<valueType> res;
//
//     copy_if(first, last, back_inserter(res), [](valueType n) {
//         return n%2 ==0;
//     });
//
//     sort(res.begin(), res.end());
//     res.erase(unique(res.begin(), res.end()), res.end());
//
//     transform(res.begin(), res.end(),res.begin(),[](valueType n) {
//         return n*n;
//     });
//     return res;
// }
//
// template<typename T>
// void affichage(const vector<T> &v) {
//     for (const auto &el: v) {
//         cout << el << " ";
//     }
// }
//
//
// int main() {
//     vector<int> data = {4, 1, 2, 4, 3, 2, 6};
//     auto res = extraire_pairs_carres(data.begin(), data.end());
//     // Résultat attendu : 4 16 36
//     affichage(res);
// }
//
// #ifndef POLYGONE_H
// #define POLYGONE_H
// #include <vector>
// #include <iostream>
// using namespace std;
//
// struct Point {
//     double x;
//     double y;
// };
//
// class Polygone {
// private:
//     vector<Point> sommets;
//
// public:
//     Polygone() = default;
//
//     void ajouterSommet(Point p);
//
//     double perimetre() const;
//
//     friend ostream &operator<<(ostream &os, const Polygone &p);
// };
// #endif
//
//
// #include <iostream>
// #include <cmath>
// //#include "Polygone.h"
//
// using namespace std;
//
// void Polygone::ajouterSommet(Point p) {
//     sommets.push_back(p);
// }
//
// double Polygone::perimetre() const {
//     double total = 0.;
//     size_t n = sommets.size();
//
//     if (n < 2) return 0.0;
//     for (size_t i = 0; i < n; ++i) {
//         Point p1 = sommets[i];
//         Point p2 = sommets[(i + 1) % n];
//
//         double dx = p2.x - p1.x;
//         double dy = p2.y - p1.y;
//
//         total += hypot(dx, dy);
//     }
//     return total;
// }
//
// ostream &operator<<(ostream &os, const Polygone &p) {
//     os<<"Polygone ["<<p.sommets.size()<<"sommets] - Perimetre :"<<p.perimetre();
//     return os;
// }
//
// int main() {
//     // Création d'un triangle rectangle (3-4-5)
//     Polygone triangle;
//
//     triangle.ajouterSommet({0, 0}); // Point(x, y)
//     triangle.ajouterSommet({3, 0});
//     triangle.ajouterSommet({0, 4});
//
//     // Affichage via surcharge operateur<<
//     // Format attendu : "Polygone [3 sommets] - Perimetre : 12"
//     cout << triangle << endl;
//
//     // Test avec un carré
//     Polygone carre;
//     carre.ajouterSommet({0, 0});
//     carre.ajouterSommet({10, 0});
//     carre.ajouterSommet({10, 10});
//     carre.ajouterSommet({0, 10});
//
//     cout << carre << endl; // Perimetre : 40
//
//     return 0;
// }
// #include <iostream>
// using namespace std;
//
// class Point {
// private:
//     int x, y;
// public:
//     Point(int xVal =0, int yVal=0);
//
//     Point& operator+=(const Point& other);
//     friend Point operator+(const Point& lhs, const Point& rhs);
//     friend std::ostream& operator<<(std::ostream&os , const Point& p);
// };
//
// Point::Point(int xVal ,  int yVal): x(xVal), y(yVal) {}
// Point& Point::operator+=(const Point& other) {
//     this->x += other.x;
//     this->y += other.y;
//
//     return *this;
// }
//  Point operator+(const Point& lhs, const Point& rhs) {
//     return Point(lhs.x + rhs.x , lhs.y+rhs.y);
//
// }
// ostream& operator<<(std::ostream&os , const Point& p) {
//     os<<"("<<p.x<<","<<p.y<<")";
//     return os;
// }
//
// int main() {
//     Point p1{2,3};
//     Point p2{4,1};
//     p1 += p2;
//     Point p3 = p1 + p2;
//     cout << p1 << "\n" << p2 << "\n" << p3 << endl;
// }

//
// #include <iostream>
// #include <cmath>
// #include <vector>
// using namespace std;
//
// struct Point {
//     double x, y;
// };
//
// #include "MultiLine.cpp"
//
// class MultiLine {
//     vector<Point> pts;
//
//     void add_point(const Point& p) {
//         pts.push_back(p);
//     }
//
//     int get_nr_of_segments()const {
//         return pts.size();
//     }
//
//     double get_length()const {
//         for(size_t i = 0; i<pts.size(); ++i) {
//             double longeur =0.0
//             Point p1 = pts[i];
//             Point p2 = pts[(i+1) % pts.size()];
//
//             double dx = p2.x -p1.x;
//             double dy = p2.y - p1.y;
//             longeur += hypot(dx, dy);
//         }
//     }
//
// };
// void show(const MultiLine& m) {
//     cout << "Nbre de segments : " << m.get_nr_of_segments()
//          << " / Longueur : " << m.get_length()
//          << endl;
// }
// // ---------------------------------------------------
// int main() {
//     Point p1{2,3};
//     const Point p2{5,3};
//     Point p3{5,7};
//
//     MultiLine m;
//
//     show(m);            // 0 segment
//     m.add_point(p1);
//     show(m);            // 0 segment
//     m.add_point(p2);
//     show(m);            // 1 segment : p1->p2
//     m.add_point(p3);
//     show(m);            // 2 segments : p1->p2, p2->p3
//     m.add_point(p1);
//     show(m);            // 3 segments : p1->p2, p2->p3, p3->p1
// }


// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
//
// template<typename T>
// struct entre {
//     T minVal;
//     T maxVal;
//     entre(T xVal, T yVal) : minVal(xVal), maxVal(yVal) {}
//
//     bool operator()(const T& val) {
//       return val>=minVal && val<=maxVal;
//     }
// };

// template<typename T>
// ostream& operator<<(ostream& os, const entre<T>& e) {
//     os<<e.x<<e.y;
// }
// int main() {
//     vector<int> v {4, 10, 7, 5, 1, 6, 8, 3, 9, 2};
//
//     int min = 3;
//     int max = 6;
//
//     cout << count_if(v.begin(), v.end(), entre<int>(min, max)) << endl;
// }
//

//
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
//
// int main() {
//     vector<int> v {1, 2, 2, 3, 2, 4, 5};
//
//     int value = 2;
//
//     auto it = remove(v.begin(), v.end(), value);
//
//     v.erase(it, v.end());
//
//
//     for (int e : v) cout << e;
// }
//
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cctype>
// using namespace std;
//
// int main() {
//     string s1("2a9d2v4");
//     string s2("0000000");
//
//     copy_if(s1.begin(), s1.end(), s2.rbegin(),[](char c) {
//         return isdigit(c);
//     });
//
//     cout << s2 << endl;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
//
// int main() {
//     vector<int> v {1, 1, 2, 2, 1, 3, 3, 1};
//     sort(v.begin(), v.end());
//     auto it = unique(v.begin(), v.end());
//     v.erase(it, v.end());
//
//     for (int e : v) cout << e;
// }

// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cctype>
// using namespace std;
//
// int main() {
//     string s("2a0bCd2v4");
//
//   auto it = remove_if(s.begin(),s.end(),[](char c) {
//       return isalpha(c);
//   } );
//
//     s.erase(it, s.end());
//     cout << s;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
//
// int main() {
//     vector<int> v {1, 1, 2, 2, 1, 3, 3, 1};
//
// auto it = unique(v.begin(), v.end());
//
// v.erase(it, v.end());
//     for (int e : v) cout << e;
// }

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// int main() {
//     vector<int> v {1,2,3,4,5};
//     // v.erase(v.begin()+1, v.end()-1 );
//     v.erase(next(v.begin()), prev(v.end()));
//
//     for (int e : v) cout << e;
// }
// #include <algorithm>
// int main() {
//     vector<int> v {5,4,3,2,1};
//     sort( next(v.begin()), prev(v.end()) );
//     for (int e : v) cout << e;
// }
// int main() {
//     vector<int> v {1,2,3,4,5};
//     copy( v.begin(), v.begin()+2, v.rbegin());
//     for (int e : v) cout << e;
// }
//.............................................

// int main() {
//     vector<int> v {1,2,3,4};
//     v.insert( v.begin()+1, 0);
//     for (int e : v) cout << e;
// }
#include <algorithm>
#include <cctype>
// int main() {
//     string s("a1b2c3");
//         auto it=remove_if(s.begin(),s.end(),[](char c) {
//             return isdigit(c);
//         });
//     s.erase(it, s.end());
//     cout << s;
// }

// int main() {
//
//
//     vector<int> v {1,2,3,4,5};
//     copy(v.begin(), v.begin()+2, v.rbegin());
//     for(int e:v) cout<<e;
//
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
//
// int main() {
//     vector<int> v {1,2,3,4};
//     v.reserve(10);
//     copy(v.rbegin()+1,v.rbegin()+3, back_inserter(v) );
//
//     for(int e: v) cout << e;
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
//
// int main() {
//     vector<int> v{4, 10, 7, 5, 1, 6, 8, 3, 9, 2};
//     int min = 3, max = 6;
//
//     cout << count_if(v.begin(), v.end(), [
//                          =](int n) {
//                          return n >= min && n <= max;
//                      }) << endl;
// }


// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// template <typename T>
// struct entre {
//     T minVal;
//     T maxVal;
//
//     entre(T x, T y): minVal(x), maxVal(y){}
//
//     bool operator()(const T n) {
//         return n>=minVal && n<= maxVal;
//     }
// };
//
// int main() {
//     vector<int> v {4,10,7,5,1,6,8,3,9,2};
//     int min = 3, max = 6;
//
//     cout << count_if(v.begin(), v.end(), entre{min, max}) << endl;
// }

//
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cctype>
// using namespace std;
//
// int main() {
//     string s1("a9b1c2");
//     string s2("000000");
//
//     copy_if(s1.begin(), s1.end(),s2.rbegin(),[](char c) {
//         return isdigit(c);
//     } );
//
//     cout << s2 << endl;
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int main() {
//     vector<int> v {1,1,2,2,1,3,3,1};
//
//     auto it = unique(v.begin(), v.end());
//     v.erase(it, v.end());
//     for(int e: v) cout << e;
// }
//
// #include <iostream>
// #include <vector>
// #include <iterator>
// using namespace std;
//
// int main() {
//     vector<int> v {10,20,30,40,50};
//
//     v.erase( next(v.begin()), prev(v.end()));
//
//     for(int e: v) cout << e << ' ';
// }

//
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
//
// int main() {
//     vector<int> v {1,2,3,4,5};
//     v.reserve(10);
//
//     copy( v.begin(), v.begin()+1, v.rbegin());
//
//     for(int e: v) cout << e;
// }
// #include <numeric>
//
// int main() {
//     vector<int> v = {2, 3, 4};
//
//
//     int resultat = accumulate(v.begin(), v.end(), 0, [](int x, int y) {
//         cout<<x<<" "<< y <<" "<< x*y <<endl;
//         return x * y;
//     });
//
//     cout << "Resultat: " << resultat << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm> // std::count_if
//
// using namespace std;
//
// int main() {
//     vector<int> v = {1, 6, 8, 9, 3, 11, 4};
//
// auto result = count_if(v.begin(), v.end(), [](int n) {
//     return n>5 && n%2!=0;
// });
//     cout<<result;
//
//
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm> // transform
#include <iterator>  // back_inserter
#include <cmath>  // back_inserter
using namespace std;

// int main() {
//     vector<int> source = {1, 2, 3, 4};
//     vector<int> destination;
//     transform(source.begin(), source.end(), back_inserter(destination),[](int n) {
//         return (pow(n,2));
//     });
//
//     // Çıktı testi
//     for(int x : destination) cout << x << " "; // 1 4 9 16
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
//
// int main() {
//     vector<int> v = {10, 20, 30, 40, 50, 60};
//
//     // v.begin() -> 10
//     auto it1 = v.begin() + 2;
//     auto it2 = v.end() - 1;
//
//     // Aritmetik işlem: İteratörler arası mesafe (distance)
//     auto dist = it2 - it1;
//
//     // Dereference (*)
//     cout << *it1 << " - " << *it2 << " - " << dist << endl;
//
//     return 0;
// }

// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
//
// int main() {
//     // Cas A
//     vector<int> data = {10, 20, 42, 50};
//
//
//   auto it = find(data.begin(),data.end(),  42);
//     if(it != data.end()) {
//        cout<<" Trouve a l'index "<<abs(distance(it, data.begin()));
//     }else {
//         cout<<"Pas trouve"<<endl;
//     }
//
//     return 0;
// }

// #include <vector>
// #include <iostream>
// using namespace std;
//
// int main() {
//     vector<int> v = {1, 2, 4, 5, 6};
//
//     for (auto it = v.begin(); it != v.end();) {
//         if (*it % 2 == 0) {
//             it = v.erase(it);
//         }else {
//             ++it;
//         }
//     }
//
//     // Affichage pour preuve
//     for(int i : v) cout << i << " ";
//     return 0;
// }

// #include <iostream>
//
// using namespace std;
//
// struct Point {
//     double x;
//     double y;
//
//     Point();
//     Point(double xVal, double yVal);
//     void afficher()const;
//     void deplacer(double dx, double dy);
//     friend ostream& operator<<(ostream&os, const Point& p);
// };
// Point::Point():x(0.0), y(0.0){}
// Point::Point(double xVal, double yVal): x(xVal), y(yVal){}
// void Point::afficher()const {
//     cout<<*this;
// }
// void Point::deplacer(double dx, double dy) {
//     this->x +=dx;
//     this->y +=dy;
// }
//
//  ostream& operator<<(ostream&os, const Point& p) {
//     os<<"("<<p.x<<","<<p.y<<")"<<endl;;
//     return os;
//
// }
//
//
//
//
// int main() {
//     Point centre{};
//     centre.afficher();
//
//     Point p{1.2, 2.4};
//     p.afficher();
//     p.deplacer(0.8, 0.6);
//     p.afficher();
//
//     p.x = 5.5;
//     p.y = 10.3;
//     cout << p.x << " -- " << p.y << endl;
// }