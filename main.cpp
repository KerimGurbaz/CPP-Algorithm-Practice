#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;


string lire_string(const string& prompt) {
    string valeur;
    cout<<prompt;
    getline(cin, valeur);
    return valeur;
}

int lire_int(const string& prompt) {
    int valeur;
    while(true) {
        cout<<prompt;
        cin>>valeur;

        if(cin.fail()) {
            cout<<"Erreur : saisie nom numerique. veuillez reessayer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valeur;
        }
    }
}

double lire_double(const string& prompt) {
    double valeur;
    while(true) {
        cout<<prompt;
        cin>>valeur;
        if(cin.fail() || valeur>6.0 ||valeur<0.0) {
            cout<<"Erreur: saisie invalide.."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valeur;
        }
    }
}
double calculer_moyenne(double note1, double note2) {
    return (note1 + note2)/2.0;
}

bool est_admis(double moyenne) {
    return moyenne >=3.8;
}

string double_to_str(double valeur) {
    stringstream ss;
    ss<<fixed<<setprecision(1)<<valeur;
    return ss.str();
}

void afficher(const string& nom, const string& age, const string& note_math, const string& note_prg1, const string& admis) {
    cout<<left
    <<setw(18)<<nom
    <<setw(5)<<age
    <<setw(14)<<note_math
    <<setw(13)<<note_prg1
    <<admis<<endl;
}

void afficher_resume(double moyenne, bool admis) {
    cout<<"Moyenne : "<<fixed<<setprecision(2)<<moyenne<<endl;
    cout<<"resultat"<<(admis ? "Admis" : "Non Admis")<<endl;
}