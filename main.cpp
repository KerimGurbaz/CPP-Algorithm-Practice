/*
 * /*
*
using matris = vector<vector<int>>;

pair<int, int> somme_diagonales(const matris& m) {

    size_t diagonal =0;
    size_t inverseDiagonal = 0;

    for(size_t i =0; i<m.size(); ++i) {
        for(size_t j = 0; j<m[i].size(); ++j) {
            if( i==j) {
                diagonal += m[i][j];
            }if(i + j == m.size()-1) {
                inverseDiagonal+= m[i][j];
            }
        }
    }

    return {diagonal, inverseDiagonal};
}

int main() {
    // Test Matrisi (3x3)
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Fonksiyonu çağır
    // pair<int, int> resultat = ...
    auto [ana, ters] = somme_diagonales(m);

    cout << "Principal: " << ana << endl; // Beklenen: 15 (1+5+9)
    cout << "Inverse: "   << ters << endl; // Beklenen: 15 (3+5+7)
}

using namespace std;
using matris = vector<vector<int>>;

pair<int,int> somme_diagonales(const matris& m) {
    int principal = 0;
    int inverse=0;

    for(size_t i = 0; i<m.size(); ++i) {
        principal += m[i][i];
        inverse += m[i][m.size()-1-i];
    }
    return {principal, inverse};
}

int main() {
    // Test Matrisi (3x3)
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    auto [ana, ters] = somme_diagonales(m);

    cout << "Principal: " << ana << endl; // Beklenen: 15 (1+5+9)
    cout << "Inverse: "   << ters << endl; // Beklenen: 15 (3+5+7)
}


void print_vec(const vector<string>& v ) {
    for(const auto& s : v) {
        cout<<s<<" ";
        cout<<endl;
    }
}

void filtrer_mots(vector<string>& v, char ch) {


    auto it = remove_if(v.begin(), v.end(), [ch](string s) {
        return (s.find(ch) != string::npos);
    });

    v.erase(it, v.end());
}

int main() {
    vector<string> mots = {"elma", "armut", "muz", "kivi", "cilek"};
    char yasakli = 'a'; // İçinde 'a' olanları sil

    cout << "Once: ";
    print_vec(mots);

    filtrer_mots(mots, yasakli);

    cout << "Sonra: ";
    print_vec(mots);
    // Beklenen: muz kivi (elma, armut, cilek silinir çünkü 'a' var)
}

void print_vec(const vector<string>& v ) {
    for(const auto& s : v) {
        cout<<s<<" ";
        cout<<endl;
    }
}

void filtrer_mots(vector<string>& v, string ch) {


    auto it = remove_if(v.begin(), v.end(), [&ch](const string & s) {
        return (s.find(ch) != string::npos);
    });

    v.erase(it, v.end());
}

int main() {
    vector<string> mots = {"elma", "armut", "muz", "kivi", "cilek"};
    string yasakli = "mu"; // İçinde 'a' olanları sil

    cout << "Once: ";
    print_vec(mots);

    filtrer_mots(mots, yasakli);

    cout << "Sonra: ";
    print_vec(mots);
    // Beklenen: muz kivi (elma, armut, cilek silinir çünkü 'a' var)
}
struct Mesure {
    size_t id = 0;
    double valeur = 0;
    bool b;
};



using vec = vector<Mesure>;

vector<double> analyser_mesures(const vec& m) {
    vector<double> result;
    for(const auto& el: m) {
        if(el.b == true && el.valeur>0) {
            result.push_back(el.valeur);
        }
    }
    sort(result.begin(), result.end());
return result;
}

int main() {
    // Veri Seti
    vector<Mesure> capteur = {
        {1, -5.0, true}, // Negatif (Atla)
        {2, 10.5, true}, // AL (1)
        {3, 20.0, false}, // Geçersiz (Atla)
        {4, 3.2, true}, // AL (2)
        {5, 100.0, true} // AL (3)
    };


    vector<double> resultats = analyser_mesures(capteur);

    cout << "Resultats tries: ";
    for (double d: resultats) {
        cout << d << " ";
    }
    cout << endl;
    // Beklenen Çıktı (Sıralı): 3.2 10.5 100
}

#include <iostream>
#include <string>
using namespace std;

enum class Direction { NORD, EST, SUD, OUEST };

string dir_to_string(const Direction d) {
    switch (d) {
        case Direction::EST: return "EST";
        case Direction::SUD: return "SUD";
        case Direction::NORD: return "NORD";
        case Direction::OUEST: return "OUEST";
        default : return "inconnu";
    }
}

Direction tourner_a_droite (const Direction& d) {
     int val = static_cast<int>(d);
        val = (val+1)%4;
    return static_cast<Direction>(val);

}

int main() {
    Direction d = Direction::NORD;
    for (int i = 0; i < 9; ++i) {
        d = tourner_a_droite(d);
        cout << dir_to_string(d) << " ";
    }
}


 */

#include <iostream>
#include <cstdint>
#include <sstream>
using namespace std;

using namespace std;
using heur = uint8_t;
using minutes = uint8_t;
using secondes = uint16_t;

struct Temps {
    heur h;
    minutes m;
    secondes s;
};

void normaliser(Temps& t) {
    while(t.s > 59) {
        t.s -= 60;
        t.m +=1;
    }
    while(t.m > 59) {
        t.m -= 60;
        t.h +=1;
    }
}
int main() {

    Temps t = {10, 59, 65};

    cout << "Avant: " << +t.h << ":" <<+t.m << ":" << +t.s << endl;

    normaliser(t);

    cout << "Apres: " << +t.h << ":" << +t.m << ":" << +t.s << endl;

}
