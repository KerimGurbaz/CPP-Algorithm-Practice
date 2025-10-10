// --- Ne pas modifier ---
#include <iostream>
#include <cmath>
using namespace std;

/*
* bool estParfait(int n) {
    int somme =1;
    if(n<=0) {
        return false;
    }else {
        int limit = sqrt(n);
        for(int i =2; i<=limit; ++i) {
            if(n%i == 0) {
                int d = n/i;
                somme = (d==i) ? somme+i : somme+i+d;
            }
        }
    }
    return somme ==n;
};

int main() {
    cout << "6 est parfait ? " << boolalpha << estParfait(6) << endl;
    cout << "12 est parfait ? " << boolalpha << estParfait(12) << endl;
    cout << "28 est parfait ? " << boolalpha << estParfait(28) << endl;
    return 0;
}

// --- Ne pas modifier ---
#include <iostream>
using namespace std;

bool estParfait(int n) {
    int somme=1;
    for(int i = 2; i<n; ++i) {
        if(n%i == 0) {
            somme+=i;
        } if(i * i == n) {
            somme-=i;
        }
    }
    return somme ==n;
}

int main() {
    cout << "6 est parfait ? " << boolalpha << estParfait(6) << endl;
    cout << "12 est parfait ? " << boolalpha << estParfait(12) << endl;
    cout << "28 est parfait ? " << boolalpha << estParfait(28) << endl;
    return 0;
}

// --- Ne pas modifier ---
#include <iostream>
#include <iomanip>
using namespace std;

void calculerStats(int a, int b, int c, int& somme, double& moyenne) {
    somme= a+b+c;
    moyenne = somme/3.;
}// <-- VOTRE FONCTION

int main() {
    int s = 0;
    double m = 0.0;
    calculerStats(10, 20, 6, s, m);
    cout << "Somme = " << s << ", Moyenne = " << fixed << setprecision(2) << m << endl;
    return 0;
}
// --- Ne pas modifier ---
#include <iostream>
#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour time()
using namespace std;

int lancerDe(int& compteur) {

  compteur++;
    int myNumber = 1+ rand()%(6-1 + 1);
    return myNumber;
}

int main() {
    srand(time(0)); // Initialise le générateur de nombres aléatoires
    int total_lancers = 0;
    int resultat_de;

    cout << "Lancement du de jusqu'a obtenir un 6..." << endl;
    do {
        resultat_de = lancerDe(total_lancers);
        cout << "Lancer " << total_lancers << " : " << resultat_de << endl;
    } while (resultat_de != 6);

    cout << "Le 6 a ete obtenu apres " << total_lancers << " lancers." << endl;
    return 0;
}
// --- Ne pas modifier ---
#include <iostream>
#include <string>
using namespace std;

void inverser(string& str) {
    int first = 0;
    int last = str.size()-1;
    while(first<last){
        char temp = str[first];
        str[first]=str[last];
        str[last]=temp;
        first ++;
        last--;
    }
}

int main() {
    string test1 = "Bonjour";
    string test2 = "kayak";
    inverser(test1);
    inverser(test2);
    cout << "Resultat 1 : " << test1 << endl; // Devrait afficher "ruojnoB"
    cout << "Resultat 2 : " << test2 << endl; // Devrait afficher "kayak"
    return 0;
}
// --- Ne pas modifier ---

// Sortie attendue pour 4x5:
// XOXOX
// OXOXO
// XOXOX
// OXOXO

// --- Ne pas modifier ---
#include <iostream>
using namespace std;

int& elementMax(int& a, int& b) {
    return a<b?a:b;
}

int main() {
    int x = 10, y = 20;
    cout << "Le max entre x et y est : " << elementMax(x, y) << endl;

    // Si la fonction retourne une vraie référence, cette ligne doit fonctionner
    // et modifier la variable y à 0.
    elementMax(x, y) = 0;

    cout << "Apres modification, x=" << x << " et y=" << y << endl; // Devrait afficher x=10 et y=0
    return 0;
}
 */


// --- Ne pas modifier ---
#include <iostream>
using namespace std;

int retirerBillets(int& solde, int montantDemande) {
    int retireEffectif = min(solde, montantDemande);
    int totalRetire = 0;

    int nb20 = retireEffectif/20;
    totalRetire += nb20*20;
    retireEffectif %= 20;

    int nb10 = retireEffectif /10;
    totalRetire += nb10* 10;
    retireEffectif %=10;

    int nb5 = retireEffectif/5;
    totalRetire += nb5 * 5;


    solde -= totalRetire;

    return totalRetire;

}

int main() {
    int compte = 188;
    cout << "Solde initial : " << compte << endl;

    int retire1 = retirerBillets(compte, 75);
    cout << "Demande: 75, Retire: " << retire1 << ", Nouveau solde: " << compte << endl;
    // Attendu: Retire: 75 (3x20, 1x10, 1x5), Nouveau solde: 113

    int retire2 = retirerBillets(compte, 120);
    cout << "Demande: 120, Retire: " << retire2 << ", Nouveau solde: " << compte << endl;
    // Attendu: Solde insuffisant. Retire: 110 (5x20, 1x10), Nouveau solde: 3

    return 0;
}