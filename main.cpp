#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;


double volume(double a, double b , double c) {
    return a*b*c/3.0;
}



int main() {

    double pyramide1 = volume(10, 3.5, 12);
    double pyramide2 = volume(3.6, 2.4, 2.7);


    cout<<fixed<<setprecision(1)<<pyramide1<<endl;
    cout<<pyramide2<<endl;

    return 0;
}