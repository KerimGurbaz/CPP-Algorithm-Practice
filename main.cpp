#include <iostream>
#include <limits>
using namespace std;

/*
* template<typename T>
void afficher(T& x,
              T& y,
              T& z) {
    cout << "x = " << x << ", "
         << "y = " << y << ", "
         << "z = " << z << endl;
}
template<typename T>
void permutation(T& x,T& y,T& z) {
    T temp = z;
    z = y;
    y = x;
    x =temp;

}


int main() {

    int x=2, y=3, z=4;
    afficher(x,y,z);
    permutation(x,y,z);
    cout<<endl;
    afficher(x,y,z);

}template<typename T>
T& min(T&a, T&b, T&c) {
    return (a<b ? a<c ? a:c : b<c ? b: c);
}

template<typename T>
T& min (T& a, T& b, T& c) {
    T *m = &a;
    if(b < *m) m = &b;
    if(c< *m) m = &c;

    return *m;

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
}


template<typename Container>
void afficher(const Container &c) {
    cout << "[";

    auto it = begin(c);
    auto end = std::end(c);
    //
    // if (it != end) {
    //     cout << *it;
    //     ++it;cout
        while (it != end) {
            cout << *it;
            ++it;
           if(it != end) {
                cout<<", ";
            }

        }
    // }
    cout << "]";
}

template<typename Iterator>
void tri_selection(Iterator begin, Iterator end) {
    for(Iterator  i =begin; i != end; ++i) {
        Iterator min_idx = i;
    for(Iterator j = i; j != end; ++j) {
        if(*j < *min_idx) {
            min_idx =j;
        }
    }
        if(i != min_idx) {
            iter_swap(i, min_idx);
        }
    }
}

int main() {
    using namespace std::string_literals;

    // --- 1. Vector ---
    vector v {6, 2, 8, 7, 1, 3};
    afficher(v);
    tri_selection(v.begin(), v.end());
    afficher(v);
    cout << endl;

    // --- 2. Array ---
    array a {"chien"s, "chat"s, "souris"s, "poisson"s};
    afficher(a);
    tri_selection(a.begin(), a.end());
    afficher(a);
    cout << endl;

    // --- 3. Tableau C (Le plus difficile à gérer génériquement) ---
    double t[] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};
    afficher(t);

    // Pour un tableau C, begin() et end() n'existent pas en tant que méthodes.
    // On utilise les fonctions libres std::begin(t) et std::end(t)
    tri_selection(std::begin(t), std::end(t));
    afficher(t);

}


 */
#include <span>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename T, typename U> int fct(T,       U)      { cout<<"fct1 ; " ;}; // 1
template <typename T, typename U> int fct(T*,      U)      {cout<<"fct2 ; "; } ; // 2
template <typename T>             int fct(T,       T)      {cout<<"fct3 ; ";};  // 3
template <typename T>             int fct(T,       int)    { cout<<"fct4 ; "; } ; // 4
int fct(int,     int)    {cout<<"fct5 ; ";} ; // 5
int fct(int*,    float)  { cout<<"fct6 ; "; };  // 6


int main() {

    int     i  = 1;
    char    c  = 65;     // code ASCII de 'A'
    short   s  = 2;
    float   f  = 1.7f;
    double  d  = 3.1;
    int*    pi = &i;     // ptr sur i
    char*   pc = &c;     // ptr sur c
    float*  pf = &f;     // ptr sur f
    double* pd = &d;     // ptr sur d

    // no 1
    fct(pd, d);

    cout<<endl;


}