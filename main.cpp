#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Statut{DISPONIBLE, EMPRUNTE, RESERVE};

struct Livre {
    string titre;
    string auteur;
    int annee;
    Statut statut;
};

size_t compter_statut(const vector<Livre>&v , const Statut& s) {
    size_t count = 0;
    for(const auto& el: v) {
        if(el.statut == s) {
            count++;
        }
    }
    return count;
}


vector<Livre> livres_par_auteur(const vector<Livre>& s, const string& prenom) {
    vector<Livre> result;
    for(const auto& el : s) {
        if(el.auteur == prenom) {
            result.push_back(el);
        }
    }
    return result;
}
Livre * chercher_plus_recent( vector<Livre>& v) {
    if(!v.empty()) {
            Livre * ptr = &v[0];
    for(size_t i = 0; i<v.size(); ++i){
        if(v[i].annee > (*ptr).annee) {
            ptr = &v[i];
        }
    }
    return ptr ;
    }
    return nullptr;

}

void afficher_livre(const Livre& l) {
    cout << l.titre << " - " << l.auteur << " (" << l.annee << ") ";
    switch (l.statut) {
        case Statut::DISPONIBLE: cout << "[DISPONIBLE]"; break;
        case Statut::EMPRUNTE:   cout << "[EMPRUNTE]";   break;
        case Statut::RESERVE:    cout << "[RESERVE]";    break;
    }
    cout << '\n';
}

void afficher_biblio(const vector<Livre>& v) {
    for (const auto& l : v) afficher_livre(l);
}

int main() {
    vector<Livre> bib = {
        {"Cien Años de Soledad", "Garcia Marquez", 1967, Statut::DISPONIBLE},
        {"Le Petit Prince",     "Saint-Exupéry",  1943, Statut::EMPRUNTE},
        {"1984",                "George Orwell",  1949, Statut::RESERVE},
        {"Animal Farm",         "George Orwell",  1945, Statut::DISPONIBLE},
        {"Les Misérables",      "Victor Hugo",    1862, Statut::EMPRUNTE}
    };

    cout << "Nb DISPONIBLE : " << compter_statut(bib, Statut::DISPONIBLE) << '\n';
    cout << "Nb EMPRUNTE   : " << compter_statut(bib, Statut::EMPRUNTE)   << '\n';
    cout << "Nb RESERVE    : " << compter_statut(bib, Statut::RESERVE)    << '\n';

    cout << "\nLivres de George Orwell:\n";
    auto orwell = livres_par_auteur(bib, "George Orwell");
    afficher_biblio(orwell);

    cout << "\nLivre le plus recent:\n";
    if (auto p = chercher_plus_recent(bib)) {
        afficher_livre(*p);
    } else {
        cout << "Aucun livre.\n";
    }
}
