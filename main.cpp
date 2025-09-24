#include <iostream>
using namespace std;

int main() {
int a;
    cin>>a;
    if(a>= 0 && a<6) {
        cout<<"A";
    }else if(a<8) {
        cout<<( a == 6 ? "34" : "4");
    }else {
        cout<<"D";
    }


    return 0;
}