#include <iostream>
#include <iomanip>
#include <vector>
#include <span>
#include <array>


// using namespace std;
// template<typename U, typename T, typename N>
// vector<U> concat_tab(T v1, T v2, N a1, N a2) {
//     vector<U> r;
//
//     for(T it = v1; it != v2; ++it) {
//         r.push_back(*it);
//     }
//
//     for(auto it = a1; it != a2; ++it) {
//         r.push_back(*it);
//     }
//     r.shrink_to_fit();
//     return r;
// }
// template<typename T, size_t N>
// ostream& operator<<(ostream& os, span<T, N>s) {
//     for(size_t i = 0; i<s.size(); ++i) {
//         if(i)os<<",";
//         os<<s[i];
//     }
//     return os;
// }
//
//
//
// int main() {
//
//     vector v {11, 12, 13};
//     array  a {21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     vector r = concat_tab<int>(v.begin(), v.end(),
//                                a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }


// template <typename T, typename T1, typename T2>
// vector<T> concat_tab(T1 v1, T1 v2, T2 a1, T2 a2 ) {
//     vector<T> res(v1, v2);
//
//     res.insert(res.end(), a1, a2);
//     return res;
// }
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s) {
//     os<<"[";
//     for(size_t i = 0; i <s.size(); ++i) {
//         os<<s[i];
//         if(i <s.size()-1) {
//             os<<",";
//         }
//     }
//     os<<"]";
//     return os;
// }
//
//
// int main() {
//     vector v {11, 12, 13};
//     array  a {21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     // Appel explicite du template <int>
//     vector r = concat_tab<int>(v.begin(), v.end(),
//                                a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }


// template<typename T1, typename T2, typename T3>
// vector<T1> merge(T2 first1, T2 last1, T3 first2, T3 last2) {
//     vector<T1> result;
//     int d1 = distance(first1, last1);
//     int d2 = distance(first2, last2);
//     result.reserve(d1 + d2);
//     int minVal = min(d1, d2);
//     while (minVal > 0) {
//         result.push_back(*first1++);
//         result.push_back(*first2++);
//         --minVal;
//     };
//
//     if (first1 != last1) {
//         result.insert(result.end(), first1, last1);
//     }
//     if (first2 != last2) {
//         result.insert(result.end(), first2, last2);
//     }
//     return result;
// }
//
// template<typename T>
// ostream& operator<<(ostream& os, span<T>s) {
//     os<<"[";
//     for(size_t i = 0; i<s.size(); ++i) {
//         os<<s[i];
//         if(i<s.size()-1)os<<",";
//     }
//     return os<<"]";
// }
//
//
// int main() {
//     vector v{11, 12, 13};
//     array a{21, 22, 23, 24, 25};
//
//     cout << "vector   : " << span<int>(v) << endl;
//     cout << "array    : " << span<int>(a) << endl;
//
//     vector r = merge<int>(v.begin(), v.end(),
//                           a.begin(), a.end());
//
//     cout << "resultat : " << span<int>(r) << endl;
// }

// template<typename T, typename U>
// vector<U> vect_iter_val(const vector<T>& v, const U & value) {
//     vector<U> result;
//     for(const auto& el: v) {
//         if(el == value) {
//             result.push_back(el);
//         }
//     }
//     return result;
// }
// template<typename T>
// void afficher_vect_iter(span<T>s) {
//
// }
// template<typename T>
// ostream & operator<<(ostream& os, span<T>s) {
//     os<<"[";
//     for(size_t i = 0; i<s.size(); ++i) {
//         os<<s[i];
//         if(i<s.size()-1) {
//             os<<", ";
//         }
//     }
//     return os<<"]";
// }
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
#include <algorithm>
#include <vector>
#include <span>
#include <array>
using namespace std;

// template<typename T>
// class Coord {
// private:
//     T x, y;
//
// public:
//     Coord(T x = T{}, T y = T{}) : x(x), y(y) {
//     }
//
//     void setCoord(T xVal, T yVal) {
//         x = xVal;
//         y = yVal;
//
//         // this->x = x;
//         // this->y =y;
//     }
//
//     T getX()const {
//         return x;
//     }
//
//     T getY()const {
//         return y;
//     }
//
//     void deplacer(T dx, T dy) {
//         x += dx;
//         y += dy;
//     }
//
//     void afficher()const {
//
//         cout<<"("<<this->x<<", "<<this->y<<")";
//     }
//
//     Coord<T> operator +(const Coord<T>& other)const {
//         return Coord(x + other.x, y +other.y);
//
//     }
// };
//
// int main() {
//     cout << "origine  : ";
//     const Coord<int> origin;
//     origin.afficher();
//     cout << endl;
//
//     cout << "p1       : ";
//     Coord<int> p1;
//     p1.setCoord(1, 2);
//     p1.afficher();
//     cout << endl;
//
//     cout << "p2       : ";
//     Coord<double> p2(3, 4);
//     p2.afficher();
//     cout << endl;
//
//     Coord<double> p3;
//     cout << "p3       : ";
//     p3.afficher();
//     p1.setCoord(11.1, 222.1);
//     cout << "p3       : ";
//     p3.afficher();
//
//     p1.setCoord(1, 2);
//     p3.afficher();
//     cout << endl;
//
//     cout << "p2->     : ";
//     p2.deplacer(1, 1);   // conversion int => double
//     cout << "(" << p2.getX() << ", " << p2.getY() << ")";
//     cout << endl;  cout << endl;  cout << endl;  cout << endl;
//     Coord<int> a(1,2);
//     Coord<int> b(3,4);
//     Coord<int> c = a + b;
//     cout << "(" << c.getX() << ", " << c.getY() << ")";
// }
template<typename T>
class Coord {
private:
    T x, y;

public:
    Coord(T xVal = T{}, T yVal = T{}) : x(xVal), y(yVal) {
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    void afficher() const {
        cout << "(" << x << ", " << y << ")";
    }

    void deplacer(T dx, T dy) {
        x += dx;
        y += dy;
    }
};

template<typename T>
class Point {
private:
    string nom;
    Coord<T>coord;


public:
    Point():nom("origine"), coord(){}
    Point(string nom, T x = T(), T y =T()) : nom(nom), coord(x,y){}
    Point(string nom, const Coord<T>& c) : nom(nom), coord(c){}

    void setNom(const string& s) {
        nom = s;
    }
    void setCoord(const Coord<T>& c) {
        coord =c;
    }

    string getNom()const {
        return nom;
    }

    const Coord<T>& getCoord()const {
        return coord;
    }

    void deplacer(T dx, T dy) {
        coord.deplacer(dx, dy);
    }

    void afficher()const {
        cout<<nom;
        coord.afficher();
    }

};

int main() {
    const Point<int> origin;

    cout << "p1       : ";
    Point<int> p1("p1"s);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Point<double> p2("p2"s, Coord(1.2, 3.4));
    p2.afficher();
    cout << endl;

    cout << "p3       : ";
    Point<double> p3("p3"s, 1.2, 3.4);
    p3.afficher();
    cout << endl;

    cout << "p3.1     : ";
    p3.setNom("p3.1"s);
    p3.afficher();
    cout << endl;

    cout << "p1(-1, 1): ";
    p1.setCoord(Coord(-1, 1));
    p1.afficher();
    cout << endl;

    cout << "p1->     : ";
    p1.deplacer(-1, 1);
    p1.afficher();
    cout << endl;

    cout << "p1(x)    : ";
    cout << p1.getNom() << " " << p1.getCoord().getX();
}
