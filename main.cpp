/*
* #include <iostream>
#include <fstream>
using namespace std;


int compter_lignes(const string& s) {
    int compter =0;
    ifstream in(s);
    if(!in.is_open()) {
    cerr<<"Erreur l'ouverture de fichier.. ";
        return 1;
    }

    string line;

    while(getline(in,line )) {
        ++compter;
    }
in.close();
return compter;
}
int main() {
    cout << compter_lignes("lines.txt") << endl;
}

size_t compter_mots(const string& s) {
    size_t compter = 0;
    ifstream in(s);
    if(!in.is_open()) {
        cerr<<"Erreur de l'ouverture de fichier..";
        return 0;
    }

    string mot;

    while(in>>mot) {
        compter++;
    }
in.close();
    return compter;
}

int main() {


    ofstream f("text.txt");
    f << "Bonjour a tous\nBienvenue a HEIG\nC++ est genial\n";
    f.close();

    cout << compter_mots("text.txt") << '\n';
}

 */

#include <iostream>
#include <fstream>
using namespace std;

void filtrer_lignes(const string& entree, const string& sortie, char debut) {
    ifstream in(entree);
    if(!in.is_open()) {
        cerr<<"l'erreur de l'ouverture..";
    }

    ofstream out(sortie);
    if(!out.is_open()) {
        cerr<<"l'erreur de l'ouverture..";
    }
    string mot ;
    while(in>>mot) {
        if(mot[0]== debut) {
            out<<mot<<"\n";
        }

    }
}


int main() {
    ofstream f("data.txt");
    f << "Chat\nChien\nLapin\nCheval\nSouris\n";
    f.close();

    filtrer_lignes("data.txt", "filtre.txt", 'C');

    ifstream in("filtre.txt");
    string line;
    while (getline(in, line))
        cout << line << endl;
}
