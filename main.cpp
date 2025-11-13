#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
using namespace std;

tuple<int, int, string> analyser_fichier(const string & s) {

    ifstream in(s);
    if(!in.is_open()) {
        cerr<<"erreur de l'ouverture de fichier";
        return {};
    }

    string lignes;
    string mot;
    int motsCount = 0;
    string motLong;
    int lignesCount = 0;
    while(getline(in, lignes)) {
        ++lignesCount;
        stringstream ss(lignes);
        while(ss>>mot) {
            ++motsCount;
            if(mot.size() > motLong.size() ) {
                motLong = mot;
            }
        }
    }

    return {motsCount, lignesCount, motLong};
}


int main() {

    ofstream f("journal.txt");

    f<<"Bonjour a tous\nBienvenue a HEIG\nC++ est puissant et genial\n";
    f.close();

    auto[lignes, mots, pluslong] = analyser_fichier("journal.txt");
    cout<<lignes<<endl;
    cout<<mots<<endl;
    cout<<pluslong<<endl;

    return 0;
}