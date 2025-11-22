#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
#include <string>
#include <sstream>


#include <iostream>
#include <array>
using namespace std;

using Vec3d = array<double, 3>;

string to_string(const Vec3d &v) {
    ostringstream os;
    os << "(";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)os << ", ";
        os << v[i];
    }
    os << ")";
    return os.str();
}

Vec3d produit(const Vec3d &v, double n) {
    Vec3d copy_a = v;
    for (double &el: copy_a) {
        el *= n;
    }
    return copy_a;
}

double produit_scalaire(const Vec3d &v1, const Vec3d &v2) {

    double sum = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

Vec3d produit_vectoriel(const Vec3d &a, const Vec3d &b) {
    Vec3d result;
    result[0] = (a[1] * b[2]) - (b[1] * a[2]);
    result[1] = (a[2] * b[0]) - (b[2] * a[0]);
    result[2] = (a[0] * b[1]) - (b[0] * a[1]);
    return result;
}


int main() {
    Vec3d a{1., 2., 3.};
    Vec3d b{2., 4., 3.};
    cout << "a = " << to_string(a) << endl
            << "b = " << to_string(b) << endl;

    Vec3d c = produit(a, 2.);
    cout << "c = a*2 = " << to_string(c) << endl;

    cout << "a.b = " << produit_scalaire(a, b)
            << ", a.c = " << produit_scalaire(a, c)
            << ", b.c = " << produit_scalaire(b, c) << endl;


    Vec3d d = produit_vectoriel(a, b);
    cout << "d = a^b = " << to_string(d) << endl;
    cout << "a.d = " << produit_scalaire(a, d)
            << ", b.d = " << produit_scalaire(b, d) << endl;

    Vec3d e = produit_vectoriel(a, a);
    cout << "e = a^a = " << to_string(e) << endl;

    array<int,3> k;
    cout << k[0] << k[1] << k[2];
}
