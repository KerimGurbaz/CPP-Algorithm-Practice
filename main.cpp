#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void majuscule(vector<string>&v) {
    transform(v.begin(), v.end(), v.begin(),[](string s) {
        for(char &c: s) {
            c= toupper(c);
        }
        return s;
    });
}
int main() {
    vector<string> mots = {"salut", "heig", "vd", "cpp"};
    majuscule(mots);
    for (auto& m : mots) cout << m << ' ';
    cout << endl;
    return 0;
}
