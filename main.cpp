#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

// class Point {
// private:
//     double x, y;
//
// public:
//     Point(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {
//     }
//
//     bool operator==(const Point &other) const {
//         return (x == other.x) && (y == other.y);
//     }
//
//     bool operator !=(const Point &other) const {
//         return !(*this == other);
//     }
//
//     Point operator+(const Point &other) const {
//         return Point(x + other.x, y + other.y);
//     }
//
//     Point operator*(double scalar) const {
//         return Point(x * scalar, y * scalar);
//     }
//
//     friend Point operator*(double scaler, const Point &p);
//
//     friend ostream &operator<<(ostream &os, const Point &p);
// };
//
// Point operator*(double scalar, const Point &p) {
//     return Point(p.x * scalar, p.y * scalar);
// }
//
// ostream &operator<<(ostream &os, const Point &p) {
//     os << "(" << p.x << "," << p.y << ")";
//     return os;
// }
//
// class Point {
// private:
//     double x, y;
// public:
//     Point(double xVal=0.0, double yVal =0.0): x(xVal), y(yVal){}
//
//     friend ostream& operator<<(ostream& os,const Point& p) {
//         os<<"("<<p.x<<","<<p.y<<")"<<endl;
//         return os;
//     }
//
//     Point operator+(const Point& other) const{
//         return Point(x+other.x , y+other.y);
//     }
//
//     Point operator *(double scalaer) const{
//         return Point(x*scalaer, y*scalaer);
//     }
//     bool operator==(const Point &other) const {
//         return (x == other.x)&& y==other.y;
//     }
//
//     bool operator!=(const Point &other) const {
//         return !((x == other.x)&& y==other.y);
//     }
//
//     friend Point operator *(double scaler , const Point& p);
//
// };
// Point operator *(double scaler , const Point& p) {
//     return Point(p.x* scaler, p.y* scaler);
// }
// int main() {
//     Point p1(1.2, 2.4);
//     Point p2(3., 4.2);
//
//     cout << "p1" << p1 << ", p2" << p2 << endl;
//
//     cout << "p1 + p2 = " << p1 + p2 << endl;
//     cout << "p2 + p1 = " << p2 + p1 << endl;
//
//     cout << "p1 * 2. = " << p1 * 2. << endl;
//
//     cout << "3. * p1 = " << 3. * p1 << endl;
//
//     cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
//
//     Point p3(p1);
//     cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
//
//     return 0;
// }

class MonEntier {
private:
    int valeur;

public:
    MonEntier(int val =0): valeur(val){}

    MonEntier& operator +=(const MonEntier& autre) {
         valeur +=autre.valeur;
        return *this;
    }

    MonEntier& operator++() {
        ++valeur;
        return *this;
    }

    MonEntier& operator++(int) {
        MonEntier temp =*this;
        ++(*this);
        return temp;
    }

    friend ostream& operator<<(ostream& os, const MonEntier& m) {
        return os<<"n = "<<m.valeur;
    }

    friend bool operator ==(const MonEntier& lhs, const MonEntier& rhs) {
        return lhs.valeur == rhs.valeur;
    }

    friend bool operator!=(const MonEntier& lhs, const MonEntier& rhs) {
        return !(lhs == rhs);
    }

    friend MonEntier operator +(MonEntier lhs, const MonEntier& rhs) {
        lhs+= rhs;
        return lhs;
    }
};


int main() {
    MonEntier m0, m1(1), m2 = 5;
    const MonEntier m3{7};

    cout << m0 << endl   // n = 0
         << m1 << endl;  // n = 1

    cout << boolalpha;
    cout << (m0 == m1) << endl; // false
    cout << (m0 != m1) << endl; // true
    cout << noboolalpha;

    cout << m1++ << endl; // n = 1 (Affiche l'ancien, interne devient 2)
    cout << m1 << endl;   // n = 2
    cout << ++m1 << endl; // n = 3 (Interne devient 3, affiche 3)

    cout << m1 + m2 << endl; // n = 8 (3 + 5)
    m1 += m2;                // m1 devient 8
    cout << m1 << endl;      // n = 8
    cout << m3 + m2 << endl; // n = 12 (7 + 5)
}