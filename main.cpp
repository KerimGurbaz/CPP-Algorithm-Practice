#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_right(vector<int>& v, size_t k) {
if(v.empty())return;
    size_t n = v.size();
    vector<int>temp(n) ;
    for(size_t i = 0; i<n; ++i) {
         temp[(i+k)%n]= v[i];
    }
    v=temp;
}

int main() {
    vector<int> v{1,2,3,4,5};
    rotate_right(v, 2);
    for (int x : v) cout << x << ' '; // beklenen: 4 5 1 2 3
}
