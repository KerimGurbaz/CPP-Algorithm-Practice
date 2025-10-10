// --- Ne pas modifier ---
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int h =7;
    int milieu = h/2 +1;

    for(int i=1; i<= h; ++i) {
        for(int j = 1; j<=h-i; ++j) {
            cout<<" ";
        }for(int k =1; k<=2*i-1; ++k) {
            cout<<"*";
        }cout<<endl;
    }

    for(int i = 1; i<=milieu; ++i) {
        for(int j =1; j<=milieu-i; ++j) {
            cout<<" ";
        }for(int k = 1; k<=2*i-1; ++k) {
            cout<<"#";
        }cout<<endl;
    }for(int i = milieu-1; i>=1; --i) {
        for(int j = milieu-i ; j>=1; --j) {
            cout<<" ";
        }for(int k = 2*i -1; k>=1; --k) {
            cout<<"#";
        }cout<<endl;
    }

 int val =2;
   const int * ptr = &val;

    cout<<"\n"<<*ptr<<endl;

    char s1 = 1<2 ?'o':'n';
    cout<<"\ns1 : "<<s1<<endl;;
    string s ="ABCDa";
    for(int c : s) {
        cout<<c;
    }


    return 0;
}

