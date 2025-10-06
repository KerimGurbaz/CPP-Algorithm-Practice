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

/*
* #include <iomanip>

double volumePyramide(double longueur, double largeur, double hauteur) {
    return longueur*largeur*hauteur/3.0;
}


int main() {
    cout<<fixed<<setprecision(1)<<volumePyramide(10, 3.5, 12)<<endl;
    cout<<fixed<<setprecision(1)<<volumePyramide(3.6, 2.4, 2.7)<<endl;
    return 0;
}

 */
/*
* bool estBissextile(int annee) {
    if(annee<0) {
        return false;
    }
    return !(annee % 400 || (annee%4==0 && annee % 100 !=0));

}

int main() {
    cout<<boolalpha<<estBissextile(1900);

    return 0;
}
 */

/*
* bool listerCaracteres(char debut, char fin) {
    return debut<=fin;
}

int main() {
cout<<boolalpha<<listerCaracteres('K','C');
    return 0;
}


 */

/*
* void permutationDroite( double& a,  double& b, double& c) {
    double temp =c;
    c=b;
    b =a;
    a=temp;
}

int main() {
    double a=1;
    double b=2;
    double c =3;
permutationDroite(a,b,c);
    cout<<a<<b<<c;
    return 0;
}
 */

/*
* double retrait(double& solde, double montant) {
    double retire = montant;
    if(retire > solde) {
        retire =solde;
        solde=0.0;
    }
    solde -= retire;
    return retire;

}

int main() {

    double solde;
    double montant;

    do {
        cout<<"Entrez le solde : ";
        cin>>solde;
        cout<<"Entrez le montant : ";
        cin>>montant;
    }while(solde<0);

   cout<< retrait(solde, montant);

    return 0;
}

 */
void triangle(int hauter) {
    for(int i = 0; i<=hauter; ++i) {
        for(int espace = 0; espace<= hauter-i; ++espace) {
            cout<<" ";
        }
        for(int e = 1; e<=2*i-1; ++e) {
            cout<<"*";
        }
        cout<<endl;
    }

}
int main() {
int hauter;
    cin>>hauter;
    triangle(hauter);

    return 0;
}