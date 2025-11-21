#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
*
bool sont_anagrammes(const string &s1, const string &s2) {
    map<char, int> result1;
    map<char, int> result2;

    for (auto c: s1) {
        if (isalpha(c)) {
            c = tolower(c);
            result1[c]++;
        }
    }
    for (char c: s2) {
        if (isalpha(c)) {
            c = tolower(c);
            result2[c]++;
        }
    }
        return equal(result1.begin(), result1.end(),
                     result2.begin(), result2.end());
}

#include <array>
#include <cctype>

bool sont_anagrammes(const string& s1, const string s2) {
    array<int, 26>count{};
    count.fill(0);

    for(char c: s1) {
        if(isalpha(c)) {
             count[tolower(c) - 'a']++;
        }
    }

    for(char c: s2) {
        if(isalpha(c)) {
            count[tolower(c) - 'a']--;
        }
    }

    for(int n : count) {
        if(n!=0) {
            return false;
        }
    }
    return true;
}


int main() {
    cout << sont_anagrammes("Listen", "Silent");
    cout << sont_anagrammes("Hello", "Olelh!");
    cout << sont_anagrammes("HEIG", "VD");
}

 */
using vec = vector<char>;
using matrice =vector<vec>;

matrice cadre_diagonale(size_t n) {
    matrice m;
    m.resize(n,vec(n));
    for(size_t i =0; i<n; ++i) {
        for(size_t j = 0; j<n; ++j) {
            if(i == j) {
                m[i][j]= 'X';
            } if(j == n-1-i) {
                m[i][j]='X';
            }
        }
    }
    return m;
}



int main(){
    auto m = cadre_diagonale(5);
    for (auto& row : m) {
        for (char c : row) cout << c;
        cout << '\n';
    }
}
