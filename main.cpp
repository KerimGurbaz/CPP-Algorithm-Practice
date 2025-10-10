/*
* // --- Ne pas modifier ---
#include <cmath>
#include <iostream>
using namespace std;

int sommeDiviseur(int &n) {
    int limit = sqrt(n);
    int somme =1;

    for(int i =2 ; i<=limit; ++i) {
        if(n%i == 0) {
            int d = n/i;
            somme += (d==i) ? d : d+i;
        }
    }
    return somme;
}

bool sontAmicaux(int a, int b) {
   return  sommeDiviseur(a) == b && sommeDiviseur(b) == a;
}

int main() {


    if (sontAmicaux(220, 284)) {
        cout << "220 et 284 sont amicaux." << endl;
    }
    if (!sontAmicaux(1184, 1211)) { // 1211 n'est pas la somme des diviseurs de 1184
        cout << "1184 et 1211 ne sont pas amicaux." << endl;
    }
    return 0;
}
// --- Ne pas modifier ---
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool estPalindrome(string& s) {
    int first = 0;
    int last = s.size()-1;
    while(first<last) {
        if(tolower(static_cast<char>(s[first])) != static_cast<char>(s[last])) {
            return false;
        }
        first++;
        last--;
    }
    return true;
}

int main() {
    string mot1 = "Kayak";
    string mot2 = "bonjour";
    cout << mot1 << " est un palindrome ? " << boolalpha << estPalindrome(mot1) << endl;
    cout << mot2 << " est un palindrome ? " << boolalpha << estPalindrome(mot2) << endl;
    return 0;
}
#include <iostream>
using namespace std;
int diviser(int a, int b, int & q, int& r) {
    int aa = a;
     q=1;
    while((a-b) >= b ) {
        a= a-b;
        ++q;
    }
    r = aa - q*b;
    return q;
}

int main() {
    int quotient, reste;
    diviser(17, 5, quotient, reste);
    cout << "17 divise par 5 -> Quotient: " << quotient << ", Reste: " << reste << endl; // Attendu: 3, 2

    diviser(8, 4, quotient, reste);
    cout << "8 divise par 2 -> Quotient: " << quotient << ", Reste: " << reste << endl; // Attendu: 4, 0
    return 0;
}
Défi 4 : Traitement d'un Tableau C-style(tablolar vektorler vs sinav konulari dahilidnde degil.. o yuzden geciyorum bu soruyu)


// --- Ne pas modifier ---
// --- Ne pas modifier ---
#include <iostream>
using namespace std;
void dessinerRectangleCreux(int h, int l) {
    for(int i =1; i<=l; ++i) {
        if(i>1 && i<l) {
            for(int k =1; k<=2; ++k) {
                cout<<"* ";
            }
        }else {
            for(int j=1; j<=h;++j) {
            cout<<"*";
        }
        }
        cout<<endl;
    }
}
int main() {
    cout << "Rectangle 8x5:" << endl;
    dessinerRectangleCreux(8, 5);
    return 0;
}
// Sortie attendue pour 8x5:
// ********
// * *
// * *
// * *
// ********

#include <iostream>
using namespace std;

int calculerTrajet(int a, int b, int c) {
   int jour=0;
    while(a>=0) {
        a-=b;
        if(a!=0) {
            a+=c;
            ++jour;
        }
    }
    return jour;
}

int main() {
    // Puits de 10m, monte 3m/jour, descend 2m/nuit
    int jours1 = calculerTrajet(10, 3, 2);
    cout << "Il faudra " << jours1 << " jours pour sortir du puits de 10m." << endl; // Attendu: 8 jours

    // Puits de 20m, monte 5m/jour, descend 1m/nuit
    int jours2 = calculerTrajet(20, 5, 1);
    cout << "Il faudra " << jours2 << " jours pour sortir du puits de 20m." << endl; // Attendu: 5 jours
    return 0;
}
 */


// --- Ne pas modifier ---
#include <iostream>
using namespace std;


 int* ptrElementMax( int  *a, int * b) {
    return (*a > *b ? a : b);
}

int main() {
    int x = 50, y = 100;
    int* ptrMax = nullptr;

    ptrMax = ptrElementMax(&x, &y);
    cout << "La valeur maximale est : " << *ptrMax << endl; // Attendu: 100

    // Si la fonction retourne un vrai pointeur, cette ligne doit fonctionner
    // et modifier la variable y à -1.
    *ptrMax = -1;

    cout << "Apres modification, x=" << x << " et y=" << y << endl; // Attendu: x=50 et y=-1
    return 0;
}
