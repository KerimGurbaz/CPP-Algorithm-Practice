#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void afficher_fichier(const string& nom) {
    ifstream mon_fichier(nom);

    if(!mon_fichier.is_open()) {
        cerr<<"Erreur le nom de fichier introuvable : ";
        return;
    }
    string ligne;
    int ligneNumber =0 ;
    while(getline(mon_fichier, ligne)) {
        cout<<ligneNumber<<" : "<<ligne;
        ++ligneNumber;
    }
    mon_fichier.close();
}

int main() {
    string nom = "demo.txt";
    afficher_fichier(nom);
}
