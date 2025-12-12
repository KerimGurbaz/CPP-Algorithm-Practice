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

// HeureMinute.h İpucu:
#ifndef HEUREMINUTE_H
#define HEUREMINUTE_H

#include <cstdint> // int8_t için

#include <iostream>

struct HeureMinute {
    int8_t heure;
    int8_t minute;

public:
   friend std::ostream& operator<<(std::ostream& os, const HeureMinute& hm);
   friend HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs);
    friend std::istream& operator>>(std::istream& is, HeureMinute& hm);
};
#endif


#include "HeureMinute.h"
#include <iostream>
#include <iomanip>
using namespace std;

ostream& operator<<(ostream& os, const HeureMinute& hm) {
    os<<setfill('0')<<setw(2)<<+hm.heure<<":"
    <<setfill('0')<<setw(2)<<+hm.minute;
    return os;
}

  HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs) {
    return {lhs.heure + rhs.heure , lhs.minute, rhs.minute};
}

istream& operator>>(std::istream& is, HeureMinute& hm) {
    int h, m;
    char c ='';
    if(is>>h>>c>>m) {
       if(c==':') {
           hm.heure = static_cast<int8_t>(h);
           hm.minute = static_cast<int8_t>(m);
       }else {
           is.setstate(ios::failbit);
       }
    }
    return is;
}