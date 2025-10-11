/*
* #include <iostream>
using namespace std;

int inverser_pairs(int n) {
    int nNum =0;
    while(n>0) {
        int reste = n%10;
        if(reste %2 ==0) {
            nNum = nNum * 10 +reste;
        }
        n/=10;
    }
return nNum;
}

int main() {
    int n;
    cin >> n;
    cout << inverser_pairs(n);
    return 0;
}
#include <iostream>
using namespace std;

int somme_limite(int limite) {
int n =0;
    int somme = 0;
do {
    somme+=n;
    if(somme<limite) {
        ++n;
    }
}while(somme<=limite);
    return n;
}

int main() {
    int n;
    cin >> n;
    cout << somme_limite(n);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

bool est_palindrome(const string& s) {
    int first =0;
    int last = s.size()-1;
    while(first < last) {
        if(tolower(s[first]) !=  tolower(s[last])){
            return false;
        }
        ++first;
        --last;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << boolalpha << est_palindrome(s);
    return 0;
}
double moyenne_glissante(int x) {
    static int count =1;
    static int somme =0;
    int moyenne =0;
    if(x== 0) {
    count =1;
   somme =0;
        moyenne=0;
    }else {
        somme += x;
        moyenne= somme / count;
        ++count;
    }
    return moyenne;
}

int main() {
    int n;
    cout << fixed << setprecision(1);
    while (cin >> n) {
        cout << moyenne_glissante(n) << endl;
    }
    return 0;
}


 */
#include <iostream>
using namespace std;

void losange(int h) {
    int m = h/2+1;
    for(int i=1; i<=m; ++i) {
        for(int j =1; j<=m-i; ++j) {
            cout<<" ";
        }for(int k = 0; k<2*i-1; ++k) {
            cout<<"*";
        }cout<<endl;
    }for(int i = m-1; i>=1; --i) {
        for(int j = m-i; j>=1; --j) {
            cout<<" ";
        }for(int k =0; k<2*i-1; ++k) {
            cout<<"*";
        }cout<<endl;;
    }
}

int main() {
    int h;
    cin >> h;
    losange(h);
    return 0;
}


