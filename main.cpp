#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
int demander_valeur_n() {
  int n_valide;
    while(true) {
        cout<<"valeur de n [1-100] : ";
        cin >>n_valide;
        if(cin.good() && n_valide>=1 && n_valide<= 100) {
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"Entree invalide : "<<endl;
    }
}

double serie_de_Bale(int n) {
    double somme =0;
    for(int i = 1; i<=n; ++i) {
        somme += (1/pow(i, 2));
    }
return somme;

}

int main() {

    cout<<"Afficher le titre : Problème de Bâle"<<endl;

    int val = demander_valeur_n();

    double result = serie_de_Bale(val);


    cout<<fixed<<setprecision(4)<<result<<endl;

    return 0;
}