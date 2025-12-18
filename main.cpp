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
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int xVal =0, int yVal=0);

    Point& operator+=(const Point& other);
    friend Point operator+(const Point& lhs, const Point& rhs);
    friend std::ostream& operator<<(std::ostream&os , const Point& p);
};

Point::Point(int xVal ,  int yVal): x(xVal), y(yVal) {}
Point& Point::operator+=(const Point& other) {
    this->x += other.x;
    this->y += other.y;

    return *this;
}
 Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.x + rhs.x , lhs.y+rhs.y);

}
ostream& operator<<(std::ostream&os , const Point& p) {
    os<<"("<<p.x<<","<<p.y<<")";
    return os;
}

int main() {
    Point p1{2,3};
    Point p2{4,1};
    p1 += p2;
    Point p3 = p1 + p2;
    cout << p1 << "\n" << p2 << "\n" << p3 << endl;
}
