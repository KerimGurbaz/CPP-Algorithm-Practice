#include <iostream>
#include <vector>

using namespace std;

/*
* void doubler_valeurs(vector<int>& v) {
    for(int& i : v) {
        i *=2;
    }
}

int main() {
    vector<int> v = {1, 2, 3};
    doubler_valeurs(v);

    for(int e : v) cout << e << " ";
    // Beklenen Çıktı: 2 4 6
}

string changer_animal(const string& s) {
    string myStr =s;
    string from ="chat";
    int pos = 0;
    while((pos = myStr.find(from, pos)) != string::npos) {
        myStr.replace(pos,from.size(), "lion");
        pos +=1;
    }
    return myStr;
}

int main() {
    string s = "le chat dort";
    string s2 = changer_animal(s);

    cout << s << endl;
    cout << s2 << endl;
}

Soru 3) "Pozitif"

#include <sstream>

int extraire_prix(const string& s) {
    int prix = 0;

    stringstream ss(s);
    string produit;
    string prixS;
    getline(ss, produit, ':');
    getline(ss, prixS, ':');
    prix += stoi(prixS);

    return prix;
}



int main() {
    int p1 = extraire_prix("Kalem:25");
    int p2 = extraire_prix("Defter:40");

    cout << "Total: " << p1 + p2 << endl;

}

struct Ogrenci {
    string nom;
    vector<double> notes;
    double moyenne = 0.0;
};
int main() {
    Ogrenci o = {"Ali", {4.0, 5.0, 6.0}, 0.0};
    cout << o.nom << " not sayisi: " << o.notes.size() << endl;
}//boyle soru olmaz ama sinav kalitesinde olmasini istiyoruz, onemli pratik metodlari ogrenmek istiyoruz. =(

enum class Couleur{ROUGE=0, ORANGE, VERT};


Couleur prochaine_couleur(const Couleur& c) {
    int cVal = static_cast<int>(c);
    int nVal = ((cVal + 2)%3);
    Couleur N = static_cast<Couleur>(nVal);
    return N;
}
int main() {
    Couleur c = Couleur::ROUGE;
    c = prochaine_couleur(c);
    c = prochaine_couleur(c);

    if(c == Couleur::ORANGE) cout << "OK";
}


 */

struct Ogrenci {
    string nom;
    vector<double> notes;
    double moyenne;
};
void trier_par_moyenne(vector<Ogrenci>& v) {
 for(size_t i =0 ;  i<v.size()-1; ++i) {
     if(v[i].moyenne < v[i+1].moyenne) {
         swap(v[i], v[i+1]);
     }
 }
}

int main() {
    vector<Ogrenci> sinif = {
        {"Zayif", {}, 2.5},
        {"Caliskan", {}, 5.5},
        {"Orta", {}, 4.0}
    };

    trier_par_moyenne(sinif);

    cout << sinif[0].nom;
    // Beklenen: Caliskan (Çünkü 5.5 en yüksek)
}