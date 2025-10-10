#include <iostream>
#include <string>
using namespace std;

/*
* size_t nbVoyelles(string_view s) {
    size_t count =0;
for(int i = 0; i<s.size(); ++i) {
    if(static_cast<char>(tolower(s[i])) == 'o' ||
        static_cast<char>(tolower(s[i])) =='a' ||
        static_cast<char>(tolower(s[i])) =='e' ||
        static_cast<char>(tolower(s[i])) =='i' ||
        static_cast<char>(tolower(s[i])) =='y' ||
        static_cast<char>(tolower(s[i])) =='u' ) {
        count++;
    } ;
}
    return count;

}
int main() {
    string s;
    getline(cin, s);
    cout << nbVoyelles(s) << '\n';
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

string periodeDuJour(int h) {
    do {

        if(h<0 || h>24) {
            cout<<"entrez un hour";
            cin>>h;
        }
    }while(h<0 || h>24);
    if(h>=6 && h<12) {
        return "matin";
    }else if(h>=12 && h<=17) {
        return "apres-midi";
    }else if(h>17 && h<20) {
        return "soir";
    }else if(h>=20 && h<=23) {
        return "soirée";
    }else  {
        return "nuit";
    }

}

int main() {
    int h;
    cin >> h;
    cout << periodeDuJour(h) << '\n';
    return 0;
}

#include <iostream>
using namespace std;

double retrait(double& solde, double montant){
    int retire = montant;
    if(montant > solde) {
        retire = solde;
       solde =0;
        return retire;
    }
   solde -= retire;
    return retire;

}

int main() {
    double solde = 500;
    cout << retrait(solde, 300) << " " << solde << '\n'; // 300 200
    cout << retrait(solde, 300) << " " << solde << '\n'; // 200 0

    return 0;
}

#include <iostream>
using namespace std;

int& min3(int& a, int& b, int& c) {
    return (a<b ?(a<c ?a :c) : (b<c?b:c));
}

int main() {
    int a=5, b=2, c=9;
    cout << min3(a,b,c) << '\n'; // 2
    min3(a,b,c) = 0;
    cout << a << " " << b << " " << c << '\n'; // 5 0 9
    return 0;
}

#include <iostream>
using namespace std;

int syracuse(int& n) {
    int stp =0;
    while(n!=1) {
        ++stp;
        if(n%2==0) {
            n/=2;
            cout<<n<<" ";
        }else {
          n= 3*n+1;
            cout<<n<<" ";
        }

    }
    return stp;

}

int main() {
    int n;
    cin >> n;
    int copie = n;
    int steps = syracuse(copie);
    cout << "\n" << steps << '\n';
    return 0;
}



 */

#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;

int  sommeDiviseursStricts(int n) {
if(n>1) {
    int limit = sqrt(n);
    int somme = 1;
    for(int i =2; i<=limit; ++i) {
        if(n%i ==0) {
            int d = n/i;
            somme += (d==i) ? i : i+d;
        }
    }
    return somme;
}
}
bool estParfait(int n) {
   return  sommeDiviseursStricts(n)== n;

}

int main() {
    int n;
    cin >> n;
    cout << sommeDiviseursStricts(n) << '\n';
    cout << boolalpha << estParfait(n) << '\n';


    for(int i = 1; i<=n; ++i) {
        for(int j = 1; j<=n-i; ++j) {
            cout<<" ";
        }for(int k = 1; k<=2*i-1; ++k) {
            cout<<"*";
        }
        cout<<endl;
    }


    for(int i = 1; i<=n; ++i) {
        for(int j = 1; j<=n-i; ++j) {
            cout<<" ";
        }for(int k = 1; k<=2*i-1; ++k) {
            cout<<"#";
        }
        cout<<endl;
    }
    for(int i =1; i<=n/2+1;++i) {
        for(int j =1; j<=n+i;++j) {
            cout<<" ";
        }for(int k =n/2+1; k>=i-1; --k) {
            cout<<"#";
        }
        cout<<endl;
    }

    return 0;
}
