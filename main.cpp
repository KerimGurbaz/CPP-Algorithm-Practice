#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

class Voiture {
private:
    double capasite;
    double consomation;
    double nbLitres;

    static double prixEssence;

public:
    Voiture(double cap, double cons);

    static double getPrixEssence();

    static void setPrixEssence(double n);

    friend void afficherVoiture(const Voiture& v);

    double effectuerTrajet(double n);

};

double Voiture::prixEssence =0.0;

Voiture::Voiture(double cap, double cons):
capasite(cap), consomation(cons), nbLitres(capasite) {
}

double Voiture::getPrixEssence()  {
    return prixEssence;
}

void afficherPrixEssence(double prix) {
    cout << "Prix de l'essence :" << prix<< "Frs." << endl;
}

void Voiture::setPrixEssence(double prix) {
    prixEssence = prix;
}

void afficherVoiture(const Voiture& v) {
    cout << "Capacite du reservoir [l]      : " <<v.capasite << endl;
    cout << "Consommation moyenne [l/100km] : " << v.consomation << endl;
    cout << "Nb litres restants             : " << v.nbLitres << endl;;
}

double Voiture::effectuerTrajet(double distanceKm) {
    double utiliseLitre = (distanceKm * consomation ) / 100.0;
    nbLitres -= utiliseLitre;
    while (nbLitres < 0) {
        nbLitres += capasite;
    }
    return utiliseLitre;
}

double afficherCoutTrajet(double distance) {
    double total = distance * Voiture::getPrixEssence();
    cout << "Cout du trajet : " << total << " Frs." << endl;
    cout<<endl;
    return total;
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
