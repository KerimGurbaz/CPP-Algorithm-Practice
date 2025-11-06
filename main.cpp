#include <iostream>
using namespace std;
#include <iomanip>

struct Date {
    int day;
    int mois;
    int annee;
};

struct Personne {
    string nom;
    string ville;
    Date date;
};

void afficher_date(Date &d) {
    cout << d.day << "."
            << d.mois << "."
            << d.annee << "\n";
}

void afficher_personne(Personne &p) {
    cout << "Nom    : " << p.nom << "\n";
    cout << "Adresse    : "<< p.ville << "\n";
    cout << "Anniversaire   : "; afficher_date(p.date);
}


int main() {
    Date uneDate = {30, 10, 2023};
    cout << "une date     : ";
    afficher_date(uneDate);
    cout << endl << endl;

    Personne anna = {"Anna", "Yverdon", uneDate};
    afficher_personne(anna);

    cout << endl;


    return 0;
}
