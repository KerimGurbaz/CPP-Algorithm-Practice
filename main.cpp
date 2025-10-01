#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
using namespace std;






int main() {


    double d;
    const int I = 5;
    const double D = 5;

    int i =1;


       do {
         cout<<i;
           i+=2;
       }while(i < 10);

    int n = 5;
    while(n>0) {
        cout<<n<<" ";
        if(n == 3) {
            break;
        }
        --n;
    }








    return 0;
}