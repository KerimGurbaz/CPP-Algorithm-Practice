
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;


int main() {

    double montant_initial;
    double taux;
    int annees;

    do {
        cout<<"Entrez le montant initial > ";
        cin>>montant_initial;

    }while(montant_initial <1000);

    // Saisie du taux d'intérêt (entre -5 et 50 inclus)

    do {
        cout<<"Entrez le taux d'interet annuel en % > ";
        cin>>taux;
    }while(taux<-5 || taux>50);

    // Saisie du nombre d'années (> 0)

    do {
        cout<<"Entrez le nobre d'annees > ";
        cin>>annees;
    }while(annees <=0);


    double montant_final = montant_initial * pow(1 + taux/100.0 , annees);

    cout<<"Le montant disponible apres "<<annees
    <<"an"<<(annees >1 ? "s" : "")
    <<"est de "<<montant_final<<" CHF"<< endl;

    return 0;

}