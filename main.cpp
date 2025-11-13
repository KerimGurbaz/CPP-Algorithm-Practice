#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <map>
using namespace std;

vector<pair<string,double>> notes_moyennes(const string& fichier) {
map<string, pair<double, int>> result;

    ifstream in(fichier);
    if(!in.is_open()) {
        cerr<<"Erreur d'ouverture : "<<fichier<<endl;
    }

    string nom, prenom;
    double note;

    while(in>>nom>>prenom>>note) {
        string key = nom + " " + prenom;

        result[key].first += note;
        result[key].second++;
    }

vector<pair<string, double>> resultats;
    resultats.reserve(result.size());
    for(const auto& entry : result) {
        const string& name = entry.first;
        double total = entry.second.first;
        int count = entry.second.second;

        double moyenne = total / count;

        resultats.push_back({name, moyenne});
    }

    return resultats;
}

int main() {

    ofstream f("notes.txt");
    f << "Ali Veli 5.5\n";
    f << "Ayse Demir 4.2\n";
    f << "Mehmet Kaya 6.0\n";
    f << "Ali Veli 5.8\n";
    f << "Ayse Demir 5.0\n";
    f.close();

    auto r = notes_moyennes("notes.txt");
    for (const auto& [nom, moy] : r)
        cout << nom << " : " << moy << '\n';
}
