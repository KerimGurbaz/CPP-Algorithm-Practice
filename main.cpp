#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Niveau { DEBUTANT, INTERMEDIAIRE, AVANCE };

struct Personne {
    string nom;
    int age;
    Niveau niveau;
};

size_t compter_par_niveau(const vector<Personne> &p, const Niveau &n) {
    size_t count = 0;
    for (const auto &el: p) {
        if (el.niveau == n) {
            ++count;
        }
    }
    return count;
}

double moyenne_age(const vector<Personne> &p) {
    double somme = 0.0;
    if (!p.empty()) {
        for (const auto &el: p) {
            somme += el.age;
        }
        return somme / p.size();
    }
    return 0.0;
}

vector<Personne> filtrer_par_age(const vector<Personne> &p, int min_age, int max_age) {
    vector<Personne> result;
    result.reserve(p.size());
    for (const auto &el: p) {
        if (el.age >= min_age && el.age <= max_age) {
            result.push_back(el);
        }
    }
    return result;
}


void afficher(const vector<Personne> &v) {
    for (const auto &p: v) {
        cout << p.nom << " (" << p.age << ") ";
        switch (p.niveau) {
            case Niveau::DEBUTANT: cout << "[DEBUTANT]";
                break;
            case Niveau::INTERMEDIAIRE: cout << "[INTERMEDIAIRE]";
                break;
            case Niveau::AVANCE: cout << "[AVANCE]";
                break;
        }
        cout << '\n';
    }
}


int main() {
    vector<Personne> personnes = {
        {"Ali", 20, Niveau::DEBUTANT},
        {"Zehra", 25, Niveau::INTERMEDIAIRE},
        {"Mehmet", 30, Niveau::AVANCE},
        {"Ayse", 28, Niveau::INTERMEDIAIRE},
        {"John", 35, Niveau::AVANCE}
    };

    cout << "Nb DEBUTANT      : "
            << compter_par_niveau(personnes, Niveau::DEBUTANT) << '\n';

    cout << "Nb INTERMEDIAIRE : "
            << compter_par_niveau(personnes, Niveau::INTERMEDIAIRE) << '\n';

    cout << "Nb AVANCE        : "
            << compter_par_niveau(personnes, Niveau::AVANCE) << '\n';

    cout << "Moyenne d'age    : "
            << moyenne_age(personnes) << '\n';

    cout << "\nFiltre [25..30] :\n";
    auto f = filtrer_par_age(personnes, 25, 30);
    afficher(f);
}
