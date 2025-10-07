#include <iostream>
using namespace std;
#include <cmath>

void valeurAbsolue(int& n) {
   if(n<0) n =-n;
}

void carre(int n) {
    if(n<=0)return ;
        for(int i=1; i<=n; ++i) {
            for(int j = 1;j<=n; ++j) {
                cout<<"*";
            }
            cout<<endl;
        }

}

int compterPairs(int n) {
    if(n == 0) return 1;
    int count = 0;
while(n>0) {
    int reste = n%10;
    if(reste%2 ==0)count++;
    n/=10;
}
    return count;
}

double celsiusToFahrenheit(double c, double& result) {
  return  (c * 9./5.)+32;
}
#include <cmath>

bool estPremier(int p2) {
    if(p2<2)return false;
    if(p2 %2 ==0) return p2==2;
    for(int d= 3; 1LL * d*d<=p2; d+=2)
        if(p2%d == 0)return false;
    return true;
}

int main() {
    int n =-100;
    valeurAbsolue((n));

    carre(3);

    int p =24813;
        cout<<compterPairs( p)<<endl;

    int c= 100;
    double r;


    while(c>=0) {
        celsiusToFahrenheit(c,r);
        cout<<c<<" celsius => "<<r<<" Fahrenheit."<<endl;
        c -=20;
    }
    int num;
    //cin>>num;
    int somme =0;
    cout<<"somme de "<<num<<  " = ";
    while(num>0) {

    int reste = num%10;
        somme +=reste;
        num/=10;
    }
    cout<<somme;

    int choix;
    do {
        cout<<"Menu interactif entrez un numero [1-3]"<<endl;
        cin>>choix;
        if(choix>0 && choix<4) {
            switch(choix) {
                case 1: cout<<"Bonjour"; break;
                case 2: cout<<"Au revoir"; break;
                case 3: break;
                default:cout<<"mauvais choix"; break;
            }
        }
    }while(choix<0 || choix>4);

    int p2 =9;
    cout<<boolalpha<<estPremier( p2);



    return 0;
}