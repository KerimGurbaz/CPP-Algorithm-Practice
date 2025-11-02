/*
* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool verifier_tri(const vector<int>& v) {
 for(size_t i = 1 ; i<v.size();++i) {
     if(v[i]<v[i-1]) {
         return false;
     }
 }
    return true;
}

int main() {
    cout << boolalpha;
    cout << verifier_tri({1,2,3,3,5}) << endl;   // true
    cout << verifier_tri({1,3,2,5}) << endl;     // false
}

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>fusion_sorted(const vector<int>&v1,
                        const vector<int>&v2) {
    vector<int>r;
    r.reserve((v1.size()+ v2.size()));
    int p1 =0 ;
    int p2 = 0;

    while(p1 < v1.size() && p2 < v2.size() ) {
        if(v1[p1] < v2[p2] ){
            r.push_back(v1[p1]);
            p1++;
        }
       else if(v2[p2]< v1[p1] ){
            r.push_back(v2[p2]);
            p2++;
        }else {
            r.push_back(v2[p2]);
            r.push_back(v1[p1]);
            p1++;
            p2++;
        }

    }
    while(p1 < v1.size()) {
        r.push_back(v1[p1]);
        ++p1;
    }
    while(p2 < v2.size()) {
        r.push_back(v2[p2]);
        ++p2;
    }

    return r;
}

int main() {
    vector<int> a{1,3,5,9};
    vector<int> b{2,4,6,7,8};
    auto r = fusion_sorted(a,b);
    for (int x : r) cout << x << ' ';
}
