#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double  montant_initial;
    double montant_cible;
    double taux ;
    cout<<"Entrez le montant initial > 1000 "<<endl;
    cin>>montant_initial;
    cout<<"Entrez le montant cible > 1000000 "<<endl;
    cin>>montant_cible;
    cout<<"Entrez le taux d'interet annuel en % > 5"<<endl;
    cin>>taux;


    int n = 0;
    while(montant_initial < montant_cible) {
        montant_initial += ( montant_initial *taux )/100;
        n++;
    }

    cout<<"Le montant cible est atteint apres "<<n<< "ans.";


}