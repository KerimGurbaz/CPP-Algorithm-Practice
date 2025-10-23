 #include <iostream>
using namespace std;



int n;
int & plus_petit_modulo_n(int & a, int & b) {

    return ( a % n <b % n ? a : b);
}

int main() {

    int a = 1234, b = 5643; cout << a << " " << b << endl;

    n = 100;
    cout << plus_petit_modulo_n(a, b) << endl;

    n = 10;  cout << plus_petit_modulo_n(a, b) << endl;

    plus_petit_modulo_n(a, b) = 9999; cout << a << " " << b << endl;
}