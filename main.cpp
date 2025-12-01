#include <iostream>
#include <array>
#include <iomanip>
#include <cstdint>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#include <cstdlib>
#include <iostream>

// using namespace std;
// template<typename T>
// void permutationCirculaireDroite(T& x, T& y, T& z) {
//     T temp = z;
//     z =y;
//     y=x;
//     x= temp;
//
// }
//
// template<typename T>
// void afficher(const T& x,const T& y,const T& z ) {
//     cout<<"x = "<<x<<endl;
//     cout<<"y= "<<y<<endl;
//     cout<<"z = "<<z<<endl;
// }
//
// int main() {
//     double x = 1, y = 2, z = 3;
//     for (int i = 1; i <= 3; ++i) {
//         permutationCirculaireDroite(x, y, z);
//         afficher(x, y, z);
//     }
//     return EXIT_SUCCESS;
// }
#include <iostream>
#include <algorithm>
using namespace std;



template<typename T>
T& min(T& a, T& b, T& c) {
    return a < c ? (a < b ? a : b) : (b < c ? b : c);
}


int main() {
    int    a = 5;
    int    b = 2;
    int    c = 9;

    double d = 5.0;
    double e = 2.0;
    double f = 9.0;

    cout << min(a, b, c);
    min(a, b, c) = 1;
    int& min_abc = min(a, b, c);

    cout << min(d, e, f);
    min(d, e, f) = 1;
    double& min_def = min(d, e, f);
    return 0;
}