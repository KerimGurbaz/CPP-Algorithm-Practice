/*
* // --- Ne pas modifier ---
#include <iostream>
#include <cmath>
using namespace std;


#include <iostream>
#include <string>
using namespace std;

string periode_de_jour(const int& h) {
    switch (h) {
        case 0:case 1:case 2:case 3:case 4:case 5:return "nuit";
        case 6:case 7:case 8:case 9:case 10:case 11:return "matin";
        case 12:case 13:case 14:case 15:case 16:case 17:return "apres-midi";
        case 18:case 19:case 20: return "soir";break;
        default: return "soiree" ;
    }
}

int main() {
    int h;
    do {
        cout<<"entrez un houre :"<<endl;
        cin >> h;
        if(h>=0 && h<=24) {
            cout << periode_de_jour(h) << '\n';
        }
    }while(h<0 || h>24);
    return 0;
}

/*
Exemples
Entrée : 7   -> matin
Entrée : 12  -> apres-midi
Entrée : 18  -> soir
Entrée : 21  -> soiree
Entrée : 2   -> nuit

#include <iostream>
#include <iomanip>
using namespace std;

double moyenne_cumulative(int &x) {
    static int count;
    ++count;
    static double somme=0;
    somme +=x;
    return somme/count;
}

int main() {
    int x;
    cout << fixed << setprecision(2);
    do {
        cin >> x;
        if (x == 0) break;                 // fin
        cout << moyenne_cumulative(x) << '\n';
    } while (true);
    return 0;
}
#include <iostream>
using namespace std;

int compter_chiffres_pairs(int n) {
    int count =0;
    if(n==0) {
        return 1;
    }
    n = n<0 ? -n : n;
        while(n>0) {
            int reste = n%10;
            if(reste %2== 0)count++;
            n/=10;
        }
    return count;
}

int main() {
    long long n;
    cin >> n;
    cout << compter_chiffres_pairs(n) << '\n';
    return 0;
}
#include <iostream>
using namespace std;

double retrait(double &solde, double montant) {
    double retire_effectif= min(solde, montant);
    solde -= retire_effectif;
    return retire_effectif;
}

int main() {
    double solde = 500;
    cout << retrait( solde, 300 ) << " " << solde << '\n'; // 300 200
    cout << retrait( solde, 300 ) << " " << solde << '\n'; // 200 0
    return 0;
}

#include <iostream>
using namespace std;

int & min3(int &a, int&b, int&c) {
    return a<b?(a<c?a:c):(b<c? b:c);
}

int main() {
    int a=5, b=2, c=9;
    cout << min3(a,b,c ) << '\n';     // 2
    min3( a,b,c ) = 0;
    cout << a << " " << b << " " << c << '\n'; // 5 0 9
    return 0;
}

#include <iostream>
using namespace std;

int syracuse_afficher_et_compter(int &n) {
int count=0;
    cout<<n<<" ";
    while(n!=1) {
        count++;
       if(n%2==0) {
           n/=2;
           cout<<n<<" ";
       }else {
           n= n*3+1;
           cout<<n<<" ";
       }
    }

return count;
}

int main() {
    int n;
    cin >> n;
    int copie = n;
    int steps = syracuse_afficher_et_compter(copie);
    cout << "\n" << steps << '\n';
    return 0;
}

/*
Exemple (entrée 6)
Affiche : 6 3 10 5 16 8 4 2 1
Retour  : 8
*/


/*
*/
#include <cmath>
#include <iostream>
using namespace std;
int somme_diviseurs_stricts(int n) {
int limit = sqrt(n);
    int somme =1;
    for(int i =2; i<=limit; ++i) {
        if(n%i == 0) {
            int d = n/i;
            somme += (d == i) ? d : i+d;
        }
    }
    if(limit *limit == n) {
        somme-=limit;
    }
    return somme;
}
bool est_parfait(int n) {
 return n == somme_diviseurs_stricts(n);
}
int main() {
    int n;
    cin >> n;
    cout << somme_diviseurs_stricts( n ) << '\n';
    cout << boolalpha << est_parfait( n ) << '\n';
    return 0;
}