
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

int nbDiviseurs(int n) {
    if(n<= 0) {
        return -1;
    }
    int count = 0;
    int r = static_cast<int>(sqrt(n));

    for(int i = 1; i<=r ; ++i) {
        if(n%i == 0) {
            count +=2;
        }
    }
    if(r * r == n) {
        --count;
    }
    return count;
}

int factorielle(int n) {

if(n ==0 || n == 1) {
    return 1;
}
    int result = 1;
    for(int i = 2; i<=n; ++i) {
        if(result > numeric_limits<int>::max() / i) {
            return -1;
        }
        result *=i;
    }
    return result;
}

int main() {

    int result = factorielle(5);
    cout << "5! = " << result << '\n';

    int d6 = nbDiviseurs(6);
    cout << "nbDiviseurs(6) = " << d6 << '\n'; // 1,2,3,6 → 4


    return 0;
}