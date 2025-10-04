#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

enum class StatutOperation {
    Succes, Erreur_operateur_invalide, Error_division_par_zero
};

StatutOperation calculer(double a, double b, char op, double& resultat) {
    switch(op) {
        case '+' :
            resultat = a+b;
        return StatutOperation::Succes;
        case '-':
            resultat = a-b;
        return StatutOperation::Succes;
        case '*':
            resultat = a*b;
        return StatutOperation::Succes;
        case '/':
            if(b == 0) {
                return StatutOperation::Error_division_par_zero;
            }
        resultat =a/b;
        return StatutOperation::Succes;

        default:
            return StatutOperation::Erreur_operateur_invalide;

    }
}

bool operation(double a, double b, char c, double &resultat) {
    switch (c) {
        case '+': resultat = a + b;
            return true;
        case '-': resultat = a - b;
            return true;
        case '*': resultat = a * b;
            return true;
        case '/':
            if (b == 0) {
                cout << "Error, division par zero..";
                return false;
            }
            resultat = a / b;
            return true;
        case '^': resultat = pow(a, b);
            return true;
        default:
            cout << "Erreur : operator inconnu( " << c << ")" << endl;
            return false;
    }
}

int main() {
    double x, y, res1;
    char op =0;
    double num1, num2, res;
    char operateur;
    StatutOperation statut = calculer(num1, num2, operateur, res);


   while(true) {
       cout<<"Entrez deux nombres (ou Ctrl+D pour quitter) : ";
       if(!(cin>>x>>y)) {
           cout<<"\nFin de saisie.\n";
           break;
       }

       cout << "Entrez l'operateur (+, -, *, /, ^) ou 'q' pour quitter : ";
       cin >> op;

       if(tolower(static_cast<unsigned char>(op)) == 'q') {
           cout<<"Au revoir !"<<endl;
           break;
       }

       if(operation(x,y,op, res)) {
           cout << "Resultat : " << res << endl;
       }else {
cin.ignore(numeric_limits<streamsize>::max(), '\n');

       }
return 0;
   }

    double s, d;
    while(true) {
        cout<<"Entez deux numbers : ";
        if(cin>>x>>y)break;
        cout<<"invalide entree, repeter svp : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');;
    }



    return 0;
}
