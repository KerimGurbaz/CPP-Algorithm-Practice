// --- Ne pas modifier ---
#include <iostream>
#include <cmath>
using namespace std;

/*
* bool estParfait(int n) {
    int somme =1;
    if(n<=0) {
        return false;
    }else {
        int limit = sqrt(n);
        for(int i =2; i<=limit; ++i) {
            if(n%i == 0) {
                int d = n/i;
                somme = (d==i) ? somme+i : somme+i+d;
            }
        }
    }
    return somme ==n;
};

int main() {
    cout << "6 est parfait ? " << boolalpha << estParfait(6) << endl;
    cout << "12 est parfait ? " << boolalpha << estParfait(12) << endl;
    cout << "28 est parfait ? " << boolalpha << estParfait(28) << endl;
    return 0;
}
 */

// --- Ne pas modifier ---
#include <iostream>
using namespace std;

bool estParfait(int n) {
    int somme=1;
    for(int i = 2; i<n; ++i) {
        if(n%i == 0) {
            somme+=i;
        } if(i * i == n) {
            somme-=i;
        }
    }
    return somme ==n;
}

int main() {
    cout << "6 est parfait ? " << boolalpha << estParfait(6) << endl;
    cout << "12 est parfait ? " << boolalpha << estParfait(12) << endl;
    cout << "28 est parfait ? " << boolalpha << estParfait(28) << endl;
    return 0;
}