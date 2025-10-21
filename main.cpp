#include <iostream>
#include <cstdlib>

//#include "date.h"
//#include "personne.h"

using namespace std;

struct Date {
    int jour;
    int mois;
    int annee;
};

void afficher_date(const Date& d) {
cout<<d.jour<<"."
    <<d.mois<<"."
    <<d.annee;
}
struct Personne {
    string prenom;
    string adres;
    Date anniversaire;
};

void afficher_personne(const Personne& p) {
    cout<<"Nom : "<<p.prenom<<endl;
    cout<<"Adress : "<<p.adres;
    cout<<"Anniversaire : ";
    afficher_date(p.anniversaire);

}

int main() {

    Date uneDate = {30, 10, 2023};
    cout << "une date     : "; afficher_date(uneDate);
    cout << endl << endl;

    Personne anna = {"Anna", "Yverdon", uneDate};
    afficher_personne(anna);

    cout << endl;

    return EXIT_SUCCESS;
}