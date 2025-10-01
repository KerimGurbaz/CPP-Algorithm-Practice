#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
using namespace std;

int nbDiviseurs(int n) {
    int limit = sqrt(n);
    int count =0;
    for(int i=1; i<=limit; ++i) {
        if(n%i==0) {
            count+=2;
        }
        if(i*i == n) {
            --count;
        }
    }
    return count;
}

int hb(int n) {
   int res = 0;
    vector<int>v;
    int precedent = 0;
    int i =1;
    while(v.size()!=n) {
         if(nbDiviseurs(i) > precedent) {
         precedent = nbDiviseurs(i);
         v.push_back(i);
     }
        ++i;
    }
    for(int i = 0; i<v.size(); ++i) {
        cout<<v[i];
        if(i!=v.size()-1) {
            cout<<",";
        }
    }

    return v[v.size()-1];
}



int main() {

  cout<<nbDiviseurs(6)<<endl;
    int hb;
    cout<<"Combien de nombres HC ?";
    cin>>hb;





    return 0;
}