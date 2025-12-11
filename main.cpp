// #include <cmath>
// #include <cstdlib>
// #include <iomanip>
// #include <iostream>
// using namespace std;
//
// class Voiture {
// private:
//     double capasite;
//     double consomation;
//     double nbLitres;
//
//     static double prixEssence;
//
// public:
//     Voiture(double cap, double cons);
//
//     static double getPrixEssence();
//
//     static void setPrixEssence(double n);
//
//     friend void afficherVoiture(const Voiture& v);
//
//     double effectuerTrajet(double n);
//
// };
//
// double Voiture::prixEssence =1.70;
//
// Voiture::Voiture(double cap, double cons):
// capasite(cap), consomation(cons), nbLitres(capasite) {
// }
//
// double Voiture::getPrixEssence()  {
//     return prixEssence;
// }
//
// void afficherPrixEssence(double prix) {
//     cout << "Prix de l'essence :" << prix<< "Frs." << endl;
// }
//
// void Voiture::setPrixEssence(double prix) {
//     prixEssence = prix;
// }
//
// void afficherVoiture(const Voiture& v) {
//     cout << "Capacite du reservoir [l]      : " <<v.capasite << endl;
//     cout << "Consommation moyenne [l/100km] : " << v.consomation << endl;
//     cout << "Nb litres restants             : " << v.nbLitres << endl;;
// }
//
// double Voiture::effectuerTrajet(double distanceKm) {
//     double utiliseLitre = (distanceKm * consomation ) / 100.0;
//     nbLitres -= utiliseLitre;
//     while (nbLitres < 0) {
//         nbLitres += capasite;
//     }
//     return utiliseLitre * prixEssence;
// }
//
// double afficherCoutTrajet(double distance) {
//     double total = distance * Voiture::getPrixEssence();
//     cout << "Cout du trajet : " << total << " Frs." << endl;
//     cout<<endl;
//     return total;
// }
//
// int main() {
//     afficherPrixEssence(Voiture::getPrixEssence());
//
//     Voiture::setPrixEssence(1.95);
//     afficherPrixEssence(Voiture::getPrixEssence());
//
//     Voiture v(52, 6.7);
//
//     afficherVoiture(v);
//     afficherCoutTrajet(v.effectuerTrajet(1000));
//     afficherVoiture(v);
//     afficherCoutTrajet(v.effectuerTrajet(200));
//     afficherVoiture(v);
//
//     return EXIT_SUCCESS;
// }

// #include <cmath>
// #include <vector>
// #include <iomanip>
// #include <iostream>
// using namespace std;
// template<typename Iterator>
// typename Iterator::value_type somme_elements(Iterator first,Iterator last) {
//     typename Iterator::value_type somme =0;
//     for(Iterator it = first; it != last; ++it) {
//         somme += *it;
//     }
//     return somme;
// }
//
// int main() {
//
//     vector<int> v{10,20,30,40,50,60};
//     cout << somme_elements(v.begin()+2, v.begin()+5);
// }

// #include <cmath>
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
//
// template<typename Iterator>
// typename Iterator::value_type somme_elements(Iterator first, Iterator last) {
//     typename Iterator::value_type somme = 0;
//     for (Iterator it = first; it != last; ++it) {
//         somme += *it;
//     }
//     return somme;
// }
//
//
// template<typename T>
// T maxElement(const vector<T> &v) {
//     auto max = max_element(v.begin(), v.end(), [](const T &a, const T &b) {
//         return a < b;
//     });
//     return *max;
// }
//
//
//
//
// int main() {
//     vector<int> v{10, 20, 30, 40, 50, 60};
//     cout << somme_elements(v.begin() + 2, v.begin() + 5);
//     cout << endl;
//     cout << maxElement(v);
//
//
//     cout<<count_if(v.begin()+1, v.end()-1, [](int x) {
//         return x%3 == 0;
//     });
// }
#include "../../../../../../Program Files/JetBrains/CLion 2024.1.4/bin/mingw/x86_64-w64-mingw32/include/complex.h"
#ifndef "INTARRAY_H"
#define "INTARRAY_H"

class IntArray {
private:
int *data; //pointeur
    int size; //dizinin boyutu

public:
   IntArray(int s);
    ~IntArray();
    IntArray(const IntArray& other);
    IntArray& operator = (const IntArray& other);

    void set(int index, int value);
    void afficher()const;
};

#endif


#include <iostream>
#include <algorithm>
#include "IntArray.h"
IntArray::Intarray(int s) : size(s) {
    data = new int[size]();
}

IntArray::~IntArray() {
    delete[]data;
}

IntArray::IntArray(const IntArray& other): size(other.size) {
    data = new int[size];

    std::copy(other.data, other.data+size, data);
}

IntArray& IntArray::operator = (const IntArray& other) {
    if(this == &other) {
        return *this;
    }
    delete[]data;
    size = other.size;
    data = new int[size];
    std::copy(other.data, other.data+ size, data);
    return *this;
}

void IntArray::set(int index, int value) {
    if(index < size) {
        data[index]=value;
    }
}

void IntArray::afficher()const {
    std::cout<<"[";
    for(size_t i = 0; i<size; ++i) {
        std::cout<<data[i]<<" ";
    }
    std::cout<<"]\n";
}





using namespace std;

int main() {
    IntArray t1(5); // 5 elemanlı, hepsi 0
    t1.set(0, 10);  // 0. indekse 10 ata (bu metodu da yaz: void set(idx, val))
    t1.set(1, 20);

    cout << "T1: "; t1.afficher(); // [ 10 20 0 0 0 ]

    {
        IntArray t2 = t1; // Copy Constructor çağrılır
        t2.set(0, 999);   // t2 değişti, t1 DEĞİŞMEMELİ!
        cout << "T2: "; t2.afficher();
    } // t2 burada yok olur (Destructor). t1 hala yaşamalı!

    IntArray t3(2);
    t3 = t1; // Assignment Operator çağrılır (t3'ün eski belleği silinmeli!)

    cout << "T3: "; t3.afficher(); // T1 ile aynı olmalı

    return 0;
}