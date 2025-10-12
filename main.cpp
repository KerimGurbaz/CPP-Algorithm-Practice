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
// --- Ne pas modifier ---
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// --- VOTRE FONCTION VIENT ICI ---
// Prototype attendu: int simulerCourse(int distanceCourse);
// Retourne: 1 si la tortue gagne, 2 si le lièvre gagne, 0 si c'est une égalité.
int simulerCourse(int distanceCourse) {
  int pos_torute=0;
    int pos_lievre =0;
    int tour=0;

    cout << "La course pour " << distanceCourse << " metres commence !" << endl;
    cout << "----------------------------------------" << endl;

    while(pos_torute <distanceCourse && pos_lievre <distanceCourse) {
        tour++;
        cout << "Tour " << tour << ":" << endl;

        // --- Mouvement de la Tortue (logique simple) ---
        pos_torute += 3;
        cout << "  > La tortue avance a la position " << pos_torute << endl;
        // --- Mouvement du Lièvre (logique probabiliste) ---
        int chance = rand()%100;

        if(chance<50) {
            // Le lièvre dort
            cout << "  > Le lievre dort a la position " << pos_lievre << endl;
        }else if(chance <70) {
            pos_lievre +=9;
        }else {
            pos_lievre -=2;
            if(pos_lievre < 0 ) {
                pos_lievre = 0;
            }
            cout << "  > Le lievre glisse en arriere a la position " << pos_lievre << endl;
        }



    }
    cout << "----------------------------------------" << endl;
    cout << "La ligne d'arrivee est franchie !" << endl;
    cout << "Position finale - Tortue: " << pos_torute << ", Lievre: " << pos_lievre << endl;

    bool tortue = pos_torute>=distanceCourse;
    bool lievre = pos_lievre >= distanceCourse;

    if(tortue && lievre) {
        return 0;
    }else if(tortue) {
        return 1;
    }else {
        return 2;
    }
}
int main() {
    srand(time(0));
    int vainqueur = simulerCourse(70);

    if (vainqueur == 1) {
        cout << "La TORTUE gagne la course !" << endl;
    } else if (vainqueur == 2) {
        cout << "Le LIEVRE gagne la course !" << endl;
    } else {
        cout << "INCROYABLE ! C'est une EGALITE !" << endl;
    }
    return 0;
}

 */

