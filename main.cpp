#include <cstdlib>
#include <limits>
#include <iostream>

using namespace std;

int fibo(int n) {


    int a = 0;

    int b= 1;
    int c;

    for(int i =1; i<=n; ++i) {
        c = a+b;
        a = b;
        b = c;
    }
return a;
}

void f2(int n) {
    if (n) {
        f2(n-1);
    }
    cout << 'A' << n << ' ';
}

void f3(int n) {
    cout << 'A' << n << ' ';
    if (n) {
        f3(n-1);
    }
    cout << 'B' << n << ' ';
}


void f4(int n) {
    if (n) {
        cout << n << ' ';
        f4(n-1);
        f4(n/2);
    }
}

void f5(int n) {
    if (n) {
        f5(n-1);
        if (n>1)
            f5(n-2);
        cout << n << ' ';
    }
}




int main() {
    cout<<fibo(19)<<endl;

    f2(2);;
    cout<<endl;
    f3(2);

    return 0;
}