// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
//
// using namespace std;
//
// class Notes {
// private:
//     vector<double> notes;
//
//     double minNote;
//     double maxNote;
//
// public:
//     Notes(double minN =0.0, double maxN=6.0):minNote(minN), maxNote(maxN){}
//
//     void ajouter(double val) {
//         if(val>=minNote && val<=maxNote) {
//             notes.push_back(val);
//         }
//     }
//
//     Notes& operator+=(double val) {
//         ajouter(val);
//         return *this;
//     }
//
//     Notes& operator+=(const Notes& autre) {
//         notes.insert(notes.end(), autre.notes.begin(), autre.notes.end());
//         return *this;
//     }
//
//     double getMoyenne()const {
//         if(notes.empty()) return 0.0;
//
//         double tot=0.0;
//         for(double x: notes) {
//             tot += x;
//         }
//         return tot / notes.size();
//     }
// double getMeilleureNote()const {
//         return *max_element(notes.begin(), notes.end());
//     }
// bool estEchec()const {
//         return getMoyenne() < 4.0;
//     }
// bool operator ==(const Notes& other)const {
//         return getMoyenne() == other.getMoyenne();
//     }
//     friend ostream&operator<<(ostream& os, const Notes& n){
//     os<<"[";
//         for(size_t i = 0; i<n.notes.size(); ++i) {
//
//             if(i)os<<",";
//             os<<n.notes[i];
//         }
//         os<<"] - Moyenne "<<n.getMoyenne();
//         return os;
//     }
//     void supprimerEchecs() {
//         notes.erase(remove_if(notes.begin(), notes.end(),[](double x) {
//             return x<4.0;
//         }), notes.end());
//     }
// };
//
// int main() {
//     cout << "--- TEST NOTES ---" << endl;
//
//     Notes etudiant1;
//     // Test: Validasyon ve Normal Ekleme
//     etudiant1.ajouter(4.0);
//     etudiant1.ajouter(5.5);
//     etudiant1.ajouter(20.0); // GEÇERSİZ! Eklenmemeli. (Sınavda Validasyon = Puan)
//     etudiant1.ajouter(-1.0); // GEÇERSİZ!
//
//     // Test: Operator+= (Tek not ekleme)
//     etudiant1 += 6.0;
//
//     // Test: Const Correctness ve Output
//     cout << "Etudiant 1 : " << etudiant1 << endl;
//     // Çıktı: [4, 5.5, 6] - Moyenne: 5.16
//
//     cout << "Max Note : " << etudiant1.getMeilleureNote() << endl; // 6.0
//     cout << "Echec ? : " << (etudiant1.estEchec() ? "OUI" : "NON") << endl; // NON
//
//     Notes etudiant2;
//     etudiant2.ajouter(3.0);
//     etudiant2.ajouter(3.5);
//
//     // Test: Operator+= (Başka bir nesneyi ekleme - Merge)
//     // Etudiant 2'nin notlarını Etudiant 1'e ekle
//     etudiant1 += etudiant2;
//
//     cout << "Etudiant 1 (Apres merge) : " << etudiant1 << endl;
//     // Çıktı: [4, 5.5, 6, 3, 3.5] ...
//
//     // Test: Operator== (Ortalama karşılaştırma)
//     if (etudiant2 == etudiant1) {
//         cout << "Meme niveau" << endl;
//     } else {
//         cout << "Niveaux differents" << endl;
//     }
//
//     return 0;
// }

//
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// #include <numeric>
// using namespace std;
//
// struct Point {
//     double x, y;
// };
//
// class Trajet {
// private:
//     vector<Point> etapes;
// public:
//     Trajet() = default;
//     void ajouterArret(const Point& p);
//     Point & operator[](size_t i);
//     const Point& operator[](size_t i)const;
//     double distanceTotale()const;
//     void inverser();
//     friend Trajet operator+(Trajet lhs, const Trajet&rhs);
//     friend ostream& operator<<(ostream& os, const Trajet& t);
// };
// void Trajet::ajouterArret(const Point& p) {
//     etapes.push_back(p);
// }
// Point& Trajet::operator[](size_t i) {
//     return etapes[i];
// }
// const Point& Trajet::operator[](size_t i)const {
//     return etapes[i];
// }
// double Trajet::distanceTotale()const {
//     if(etapes.size() <2) return 0.0;
//     double total = 0.0;
//     for(size_t i = 0; i<etapes.size()-1; ++i) {
//         double dx = etapes[i+1].x - etapes[i].x;
//         double dy = etapes[i+1].y - etapes[i].y;
//         total += hypot(dx, dy);
//     }
//     return total;
// }
// void Trajet::inverser() {
//     reverse(etapes.begin(), etapes.end());
// }
//
//  Trajet operator+(Trajet lhs, const Trajet&rhs) {
//     lhs.etapes.insert(lhs.etapes.end(), rhs.etapes.begin(), rhs.etapes.end());
//     return lhs;
// }
//
//  ostream& operator<<(ostream& os, const Trajet& t) {
//     os << "Trajet [" << t.etapes.size() << " points] - Distance : "
//                << t.distanceTotale();
//     return os;
// }
//
// int main() {
//     cout << "\n--- TEST TRAJET ---" << endl;
//
//     Trajet aller;
//     aller.ajouterArret({0, 0});
//     aller.ajouterArret({3, 4}); // Mesafe: 5
//
//     // Test: Operator[] (Okuma ve Yazma)
//     aller[1].x = 3.0; // Yazma (Non-const version)
//     cout << "Premier point : " << aller[0].x << ", " << aller[0].y << endl; // Okuma
//
//     Trajet retour;
//     retour.ajouterArret({3, 4});
//     retour.ajouterArret({10, 4}); // Mesafe: 7
//
//     // Test: Operator+ (Birleştirme) ve Zincirleme
//     Trajet voyageComplet = aller + retour;
//
//     cout << "Voyage Complet : " << voyageComplet << endl;
//     // Çıktı: Trajet [4 points] - Distance : 12.0
//
//     // Test: Ters Çevirme (Modification)
//     voyageComplet.inverser();
//     cout << "Voyage Inverse (Premier point) : "
//          << voyageComplet[0].x << ", " << voyageComplet[0].y << endl;
//     // Artık (10, 4) olmalı
//
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // remove_if
#include <numeric>   // accumulate

using namespace std;

struct Article {
    string nom;
    double prix;
};
class Panier {
private:
    vector<Article> stock;
public:
    Panier()= default;
    void ajouter(const string& s, double prix);
    friend ostream&operator<<(ostream& os, const Panier& p);
    void supprimerCher(double n);
    double getTotal()const;
};


void Panier::ajouter(const string& s, double prix) {
    stock.push_back(Article{s, prix});
}

ostream& operator<<(ostream& os, const Panier& p) {
    os<<"Panier :"<<p.stock.size()<<" articles. Total :"
    <<p.getTotal();
    return os;
}

void Panier::supprimerCher(double n) {
    auto it = remove_if(stock.begin(), stock.end(),[=](Article& a) {
        return a.prix>n;
    });
    stock.erase(it,stock.end());
}

double Panier::getTotal()const {
    double tot = 0.0;
    for(size_t i = 0; i<stock.size(); ++i) {
        tot += stock[i].prix;
    }
    return tot;
}


int main() {
    Panier monPanier;

    monPanier.ajouter("Pomme", 1.50);
    monPanier.ajouter("Champagne", 45.00);
    monPanier.ajouter("Pain", 2.20);
    monPanier.ajouter("Caviar", 120.00);

    // Etat initial
    cout << monPanier << endl;
    // Panier : 4 articles. Total : 168.7

    // Filtrage
    monPanier.supprimerCher(20.00);

    // Verification
    cout << "Apres suppression :" << endl;
    cout << monPanier << endl;
    // Panier : 2 articles. Total : 3.7 (Sadece Pomme ve Pain kalmalı)

    return 0;
}