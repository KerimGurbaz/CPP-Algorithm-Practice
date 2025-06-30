#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;


/*
* template<typename T>
void print_container(const T& container) {
    cout<<"[";
    for(auto it = begin(container); it != end(container); ++it) {
        cout<<*it;
        if(next(it) != end(container)) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

template<typename T>
void selection_sort(T begin, T end) {
    for(T it = begin; it!= end; ++it) {
        T min_it = it;
        for(T j = next(it); j != end; ++j) {
            if(*j <*min_it) {
                min_it = j;
            }
        }
        iter_swap(it, min_it);
    }
}




int main() {
    // --- Initialisation des conteneurs ---
    vector<int> v = {6, 2, 8, 7, 1, 3};
    array<string, 4> a = {"chien"s, "chat"s, "souris"s, "poisson"s};
    double t[] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};

    // --- Traitement du vector<int> ---
    cout << "Vector (avant tri) : ";
    print_container(v);
    selection_sort(begin(v), end(v));
    cout << "Vector (après tri) : ";
    print_container(v);
    cout << endl;

    // --- Traitement du array<string, 4> ---
    cout << "Array (avant tri) : ";
    print_container(a);
    selection_sort(begin(a), end(a));
    cout << "Array (après tri) : ";
    print_container(a);
    cout << endl;

    // --- Traitement du C-style array double[] ---
    cout << "C-style Array (avant tri) : ";
    print_container(t);
    // std::begin et std::end fonctionnent aussi pour les tableaux C-style.
    selection_sort(begin(t), end(t));
    cout << "C-style Array (après tri) : ";
    print_container(t);

    return 0;
}

template<typename T>
void selection_sort(T begin, T end) {
    for(T it = begin; it != end; ++it) {
        T min_it = it;
        for(T j = next(it); j != end; ++j) {
            if(*j < *min_it) {
                min_it = j;
            }
        }
        iter_swap(it, min_it);
    }
}


struct Employe {
    string nom;
    int salaire;
};

bool operator<(const Employe& a, const Employe& b) {
    return a.salaire < b.salaire;
}

ostream& operator<<(ostream & os, const Employe&  e) {
    os<<"{"<<e.nom<<", "<< e.salaire<<"}"<<endl;
    return os;
}
int main() {
    vector<Employe> equipe = {
        {"Alice", 80000},
        {"Bob", 65000},
        {"Charlie", 95000},
        {"David", 60000}
    };

    cout << "Équipe avant tri : ";
    for(const auto& e : equipe) cout << e << " ";
    cout << endl;

    selection_sort(begin(equipe), end(equipe));

    cout << "Équipe après tri (par salaire) : ";
    for(const auto& e : equipe) cout << e << " ";
    cout << endl;

    return 0;
}

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Produit {
    string nom;
    double prix;
    int stock;
};

vector<const Produit*> make_pointers(const vector<Produit>& v) {
    vector<const Produit*> ptr_vec;
    ptr_vec.reserve(v.size());
    for(const auto& p : v) {
        ptr_vec.push_back(&p);
    }
    return ptr_vec;
}

bool compareProduits(const Produit* a, const Produit* b) {
    if(a->prix < b-> prix) {
        return true;
    }
    if(a->prix > b->prix) {
        return false;
    }
    return a->nom < b-> nom;
}

int main() {
    const vector<Produit> inventaire = {
        {"Stylo", 1.50, 150},
        {"Cahier", 3.00, 80},
        {"Gomme", 1.00, 200},
        {"Crayon", 1.50, 120}
    };
    vector<const Produit*> ptr_inventaire = make_pointers(inventaire);

    // On utilise l'algorithme std::sort et on lui passe notre fonction de comparaison
    sort(ptr_inventaire.begin(), ptr_inventaire.end(), compareProduits);

    cout << "Inventaire trié par prix, puis par nom :" << endl;
    for (const Produit* p : ptr_inventaire) {
        cout << "- " << p->nom << " (" << p->prix << " CHF, " << p->stock << " en stock)" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using Data = double;
using Ligne = vector<Data>;
using Matrice = vector<Ligne>;

Data calculer_somme(const Ligne& ligne) {
    Data total = 0.0;
    for(Data valeur : ligne) {
        total += valeur;
    }
    return total;
}

Data calculer_moyenne(const Ligne& ligne) {
    if(ligne.empty()) {
        return 0.0;
    }
    return calculer_somme(ligne) / ligne.size();
}

template <typename Operation>
vector<Data> statistique_par_ligne(const Matrice& matrice, Operation op) {
    vector<Data> resultats;
    resultats.reserve(matrice.size());

    for(const Ligne& ligne :matrice) {
        resultats.push_back(op(ligne));
    }
    return resultats;
}

void afficher_resultat(const string& titre, const vector<Data>& vecteur) {
    cout<<titre<<": [";
    for(size_t i = 0; i < vecteur.size(); ++i) {
        cout<<vecteur[i];
        if(i < vecteur.size() - 1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main() {
    const Matrice notes {{4.0, 5.0, 6.0},
                         {4.1, 5.1, 4.8},
                         {3.5, 4.1     },
                         {4.5, 4.5, 4.6}};

    vector<Data> sommes =   statistique_par_ligne(notes, calculer_somme);
    afficher_resultat("somme  ", sommes);

    vector<Data> moyennes = statistique_par_ligne(notes, calculer_moyenne);
    afficher_resultat("moyenne", moyennes);
    return 0;
}

 */
