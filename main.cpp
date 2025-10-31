#include <iostream>
using namespace std;

class Compteur {
public:
    Compteur() : Compteur(0) { cout << "1"; }
    Compteur(int i) { cout << "2"; }
    Compteur(double d) : Compteur(int(d)) { cout << "3"; }
    ~Compteur() { cout << "0"; }
};

int main() {
    Compteur* p;
    {
        Compteur c1(1);
        p = new Compteur(2);
    }
    cout << "/";
    delete p;

}