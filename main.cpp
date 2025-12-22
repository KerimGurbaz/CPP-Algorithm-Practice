// // // #include <iostream>
// // //
// // // using namespace std;
// // //
// // // class Point {
// // //
// // // private:
// // //     double x, y;
// // //     double minVal, maxVal;
// // // public:
// // //     Point();
// // //     Point(double xVal, double yVal, double minVal,double maxVal);
// // //     void afficher()const;
// // //     void deplacer(double dx, double dy);
// // //     void setX(double x) {
// // //         if(x<0 || x>minVal) {
// // //
// // //         }else {
// // //             this->x =x;
// // //         }
// // //
// // //     }
// // //     void setY(double y) {
// // //         if(y<0 || y>maxVal) {
// // //
// // //         }else {
// // //             this->x =x;
// // //         }
// // //     }
// // // };
// // // Point::Point(): x(0.), y(0.0){}
// // // Point::Point(double xVal, double yVal, double minVal= 0.,double maxVal=100.)
// // // : x(xVal), y(yVal), minVal(minVal), maxVal(maxVal){}
// // //
// // // void Point::afficher()const {
// // //     cout<<"("<<x<<","<<y<<"), contraintes: "
// // //                           "["<<0<<","<<maxVal<<"]X["<<0<<","<<maxVal<<"]"<<endl;
// // // }
// // //
// // // void Point::deplacer(double dx, double dy) {
// // //    if( x+dx >=0 && x+dx<=maxVal  ) {
// // //        x+=dx;
// // //    }if( y+dy >=0 && y+dy<=maxVal  ) {
// // //        y+=dy;
// // //    }
// // // }
// // //
// // //
// // // int main() {
// // //     Point p1(1.2, 2.4);
// // //     cout << "p1"; p1.afficher();
// // //     p1.deplacer(1., 3.);
// // //     cout << "p1"; p1.afficher();
// // //     p1.setX(4.);
// // //     cout << "p1"; p1.afficher();
// // //     p1.setY(7.);
// // //     cout << "p1"; p1.afficher();
// // //
// // //     Point p2(3., 4.2, 10., 10.);
// // //     cout << "p2"; p2.afficher();
// // //     p2.deplacer(15, 2);
// // //     cout << "p2"; p2.afficher();
// // //     p2.deplacer(3, 2);
// // //     cout << "p2"; p2.afficher();
// // //     p2.setX(-3);
// // //     cout << "p2"; p2.afficher();
// // //     p2.setY(12);
// // //     cout << "p2"; p2.afficher();
// // // }
// // //
// // // #include <iostream>
// // // using namespace std;
// // // #include <vector>
// // //
// // // class Pays {
// // // private:
// // //     string nom;
// // //     double population;
// // //     double superficie;
// // //
// // // public:
// // //     Pays(string nom, double population, double superficie):
// // //     nom(nom), population(population),superficie(superficie){}
// // //
// // //    double get_superficie()const {
// // //        return superficie;
// // //    }
// // //     double get_population() const {
// // //         return population;
// // //     }
// // //     string get_nom() const {
// // //         return nom;
// // //     }
// // //     double calcule_densite_population() {
// // //         return population/superficie;
// // //     }
// // // };
// // //
// // //
// // // int main() {
// // //     vector<Pays> v_pays{
// // //         Pays("Suisse", 8.121830, 41290),
// // //         Pays("France", 66.663766, 547030),
// // //         Pays("Italie", 61.855120, 301230),
// // //         Pays("Allemagne", 80.854408, 357021)
// // // };
// // //
// // //     size_t idx_max_superficie = 0;
// // //     size_t idx_max_population = 0;
// // //     size_t idx_max_densite = 0;
// // //
// // //     for (size_t i = 0; i < v_pays.size(); ++i){
// // //         if (v_pays[i].get_superficie() > v_pays[idx_max_superficie].get_superficie()) {
// // //             idx_max_superficie = i;
// // //         }
// // //         if (v_pays[i].get_population() > v_pays[idx_max_population].get_population()) {
// // //             idx_max_population = i;
// // //         }
// // //         if (v_pays[i].calcule_densite_population() > v_pays[idx_max_densite].calcule_densite_population()) {
// // //             idx_max_densite = i;
// // //         }
// // //     }
// // //     cout << "Pays ayant la plus grande superficie               : "
// // //          << v_pays[idx_max_superficie].get_nom()
// // //          << endl
// // //          << "Pays ayant le plus d'habitants                     : "
// // //          << v_pays[idx_max_population].get_nom()
// // //          << endl
// // //          << "Pays ayant la densite de population la plus grande : "
// // //          << v_pays[idx_max_densite].get_nom()
// // //          << endl;
// // // }
// // #ifndef PAYS_H
// // #define PAYS_H
// //
// // #include <iostream>
// // #include <string>
// // #include <vector>
// //
// //
// // class Pays {
// // private:
// //     std::string nom;
// //     double population;
// //     double superficie;
// //
// // public:
// //     Pays(std::string nom, double population, double superficie);
// //
// //     std::string getNom() const;
// //
// //     double getPopulation() const;
// //
// //     double getSuperficie() const;
// //
// //     double getDensite() const;
// // };
// // #endif
// //
// // #include <iomanip>
// // using namespace std;
// //
// // Pays::Pays(std::string nom, double population, double superficie): nom(nom), population(population),
// //                                                                    superficie(superficie) {
// // }
// //
// // string Pays::getNom() const {
// //     return nom;
// // }
// //
// // double Pays::getPopulation() const {
// //     return population;
// // }
// //
// // double Pays::getSuperficie() const {
// //     return superficie;
// // }
// //
// // double Pays::getDensite() const {
// //     if (superficie == 0)return 0.0;
// //     return getPopulation() * 1000000 / getSuperficie();
// // }
// //
// //
// // int main() {
// //     vector<Pays> pays;
// //     pays.push_back(Pays("Suisse", 8.121830, 41290));
// //     pays.push_back(Pays("France", 66.663766, 547030));
// //     pays.push_back(Pays("Italie", 61.855120, 301230));
// //     pays.push_back(Pays("Allemagne", 80.854408, 357021));
// //
// //     if (pays.empty()) return 0;
// //     const Pays *maxSuperficie = &pays[0];
// //     const Pays *maxPopulation = &pays[0];
// //     const Pays *maxDensite = &pays[0];
// //
// //
// //     for(size_t i = 0; i<pays.size(); ++i) {
// //         if(pays[i].getSuperficie() > maxSuperficie->getSuperficie()) {
// //             maxSuperficie = &pays[i];
// //         }
// //         if(pays[i].getPopulation() > maxPopulation->getPopulation()) {
// //             maxPopulation = &pays[i];
// //         }
// //         if(pays[i].getDensite() > maxDensite->getDensite()) {
// //             maxDensite = &pays[i];
// //         }
// //     }
// //
// //     cout<<left<<setw(50)<<"Pays ayant la plus grande superficie"
// //     <<": "<<maxSuperficie->getNom()<<endl;
// //
// //     cout<<left<<setw(50)<<"Pays ayant le plus d'habitants"
// //     <<": "<<maxPopulation->getNom()<<endl;
// //
// //     cout<<left<<setw(50)<<"Pays ayant la densite de population la plus grande"
// //     <<": "<<maxDensite->getNom()<<endl;
// //
// //     return 0;
// // }
// #include <iostream>
// using namespace std;
// class Robot {
// private:
//     int x;
// public:
//     Robot() ;
//     Robot(int x);
//
//     friend ostream& operator<<(ostream& os, const Robot& r);
//
//     int getPosition()const;
//
//     void deplacer(int dx);
//     void faireDemiTour();
// };
//
// Robot::Robot(): x(0) {}
// Robot::Robot(int x) : x(x){};
// ostream& operator<<(ostream& os, const Robot& r) {
//     os<<r.x;
//     return os;
// }
//
// int Robot::getPosition()const {
//     return x;
// }
//
// void Robot::deplacer(int dx=1) {
//  if(dx>0) {
//      if(x>=0) {
//          x+=dx;
//      }else {
//          x = -x;
//          x -= dx;
//      }
//  }
// }
//
// void Robot::faireDemiTour() {
//     x = -x;
// }
//
//
// int main() {
//     Robot r1, r2(10);
//     cout << "position courante de r2: " << r2.getPosition() << endl;
//     r1.deplacer();
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//     r1.deplacer(-1);
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//     r1.deplacer(2);
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//     r1.faireDemiTour();
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//     r1.deplacer(4);
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//     return EXIT_SUCCESS;
// }


// #include <iostream>
//
// using namespace std;
//
// class Point {
// private:
//     double x, y;
//
// public:
//     Point();
//
//     Point(double x, double y);
//
//     friend ostream &operator<<(ostream &os, const Point &p);
//
//     friend Point operator+(const Point &lhs, const Point &rhs);
//
//     friend Point operator*(const Point &lhs, const double &rhs);
//
//     friend Point operator*(const double &lhs, const Point &rhs);
//
//     friend bool operator==(const Point &lhs, const Point &rhs);
// };
//
// Point::Point(): x(0.), y(0.) {
// }
//
// Point::Point(double x, double y): x(x), y(y) {
// }
//
// ostream &operator<<(ostream &os, const Point &p) {
//     os << "(" << p.x << "," << p.y << ")";
//     return os;
// }
//
// Point operator+(const Point &lhs, const Point &rhs) {
//     return {lhs.x + rhs.x, lhs.y + rhs.y};
// }
//
// Point operator*(const Point &lhs, const double &rhs) {
//     return {lhs.x * rhs, lhs.y * rhs};
// }
//
// Point operator*(const double &lhs, const Point &rhs) {
//     return rhs * lhs;
// }
//
// bool operator==(const Point &lhs, const Point &rhs) {
//     return (lhs.x == rhs.x && rhs.y == lhs.y);
// }
//
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
//     cout << "3. * p1 = " << 3. * p1 << endl;
//
//     cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
//     Point p3(p1);
//     cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
// }
