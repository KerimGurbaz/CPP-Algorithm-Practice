#include <iostream>
using namespace std;
#include <string>


int fibo(int n) {
    int a = 0;
    int b = 1;
    int sum ;

    while(n>0) {
        a =b;
        b = sum;
        sum = a+b;
        --n;
    }
    return sum;
}
int main() {
    int n;
    cin>>n;

    cout<<fibo(n);

}