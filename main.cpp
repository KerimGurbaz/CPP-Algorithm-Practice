#include <cstdint>
#include <iostream>
#include <limits>
using namespace std;

// struct HeureMinute {
//     int8_t heure;
//     int8_t minute;
// };
//
// ostream &operator<<(ostream &os, const HeureMinute &hm) {
//     os << +hm.heure << ":" << +hm.minute;
//     return os;
// }
//
// bool operator<(const HeureMinute &lhs, const HeureMinute &rhs) {
//     if (lhs.heure < rhs.heure) {
//         return true;
//     } else if (lhs.minute < rhs.minute) {
//         return true;
//     } else {
//         false;
//     }
// }
//
// bool operator >(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return !(lhs < rhs);
// }
//
// bool operator <=(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return (rhs > lhs);
// }
//
// bool operator >=(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return !(lhs < rhs);
// }
// bool operator ==(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return (lhs.heure == rhs.heure && lhs.minute == rhs.minute );
// }
//
// bool operator !=(const HeureMinute& lhs, const HeureMinute& rhs) {
//     return !(lhs==lhs);
// }
//
// HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs) {
//     return {int8_t(lhs.heure +rhs.heure +(lhs.minute + rhs.minute)/60), int8_t((lhs.minute + rhs.minute)% 60)};
// }
// HeureMinute& operator+=(HeureMinute& hm , int8_t minute) {
//     hm = {int8_t(hm.heure + (hm.minute + minute)/60),
//     int8_t((hm.minute + minute)%60)};
//     return hm;
// }
//
//
// HeureMinute operator+(HeureMinute hm , int8_t minute) {
//     return hm += minute;
// }
//
// HeureMinute operator+(int8_t minute , HeureMinute hm) {
//     return hm += minute;
// }
//
// HeureMinute& operator++(HeureMinute& hm) {
//     return hm +=1;
// }
// HeureMinute operator++ (HeureMinute& hm, int) {
//     HeureMinute tmp = hm;
//     ++hm;
//     return tmp;
// }
//
// istream& operator>>(istream& is, HeureMinute& h) {
//     char c;
//     int valeur;
//     is>>valeur;
//     h.heure = valeur;
//     is>>c;
//     if(c != ':') {
//         is.setstate(ios::failbit);
//     }
//     is>>valeur;
//     h.minute = valeur;
//
//     if(h.minute >= 60) {
//         cout<<h.minute<<endl;
//         cout<<"fail 60"<<endl;
//         is.setstate(ios::failbit);
//     }
//     return is;
// }
//
//
//
//
// int main() {
//     HeureMinute saisie(const string &msg) {
//         HeureMinute hm;
//         bool erreur;
//         do {
//             cout << msg;
//             cin >> hm;
//             erreur = cin.fail();
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } while (erreur);
//         return hm;
//     }
//
//     HeureMinute hm1 = {12, 34};
//     HeureMinute hm2 = {21, 43};
//
//     cout << boolalpha;
//     cout << hm1 << " <  " << hm2 << "  : " << (hm1 < hm2) << endl;
//     cout << hm1 << " >  " << hm2 << "  : " << (hm1 > hm2) << endl;
//     cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
//     cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
//     cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
//     cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;
//
//     cout << hm1 << " +  " << hm2 << "  : " << (hm1 + hm2) << endl;
//     cout << hm1 << " +  " << 44 << "     : " << (hm1 + 44) << endl;
//     cout << 44 << "    +  " << hm1 << "  : " << (44 + hm1) << endl;
//     cout << hm1 << " += " << 2 << "      : " << (hm1 += 2) << endl;
//
//     cout << "++" << hm1 << "\t\t: " << ++hm1 << endl;
//     cout << hm1 << "++" << "\t\t: " << hm1++ << endl;
//     cout << hm1 << endl;
//
//     cout << endl;
//     HeureMinute hm3 = saisie("heure [hh:mm]: ");
//     cout << "votre saisie : " << hm3 << endl;
// }
// #include <vector>
// template<typename T>
// using Ligne = vector<T>;
// template<typename T>
// using Matrice = vector<Ligne<T> >;
// template<typename T>
// ostream& operator<<(ostream& os, Matrice<T>&m) {
// // for(auto& el : m) {
// //     os<<"[";
// //     for(auto& e : el) {
// //         os<<e<<",";
// //     }
// //     os<<"]"<<endl;
// // }
//     os<<"[";
//     for(size_t i = 0; i<m.size(); ++i) {
//         os<<"[";
//         for(size_t j = 0 ; j<m[i].size(); ++j) {
//             os<<m[i][j];
//             if(j<m[i].size()-1) {
//                 os<<",";
//             }
//         }
//
//         if(i == m.size()-1) {
//             os<<"]";
//         }
//         os<<"]"<<endl;
//
//     }
//
//     return os;
// }
//
//
// int main() {
//     Matrice<int> m{
//         {0},
//         {1, 2},
//         {3, 4, 5},
//         {6, 7, 8, 9}
//     };
//
//     cout << m;
//
//
//     return 0;
// }



//
// template<typename T>
// class Coord {
// private:
//     T x, y;
//
// public:
//     Coord(T x = T{}, T y = T{}): x(x), y(y) {
//     }
//
//     T getX() const { return x; }
//     T getY() const { return y; }
// };
//
// template<typename T>
// class Point {
// private:
//     string nom;
//     Coord<T> coord;
//
// public:
//     Point(string nom, T x, T y): nom(nom), coord(x, y) {
//     }
//
//     const Coord<T> &getCoord() const { return coord; }
//     const string &getNom() const { return nom; }
// };
//
// enum class Quadrant { I = 1, II, III, IV };
//
// template<typename T>
// struct DansQuadrant {
//     Quadrant q;
//
//     bool operator()(const Point<T> &p) {
//         switch (q) {
//             case Quadrant::I: return p.getCoord().getX() > T() && p.getCoord().getY() > T();
//             case Quadrant::II: return p.getCoord().getX() < T() && p.getCoord().getY() > T();
//             case Quadrant::III: return p.getCoord().getX() < T() && p.getCoord().getY() < T();
//             case Quadrant::IV: return p.getCoord().getX() > T() && p.getCoord().getY() < T();
//             default: return false;
//         }
//     }
// };
//
// int main() {
//     vector<Point<int>> dessin {{"p1",  1,  2},
//                                {"p2",  4,  2},
//                                {"p3",  9,  8},
//                                {"p4", -1,  5},
//                                {"p5",  3, -1},
//                                {"p6",  7,  0}};
//
//     int nbI  = count_if(dessin.begin(), dessin.end(), DansQuadrant<int>{Quadrant::I});
//     int nbII = count_if(dessin.begin(), dessin.end(), DansQuadrant<int>{Quadrant::II});
//
//     cout << "Nb points dans quadrant I  : " << nbI << endl;
//     cout << "Nb points dans quadrant II : " << nbII << endl;
// }


// template<typename T>
// class Point {
// private:
//     string nom;
//     T x,y;
//
// public:
//     Point(string nom_, T xVal = T(), T yVal = T() ): nom(nom_), x(xVal), y(yVal){}
//
//     void deplacer(T dx, T dy) {
//         x+=dx;
//         y+=dy;
//     }
//
//     void afficher()const {
//         cout<<nom<<"("<<x<<","<<y<<")";
//     }
//
//     T getX()const{return x;}
//     T getY()const{return x;}
// };
//
// #include <vector>
// #include <algorithm>
//     int main() {
//         // 1. Veri Seti (Dataset)
//         vector<Point<int>> dessin {
//             {"p1",  1,  2},
//             {"p2",  4,  2},
//             {"p3",  9,  8}
//         };
//
//         cout << "Avant : ";
//         for(const auto& p : dessin) p.afficher();
//         cout << endl;
//
//         int dx = 1;
//         int dy = 2;
//
//         // for_each: Vektörün başından sonuna kadar gezer.
//         // Lambda: [dx, dy] -> Dışarıdaki değişkenleri içeri alır (Capture).
//         // (Point<int>& p) -> Referans alır ki orijinal veriyi değiştirebilsin.
//         for_each(dessin.begin(), dessin.end(),
//             [dx, dy](Point<int>& p) {
//                 p.deplacer(dx, dy);
//             }
//         );
//
//         cout << "Apres : ";
//         for(const auto& p : dessin) p.afficher();
//         cout << endl;
//
//         return 0;
//     }

#include <iostream>
#include <vector>
#include <array>

using namespace std;
template<typename T, size_t N =100>
class Stack {
private:
    array<T, N> data;
    size_t current_size;

public:
    Stack(): current_size(0){}
    bool full()const {
        return current_size ==N;
    }
    bool empty()const {
        return current_size ==0;
    }
    size_t size()const {
        return current_size;
    }
    void push(const T& element) {
        if(!full()) {
            data[current_size] =element;
            current_size++;
        }
    }
    void pop() {
        if(!empty()) {
            --current_size;
        }
    }

    const T& top()const {
        return data[current_size-1];
    }

    void display()const{
        cout<<"size: "<<current_size<<endl;
        cout<<"data : [";
        for(size_t i = 0; i<current_size; ++i) {
            if(i>0)cout<<",";
            cout<<data[i];
        }
        cout<<"]"<<endl;
    }

};
template<typename T, size_t N>
void viderDans(Stack<T, N>& source, Stack<T, N>& dest) {
    Stack<T, N> tmp;

    while(!source.empty()) {
        tmp.push(source.top());
        source.pop();
    }

    while(!tmp.empty()) {
        dest.push(tmp.top());
        tmp.pop();
    }
}

int main() {
    // Stack d'entiers avec capacité 10
    Stack<int, 10> s;
    int i = 1;

    s.display();
    cout << endl;

    while (not s.full()) {
        s.push(i*=2);
    }

    cout << "top  : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    cout << endl;

    s.display();
    cout << endl;

    while (not s.empty()) {
        s.pop();
    }

    s.display();
    cout << endl;

    return 0;
}



