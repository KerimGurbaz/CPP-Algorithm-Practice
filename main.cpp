#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*
* string compresser(const string & s) {
    ostringstream os;
    size_t slow = 0;

 for(size_t i = 1; i<=s.size();) {
     size_t count =1;
    while(s[slow] == s[i]) {
        ++count;
        ++i;
    }
     os<<s[slow]<<count;
     slow = i;
     ++i;
 }
return os.str();
}
int main() {
    cout << compresser("aaabbc") << '\n';        // a3b2c1
    cout << compresser("HEIG") << '\n';          // H1E1I1G1
    cout << compresser("xxxYYYYzz") << '\n';     // x3Y4z2
    cout << '"' << compresser("") << '"' << '\n';// ""
}
string compresser(const string&s) {
    if(s.empty())return "";

    ostringstream os;

    size_t i = 0;

    while(i<s.size()) {
        char current = s[i];
        size_t count=0;

        while(i<s.size() && s[i] == current) {
            ++count;
            ++i;
        }

        os<<current<<count;
    }

return os.str();
}

int main() {
    cout << compresser("aaabbc") << '\n';        // a3b2c1
    cout << compresser("HEIG") << '\n';          // H1E1I1G1
    cout << compresser("xxxYYYYzz") << '\n';     // x3Y4z2
    cout << '"' << compresser("") << '"' << '\n';// ""
}

 */
static void printv(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

void miroir(vector<int>& v) {
   int slow = 0;
    int fast = v.size()-1;

    while(slow < fast) {
        int temp = v[slow];
        v[slow]= v[fast];
        v[fast] = temp;
        slow++;
        fast--;
    }

}

int main() {
    vector<int> a{1,2,3,4,5};
    vector<int> b{10};
    vector<int> c{};

    miroir(a); // 5 4 3 2 1
    miroir(b); // 10
    miroir(c); // (rien)

    printv(a);
    printv(b);
    printv(c);
}
