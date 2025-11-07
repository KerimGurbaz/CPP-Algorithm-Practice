#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 *
 */
int compter_doublons(const vector<int> &v) {
    int slow = 0;
    int count = 0;
    int el = 99999;

    for (size_t fast = 1; fast < v.size();) {
        if (v[slow] == v[fast] && v[slow] != el) {
            el = v[slow];
            ++count;
        }
        ++slow;
        ++fast;
    }
    return count;
}

int somme_impairs(const vector<int> &v) {
    int somme = 0;
    for (int c: v) {
        if (c % 2) {
            somme += c;
        }
    }
    return somme;
}
bool egaux( vector<int> v1, vector<int> v2 ) {
    if(v1.size() != v2.size()) {
        return false;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(size_t i = 0; i<v1.size(); ++i) {
        if(v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}
pair<int, int> minmax( vector<int>&v) {
    pair<int, int> result;
    for(size_t i = 0; i<v.size(); ++i) {
        for(size_t j = 1; j<v.size(); ++j) {
            if(v[j] < v[j-1]) {
                swap(v[j], v[j-1]);
            }
        }
        result.first = v[0];
        result.second = v[v.size()-1];

    }
    return result;
}
int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    cout << somme_impairs(v); // beklenen: 16
    cout << boolalpha << egaux({1,2,3}, {1,2,3}) << '\n';
    cout << boolalpha << egaux({1,2,3}, {3,2,1}) << '\n';

    vector<int> s{4,8,2,9,1,7};
    auto [mn, mx] = minmax(s);
    cout << mn << " " << mx; // beklenen: 1 9


}
