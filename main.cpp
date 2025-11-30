#include <iostream>
#include <array>
#include <iomanip>
#include <cstdint>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// template<typename T>
//
// ostream &operator<<(ostream &os, const vector<T> &v) {
//     os << "[";
//     for (size_t i = 0; i < v.size(); ++i) {
//         os << v[i] << (i < v.size() - 1 ? ", " : "");
//     }
//     return os << "]";
// };
//
// template<typename T>
// ostream &operator<<(ostream &os, const vector<vector<T> > &m) {
//     os << "[";
//     for (size_t i = 0; i < m.size(); ++i) {
//         if (i) {
//             os << "\n";
//         }
//         os << m[i];
//     }
//     os << "]";
//     return os;
// }
//
// template<typename T>
// using Ligne = vector<T>;
// template<typename T>
// using Matrice = vector<Ligne<T> >;
//
// int main() {
//     Matrice<int> m{
//         {0},
//         {1, 2},
//         {3, 4, 5},
//         {6, 7, 8, 9}
//     };
//
//     cout << m << endl;
//     return 0;
// }

//
// enum class Chiffre { ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF };
//
// string to_string(Chiffre c) {
//     switch (c) {
//         case Chiffre::ZERO: return "ZERO";
//         case Chiffre::UN: return "UN";
//         case Chiffre::DEUX: return "DEUX";
//         case Chiffre::TROIS: return "TROIS";
//         case Chiffre::QUATRE: return "QUATRE";
//         case Chiffre::CINQ: return "CINQ";
//         case Chiffre::SIX: return "SIX";
//         case Chiffre::SEPT: return "SEPT";
//         case Chiffre::HUIT: return "HUIT";
//         case Chiffre::NEUF: return "NEUF";
//         default: return "incnnu";
//     }
// }
//
// ostream &operator<<(ostream & os, const vector<Chiffre> &v) {
//     for (size_t i = 0; i < v.size(); ++i) {
//         if (i > 0) os << " ";
//         os << to_string(v[i]);
//     }
//     return os;
// }
//
// vector<Chiffre> nbreToEnums(int n) {
//     if (n == 0)return {Chiffre::ZERO};
//     vector<Chiffre> result;
//     n = abs(n);
//
//     while (n > 0) {
//         int digit = n % 10;
//         result.push_back(static_cast<Chiffre>(digit));
//         n /= 10;
//     }
//
//     reverse(result.begin(), result.end());
//     return result;
// }
//
//
// int main() {
//     cout << nbreToEnums(123) << endl; // UN DEUX TROIS
//     cout << nbreToEnums(0) << endl;   // ZERO
//     cout << nbreToEnums(905) << endl; // NEUF ZERO CINQ
//
//     return 0;
// }

// struct Date {
//     int jour;
//     int mois;
//     int annee;
// };
//
// ostream& operator<<(ostream& os, const Date& d) {
//     return os<<d.jour<<"."<<d.mois<<"."<<d.annee;
// }
//
// struct Personne {
//     string Prenom;
//     string nom;
//     Date naissance;
// };
//
// #include <span>
// template<typename T, size_t N>
// ostream& operator<<(ostream& os, const Personne& p) {
//     os<<"prenom "<<p.nom<<"\n";
//     os<<"nom    "<<p.nom<<"\n";
//     os<<"date   "<<p.naissance;
//     return os;
// }
//
//
//
// template<typename T, size_t N>
// ostream& operator<<(ostream& os, span<T, N>& s) {
//     for(size_t i =0; i<s.size(); ++i) {
//        os<<s[i];
//     }
//     return os;
// }
//
// int main() {
//     // Nécessaire pour le suffixe "s" (ex: "Jean"s)
//     using namespace std::string_literals;
//
//     // Déclaration fournie par l'énoncé
//     array carnet {
//         Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
//         Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
//         Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
//         Personne{"Remi"s,   "Fasol"s,    Date{17,  5, 1957}}
//     };
//
//     // L'instruction magique
//     carnet;
//
//     return 0;
// }

// template<typename T, size_t N, typename Fn>
// void transformer(array<T, N>& a, Fn f) {
//     for(T& t : a)
//         t = f(t);
// }
#include <iostream>

using namespace std;

// struct Point {
//     double x =0.0;
//     double y =0.0;
//
//     void afficher()const {
//         cout<<"("<<x<<", "<<y<<" )"<<endl;
//     }
//
//     void deplacer(double dx, double dy) {
//         x += dx;
//         y += dy;
//     }
//
// };

// struct Point {
//     double x = {};
//     double y = {};
//
//     void afficher() const {
//         cout << "(" << x << ", " << y << " )" << endl;
//     }
//
//     void deplacer(double dx, double dy) {
//         x += dx;
//         y += dy;
//     }
// };

// struct Point {
//     double x;
//     double y;
//
//     Point() : x(0.0), y(0.0){}
//
//     Point(double x, double y):x(x), y(y){}
//
//     void afficher()const {
//         cout<<"("<<x<<","<<y<<")"<<endl;
//     }
//
//     void deplacer(double dx, double dy) {
//         x += dx;
//         y += dy;
//     }
//
// };
// int main() {
//     Point centre{};
//     centre.afficher(); // (0,0)
//
//     Point p{1.2, 2.4}; // Initialisation par agrégat (C++11)
//     p.afficher(); // (1.2,2.4)
//
//     p.deplacer(0.8, 0.6);
//     p.afficher(); // (2,3)
//
//     p.x = 5.5; // Accès direct autorisé car struct
//     p.y = 10.3;
//     cout << p.x << " -- " << p.y << endl; // 5.5 -- 10.3
// }

// #ifndef POINT_H
// #define POINT_H
// struct Point {
//     double x, y;
//
//     void deplacer(double dx, double dy);
//     void afficher()const;
// };
// #endif
// #include <iostream>
// #include "Point.h";
//
// void Point::deplacer(double dx, double dy) {
//     x += dx;
//     y += dy;
// }
//
// void Point::afficher()const {
//     cout << "(" << x << "," << y << ")" << endl;
// }
//
// #include <iostream>
// #include "Point.h"
// using namespace std;
//
// int main() {
//
// }

class Point {
private:
    double x, y;

public:
    Point(double val_x, double val_y): x(val_x), y(val_y){}
   Point():Point(0.0, 0.0){}

    void setX(double val) {
        x = val;
    }

    void setY(double val) {
        y = val;
    }

    double getX()const {
        return x;
    }

    double getY()const {
        return y;
    }

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void afficher()const {
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }
};

int main() {
    Point centre;
    centre.afficher();

    Point p(1.2, 2.4);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;

    return 0;
}