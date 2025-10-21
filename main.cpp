#include <chrono>
#include <iostream>
using namespace std;
#include <utility>
#include <cstdint>
#include <map>
using namespace std;


using Jour = uint8_t;
using Mois = uint8_t;
using Annee = uint16_t;

struct Date {
    Jour jour;
    Mois mois;
    Annee annee;
};

bool est_bissextile(Annee an) {
    if(an <=0) {
        return false;
    }
    return (an%400 == 0 || (an%4 == 0 && an%100 !=0));
}
enum  MoisValeur {
    JANVIER =1, FEVRIER, MARS, AVRIL,
    MAI, JUIN, JUILLET, AOUT,
    SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

Jour nombre_de_jours(Mois m, Annee an) {
    if(m<JANVIER || m>DECEMBRE) {
        return 0;
    }
    switch (m) {
        case AVRIL:
            case JUIN:
        case SEPTEMBRE:
        case NOVEMBRE:
        return 30;
        case FEVRIER:
            return est_bissextile(an) ? 29: 28;
        default:return 31;
    }
}


int main() {
    cout << "Jours en Fev 2023 : " << (int)nombre_de_jours(FEVRIER, 2023) << endl;
    cout << "Jours en Fev 2024 : " << (int)nombre_de_jours(FEVRIER, 2024) << endl;
    cout << "Jours en Juin 2023: " << (int)nombre_de_jours(JUIN, 2023) << endl;
    cout << "Jours en Jan 2023: " << (int)nombre_de_jours(JANVIER, 2023) << endl;
    cout << "Mois invalide (13): " << (int)nombre_de_jours(13, 2023) << endl;

    return 0;
}