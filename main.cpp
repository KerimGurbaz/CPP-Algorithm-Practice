/*
* #include <iostream>
using namespace std;

int inverserNombre(int n) {
    int newNum=0;
    while(n>0) {
        int reste = n%10;
        newNum = newNum * 10 +reste;
        n/=10;
    }
    return newNum;
}

int main() {
    cout << "L'inverse de 12345 est : " << inverserNombre(12345) << endl; // Attendu: 54321
    cout << "L'inverse de 900 est : " << inverserNombre(900) << endl;     // Attendu: 9
    return 0;
}

// --- Ne pas modifier ---
#include <iostream>
using namespace std;

void trier(int &x,int& y,int & z) {
    if(x>y) {
        int temp = y;
        y=x;
        x=temp;
    }if(x>z) {
        int temp =z;
        z =x;
        x=temp;
    }
    if(y>z) {
        int temp=z;
        z =y;
        y=temp;
    }

}


void swp(int& a, int &b, int & c) {
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b<c) swap(b,c);
}



int main() {
    int x = 30, y = 10, z = 20;
    trier(x, y, z);
    cout << "Nombres tries : " << x << ", " << y << ", " << z << endl; // Attendu: 10, 20, 30


    int a= 40, b = 3210, c= 340;
    swp(a, b, c);
    cout << "Nombres tries : " << a<< ", " << b<< ", " << c << endl;
    return 0;
}
// --- Ne pas modifier ---
#include <iostream>
using namespace std;

void dessinerZigzag(int h, int l) {
    for(int i = 1; i<=h; ++i) {
        for(int j =1 ; j<i%l; ++j) {
            cout<<" ";
        }for(int k =0; k<1; ++k) {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main() {
    cout << "Zigzag 10x5:" << endl;
    dessinerZigzag(10, 5);
    return 0;
}

#include <iostream>
#include <string>
#include <cctype> // pour isalpha, isspace
using namespace std;

void epurerChaine(string& s) {
    string nStr ="";
    for(char c : s) {
        if(isalnum(c)|| isspace(c)) {
            nStr.push_back(c);
        }
    }
   s =nStr;

}

int main() {
    string phrase = "J'ai 2 pommes et 3 poires!!!";
    epurerChaine(phrase);
    cout << "Phrase epuree : '" << phrase << "'" << endl; // Attendu: 'Jai pommes et poires'
    return 0;
}
 */

// --- Ne pas modifier ---
// --- Ne pas modifier ---
#include <iostream>
using namespace std;

void compteARebours(int n) {
    while(n>0) {
        if(n%15 == 0) {
            cout<<"TicTac,";
  n--;
        }else if(n%5==0) {
            cout<<"Tic,";
 n--;
        }else if(n%3 == 0) {
            cout<<"Tac,";
         n--;
        }else {
            cout<<n--<<",";
        }

    }
}

int main() {
    cout << "Compte a rebours depuis 16 :" << endl;
    compteARebours(16);
    return 0;
}
// Sortie attendue:
// 16, TicTac, 14, 13, Tac, 11, Tic, Tac, 8, 7, Tac, Tic, 4, Tac, 2, 1,