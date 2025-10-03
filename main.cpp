#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;

void echanger(int &a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

int min(int &a, int &b) {
    if (a<b) {
        return b;
    }
    return b;
}

void fonction_A(int& ref);       // Attend une référence non-constante
void fonction_B(const int& ref); // Attend une référence constante

int main() {
    int x =3;
    int y = 4;
cout<<x<<" "<<y<<endl;

    echanger(x, y);
    cout<<x<<" "<<y<<endl;
    cout<<min(145, 30);


    int a = 3, b = 5;

    // Affiche : a=3, b=5
    std::cout << "Avant: a=" << a << ", b=" << b << std::endl;

    // La ligne qui pose problème
    min(a, b), std::max(a, b);

    // Devrait afficher : a=5, b=3
    std::cout << "Après: a=" << a << ", b=" << b << std::endl;

    int i;
    double d;
    const int I = 5;
    const double D = 5;

    int *const ptr1 = &i;
    double *const ptr2 =&d;
    cout<<*ptr1<<endl;;
    cout<<&d<<endl;
    cout<<ptr2;
    *ptr1 = 3;
const double &ref_d = d;
    return 0;
}