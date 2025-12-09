#include <iostream>
#include <vector>
using namespace std;

//
// template<typename T>
// class Point {
// private:
//     T x, y;
//     T xMax, yMax;
//
// public:
//     Point(T xVal = T{}, T yVal = T{}, T xMaxVal = {100}, T yMaxVal = {100}) : x(xVal), y(yVal), xMax(xMaxVal), yMax(yMaxVal) {}
//
//     void afficher() {
//         cout << "(" << x << ", " << y << "), contraintes: [0," << xMax << "]X[0," << yMax << "]\n";
//     }
//
//     void deplacer(T dx, T dy) {
//         x += dx;
//         y += dy;
//     }
//
//     void setX(T xVal) {
//         x = xVal;
//     }
//
//     void setY(T yVal) {
//         y = yVal;
//     }
//
//     T getX() const {
//         return x;
//     }
//
//     T getY() const {
//         return y;
//     }
// };
//
//
// int main() {
//     Point p1(1.2, 2.4);
//     cout << "p1";
//     p1.afficher();
//     p1.deplacer(1., 3.);
//     cout << "p1";
//     p1.afficher();
//     p1.setX(4.);
//     cout << "p1";
//     p1.afficher();
//     p1.setY(7.);
//     cout << "p1";
//     p1.afficher();
//
//     Point p2(3., 4.2, 10., 10.);
//     cout << "p2";
//     p2.afficher();
//     p2.deplacer(15, 2);
//     cout << "p2";
//     p2.afficher();
//     p2.deplacer(3, 2);
//     cout << "p2";
//     p2.afficher();
//     p2.setX(-3);
//     cout << "p2";
//     p2.afficher();
//     p2.setY(12);
//     cout << "p2";
//     p2.afficher();
// }

// template<typename T>
// class Pays {
// private:
//     string nom;
//     T habitant;
//     T superficie;
// public:
//
//
//
//
// };
//
//
// int main() {
//     vector<Pays> v_pays{
//         Pays("Suisse", 8.121830, 41290),
//         Pays("France", 66.663766, 547030),
//         Pays("Italie", 61.855120, 301230),
//         Pays("Allemagne", 80.854408, 357021)
// };
//
//     size_t idx_max_superficie = 0;
//     size_t idx_max_population = 0;
//     size_t idx_max_densite = 0;
//
//     for (size_t i = 0; i < v_pays.size(); ++i){
//         if (v_pays[i].get_superficie() > v_pays[idx_max_superficie].get_superficie()) {
//             idx_max_superficie = i;
//         }
//         if (v_pays[i].get_population() > v_pays[idx_max_population].get_population()) {
//             idx_max_population = i;
//         }
//         if (v_pays[i].calcule_densite_population() > v_pays[idx_max_densite].calcule_densite_population()) {
//             idx_max_densite = i;
//         }
//     }
//     cout << "Pays ayant la plus grande superficie               : "
//          << v_pays[idx_max_superficie].get_nom()
//          << endl
//          << "Pays ayant le plus d'habitants                     : "
//          << v_pays[idx_max_population].get_nom()
//          << endl
//          << "Pays ayant la densite de population la plus grande : "
//          << v_pays[idx_max_densite].get_nom()
//          << endl;
// }


// template<typename T>
// class Point {
// private:
//     T x, y;
//
//
// public:
//     Point():x(0.0), y(0.0){}
//     Point(T xVal = T{}, T yVal=T{}  ): x(xVal), y(yVal) {}
//
//     void afficher() {
//         cout << "(" << x << ", " << y<<")";
//     }
//
//     void deplacer(T dx, T dy) {
//         x += dx;
//         y += dy;
//     }
//
//     void setX(T xVal) {
//         x = xVal;
//     }
//
//     void setY(T yVal) {
//         y = yVal;
//     }
//
//     T getX() const {
//         return x;
//     }
//
//     T getY() const {
//         return y;
//     }
// };
//
//
//
//
// int main() {
//     Point centre;
//     centre.afficher();
//
//     Point p(1.2,2.4);
//     p.afficher();
//
//     p.deplacer(0.8, 0.6);
//     p.afficher();
//
//     p.setX(5.5);
//     p.setY(10.3);
//     cout << p.getX() << " -- " << p.getY() << endl;
// }

// template <typename T>
// class MonEntier {
// private:
//     T n;
// public:
//     MonEntier():MonEntier(n(0)){}
//     MonEntier(T nVal = T(0)) : n(nVal){}
//
//     MonEntier operator ++(int) {
//         T temp = *this;
//         n +=1;
//         return temp;
//     }
//
//     friend ostream& operator<<(ostream& os, const MonEntier& m) {
//         os<<m;
//         return os;
//     }
//
//     MonEntier operator + (const MonEntier& lhs, const MonEntier& rhs) {
//         return (lhs.n + rhs.n);
//     }
//     MonEntier& operator +=( MonEntier lhs, const MonEntier& rhs) {
//         return (lhs.n + rhs.n);
//     }
//     bool operator==(const MonEntier& lhs, const MonEntier& rhs) {
//         return lhs.n == rhs.n;
//     }
//
//
// };
//
//
// int main() {
//     MonEntier m0, m1(1), m2 = 5;
//     const MonEntier m3{7};
//
//     cout << m0 << endl
//          << m1 << endl;
//
//     cout << boolalpha;
//     cout << (m0 == m1) << endl;
//     cout << (m0 != m1) << endl;
//     cout << noboolalpha;
//
//     cout << m1++ << endl;
//     cout << m1 << endl;
//     cout << ++m1 << endl;
//
//     cout << m1 + m2 << endl;
//     m1 += m2;
//     cout << m1 << endl;
//     cout << m3 + m2 << endl;
// }

// template<typename T>
// void yazdir(const T& valeur) {
//     cout<<valeur;
// }
//
// template<typename T>
// void yazdir( T* ptr) {
//     if(ptr ==nullptr) {
//         cout<<"vide";
//     }
//     else{cout<<*ptr;}
// }
//
// int main() {
//     int x = 42;
//     string s = "Hello";
//     double* d_ptr = new double(3.14);
//     int* i_ptr = nullptr;
//
//     yazdir(x);
//     cout << " | ";
//     yazdir(s);
//     cout << " | ";
//
//
//     yazdir(d_ptr);
//     cout << " | ";
//
//
//     yazdir(i_ptr);
//
//     delete d_ptr;
//     return 0;
// }
//
// #ifndef COMPTEUR_H
// #define COMPTEUR_H
//
// class Compteur {
// private:
//     int x;
// public:
//     Compteur(int xVal=0);
//     void incrementer(int d=1);
//
//     int getVal()const;
//
// };
// #endif
//
// #include "Compteur.h"
// #include <iostream>
// Compteur::Compteur(int xVal):x(xVal){};
// int Compteur::getVal()const {
//     return x;
// }
//
// void Compteur::incrementer(int d) {
//     x+=d;
// }

