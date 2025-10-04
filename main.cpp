#include <iostream>
#include <iomanip>

using namespace std;

double effectuerRetrait( double& soldeCourant, double montantSouhaite) {
  if(soldeCourant <0 || montantSouhaite<0) return 0.0;

    montantSouhaite = min(soldeCourant,montantSouhaite );
    soldeCourant -=montantSouhaite;
    return montantSouhaite;
}
double retrait (double& solde, double montant, double comissionPourcent) {
    if(solde <=0.0 || montant <=0 || comissionPourcent <0.0 )return 0.0;

 double commision = montant * comissionPourcent/100.0;
    double total = montant + commision;

    if(total> solde) {
        montant = solde / (1+ comissionPourcent)/100;
        commision = montant * comissionPourcent/100;
        total = montant + commision;
    }

    solde -= total;
    return montant;
}




int main() {
    double solde = 500.0;
    cout << fixed << setprecision(2); // Para birimi için formatlama

    cout << "Solde initial du compte = " << solde << " CHF" << endl;

    // --- Premier retrait ---
    double retrait1 = 300.0;
    cout << "\nPremier retrait souhaite = " << retrait1 << " CHF" << endl;

    double retraitEffectif1 = effectuerRetrait(solde, retrait1);

    cout << "Montant du retrait effectif : " << retraitEffectif1 << " CHF" << endl;
    cout << "Nouveau solde du compte    : " << solde << " CHF" << endl;

    // --- Deuxième retrait ---
    double retrait2 = 300.0;
    cout << "\nDeuxieme retrait souhaite = " << retrait2 << " CHF" << endl;

    double retraitEffectif2 = effectuerRetrait(solde, retrait2);

    cout << "Montant du retrait effectif : " << retraitEffectif2 << " CHF" << endl;
    cout << "Nouveau solde du compte    : " << solde << " CHF" << endl;

    return 0;
}