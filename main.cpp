#include <iostream>
using namespace std;



void valeurAbsolue(int& n) {
    n =n<0 ? -n : n;
}
void carre(int n) {
    if(n>0) {
        for(int i = 1; i<=n; ++i) {
            for(int j = 1; j<=n; ++j) {
                cout<<"*";
            }
            cout<<endl;
        }
    }
}

int compterPairs(int n) {
    int compte =0;
    if(n == 0)return 1;
    if(n<0) {
        n= abs(n);
    }
    while(n>0) {
        int reste = n%10;
        if(reste %2 ==0) {
            compte++;
        }
        n/=10;
    }
    return  compte;
}
bool estBissextile(int annee) {
    if(annee<0)return false;
    return annee%400==0 ||( annee%4 ==0 && annee%100!=0);
}

double retrait(double& solde, double montant) {
   int retire = montant;
    if(solde<0.) {
        return -1;
    }else if(montant >= solde) {
         retire = solde;
        solde =0.;
    }else {
        solde -= montant;
    }
        return retire;

}

void permuter_gauche(int& a, int& b, int&c) {
    int temp =a;
    a =b;
    b=c;
    c=temp;
}


int main() {

    int n=-100;
     valeurAbsolue(n);
    cout<<n<<endl ;
    int k =5;
    carre(k);
    cout<<compterPairs(245678)<<endl;
    cout<<estBissextile(2400)<<endl;


    int h;
    cin>>h;
    for(int i=1; i<=h; ++i) {
        for(int es =0; es<i; ++es) {
            cout<<" ";
        }
        for(int e = 1;e<=h-i+1; ++e) {
            cout<<e;
        }cout<<endl;

    }

    return 0;

}