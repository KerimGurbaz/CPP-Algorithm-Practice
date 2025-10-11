/*
* #include <iostream>
#include <string>
using namespace std;

string mention(double n) {
  do {
      if(n<0 || n>10) {
       cout<< "repetez svp.. ";
          cin>>n;
      }
  }while(n<0 || n>10);
    if(n>=8) {
        return "excellent";
    }else if(n>=6.5) {
       return "très bien";
    }else if(n>=5.5) {
     return "bien";
    }else if(n>=4.5) {
      return "passable";
    }else {
     return "insuffisant";
    }
}

int main() {
    double n;
    cin >> n;
    cout << mention(n);
    return 0;
}

/*
Entrée : 4.5 → passable
Entrée : 8.7 → excellent


#include <iostream>
using namespace std;
void compte_a_rebours(int n) {

   do {
       cout<<n--<<" ";
   }while(n>=0);
}
int main() {
    int n;
    cin >> n;
    compte_a_rebours(n);
    return 0;
}

#include <iostream>
using namespace std;


/*
Entrée : 53842 → 5 + 3 = 8



#include <iostream>
using namespace std;
void table(int n) {
        for(int j=1; j<=10; ++j) {
            cout<<n<<" x "<<j<<" = "<<n*j<<endl;
        }
    cout<<endl;
int x = 1;
    while(x<11) {
        cout<<n<<" x "<<x<<" = "<<n*x<<endl;
        ++x;
    }
}

int main() {
    int n;
    cin >> n;
    table(n);
    return 0;
}

/*
Entrée : 3
Sortie :
3 x 1 = 3
3 x 2 = 6
...
3 x 10 = 30



/*
Entrées : 4 5 12 -3 6 -1
Sortie : 5.0


/*
Entrée : 5
*/


/*
*
double remplir(double&v, double a) {
    if(v+a>=100) {
        double ajoutEffectif = 100-v;
        v=100;
        return ajoutEffectif;
    }else {
        v+=a;
        return a;
    }
}

double remplir(double & v, double ajout) {
    if(ajout <=0) ajout =0;
    double libre = 100-v;
    if(libre <=0)return 0.0;
    double effectif = (ajout <=libre) ? ajout : libre;
    v +=effectif;
    return effectif;
}

int main() {
    double v = 90;
    cout << remplir(v, 2) << " " << v << endl; // 10 100
    cout << remplir(v, 15) << " " << v << endl; // 10 100
    cout << remplir(v, 5) << " " << v << endl;  // 0 100
    return 0;
}


int somme_impairs(int n) {
    n = n<0 ? abs(n): n;
    int somme = 0;
    while(n>0) {
        int reste = n%10;
        if(reste%2) {
            somme+=reste;
        }
        n/=10;
    }
    return somme;
}

int main() {
    int n;
    cin >> n;
    cout << somme_impairs(n);
    return 0;
}


#include <iostream>
using namespace std;

double moyenne_valide() {
    int x;
    long long somme =0;
    int count = 0;

    while (cin>>x &&  x!= -1) {
        if(x<0 ||x>6)continue;
        somme+=x;
        ++count;
    }
    return count == 0 ? 0.0 : static_cast<double>(somme)/count;
}


int main() {
    cout << moyenne_valide();
    return 0;
}

 */
#include <iostream>
using namespace std;

void triangle_creux(int h) {
    if(h<=0) return ;
    if(h==1){cout<<"*\n";}
    cout<<"*\n";
    for(int i = 2; i<h; ++i) {
        cout<<"*";
        for(int s = 0; s<2*i-3; ++s)cout<<" ";
        cout<<"*\n";
    }
    for(int k = 0; k<2*h -3; ++k)
        cout<<"*";
    cout<<endl;

}

int main() {
    int h;
    cin >> h;
    triangle_creux(h);
    return 0;
}
