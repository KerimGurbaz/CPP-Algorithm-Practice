#include <iostream>
#include <cmath>

using namespace std;

void permutation(double & a, double& b, double& c) {
    double temps =c;
    c = a;
    a =b;
    b =temps;

}

double retrait(double& solde, double somme) {
   double montabRetire = somme;

    if(solde<somme) {
        montabRetire = solde;
    }

    montabRetire= min(solde, somme);
    solde -= montabRetire;


    return somme;
}

int main() {
    double a =3;
    double b =4;
    double c =5;
   permutation(a, b, c);

    cout<<a<<b<<c;
    cout<<endl;
    int hauter =6;

    for(int ligne = 0; ligne<6; ++ligne) {
        for(int espace = 0; espace < 6- ligne; ++espace) {
            cout<<" ";
        }
        for(int k = 0; k<2*ligne+1; ++k) {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;

}