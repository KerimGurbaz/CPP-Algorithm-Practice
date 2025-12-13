// #ifndef VOITURE_H
// #define VOITURE_H
//
// class Voiture {
// private:
//     double capacite;
//     double niveau;
//     double conso;
//
//     static double prixEssence;
//
//
// public:
//     Voiture(double cap, double cons);
//     static void setPrixEssence(double prix);
//     static double getPrixEssence();
// };
//
// #endif
//
// #include <iostream>
// #include "Voiture.h"
//
// double Voiture::prixEssence=0.0;
//
// Voiture::Voiture(double cap, double cons) : capacite(cap), conso(cons) {
//     niveau(capacite);
// }
//
// void Voiture::setprixEssance(double prix) {
//     prixEssence = prix;
// }
//
// double Voiture::getPrixEssence(){
//     return prixEssence;
// }
//
#include <iostream>
#include <numeric>

// // HeureMinute.h İpucu:
// #ifndef HEUREMINUTE_H
// #define HEUREMINUTE_H
//
// #include <cstdint> // int8_t için
//
// #include <iostream>
//
// struct HeureMinute {
//     int8_t heure;
//     int8_t minute;
//
// public:
//    friend std::ostream& operator<<(std::ostream& os, const HeureMinute& hm);
//    friend HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs);
//     friend std::istream& operator>>(std::istream& is, HeureMinute& hm);
// };
// #endif
//
//
// #include "HeureMinute.h"
// #include <iostream>
// #include <iomanip>
// using namespace std;
//
// ostream& operator<<(ostream& os, const HeureMinute& hm) {
//     os<<setfill('0')<<setw(2)<<+hm.heure<<":"
//     <<setfill('0')<<setw(2)<<+hm.minute;
//     return os;
// }
//
//   HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs) {
//     return {lhs.heure + rhs.heure , lhs.minute, rhs.minute};
// }
//
// istream& operator>>(std::istream& is, HeureMinute& hm) {
//     int h, m;
//     char c ='';
//     if(is>>h>>c>>m) {
//        if(c==':') {
//            hm.heure = static_cast<int8_t>(h);
//            hm.minute = static_cast<int8_t>(m);
//        }else {
//            is.setstate(ios::failbit);
//        }
//     }
//     return is;
// }


// #ifndef PUAN_H
// #define PUAN_H
//
// class Puan {
// private:
//     int num;
//     const int minVal;
//     const int maxVal;
//
// public:
//     Puan(int numVal = {0});
//
//     void set(int n);
//
//     friend std::ostream &operator<<(std::ostream &os, const Puan &p);
// };
// #endif
//
// // main.cpp
// #include <iostream>
//
// #include <stdexcept>
//
// Puan::Puan(int numVal)
//     : num(numVal), minVal(0), maxVal(100) {
//     if (num < minVal || num > maxVal) {
//         num = minVal;
//     }
// }
//
// void Puan::set(int n) {
//     if (n >= minVal && n <= maxVal) {
//         num = n;
//     } else {
//         throw std::out_of_range("Not 0-100 arasinda olmali!");
//     }
// }
//
// std::ostream &operator<<(std::ostream &os, const Puan &p) {
//     os << "[Not : " << p.num << "]";
//     return os;
// }
//
//
// using namespace std;
//
//
// int main() {
//     try {
//         Puan p1; // Varsayılan kurucu (0 atamalı)
//         Puan p2(50); // Parametreli kurucu
//
//         cout << "P1 Baslangic: " << p1 << endl; // Çıktı: [Not: 0]
//
//         p1.set(85);
//         cout << "P1 Yeni: " << p1 << endl; // Çıktı: [Not: 85]
//
//         cout << "Hata Testi yapiliyor..." << endl;
//         p2.set(150); // BURADA "std::out_of_range" FIRLATMALI!
//
//         cout << "Bu satir asla calismamali!" << endl;
//     } catch (const exception &e) {
//         cerr << "Hata yakalandi: " << e.what() << endl;
//         // Çıktı: Hata yakalandi: Not 0-100 arasinda olmali! (veya benzeri)
//     }
//     return 0;
// }

// #ifndef BULLETIN_H
// #define BULLETIN_H
// #include <vector>
// class Bulletin {
// private:
//     std::vector<int>v;
//     const int minNote;
//     const int maxNote;
//
// public:
//     Bulletin(int min =0, int max =6) ;
//     void ajouterNote(int n);
//     double calculerMoyenne()const;
// };
//
// #endif
//
// #include <iostream>
// #include <algorithm>
// #include <stdexcept>
// using namespace std;
// #include "Bulletin.h"
//
// Bulletin::Bulletin(int min, int max): minNote(min), maxNote(max){}
//
// void Bulletin::ajouterNote(int n) {
//     if(n >= minNote && n<= maxNote) {
//         v.push_back(n);
//     }else {
//         throw invalid_argument("Note invalid");
//     }
// }
//
// double Bulletin::calculerMoyenne() const {
//     if(v.empty()) {
//         throw runtime_error("Bulletrin vide ! pas de moyenne");
//     }
//
//     double somme = accumulate(v.begin(), v.end(), 0.0);
//     return somme/v.size();
// }

// #include <iostream>
// #include <utility>
// #include <vector>
// #include <iterator>
// #include <list>
// using namespace std;
//
// template<typename It, typename Compare>
// pair<It, It> plus_long_sequence_croissante(It first, It last, Compare comp) {
//     if (first == last)return {first, first};
//
//     It bestStart = first;
//     It bestEnd = next(first);
//
//     size_t maxSeq = 1;
//
//     It curSeq = first;
//     size_t curMAx = 1;
//
//     for (It it = next(first); it != last; ++it) {
//         if (comp(*prev(it), *it)) {
//             curMAx++;
//         } else {
//             if (curMAx > maxSeq) {
//                 maxSeq = curMAx;
//                 bestStart = curSeq;
//                 bestEnd = it;
//             }
//             curSeq = it;
//             curMAx = 1;
//         }
//     }
//
//     if (curMAx > maxSeq) {
//         bestEnd = last;
//         bestStart = curSeq;
//     }
//
//     return {bestStart, bestEnd};
// }
//
// int main() {
//     // Test 1: Vektör ile (Varsayılan Artan Sıralama)
//     vector<int> v = {10, 2, 3, 4, 1, 5};
//
//     // std::less<int>() -> "a < b" kontrolü yapar (Artan dizi arar)
//     auto res1 = plus_long_sequence_croissante(v.begin(), v.end(), std::less<int>());
//
//     cout << "Vektor (Artan): ";
//     for (auto it = res1.first; it != res1.second; ++it) cout << *it << " ";
//     cout << endl; // Çıktı: 2 3 4
//
//     // Test 2: Liste ile (AZALAN Sıralama - Compare değişiyor!)
//     list<int> l = {1, 2, 5, 4, 3, 2, 8};
//
//     // std::greater<int>() -> "a > b" kontrolü yapar (Azalan dizi arar)
//     // Lambda kullanımı: [](int a, int b){ return a > b; } de olurdu.
//     auto res2 = plus_long_sequence_croissante(l.begin(), l.end(), std::greater<int>());
//
//     cout << "Liste (Azalan): ";
//     for (auto it = res2.first; it != res2.second; ++it) cout << *it << " ";
//     cout << endl; // Çıktı: 5 4 3 2
//
//
//
//
//     return 0;
// }
//
// #include <iterator>
//
// template <typename It>
// size_t total_size(It first, It last) {
//    size_t total =0;
//     for(; first != last; ++first) {
//         total += distance(first->first, first-> second);
//     }
//     return total;
// }
//
// template<typename It, typename Out>
// Out concat(It first, It last, Out out) {
//     for(; first!= last; ++first) {
//
//         for(auto p = first->first; p != first->second; ++p) {
//             *out++ = *p;
//         }
//     }
//     return out;
// }


// #include <cstdlib>
// #include <iostream>
// #include <utility>
// #include <vector>
// #include <iterator>
// using namespace std;
//
// //------------------------------------------------------------
// // Types donnés (NE PAS MODIFIER)
// template <typename T>
// using Iterateur = typename vector<T>::const_iterator;
//
// template <typename T>
// using Plage = pair<Iterateur<T>, Iterateur<T>>;
//
// template <typename T>
// using vPlages = vector<Plage<T>>;
//
// template<typename It>
// size_t total_size( It first, It last) {
//     size_t total =0;
//     for(;first != last; ++first) {
//         total += distance(first->first, first->second);
//     }
//     return total;
// }
// template<typename It, typename Out>
// Out concat(It first, It last, Out out) {
//     for(; first != last; ++first) {
//         for(auto p = first->first; p!=first->second; ++p) {
//             *out++ = *p;
//         }
//     }
//     return out;
// }
//
// //------------------------------------------------------------
// template <typename T>
// ostream& operator<<(ostream& os, const vector<T>& v) {
//     os << "[";
//     for (size_t i = 0; i < v.size(); ++i) {
//         if (i) os << ", ";
//         os << v[i];
//     }
//     return os << "]";
// }
// //------------------------------------------------------------
// int main() {
//     const vector<int> v1 {11, 12, 13, 14, 15, 16};
//     const vector<int> v2 {21, 22, 23, 24};
//     vector<int> v3 {31, 32};
//
//     const vPlages<int> plages {
//             {v1.cbegin()+3, v1.cend()},     // 14,15,16
//             {v1.cbegin(),   v1.cend()-3},   // 11,12,13
//             {v2.cbegin(),   v2.cend()},     // 21,22,23,24
//             {v3.cbegin(),   v3.cend()}      // 31,32
//     };
//
//     size_t n = total_size(plages.cbegin(), plages.cend());
//     cout << "total_size : " << n << endl;
//
//     vector<int> v4(n);
//     auto itEnd = concat(plages.cbegin(), plages.cend(), v4.begin());
//     cout << v4 << endl;
//
//     // Bonus: vérifier l’itérateur retourné (doit pointer après la dernière écriture)
//     cout << boolalpha << (itEnd == v4.end()) << endl;
//
//     return EXIT_SUCCESS;
// }

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

class Voiture {
public:
    double capacite;
    double conso;
    double nbLitres;

    static double prixEssence;

public:
    Voiture(double cap, double cons):capacite(cap), conso(cons),nbLitres(capacite){}

   static double getPrixEssence() {
        return prixEssence;
    }

   static void setPrixEssence(double n) {
        prixEssence = n;
    }

    double effectuerTrajet(double km) {
        double utiliserEssence = conso * km /100.0;
        nbLitres -= utiliserEssence;

        while(nbLitres <=0) {
            nbLitres+= capacite;
        }

        return utiliserEssence * prixEssence;
    }

    friend void afficherVoiture(const Voiture& v) ;

};
double Voiture::prixEssence =1.70;

void afficherVoiture(const Voiture& v)  {
    cout<<"Capacite du reservoir [l]      :"<<v.capacite<<endl;
    cout<<"Consommation moyenne [l/100km] :"<<v.conso<<endl;
    cout<<"Nb litres restants             :"<<fixed << setprecision(1)<<v.nbLitres<<endl;
    cout<<endl;
}

void afficherPrixEssence(double prix) {
    cout<<"Prix de l'essence :"<<fixed << setprecision(2)<<prix<<" Frs";
}

void afficherCoutTrajet(double coutTrajet) {
    cout<<"Cout du trajet :"<<fixed << setprecision(2)<<coutTrajet<<" Frs"<<endl;
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
