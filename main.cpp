#include <iostream>
#include <string>

using namespace std;

string milieu(const string& s) {
    int n = s.size();
    if(n%2) {
        return s.substr(n/2, 1);
    }else {
        return s.substr(n/2-1, 2);
    }
}

int main() {
    string s = "ABCD";
    cout<<milieu(s);
    return 0;
}