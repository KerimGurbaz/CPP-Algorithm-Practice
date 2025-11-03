#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

size_t unique_en_place(vector<int>& v) {
    size_t slow = 0;
    for(size_t fast = 1; fast <v.size(); ++fast) {
        if(v[fast] != v[slow]) {
            ++slow;
            v[slow]=v[fast];
        }
    }
return slow+1;
}

int main() {
    vector<int> v{1,1,2,2,2,3,3,5,5,7};
   size_t n = unique_en_place(v);
    v.resize(n);
    for (int x : v) cout << x << ' '; // beklenen: 1 2 3 5 7
}
