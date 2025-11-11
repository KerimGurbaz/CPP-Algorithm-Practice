/*
* #include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void creer_fichier_csv() {
    ofstream in("data.csv");
    in<<"Nom, Prenom, ville, Note"<<endl;
    in<<"Durand, Alice, Yverdon, 18"<<endl;
    in<<"Weber, Bob,,12"<<endl;
    in<<"Merlin, Carlie, Lausanne, 20"<<endl;
    in.close();
}
 void display_csv(const string& s, char separateur, int largeur ) {

    ifstream f(s);
    if(!f.is_open()) {
        throw runtime_error("Impossible d'ovrir le fichier.." + s);
    }
    string ligne;

    while(getline(f, ligne)) {
        stringstream ss(ligne);
        string mot;
        while(getline(ss, mot, separateur)) {
            cout<<setw(largeur)<<left<<mot;
        }
        cout<<endl;
    }
f.close();

}

int main() {
    creer_fichier_csv();
    int largeur_colonne = 10;
    char separateur = ',';

    try {
        display_csv("data.csv", separateur, largeur_colonne);

        cout << "\n--- Test non-existant ---" << endl;
        display_csv("nexiste_pas.csv", separateur, largeur_colonne);

    } catch (const std::runtime_error& e) {
        cerr << "ERREUR: " << e.what() << endl;
    }
}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

template<typename T>
void print_vec(const vector<T>& v) {
    for(const auto& e : v) {
        cout<<e<<" ";
    }
    cout<<endl;
}
template<typename T, typename Predicat>
void supprimer_si(vector<T>& v, Predicat p) {
  auto it = remove_if(v.begin(), v.end(), p );
    v.erase(it, v.end());
}
bool est_pair(int a) {
    return a%2 ==0;
}

int main() {
    // Test 1: int vektörü
    vector<int> v1{1, 2, 3, 5, 7, 10, 15, 22};
    supprimer_si(v1, est_pair); // Çiftleri sil
    print_vec(v1); // Beklenen: 1 3 5 7 15

    // Test 2: char vektörü
    vector<char> v2{'R', '2', '-', 'D', '2', ' ', 'C', '-', '3', 'P', 'O'};
    supprimer_si(v2, ::isdigit); // Rakamları sil
    print_vec(v2); // Beklenen: R - D   C - P O
}
 */
#include <iostream>
#include <limits> // (Gerekirse)

using namespace std;
int trouver_limite_float() {
    int i = 1;
    for(; ; ++i) {
        float f =i;
      int r =f;
        if(r != i) {
            return i;
        }
    }
}

int main() {
    cout << "Plus petit entier non representable en float: "
         << trouver_limite_float() << endl;
}