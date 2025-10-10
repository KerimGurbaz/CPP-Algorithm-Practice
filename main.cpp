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
#include <iostream>
using namespace std;

void dessinerDamier(int lignes, int colonnes) {
    for(int i = 0; i<lignes; ++i) {
        for(int j =0; j<colonnes; ++j) {
            if(j%2==0) {
                cout<<"X";
            }else {
                cout<<"O";
            }
        }cout<<endl;
    }
}

int main() {
    cout << "Damier 4x5 :" << endl;
    dessinerDamier(4, 5);
    cout << "\nDamier 3x3 :" << endl;
    dessinerDamier(3, 3);
    return 0;
}
// Sortie attendue pour 4x5:
// XOXOX
// OXOXO
// XOXOX
// OXOXO
 */


