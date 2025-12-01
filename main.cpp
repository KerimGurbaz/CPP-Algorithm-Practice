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
