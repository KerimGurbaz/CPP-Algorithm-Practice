#include <iostream>
#include <array>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
for(size_t i = 0; i<v.size(); ++i) {
    if(i)cout<<",";
    cout<<v[i];
}
    cout<<endl;
}

vector<int >my_push_back(vector<int>& v, const int n) {
    v.resize(v.size()+1);
    v[v.size()-1]=n;
    return v;
}

vector<int> my_pop_back(vector<int>& v) {
    v.resize(v.size()-1);
    return v;
}

vector<int>my_resize(vector<int>& v,int n, int value=int()) {
    while(v.size() < n) {
        v.push_back(value);
    }
    while(v.size()>n) {
        v.pop_back();
    }
    return v;
}
int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    my_push_back(v, 7);     // v contient {1, 2, 3, 4, 5, 6, 7}
    print(v);

    my_pop_back(v);         // v contient {1, 2, 3, 4, 5, 6}
print(v);

    my_pop_back(v);         // v contient {1, 2, 3, 4, 5}
    print(v);

    my_resize(v,3);         // v contient {1, 2, 3}
    print(v);
    my_resize(v,5,1);       // v contient {1, 2, 3, 1, 1}
    print(v);
    my_resize(v,8);         // v contient {1, 2, 3, 1, 1, 0, 0, 0}
    print(v);

}