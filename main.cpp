/*
*
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>>compress_runs(const vector<int>& v) {
    vector<pair<int, int>> result;
    result.reserve(v.size());
    int slow =0 ;
    int count =0;
    for(size_t fast = 0; fast<v.size();++fast) {
        if(v[slow] == v[fast]) {
            ++count;
        }else {
            result.push_back({v[slow], count});
            count =1;
            slow = fast;
        }
    }
    result.push_back({v[slow], count});
    return result;
}

int main() {
    vector<int> v{1,1,1,2,2,3,5,5,5,5};
    auto r = compress_runs(v);
    for (auto [val, cnt] : r) {
        cout << "(" << val << "," << cnt << ") ";
    }

}

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> filtrer_intervalle( vector<int>v, int min_Val, int max_Val) {
auto it = remove_if(v.begin(), v.end(),[min_Val, max_Val](int n) {
    return (n < min_Val || n>max_Val);
});

    v.erase(it, v.end());
    sort(v.begin(), v.end());
    return v;
}

int main() {
    vector<int> v{5,1,9,3,7,2,8};
    auto r = filtrer_intervalle(v, 3, 7);
    for (int x : r) cout << x << ' ';

}
