//
//
// #include <iostream>
// using namespace std;
// #include <iomanip>
//
// class Duree {
// private:
//     size_t minutes;
//     size_t secondes;
// public:
//     Duree(size_t minutes, size_t secondes);
//     Duree& operator +=(const Duree& other);
//     friend Duree operator+( Duree& lhs,  Duree rhs);
//     friend ostream& operator<<(ostream&os, const Duree& d);
//     void normailser(Duree& d);
// };
// void Duree::normailser(Duree& d) {
//     while(d.secondes > 60) {
//         d.secondes -= 60;
//         d.minutes +=1;
//     }
// }
// Duree::Duree(size_t minutes, size_t secondes): minutes(minutes), secondes(secondes){}
// Duree& Duree::operator +=(const Duree& other) {
//     this->minutes += other.minutes;
//     this->secondes += other.secondes;
//     normailser(*this);
//     return *this;
// }
// Duree operator+( Duree& lhs,  Duree rhs) {
//
//     return lhs += rhs;
//
// }
//
// ostream& operator<<(ostream&os, const Duree& d) {
//   os<<setfill('0')<<setw(2)<<d.minutes <<" : "
//     <<setfill('0')<<setw(2)<<d.secondes;
//     return os;
// }
//
// int main() {
//     Duree d1(1, 50); // 1 min, 50 sec
//     Duree d2(0, 20); // 0 min, 20 sec
//
//     // Doit gérer le report ! (50s + 20s = 70s -> 1m 10s)
//     Duree total = d1 + d2;
//
//     cout << total << endl; // Affiche "02:10"
// }

// #define DUREE_H
//
// #include <iostream>
// #include <iomanip>
// using namespace std;
// class Duree {
// private:
//
//     int minutes;
//     int secondes;
//     void normaliser();
//
// public:
//     Duree(int minutes = 0, int secondes=0);
//     int getMinutes()const;
//     int getSecondes()const;
//
//     Duree& operator+=(const Duree& autre);
//  friend   std::ostream& operator<<(std::ostream &os, const Duree& d);
// };
// using namespace std;
// Duree operator+(Duree a, const Duree& b);
//
// #endif
//
// Duree::Duree(int minutes, int secondes):
// minutes(minutes), secondes(secondes){normaliser();
// }
//
// void Duree::normaliser() {
//     if(secondes >=60) {
//         minutes += secondes/60;
//         secondes %= 60;
//     }
// }
// int Duree::getMinutes()const {
//     return minutes;
// }
// int Duree::getSecondes()const {
//     return secondes;
// }
// Duree& Duree::operator+=(const Duree& autre) {
//     minutes+= autre.minutes;
//     secondes += autre.secondes;
//     normaliser();
//     return *this;
// }
// Duree operator+(Duree a, const Duree& b) {
//     a += b;
//     return a;
// }
// ostream& operator<<(std::ostream &os, const Duree& d) {
//     os<<std::setw(2)<<setfill('0')<<d.getMinutes()<<":"
//     <<std::setw(2)<<setfill('0')<<d.getSecondes();
//     return os;
// }
//
// int main() {
//     Duree d1(1, 50); // 1 min, 50 sec
//     Duree d2(0, 20); // 0 min, 20 sec
//
//     // Test de l'addition (report attendu : 50+20=70s -> +1min 10s)
//     // Résultat brut avant normalisation : 1m 70s -> Normalisé : 2m 10s
//     Duree total = d1 + d2;
//
//     cout << "D1    : " << d1 << endl;
//     cout << "D2    : " << d2 << endl;
//     cout << "Total : " << total << endl; // Affiche "02:10"
//
//     // Test du +=
//     total += Duree(0, 50); // Ajoute 50 sec -> 2m 60s -> 3m 00s
//     cout << "Apres ajout de 50s : " << total << endl;
//
//     return 0;
// }
//
// #include <vector>
// #include <cmath>   // std::hypot
// using namespace std;
//
//
// struct Point {
//     double x;
//     double y;
// };
//
// class Trajetoire {
// private:
// vector<Point> etapes;
// public:
//     void ajouterEtape(const Point& p) {
//         etapes.push_back(p);
//     }
//     double distanceTotal()const {
//         double total =0.0;
//         for(size_t i= 1; i<etapes.size(); ++i) {
//             const auto& a = etapes[i-1];
//             const auto& b = etapes[i];
//             total += hypot(b.x -a.x, b.y-a.y);
//         }
//         return total;
//     }
//
//     bool estFerme()const {
//         if(etapes.size() <2) return false;
//         const Point& debut = etapes.front();
//         const Point& fin = etapes.back();
//
//         return debut.x == fin.x && debut.y == fin.y;
//     }
// };
//
// #include <iostream>
// #include <vector>
// using namespace std;
//
// struct Action {
//     double prix;
//     int quantite;
// };
//
// class Portfolio {
// private:
//     std::vector<Action> stocker;
//
// public:
//     Portfolio() = default;
//
//     void ajouter(const double &prx, const int &q) {
//         stocker.push_back({prx, q});
//     }
//
//     double valeurTotal() const {
//         double tot = 0.0;
//         for (size_t i = 0; i < stocker.size(); ++i) {
//             tot += stocker[i].prix * stocker[i].quantite;
//         }
//         return tot;
//     }
//
//     Portfolio &operator+=(const Portfolio &other) {
//         stocker.insert(stocker.end(), other.stocker.begin(), other.stocker.end());
//         return *this;
//     }
//
//     friend ostream &operator<<(ostream &os, const Portfolio &p) {
//         os << "Portfolio : [" << p.stocker.size() << "]actions, Valeur :"
//                 << p.valeurTotal() << " CHF";
//         return os;
//     }
//
// };
// Portfolio operator+(Portfolio lhs, const Portfolio& rhs) {
//     lhs+=rhs;
//     return lhs;
//
// }
//
//
// int main() {
//     Portfolio p1;
//     p1.ajouter(100.0, 2); // 200 CHF
//     p1.ajouter(50.0, 4); // 200 CHF
//     // p1 Valeur : 400 CHF
//
//     Portfolio p2;
//     p2.ajouter(10.0, 10); // 100 CHF
//
//     // Test operator+=
//     p1 += p2;
//     // p1 contient maintenant tout (Valeur 500 CHF)
//
//     // Test operator+
//     Portfolio p3 = p1 + p2;
//
//     // Test operator<<
//     cout << p1 << endl;
//     // Affiche : "Portfolio : [3] actions, Valeur : 500 CHF"
//
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm> // max_element
#include <numeric>   // accumulate

using namespace std;

class Notes {
private:
    vector<double> notes; // Veriyi gizle (Encapsulation)

    // HEIG-VD/İsviçre sistemi için sabitler (Static Constexpr)
    static constexpr double MIN_NOTE = 1.0;
    static constexpr double MAX_NOTE = 6.0;

public:
    // Constructeur par défaut
    Notes() = default;

    // 1. AJOUTER (Validation)
    void ajouter(double val) {
        if (val >= MIN_NOTE && val <= MAX_NOTE) {
            notes.push_back(val);
        } else {
            // Opsiyonel: Hata mesajı (cout << "Note invalide!" << endl;)
        }
    }

    // 2. OPERATOR += (Surcharge - Overloading)
    // Senaryo A: Tek bir not eklemek (etudiant1 += 6.0)
    Notes& operator+=(double val) {
        ajouter(val); // Mantığı tekrar yazma, fonksiyonu çağır (DRY Prensibi)
        return *this;
    }

    // Senaryo B: Başka bir öğrencinin notlarını birleştirmek (etudiant1 += etudiant2)
    Notes& operator+=(const Notes& autre) {
        // vector::insert en performanslı yöntemdir
        notes.insert(notes.end(), autre.notes.begin(), autre.notes.end());
        return *this;
    }

    // 3. ANALYSE METHODS (Const Correctness!)
    double getMoyenne() const {
        if (notes.empty()) return 0.0;
        // std::accumulate (toplama için standart algoritma)
        double sum = accumulate(notes.begin(), notes.end(), 0.0);
        return sum / notes.size();
    }

    double getMeilleureNote() const {
        if (notes.empty()) return 0.0;
        // max_element bir iteratör döner, değerini almak için * koymalısın
        return *max_element(notes.begin(), notes.end());
    }

    bool estEchec() const {
        // İsviçre sisteminde ortalama < 4.0 başarısızdır
        return getMoyenne() < 4.0;
    }

    // 4. FRIEND OPERATORS
    // Operator== (Karşılaştırma)
    // Sınıf dışından (friend) tanımlamak genellikle daha esnektir (Simetri)
    friend bool operator==(const Notes& a, const Notes& b) {
        return a.getMoyenne() == b.getMoyenne();
    }

    // Operator<< (Affichage)
    friend ostream& operator<<(ostream& os, const Notes& n) {
        os << "[ ";
        for (const auto& val : n.notes) { // private üyeye friend sayesinde erişiyoruz
            os << val << " ";
        }
        os << "] - Moyenne: " << n.getMoyenne();
        return os;
    }
};

// Main fonksiyonunda hiçbir değişiklik yapmadım, aynen çalışıyor.
int main() {
    cout << "--- TEST NOTES ---" << endl;

    Notes etudiant1;
    etudiant1.ajouter(4.0);
    etudiant1.ajouter(5.5);
    etudiant1.ajouter(20.0); // Geçersiz, eklenmeyecek
    etudiant1.ajouter(-1.0); // Geçersiz, eklenmeyecek

    // Test: Operator+= (double)
    etudiant1 += 6.0;

    cout << "Etudiant 1 : " << etudiant1 << endl;
    cout << "Max Note : " << etudiant1.getMeilleureNote() << endl;
    cout << "Echec ? : " << (etudiant1.estEchec() ? "OUI" : "NON") << endl;

    Notes etudiant2;
    etudiant2.ajouter(3.0);
    etudiant2.ajouter(3.5);

    // Test: Operator+= (Notes) Merge
    etudiant1 += etudiant2;

    cout << "Etudiant 1 (Apres merge) : " << etudiant1 << endl;

    if (etudiant2 == etudiant1) {
        cout << "Meme niveau" << endl;
    } else {
        cout << "Niveaux differents" << endl;
    }

    return 0;
}