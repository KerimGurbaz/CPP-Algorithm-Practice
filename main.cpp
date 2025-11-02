#include <iostream>
#include <vector>
#include <iomanip> // setw

using namespace std;

vector<vector<int>>generer_matrice(
    const vector<int>& contenu,
    const vector<size_t>& tailles) {
    int pos =0;
    vector<vector<int>> r(tailles.size());
    for(int i=0; i<tailles.size();++i) {
        //r[i].resize(tailles[i]);
        for(int j = tailles[i]; j>0 ; --j) {
            r[i].push_back(contenu[pos]);
            ++pos;
        }
    }
    return r;
}

void print_matrix(const vector<vector<int>>& m) {
    for (const auto& row : m) {
        for (int e : row) {
            cout << setw(3) << e;
        }
        cout << endl;
    }
}

int main() {
    const vector<int> contenu{1, 2, 3, 4, 5, -1, -2, -3, -4, -5};
    const vector<size_t> tailles{2, 3, 1, 4};

    auto m = generer_matrice(contenu, tailles);
    print_matrix(m);
}