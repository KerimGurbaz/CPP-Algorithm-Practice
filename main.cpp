#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Donnez les valeurs de a, b, et c de l'equation a*x^2+b*x+c : ";
    double a, b, c;
    cin >> a >> b >> c;

    // votre code vient ici.
    if(a == 0) {
        if(b == 0) {
            if(c == 0) {
                cout<<"Tout x est un solution"<<endl;
            }else {
                cout << "pas de solution" << endl;
            }
        }else {
            cout<<"1 solution"<<endl;
        }
    }else {
        double discriminant = b*b - 4*a*c;
        if(discriminant < 0) {
            cout << "pas de solution" << endl;
        }else if(discriminant == 0) {
            cout<<"1 solution : "<<-b / (2*a)<<endl;
        }else {
            double d = sqrt(discriminant);
            double x1 = (-b + d)/ (2*a);
            double x2 = (-b - d)/ (2*a);
            cout << "2 solutions : " << x1 << " et " << x2 << endl;
        }

    }
}