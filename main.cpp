#include <string>
#include <algorithm>
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

void calculer_representation(double r, double base, double& mantisse, int& exposant) {
    if( r == 0.0) {
        mantisse == 0.0;
        exposant == 0;
        return;
    }

    exposant = 0;
    mantisse = r;

    while(fabs(mantisse)>=base) {
        mantisse /=base;
        exposant++;
    }

    while(fabs(mantisse) < 1.0) {
        mantisse *= base;
        exposant --;
    }
}


int main() {
    cout << "Entrez un nombre réel : ";
    double r;
    cin >> r;

    double mantisse;
    int exposant;

    calculer_representation(r, 10., mantisse, exposant);
    cout << r << " = " << mantisse << " * 10^" << exposant << endl;

    calculer_representation(r, 2., mantisse, exposant);
    cout << r << " = " << mantisse << " * 2^" << exposant << endl;

    return 0;
}
