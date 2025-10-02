#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;

bool estBissextile (int n) {
    if(n<1) {
        return false;
    }
    return (n%400 ==0 || (n%4 ==0 && n%100 !=0));
}

bool listerCaracteres(char debut, char fin) {
    if(debut > fin) {
        return false;
    }
    for(char c = debut; c <= fin; ++c) {
        cout<<c;
    }
    return true;
}

void mystere(int& x, int& y) {
    int temp = y;
    y =x;
    x =temp;
}

void permutation_circulaire(int &a, int &b, int&c) {
    int temp =c;
    c=b;
    b = a;
    a= temp;
}


int main() {

    cout<<boolalpha<<estBissextile(2020)<<endl;

    cout<<listerCaracteres(65, 67) <<endl;

    int x = 3, y = 4;
    mystere(x, y);
    cout << "x = " << x << " " << "y = " << y << endl;
    return EXIT_SUCCESS;



    return 0;
}