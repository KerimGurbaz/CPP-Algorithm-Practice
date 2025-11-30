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
//
// class Point {
// private:
//     double x, y;
//
// public:
//     Point(double val_x, double val_y): x(val_x), y(val_y){}
//    Point():Point(0.0, 0.0){}
//
//     void setX(double val) {
//         x = val;
//     }
//
//     void setY(double val) {
//         y = val;
//     }
//
//     double getX()const {
//         return x;
//     }
//
//     double getY()const {
//         return y;
//     }
//
//     void deplacer(double dx, double dy) {
//         x += dx;
//         y += dy;
//     }
//
//     void afficher()const {
//         cout<<"("<<x<<", "<<y<<")"<<endl;
//     }
// };
//
// class Cercle {
// private:
//     Point centre;
//     double rayon;
//
// public:
//     Cercle(const Point&  c, double r=1) : centre(c), rayon(r){}
//     double getRayon()const {
//         return rayon;
//     }
//     Point getCentre() {
//         return centre;
//     }
//     void setRayon(double s_r) {
//         rayon = s_r;
//     }
//
//     void setCentre(const Point& p) {
//         centre =p;
//     }
//
//     void deplacer(double dx, double dy) {
//         centre.deplacer(dx, dy);
//     }
//     void afficher()const {
//         centre.afficher();
//         cout<<", "<<rayon<<endl;
//     }
//
// };
//
// int main() {
//     Point p(1.0, 2.0);
//     Cercle c(p, 3.0);
//     c.afficher();
//     c.deplacer(1, -1);
//     c.afficher();
//
//     return 0;
// }

// class Point {
// private:
//     double x, y;
//     const double xMax;
//     const double yMax;
//
// public:
//     Point(double x_val, double y_val, double xMax = 100.0, double yMax = 100.0)
//         : x(x_val), y(y_val), xMax(xMax), yMax(yMax) {
//     }
//
//     void setX(double x_val) {
//         if (x_val >= 0 && x_val <= xMax) {
//             x = x_val;
//         }
//     }
//
//     void setY(double y_val) {
//         if (y_val >= 0 && y_val <= yMax) {
//             y = y_val;
//         }
//     }
//
//     void deplacer(double x_val, double y_val) {
//         if((x_val >= 0 && x_val <= xMax) && (y_val >= 0 && y_val <= yMax)) {
//             x += x_val;
//             y += y_val;
//         }
//     }
//
//     void afficher()const {
//     cout<<"("<<x<<","<<y<<"), contraintes: [0,"<<xMax<<"]x[0,"<<yMax<<"]"<<endl;
//     }
//
//
// };
//
// int main() {
//     Point p1(1.2, 2.4);
//     cout << "p1"; p1.afficher();
//     p1.deplacer(1., 3.);
//     cout << "p1"; p1.afficher();
//     p1.setX(4.);
//     cout << "p1"; p1.afficher();
//     p1.setY(7.);
//     cout << "p1"; p1.afficher();
//
//     Point p2(3., 4.2, 10., 10.);
//     cout << "p2"; p2.afficher();
//     p2.deplacer(15, 2);
//     cout << "p2"; p2.afficher();
//     p2.deplacer(3, 2);
//     cout << "p2"; p2.afficher();
//     p2.setX(-3);
//     cout << "p2"; p2.afficher();
//     p2.setY(12);
//     cout << "p2"; p2.afficher();
// }

// #ifndef PAYS_H
// #define PAYS_H
// #include <string>
// #include <iostream>
//
// class Pays {
// private:
//     std::string nom;
//     double population;
//     double superficie;
//
// public:
//     //constructeur
//     Pays(std::string nom, double pop, double sup );
//
//     //getters
//     std::string getNom()const;
//     double getPopulation()const;
//     double getSuperficie()const;
//
//     double getDensite()const;
//
// };
// #include <vector>
// #include <algorithm> // Pour std::max_element
// #include <iomanip>
// // #endif
//
// // #include "Pays.h"
// using namespace std;
// Pays::Pays(string nom, double pop, double sup) : nom(nom), population(pop),superficie(sup){}
// string Pays::getNom()const {
//     return nom;
// }
// double Pays::getPopulation()const {
//     return population;
// }
//
// double Pays::getSuperficie()const {
//     return superficie;
// }
//
// double Pays::getDensite()const {
//     if(superficie == 0) return 0.0;
//     return (population * 1000000.0)/ superficie;
// }
//
// int main() {
//
//     vector<Pays> monde = {
//         Pays("Suisse",     8.121830,  41290),
//               Pays("France",    66.663766, 547030),
//               Pays("Italie",    61.855120, 301230),
//               Pays("Allemagne", 80.854408, 357021)
//     };
//
//     if(monde.empty()) return 0;
//
//     auto it_surf = min_element(monde.begin(), monde.end(),[]
//         (const Pays& a, const Pays& b) {
//         return a.getSuperficie() < b.getSuperficie();
//     });
//
//     auto it_pop = max_element(monde.begin(), monde.end(),[]
//         (const Pays& a, const Pays& b) {
//         return a.getPopulation() < b.getPopulation();
//     });
//
//     auto it_densite = max_element(monde.begin(), monde.end(),[]
//         (const Pays& a, const Pays& b) {
//         return a.getDensite()< b.getDensite();
//     });
//
//     cout << left << setw(55) << "Pays ayant la plus grande superficie"
//          << ": " << it_surf->getNom() << endl;
//
//     cout << left << setw(55) << "Pays ayant le plus d'habitants"
//          << ": " << it_pop->getNom() << endl;
//     cout << left << setw(55) << "Pays ayant la densite de population la plus elevee"
//          << ": " << it_densite->getNom() << endl;
//
//
//     return 0;
// }
//
// #ifndef ROBOT_H
// #define ROBOT_H

class Robot {
private:
    int position;
    int direction;

public:
    Robot(int posInitiale = 0, int direction =1) : position(posInitiale), direction(1) {
    }

    void deplacer(int n = 1) {
        if (n <= 0) {
            return;
        }

        position += n * direction;
    }

    void faireDemiTour() {
        direction *= -1;
    }

    int getPosition() const {
        return position;
    }
};
int main() {
    Robot r1;       // Varsayılan konstrüktör (pos=0)
    Robot r2(10);   // Parametreli (pos=10)

    cout << "position courante de r2: " << r2.getPosition() << endl; // 10

    r1.deplacer(); // Varsayılan (n=1). Pos: 0 -> 1
    cout << "position courante de r1: " << r1.getPosition() << endl; // 1

    r1.deplacer(-1); // Geçersiz (n<=0). Hareket yok.
    cout << "position courante de r1: " << r1.getPosition() << endl; // 1

    r1.deplacer(2); // n=2. Pos: 1 -> 3
    cout << "position courante de r1: " << r1.getPosition() << endl; // 3

    r1.faireDemiTour(); // Yön artık Sol (-1)

    r1.deplacer(4); // n=4. Yön Sol. Pos: 3 - 4 = -1
    cout << "position courante de r1: " << r1.getPosition() << endl; // -1

    return EXIT_SUCCESS;
}