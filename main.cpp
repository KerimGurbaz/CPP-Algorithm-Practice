/*
* #include <iostream>
#include <string>
#include <utility>

using namespace std;

// Définition de la structure Livre
struct Livre {
    string titre;
    string auteur;
    string langue;
    int year;
};

// Définition de l'enum StatutLivre
// (Enum değerleri DISPONIBLE, EMPRUNTE, RESERVE olmalı)
enum class StatutLivre{
    DISPONIBLE=1, EMPRUNTE=2, RESERVE=3
};


int main() {
    Livre nouveauLivre;
    StatutLivre st;
    int en =0;

    // Lecture des informations du livre
    cout << "Entrez le titre du livre: ";
    std::getline(std::cin,nouveauLivre.titre);
    cout << "Entrez l'auteur du livre: ";
    std::getline(std::cin, nouveauLivre.auteur);
    cout << "Entrez la langue du livre: ";
    std::getline(std::cin, nouveauLivre.langue);
    cout << "Entrez l'année du livre: ";
    std::cin >> nouveauLivre.year;
    cout << "Entrez le statut du livre (1 pour DISPONIBLE, 2 pour EMPRUNTE, 3 pour RESERVE): ";
    std::cin >> en; // int'e oku
    st = static_cast<StatutLivre>(en);

    // Affichage des informations du livre
    cout << "Titre du Livre : " <<nouveauLivre.titre << endl;
    cout << "Auteur du Livre : " <<nouveauLivre.auteur << endl;
    cout << "Langue du Livre : " <<nouveauLivre.langue << endl;
    cout << "Année du Livre : " << nouveauLivre.year<< endl;
    cout << "Statut : ";

    // 'switch' kullanarak enum'u string'e çevirip basın
    switch (st) {
        case StatutLivre::DISPONIBLE: cout<<"DISPONIBLE";break;
        case StatutLivre::EMPRUNTE : cout<<"EMPRUNTE";break;
        case StatutLivre::RESERVE : cout<<"RESERVE"; break;
    };
    cout << std::endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    std::string inputFileName, outputFileName;

    // 1. Lire les noms de fichiers
    std::getline(std::cin, inputFileName);
    std::getline(std::cin, outputFileName);

    // 2. Vérifier que le fichier entrée existe
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error d'ouverture du fichier : " << inputFileName;
        return 1;
    }

    // 3. cikti
    std::ofstream outputFile(outputFileName);

    std::string line;
    // 4. Girdi dosyasını satır satır oku
    while (std::getline(inputFile, line)) {
        // Hangi dosyadan, hangi string'e?

        // 5. Satırı büyük harfe çevir
        for (char &ch: line) {
            ch = std::toupper(ch);
        }

        // 6. Çıktı dosyasına yaz
        outputFile << line << std::endl;
    }

    // 7. Dosyaları kapat
    inputFile.close();
    outputFile.close();

    // 8. Çıktı dosyasını okumak için yeniden aç
    std::ifstream outputRead(outputFileName);

    // 9. Konsola bas
    while (std::getline(outputRead, line)) {
        std::cout << line << std::endl;
    }
    outputRead.close();
    return 0;
}
#include <iostream>
#include <cmath> // log10, floor, pow, abs için
#include <string>

using namespace std;
#include <vector>
#include <array>

int main() {array<int,5> a{1,2,3,4,5};
    for (size_t i = 1; i < a.size(); ++i)
        a[i] = a[i-1];
    for (int e : a) cout << e;
cout<<endl;

    cout << hex << uppercase << showbase << 42;

    return 0;
}
 */
/*
* vector<int> pairs_carres_tries(const vector<int> &v) {
    vector<int> myVec;

  copy_if(v.begin(), v.end(), back_inserter(myVec),[](int n) {
      return (n%2 == 0);
  });

    transform(myVec.begin(), myVec.end(), myVec.begin(),[](int n) {
        return n*n;
    });
    sort(myVec.begin(), myVec.end());

    return myVec;
}
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

vector<int>intersection_sorted(vector<int>& a,vector<int>& b) {
   vector<int> r;
    size_t i = 0;
    size_t j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {

            i++;
        }else if(b[j] < a[i]) {

            ++j;
        }else {
            r.push_back(a[i]);
            i++;
            j++;
        }
    }
    return r;
}

int main() {
    vector<int> a{1,2,2,3,5,7,9};
    vector<int> b{2,2,4,5,6,9,9};
    auto r = intersection_sorted(a, b);
    for (int x : r) cout << x << ' ';
}

 */




#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int compter_mots(const string& s) {

    ifstream in(s);
    if(!in.is_open()) {
        cerr<<"Error l'ouverture de fiichier "<<s;
        return -1;
    }
    string mot;
    int compte =0;
    while(in>>mot) {
        compte++;
    }
    in.close();
    return compte;
}


int main() {
    cout << compter_mots("notes.txt") << '\n';
}
