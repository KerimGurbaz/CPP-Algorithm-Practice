#include <iostream>
#include <vector>
using namespace std;

pair<int, int>somme_diagonales(const vector<vector<int>>& m) {
    using v = vector<int>;
    using mm = vector<v>;
    int sum1 =0;
    int sum2 =0;
    for(size_t i = 0; i<m.size(); ++i) {
        for(size_t j = 0; j<m[i].size(); ++j) {
            if(i == j) {
                sum1 += m[i][j];
            }
            if(i + j == m.size()-1) {
                sum2 += m[i][j];
            }
        }
    }
    return {sum1, sum2};
}
#include <unordered_map>
#include <sstream>
string mot_le_plus_frequent(const string& s) {
    stringstream ss(s);
    unordered_map<string, int>myMap;
    string mot;

    while (ss>>mot) {
        myMap[mot]++;
    }
    int plusFrequant =0;
    string plusFrequantMot ="";
    for(const auto&p : myMap) {
      if(p.second >plusFrequant ) {
          plusFrequant = p.second;
          plusFrequantMot = p.first;
      }
    }

    return plusFrequantMot;
}
int main() {
    vector<vector<int>> m{
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    auto [dp, ds] = somme_diagonales(m);
    cout << dp << " " << ds << "\n"; // beklenen: 15 15


    string t = "le code en C++ est rapide et le code est fort";
    cout << mot_le_plus_frequent(t) << "\n"; // "le" veya "est"
}
