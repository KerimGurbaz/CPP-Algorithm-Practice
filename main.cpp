// #include <cmath>
// #include <cstdlib>
// #include <iomanip>
// #include <iostream>
// using namespace std;
//
// class Voiture {
// private:
//     double capasite;
//     double consomation;
//     double nbLitres;
//
//     static double prixEssence;
//
// public:
//     Voiture(double cap, double cons);
//
//     static double getPrixEssence();
//
//     static void setPrixEssence(double n);
//
//     friend void afficherVoiture(const Voiture& v);
//
//     double effectuerTrajet(double n);
//
// };
//
// double Voiture::prixEssence =1.70;
//
// Voiture::Voiture(double cap, double cons):
// capasite(cap), consomation(cons), nbLitres(capasite) {
// }
//
// double Voiture::getPrixEssence()  {
//     return prixEssence;
// }
//
// void afficherPrixEssence(double prix) {
//     cout << "Prix de l'essence :" << prix<< "Frs." << endl;
// }
//
// void Voiture::setPrixEssence(double prix) {
//     prixEssence = prix;
// }
//
// void afficherVoiture(const Voiture& v) {
//     cout << "Capacite du reservoir [l]      : " <<v.capasite << endl;
//     cout << "Consommation moyenne [l/100km] : " << v.consomation << endl;
//     cout << "Nb litres restants             : " << v.nbLitres << endl;;
// }
//
// double Voiture::effectuerTrajet(double distanceKm) {
//     double utiliseLitre = (distanceKm * consomation ) / 100.0;
//     nbLitres -= utiliseLitre;
//     while (nbLitres < 0) {
//         nbLitres += capasite;
//     }
//     return utiliseLitre * prixEssence;
// }
//
// double afficherCoutTrajet(double distance) {
//     double total = distance * Voiture::getPrixEssence();
//     cout << "Cout du trajet : " << total << " Frs." << endl;
//     cout<<endl;
//     return total;
// }
//
// int main() {
//     afficherPrixEssence(Voiture::getPrixEssence());
//
//     Voiture::setPrixEssence(1.95);
//     afficherPrixEssence(Voiture::getPrixEssence());
//
//     Voiture v(52, 6.7);
//
//     afficherVoiture(v);
//     afficherCoutTrajet(v.effectuerTrajet(1000));
//     afficherVoiture(v);
//     afficherCoutTrajet(v.effectuerTrajet(200));
//     afficherVoiture(v);
//
//     return EXIT_SUCCESS;
// }

// #include <cmath>
// #include <vector>
// #include <iomanip>
// #include <iostream>
// using namespace std;
// template<typename Iterator>
// typename Iterator::value_type somme_elements(Iterator first,Iterator last) {
//     typename Iterator::value_type somme =0;
//     for(Iterator it = first; it != last; ++it) {
//         somme += *it;
//     }
//     return somme;
// }
//
// int main() {
//
//     vector<int> v{10,20,30,40,50,60};
//     cout << somme_elements(v.begin()+2, v.begin()+5);
// }

#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename Iterator>
typename Iterator::value_type somme_elements(Iterator first, Iterator last) {
    typename Iterator::value_type somme = 0;
    for (Iterator it = first; it != last; ++it) {
        somme += *it;
    }
    return somme;
}


template<typename T>
T maxElement(const vector<T> &v) {
    auto max = max_element(v.begin(), v.end(), [](const T &a, const T &b) {
        return a < b;
    });
    return *max;
}




int main() {
    vector<int> v{10, 20, 30, 40, 50, 60};
    cout << somme_elements(v.begin() + 2, v.begin() + 5);
    cout << endl;
    cout << maxElement(v);


    cout<<count_if(v.begin()+1, v.end()-1, [](int x) {
        return x%3 == 0;
    });
}
