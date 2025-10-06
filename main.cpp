#include <iostream>
using namespace std;

/*
* void permuter(double &a, double & b, double &c) {
    double temps = c;
    c= b;
    b=a;
    a =temps;
}
 */

/*
* void triangle(int h) {
    for(int i = 0; i<h; ++i) {
        for(int espace = 0; espace<h - i; ++espace) {
            cout<<" ";
        }
        for(int etoil = 0; etoil<2*i-1; ++etoil) {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main() {
    int hauteur;
    do {
        cout<<"entrez un hauter : ";
        cin>>hauteur;
        triangle( hauteur);

    }while(hauteur<0);

}
 */

int& min(int &a, int &b, int &c) {
    return (a<b ? (a<c ?a :c) : b<c ?b: c);
}
int main() {
    int a = 5, b = 2, c = 9;
    cout << "Minimum initial : " << min(a, b, c) << endl;


    min(a, b, c) = 1;


    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
