#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>
using namespace std;

string lire_string(const string& prompt) {
    string valeur;
    cout<<prompt;
    getline(cin, valeur);
    return valeur;
}

int lire_int(const string& prompt, int min, int max) {
    int valeur;
    while(true) {
        cout<<prompt;
        cin>>valeur;

        if(cin.fail()) {
            cout<<"Erreur: saisie nom numerique...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(valeur >=min && valeur<=max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valeur;
        }

        cout<<"Erreur: la valeur doit etre entre "<<min<<" et "<<max<<".\n";
    }

}

double lire_double(const string& prompt, double min, double max) {

    double valeur;
    while(true) {
        cout<<prompt;
        cin>>valeur;

        if(cin.fail()) {
            cout<<"Erreur: saisie non numerique.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if(valeur>=min && valeur<=max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valeur;
        }
        cout << "Erreur: La valeur doit etre entre " << min << " et " << max << ".\n";
    }
}

double calculer_moyenne(double note1, double note2) {
    return (note1 + note2)/2.0;
}

bool est_admis(double moyenne) {
    return moyenne >=4.0;
}

string double_to_str(double valeur) {
    stringstream ss;
    ss<<fixed<<setprecision(1)<<valeur;
    return ss.str();
}

void afficher_ligne_tableau(const string& nom, const string& age, const string& note_math, const string& note_prg1, const string& admis) {
    cout<<left<<setw(18)<<nom<<setw(5)<<setw(14)<<note_math<<setw(13)<<note_prg1<<admis<<endl;
}

void afficher_resume(double moyenne, bool admis) {
    cout<<"Moyenne : "<<fixed<<setprecision(2)<<moyenne<<endl;
    cout<<"Resultat : "<<(admis ? "Admis" : "Non Admis")<<endl;
}

int main() {
    const int age_min = 1; const int age_max = 100;
    const double note_min = 1.0; const double note_max = 6.0;
    const string LIGNE_SEPARATION(59, '-');

    string nom = lire_string("Entrez le nom de l'etudiant.e : ");
    int age = lire_int("Entrez l'age de l'etudiant.e : ", age_min, age_max);
    double note_math = lire_double("Entrez la note en mathematiques : ", note_min, note_max);
    double note_prg1 = lire_double("Entrez la note en PRG1 : ", note_min, note_max);

    double moyenne = calculer_moyenne(note_math, note_prg1);
    bool admis = est_admis(moyenne);

    cout << endl;
    afficher_ligne_tableau("Nom", "Age", "Note Math", "Note PRG1", "Admis");
    cout << LIGNE_SEPARATION << endl;
    afficher_ligne_tableau(nom, to_string(age), double_to_str(note_math), double_to_str(note_prg1), admis ? "Oui" : "Non");
    cout << LIGNE_SEPARATION << endl;
    afficher_resume(moyenne, admis);

    return 0;
}