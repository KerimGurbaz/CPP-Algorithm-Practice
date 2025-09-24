#include <iostream>
using namespace std;

int main() {
int a, b ,c , r, d, n=5;

if(a>=1) {
    a =42;
}else {
    a *=a;
}

    if(a ==2) {
        b= 32;
    }else if(a<5) {
        b=12;
    }else {
        b =23;
    }

    if(a<0) {
        if(b<0) {
            c=a;
        }else {
            c= -a;
        }
    }else {
        if(b<5) {
            c =a+b;
        }else {
            c =a-b;
        }
    }

    return 0;
}