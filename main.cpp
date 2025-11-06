#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::sort için

using namespace std;

struct Etudiant {
    string nom;
    double note;
};

void print_classe(const vector<Etudiant>& classe) {
    for(const auto& e : classe) {
        cout << e.nom << " (" << e.note << ")" << endl;
    }
}

int main() {
    vector<Etudiant> classe = {
        {"Bob", 92.5},
        {"Alice", 85.0},
        {"David", 92.5}, // Bob ile notu eşit
        {"Charlie", 78.0},
        {"Eve", 95.0}
    };

    sort(classe.begin(), classe.end(),[](const Etudiant& a, const Etudiant& b) {
        if(a.note != b.note) {
            return a.note > b.note;
        }
        return a.nom < b.nom;
    });




    print_classe(classe);
}