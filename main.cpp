/*
*


enum class Chiffre {ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF};


Chiffre next(Chiffre c) {
    int val = static_cast<int>(c);
    val = (val - 1 +10) %10;
    return static_cast<Chiffre>(val);
}

void afficher(Chiffre c) {
    switch(c) {
        case Chiffre::ZERO:  cout << "ZERO";  break;
        case Chiffre::UN:    cout << "UN";    break;
        case Chiffre::DEUX:  cout << "DEUX";  break;
        case Chiffre::TROIS: cout << "TROIS"; break;
        case Chiffre::QUATRE:cout << "QUATRE";break;
        case Chiffre::CINQ:  cout << "CINQ";  break;
        case Chiffre::SIX:   cout << "SIX";   break;
        case Chiffre::SEPT:  cout << "SEPT";  break;
        case Chiffre::HUIT:  cout << "HUIT";  break;
        case Chiffre::NEUF:  cout << "NEUF";  break;
        default:             cout << "INCONNU";

    }
}

bool operator<( Chiffre a, Chiffre b) {
    return static_cast<int>(a) < static_cast<int>(b);
}

int main() {

    Chiffre a = Chiffre::CINQ;
    Chiffre b = next(a);
    afficher(a);
    cout << (a < b ? " < " : " >= ");	   // CINQ < SIX
    afficher(b);


    return 0;
}
 */
#include <iostream>
#include <cstdint>
#include <sstream>
using namespace std;

enum class Mois:uint8_t {
    JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN,
    JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

struct Date {
    uint8_t jour;
    Mois mois;
    int16_t annee;
};

bool est_bissextile_annee(int16_t annee) {
    if(annee <= 0) return  0;
    return (annee % 400 == 0) || (annee %4 == 0 && annee %100 !=0);
}

uint8_t jours_dans_le_mois(Mois m, int16_t a ) {
    switch (m) {
        case Mois::FEVRIER : return est_bissextile_annee(a) ? 29 :28;
        case Mois::AVRIL:
            case Mois::JUIN:
        case Mois::SEPTEMBRE:
        case Mois::NOVEMBRE:
        return 30;
        default: return 31;
    }
}

long date_to_int(const Date& d) {
    if(d.annee<=0)return 0;
    long total_jours = 0;

    for(int16_t y = 1; y<d.annee; ++y) {
        total_jours += est_bissextile_annee(y) ? 366 : 365;
    }

    for(uint8_t m =1; m<static_cast<uint8_t>(d.mois); ++m) {
        total_jours += jours_dans_le_mois(static_cast<Mois>(m), d.annee);
    }

    total_jours += d.jour;
    return  total_jours;
}


string to_string(const Date& d) {
    stringstream ss;

    ss<<static_cast<int>(d.jour)<<"/"<<static_cast<int>(d.mois)<<"/"<<static_cast<int>(d.annee);
    return ss.str();
}

long jours_entre(const Date& d1, const Date& d2) {
    return abs(date_to_int(d1) - date_to_int(d2));
}

int main() {
    // Initialisation avec l'enum class
    Date d1{29, Mois::OCTOBRE, 1987};
    Date d2{23, Mois::OCTOBRE, 2025};

    cout << jours_entre(d1, d2) << " jours entre "
         << to_string(d1) << " et "
         << to_string(d2) << endl;
    // Sortie attendue: 18542 jours entre 31/1/1973 et 7/11/2023

    return 0;
}