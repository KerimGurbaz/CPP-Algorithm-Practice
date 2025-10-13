// --- Ne pas modifier ---
/*
* #include <iostream>
#include <iomanip> // std::setw() için, çıktı hizalamasına yardımcı olabilir
using namespace std;

void dessinerTriangleFloyd(int h) {
static int s =0;
    for(int i = 1; i<=h; ++i) {
        for(int j=1; j<=i; ++j) {
            cout<<++s<<" ";
        }cout<<endl;
    }
}

int main() {
    cout << "Triangle de Floyd pour une hauteur de 5 :" << endl;
    dessinerTriangleFloyd(5);
    return 0;
}

// --- Ne pas modifier ---
#include <iostream>
#include <cmath> // abs() için faydalı olabilir
using namespace std;

void dessinerLosange(int h) {
    int m =h/2+1;
    for(int i =1; i<=m; ++i) {
        for(int j =1; j<=m-i; ++j) {
            cout<<" ";
        }for(int k=0; k<2*i-1; ++k) {
            cout<<"*";
        }cout<<endl;
    }for(int i =m-1; i>=1; --i) {
        for(int j =m-i; j>=1; --j) {
            cout<<" ";
        }for(int k = 2*i-1; k>=1; --k) {
            cout<<"*";
        }cout<<endl;
    }
}


int main() {
    int largeur;
    do {
        cout << "Donnez la largeur maximale du losange (nombre impair > 0) : ";
        cin >> largeur;
    } while (largeur <= 0 || largeur % 2 == 0);

    dessinerLosange(largeur);
    return 0;
}

 */

// --- Ne pas modifier ---
#include <iostream>
#include <algorithm> // std::min için
using namespace std;

void dessinerCarreNumerique(int n) {
    for(int i =1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {

        }cout<<endl;
    }
}

void afficher(const   double& valer) {

cout<<valer<<endl;
}
int main() {
    afficher(5);
    cout << "Carre numerique de taille 7 :" << endl;
    dessinerCarreNumerique(7);
    //int i =5;
    int u = 4.0;
    double d =10;

   // cout<< (i > u ? u :d);

cout<<endl;
    int i=1,j=3;
    while(i<j){
        cout<<i++<<j--;
    }

    int a = 2;
     int& ref = a;
    ref++;
    cout << a;

    cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
    for(int i=1; i<4; i++) {
        switch(i) {
        case 1: cout<<"A"; continue;
        case 2: cout<<"B"; break;
    } cout<<"X"; }


    return 0;



}
