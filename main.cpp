/*
* // --- Ne pas modifier ---
#include <iostream>
#include <cmath> // pow() fonksiyonunu kullanabilirsin, ama manuel olarak çarpmak daha temeldir.
using namespace std;

bool estArmstrong(int n) {
    int copy = n;
    int somme =0;

    while(n>0) {
        int reste= n%10;
        int cube =1;
        //somme += pow(reste, 3);

        for(int i =0; i<3; ++i) {
            cube *= reste;
        }
        somme +=cube;
        n/=10;
    }
    return copy == somme;
}
bool palindrom (int n){
    int n1 = n;
    int somme = 0;
    while(n>0) {
        int reste = n%10;
        somme = (somme *10) + reste;
        n/=10;
    }
    return somme == n1;
}


int main() {
    cout << "153 est un nombre d'Armstrong ? " << boolalpha << estArmstrong(153) << endl; // Attendu: true
    cout << "370 est un nombre d'Armstrong ? " << boolalpha << estArmstrong(370) << endl; // Attendu: true
    cout << "123 est un nombre d'Armstrong ? " << boolalpha << estArmstrong(123) << endl;
    return 0;
}
// --- Ne pas modifier ---
#include <iostream>
using namespace std;
#include <cmath>

int binaireVersDecimal(int n) {
    int reste=0;
    int somme = 0;
     int pw =0;
    while(n>0) {
        reste = n % 10;
        if(reste){
            somme+= pow(2,pw++);
        }else {
            ++pw;
        }
        n/=10;
    }
    return somme;
}
int main() {
    cout << "Le binaire 1011 en decimal est : " << binaireVersDecimal(1011) << endl; // Attendu: 11
    cout << "Le binaire 11001 en decimal est : " << binaireVersDecimal(11001) << endl; // Attendu: 25
    return 0;
}
 */

// --- Ne pas modifier ---
#include <iostream>
using namespace std;


int persistanceMultiplicative( int n) {
   if(n<10) {
       return 0;
   }
    int persistance =0;

    while(n>9) {
        persistance++;
        int produit_des_chiffres =1;

        int  temp = n;
        while(temp >0) {
            produit_des_chiffres *= (temp %10);
            temp /=10;
        }
        n= produit_des_chiffres;
    }
    return persistance;
}
int binaireVersDecimal1(int binaire) {
    int decimal = 0;
    int puissance =1;
    while(binaire>0) {
        int reste = binaire%10;
        if(reste>0) {
            decimal+= puissance;
        }
        puissance *=2;
        binaire/=10;
    }
    return decimal;
}


int main() {
    cout << "La persistance de 679 est : " << persistanceMultiplicative(679) << endl; // Attendu: 5
    cout << "La persistance de 277777788888899 est : " << persistanceMultiplicative(27777778) << endl; // Attendu: 10 (long int gerekebilir, int ile test et)
    // Note: Büyük sayıyı test etmek yerine int 27777778 ile test edelim.
    return 0;
}