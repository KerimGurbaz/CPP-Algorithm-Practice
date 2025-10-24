#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int compter_lettres(const string& nom) {

    ifstream in(nom);
    if(!in.is_open()) {
        cerr<<"Le fichier n'est pas ouvrable..\n";
        return -1;
    }
    int compte = 0;
    string ligne;
    while(getline(in, ligne)) {
        for(char c : ligne) {
            if(isalpha(c)) {
                compte++;
            }
        }
    }
return compte;
}

int main() {
    cout << compter_lettres("notes.txt");
}
