#include <iostream>
#include <fstream>   // ifstream
#include <sstream>   // stringstream
#include <string>
#include <vector>

using namespace std;


struct StatsFichier {
    size_t lignes = 0;
    size_t mots = 0;
    size_t caracteres = 0;
};

void creer_fichier_test() {
    ofstream f("test.txt");
    f << "Bonjour le monde" << endl;
    f << "Ceci est un test" << endl;
    f << "   fin." << endl;
}

StatsFichier analyser_fichier(const string &nom_fichier) {
    StatsFichier stats;
    ifstream in(nom_fichier);
    if (!in.is_open()) {
        return stats;
    }
    string ligne;
    while (getline(in, ligne)) {
        stats.lignes++;
        stats.caracteres += ligne.size();
        stringstream ss(ligne);
        string mot;
        while (ss >> mot) {
            stats.mots++;

        }
    }
    return stats;
}


int main() {
    creer_fichier_test(); // test.txt dosyasını oluştur

    StatsFichier s = analyser_fichier("test.txt");

    cout << "Lignes: " << s.lignes << endl;
    cout << "Mots: " << s.mots << endl;
    cout << "Caracteres: " << s.caracteres << endl;
}
