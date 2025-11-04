
#include <iostream>
#include <string>
using namespace std;

void remplacer_toutes(string& texte, const string&mot, const string& alternatif) {

        size_t pos = 0;
        while((pos = texte.find(mot, pos)) != string::npos) {
            texte.replace(pos, mot.size(), alternatif);
            pos += alternatif.size();
    }
}

int main() {
    string s1 = "le chat chasse le chat, mais le chat est rapide.";
    remplacer_toutes(s1, "chat", "chien");
    cout << s1 << endl;

    string s2 = "aaaaa";
    remplacer_toutes(s2, "aa", "b");
    cout << s2 << endl; // Dikkat, örtüşen (overlapping) durum!
}
 /*

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Etudiant {
    string nom;
    double note;
};
Etudiant trouver_meilleur_etudiant(const vector<Etudiant>& v) {
    if(v.empty())return {"inconnu", 0.0};
    Etudiant meilleur = v[0];
    for(size_t i =1; i<v.size(); ++i) {
        if(v[i].note>=meilleur.note) {
            meilleur =v[i];
        }
    }
    return meilleur;
}

int main() {
    vector<Etudiant> classe = {
        {"Alice", 85.0},
        {"Bob", 92.5},
        {"Charlie", 78.0},
        {"David", 92.5} // Eşitlik durumu (égalité)
    };

    Etudiant meilleur = trouver_meilleur_etudiant(classe);
    cout << "Meilleur etudiant: " << meilleur.nom
         << " (Note: " << meilleur.note << ")" << endl;

    vector<Etudiant> vide;
    Etudiant personne = trouver_meilleur_etudiant(vide);
    cout << "Meilleur etudiant: " << personne.nom
         << " (Note: " << personne.note << ")" << endl;
}
*/