// #ifndef VOITURE_H
// #define VOITURE_H
//
// class Voiture {
// private:
//     double capacite;
//     double niveau;
//     double conso;
//     static double prix;
//
// public:
//     Voiture(double cap, double cons);
//
//     double effectuerTrajet(double distanceKm);
//
//     static void setPrixEssence(double nouveauEssence);
//
//     static double getPrixEssence();
// };
//
// #endif
//
// // Voiture.cpp
// #include <iostream>
// #include "Voiture.h"
//
// double Voiture::prix =0.0;
// Voiture::Voiture(double cap, double cons) : capacite(cap), conso(cons) {
//     niveau(capacite);
// }
//
// double Voiture::effectuerTrajet(double disKm) {
//     double LitreUtilise = (disKm * conso) / 100.0;
//     niveau -= LitreUtilise;
//     while(niveau <0) {
//         niveau += capacite;
//     }
//
//     return LitreUtilise * prix;
// }
//
// void Voiture::setPrixEssence(double nouveauEssence) {
//     prix = nouveauEssence;
// }
//
// double Voiture::getPrixEssence() {
//     return prix;
// }


// HeureMinute.h
#include <bits/ranges_algo.h>
#ifndef HEUREMINUTE_H
#define HEUREMINUTE_H
#include <iostream>
#include <cstdint> // int8_t için

struct HeureMinute {
    int8_t heure;
    int8_t minute;

    friend std::ostream &operator<<(std::ostream &os, const HeureMinute &hm);

    friend std::istream &operator>>(std::istream &is, HeureMinute &hm);

    friend bool operator<(const HeureMinute &lhs, const HeureMinute &rhs);

    friend HeureMinute operator+(const HeureMinute &lhs, const HeureMinute &rhs);

    // Prototip ekle: operator<<, operator>>, operator<, operator+
};
#endif

#include "HeureMinutes.h"
#include <iostream>
#include <iomanip>
using namespace std;

ostream &operator<<(std::ostream &os, const HeureMinute &hm) {
    os << setw(2) << setfill('0') << +hm.heure << ":"
            << setw(2) << setfill('0') << +hm.minute;
    return os;
}

istream &operator>>(std::istream &is, HeureMinute &hm) {
    int h, m;
    char sep;

    if (is >> h >> sep >> m) {
        hm.heure = static_cast<int8_t>(h);
        hm.minute = static_cast<int8_t>(m);
    }
    return is;
}

bool operator<(const HeureMinute &lhs, const HeureMinute &rhs) {
    if (lhs.heure != rhs.heure) {
        return lhs.heure < rhs.heure;
    } else {
        return lhs.minute < rhs.minute;
    }
}



HeureMinute operator+(const HeureMinute &lhs, const HeureMinute &rhs) {
int totalMinutes = (lhs.heure*60 + lhs.minute) + rhs.heure*60 +rhs.minute;
    totalMinutes = totalMinutes %1440;

    return HeureMinute{static_cast<int8_t>(totalMinutes /60),
    static_cast<int8_t>(totalMinutes%60)};
}
