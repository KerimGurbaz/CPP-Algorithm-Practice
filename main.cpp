

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
//
// class MonEntier {
// private:
//     int valeur;
//
// public:
//     MonEntier(int val =0): valeur(val){}
//
//     MonEntier& operator +=(const MonEntier& autre) {
//          valeur +=autre.valeur;
//         return *this;
//     }
//
//     MonEntier& operator++() {
//         ++valeur;
//         return *this;
//     }
//
//     MonEntier& operator++(int) {
//         MonEntier temp =*this;
//         ++(*this);
//         return temp;
//     }
//
//     friend ostream& operator<<(ostream& os, const MonEntier& m) {
//         return os<<"n = "<<m.valeur;
//     }
//
//     friend bool operator ==(const MonEntier& lhs, const MonEntier& rhs) {
//         return lhs.valeur == rhs.valeur;
//     }
//
//     friend bool operator!=(const MonEntier& lhs, const MonEntier& rhs) {
//         return !(lhs == rhs);
//     }
//
//     friend MonEntier operator +(MonEntier lhs, const MonEntier& rhs) {
//         lhs+= rhs;
//         return lhs;
//     }
// };
//
//
// int main() {
//     MonEntier m0, m1(1), m2 = 5;
//     const MonEntier m3{7};
//
//     cout << m0 << endl   // n = 0
//          << m1 << endl;  // n = 1
//
//     cout << boolalpha;
//     cout << (m0 == m1) << endl; // false
//     cout << (m0 != m1) << endl; // true
//     cout << noboolalpha;
//
//     cout << m1++ << endl; // n = 1 (Affiche l'ancien, interne devient 2)
//     cout << m1 << endl;   // n = 2
//     cout << ++m1 << endl; // n = 3 (Interne devient 3, affiche 3)
//
//     cout << m1 + m2 << endl; // n = 8 (3 + 5)
//     m1 += m2;                // m1 devient 8
//     cout << m1 << endl;      // n = 8
//     cout << m3 + m2 << endl; // n = 12 (7 + 5)
// }
//
// class Voiture {
// private:
//     double capaciteReservoir;
//     double consommationMoyenne;
//     double litresRestants;
//
//     static double prixEssence;
//
// public:
//     Voiture(double capacite, double consommation)
//         :capaciteReservoir(capacite), consommationMoyenne(consommation) {
//         this-> litresRestants = capacite;
//     }
//
//     static double getPrixEssence() {
//         return prixEssence;
//     }
//
//     static void setPrixessence(double prix) {
//         prixEssence = prix;
//     }
//
//     double effectuerTrajet(double distanceKm) {
//         double litresConsommes =(distanceKm * consommationMoyenne) /100.0;
//         double cout = litresConsommes * prixEssence;
//
//         litresRestants -= litresConsommes;
//
//         while(litresRestants <0) {
//             litresRestants += capaciteReservoir;
//         }
//
//
//         return cout;
//     }
//
//     double getCapacite()const {
//         return capaciteReservoir;
//     }
//
//     double getConsommation()const{return consommationMoyenne;}
//
//     double getLitresRestant()const {
//         return litresRestants;
//     }
// };
//
// double Voiture::prixEssence =1.70;
//
// void afficherPrixEssence(double prix) {
//     cout<<fixed<<setprecision(2)<<"prix l'essance"<<prix<<" Frs"<<endl;
// }
//

#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

class Voiture {
private:
    double capacite_;
    double consommation_;
    double nbLitres_;

    static double prixEssence_;

public:
    Voiture(double capacite, double consomation)
        : capacite_(capacite), consommation_(consomation), nbLitres_(capacite) {
    }

    static double getPrixEssence() {
        return prixEssence_;
    }

    static void setPrixEssence(double prix) {
        prixEssence_ = prix;
    }

    double effectuerTrajet(double distanceKm) {
        double litresUtilise = distanceKm * consommation_ / 100.0;
        nbLitres_ -= litresUtilise;
        while(nbLitres_ < 0) {
            nbLitres_ += capacite_;
        }

        return (litresUtilise * prixEssence_);
    }

    double getCapacite() const {
        return capacite_;
    }

    double getConsommation() const {
        return consommation_;
    }

    double getNbLitres() const {
        return nbLitres_;
    }
};

double Voiture::prixEssence_ = 1.70;

void afficherPrixEssence(double prix) {
    cout<<"Prix de l'essence : "<<fixed<<setprecision(2)<<prix<<" Frs"<<endl;
}

void afficherVoiture(const Voiture& v) {
    cout << "Capacite du reservoir [l]      : " << v.getCapacite() << endl;
    cout << "Consommation moyenne [l/100km] : " << v.getConsommation() << endl;
    cout << "Nb litres restants             : " << fixed << setprecision(1)
         << v.getNbLitres() << endl << endl;


}

void afficherCoutTrajet(double cout_x) {
    cout << "Cout du trajet : " << fixed << setprecision(2)
         << cout_x << " Frs" << endl << endl;
}

int main() {

    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture::setPrixEssence(1.95);
    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture v(52, 6.7);

    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(1000));
    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(200));
    afficherVoiture(v);

    return EXIT_SUCCESS;
}