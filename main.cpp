#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

size_t remove_duplicates(vector<int>& v) {
    if(v.size() < 2) {
        return v.size();
    }
    size_t first = 0;
    for(size_t i =1; i < v.size(); ) {
        if(v[first] != v[i]) {
            ++first;
            v[first]=v[i];
            ++i;
        }else {
            v[first]=v[i];
            ++i;
        }
    }
            v.erase(v.begin() + first + 1 , v.end());

    return v.size();
}

vector<int> uniq(vector<int>& v) {
    auto new_end = unique(v.begin(), v.end());
    v.erase(new_end, v.end());
    return v;
}


int main() {
    vector<int> v{1,1,2,2,2,3,3,5,5,7};
    size_t n = remove_duplicates(v);
    v.resize(n);
    for (int x : v) cout << x << ' ';  // beklenen: 1 2 3 5 7
    cout << '\n';

    vector<int> a{};
    cout << remove_duplicates(a) << '\n'; // beklenen: 0

    vector<int> b{4};
    size_t nb = remove_duplicates(b);
    b.resize(nb);
    for (int x : b) cout << x << ' ';    // beklenen: 4
    cout << '\n';

    cout << '\n';    cout << '\n';
    vector<int> v2{1,2,5, 1,2,2,2,23, 33,33,5,5,7};
    uniq(v2);
    for(int c :v2) {
        cout<<c<<" ";
    }
}
