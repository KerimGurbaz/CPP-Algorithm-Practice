
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int nbDiviseurs(int n) {
    int count = 0;
    for(int i = 1; i<=n ; ++i) {
        if(n%i == 0) {
            count++;
        }
    }
    return count;
}

int factorielle(int n) {
  if(n<0) {
      return -1;
  }if(n== 0) {
      return 1;
  }

    long long resultat = 1;
    for(int i = 1; i<=n; ++i) {
        if(resultat > numeric_limits<int>::max() / i) {
            return -1;
        }
        resultat *= i;
    }
}



int main() {

    int result = factorielle(5);
    cout<<result<<endl;

    return nbDiviseurs(6);
}