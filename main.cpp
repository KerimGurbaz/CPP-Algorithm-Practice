#include <iostream>
#include <array>
using namespace std;
#include <string>
#include <sstream>

using Vec3d = array<double, 3>;

string to_string(const Vec3d &v) {
    stringstream ss;
    ss << "(" << v[0] << "," << v[1] << "," << v[2] << ")";
    return ss.str();
}

Vec3d produit(const Vec3d &v, double d) {
    Vec3d result;
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] * d;
    }
    return result;
}

double produit_scalaire(Vec3d &v1, Vec3d &v2) {
    double result = 0.0;

    for (size_t i = 0; i < v1.size(); ++i) {
        result += (v1[i] * v2[i]);
    }

    return result;
}

Vec3d produit_vectoriel(Vec3d &v1, Vec3d &v2) {
    Vec3d result;
    if (v1.size() != v2.size()) {
        return {};
    } else {
        for (size_t i = 0; i < v1.size(); ++i) {
            result[i] = (v1[i] * v2[i]);
        }
    }
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
}
