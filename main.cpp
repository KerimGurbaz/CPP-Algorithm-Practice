#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;

void affichage(const vector<int> &v) {
    for (int c: v) {
        cout << c << " ";
    }
    cout << endl;
}

void my_push_back(vector<int> &v, const int n) {
    v.push_back(n);
    affichage(v);
};

void my_pop_back(vector<int> &v) {
    v.pop_back();
    affichage(v);
};

void my_resize(vector<int> &v, const int n) {
    v.resize(n);
    affichage(v);
}

void my_resize(vector<int> &v, const int n, const int k) {
    v.resize(n, k);
    affichage(v);
}


int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    my_push_back(v, 7); // v contient {1, 2, 3, 4, 5, 6, 7}
    my_pop_back(v); // v contient {1, 2, 3, 4, 5, 6}
    my_pop_back(v); // v contient {1, 2, 3, 4, 5}
    my_resize(v, 3); // v contient {1, 2, 3}
    my_resize(v, 5, 1); // v contient {1, 2, 3, 1, 1}
    my_resize(v, 8); // v contient {1, 2, 3, 1, 1, 0, 0, 0}
}
