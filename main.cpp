#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Pays {
private:
    const string nom;
    double population;
    double superficie;

public:
    Pays(const string& n, double pop, double sup);

    double getSuperficie() const;

    double getPopulation() const;

    const string& getNom() const;

    double densite()const;
};

Pays::Pays(const string& n, double pop, double sup) : nom(n), population(pop),
                                               superficie(sup) {
}

double Pays::getSuperficie() const {
    return this->superficie;
}

double Pays::getPopulation() const {
    return this->population;
}


double Pays::densite() const {
    return population * 1000000 / superficie;
}

const string& Pays::getNom() const {
    return this->nom;
}

int main() {
    vector<Pays> pays{
            {"Suisse", 8.121830, 41290},
            {"France", 66.663766, 547030},
            {"Italie", 61.855120, 301230},
            {"Allemagne", 80.854408, 357021}
    };

    // 1) En büyük yüzölçümü
    auto maxSuperficie = max_element(pays.begin(), pays.end(),[](const Pays& p1, const Pays&p2) {
        return p1.getSuperficie() < p2.getSuperficie();
    });
    // 2) En fazla nüfus
    auto maxPopulation =max_element(pays.begin(), pays.end(),[](const Pays& p1, const Pays& p2) {
        return p1.getPopulation() < p2.getPopulation();
    });

    // 3) En büyük yoğunluk
    auto maxDensite =max_element(pays.begin(), pays.end(),[](const Pays& p1, const Pays&p2) {
        return p1.densite() < p2.densite();
    });

    cout << "Pays ayant la plus grande superficie               : "
         << maxSuperficie->getNom() << endl;
    cout << "Pays ayant le plus d'habitants                     : "
         << maxPopulation->getNom() << endl;
    cout << "Pays ayant la densite de population la plus grande : "
         << maxDensite->getNom() << endl;

    return 0;
}