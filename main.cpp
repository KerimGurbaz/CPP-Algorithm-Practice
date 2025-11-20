/*
* #include <iostream>
#include <vector>

using namespace std;

using matrice = vector<vector<int>>;

void afficher(const matrice& m) {
    for(const auto& l : m) {
        for(const auto& v : l) {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

matrice dessiner_sablier(const int n) {
    matrice m(n, vector<int>(n, 0));

    for(size_t i  = 0; i<n; ++i) {
        size_t left = min(i, n-i-1);
        size_t right = max(i, n-i-1);

        for(size_t j = left; j<=right; ++j) {
            m[i][j] = 1;
        }
    }
    return m;
}


int main() {
    auto m = dessiner_sablier(5);
    afficher(m);
}


vector<int> analyser_frequence(const string& s) {
    vector<int> counts(26, 0);

    for(char c: s) {
        c= tolower(c);
        counts[c - 'a']++;
    }

    return counts;
}

int main() {
    string s = "Hello World!";
    auto freqs = analyser_frequence(s);


    for(size_t i = 0; i < 26; ++i) {
        if(freqs[i] > 0) {
            cout << (char)('A' + i) << ": " << freqs[i] << endl;
        }
    }
}
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// VOTRE CODE VIENT ICI
vector<int>analyser_frequence(const string& s) {
    vector<int> result(26, 0);
    for(char c : s) {
        c= tolower(c);
        result[c-'a']++;
    }
    return result;
}

int main() {
    string s = "Hello World!";
    auto freqs = analyser_frequence(s);

    // Sadece geçen harfleri basalım
    for(size_t i = 0; i < 26; ++i) {
        if(freqs[i] > 0) {
            cout << (char)('A' + i) << ": " << freqs[i] << endl;
        }
    }
    // Beklenen (örnek): D:1, E:1, H:1, L:3, O:2, R:1, W:1

    unsigned char c = 255;
    cout << " | " << c + 22;
}
