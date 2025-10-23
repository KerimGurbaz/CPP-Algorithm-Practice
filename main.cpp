#include <iostream>
#include <array>
#include <iomanip> // setw için
using namespace std;

template<typename T, size_t N >
ostream& operator<<(ostream& os, const array<T, N>& arr) {
    os<<"[";
    for(size_t i = 0; i<N; ++i) {
        os<<arr[i];
        if(i<N-1) {
            os<<", ";
        }
    }
    os<<"]";
    return os;
}

template<typename T, size_t M, size_t N>
ostream& operator<<(ostream& os, const array<array<T,M>, N>& mat) {
    os<<"[";
    for(size_t i = 0; i<N; ++i) {
        if(i>0) {
            os<<",\n";
        }
        os<<mat[i];
    }
    os<<"]";
        return os;
    }


int main() {
    array<array<int, 3>, 2> m1 = {1, 2, 3, 4, 5, 6};
    cout << m1 << "\n\n";

    array<double, 4> v = {1.1, 2.2, 3.3, 4.4};
    cout << v << "\n\n";

    array<array<int, 4>, 3> m2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << m2;
}