#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

void nettoyer(vector<char>& v) {
/*
    *     erase_if(v, [](char c) {
            return isalpha(c);
        });
 */

    v.erase(remove_if(v.begin(), v.end(),
        [](char c) {
        return !isalpha(c);
    }));
}

int main() {
    vector<char> texte = {'H','e','1','l','2','l','o','!','3'};
    nettoyer(texte);
    for (char c : texte) cout << c;
    cout << '\n';
}
