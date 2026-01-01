
#include <vector>
#include <string>
#include <iostream>
#include <algorithm> // remove_if, transform, max_element, all_of
#include <numeric>   // iota
#include <random>
#include <iomanip>   // setprecision
using namespace std;


template<typename iter, typename T>
T somme_si_superieur(iter first, iter last,const T& n) {
    T somme = accumulate(first, last, T{},[&n](const T&total, auto&el) {
        return el > n ? total+el : total;
    } );

    return somme;
}


int main() {

    vector<int> v {1, 5, 10, 2};
     int s = somme_si_superieur(v.begin(), v.end(), 4);
    cout<<s;

}