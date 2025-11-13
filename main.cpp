#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Statut { DISPONIBLE, EMPRUNTE, RESERVE };

struct Livre {
    string nomLivre;
    string nomAuteur;
    int annee;
    Statut statut;
};


void afficher_livre(const Livre &l) {
    cout << l.nomLivre << ", \n";
    cout << l.nomAuteur << ", \n";
    cout << l.annee << ", \n";
    switch(l.statut) {
        case Statut::RESERVE: cout<<"RESERVE"; break;
        case Statut::EMPRUNTE: cout<<"EMPRUNTE"; break;
        case Statut::DISPONIBLE: cout<<"DISPONIBLE"; break;
        default:cout<<"inconnu"; break;
    }
}

vector<Livre> filtrer_par_statut(const vector<Livre> & v, Statut s) {
    vector<Livre> result;
    for (const auto el&: v) {
        if (el.statut == s) {
            result.push_back(el);
        }
    }
    return result;
}


int main() {
    vector<Livre> bib = {
        {"Cien Años de Soledad", "G. Garcia Marquez", 1967, Statut::DISPONIBLE},
        {"Le Petit Prince", "A. de Saint-Exupéry", 1943, Statut::EMPRUNTE},
        {"1984", "George Orwell", 1949, Statut::RESERVE},
        {"Les Misérables", "Victor Hugo", 1862, Statut::EMPRUNTE}
    };
    auto empruntes = filtrer_par_statut(bib, Statut::EMPRUNTE);
    for (const auto &l: empruntes) afficher_livre(l);
}
