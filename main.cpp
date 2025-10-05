#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

int factorielle(int n) {
    int result =1;
    if(n<0)return 1;
    if(n == 0 || n==1) {
        return 1;
    }
    for(int i = 2; i<=n; ++i) {
        if(result > numeric_limits<int>::max() / i) {
            return -1;
        }
        result *= i;
    }

    return result;

}

string getSeason(int mois) {
    if(mois<1 || mois>12) {
        return "invalide mois";
    }else {
          switch(mois) {
            case 3 : case 4: case 5: return "printemps";
            case 6 : case 7: case 8: return "été";
            case 1 : case 2: case 12: return "hiver";
            default: return "automne";
        }
    }
}

int transformer(string& s, string_view from, string_view to) {
    int count=0;
    if(from.size() != to.size()) {
        return 0;
    }
    for(int i=0; i<from.size(); ++i) {
        for(int j = 0; j<s.size(); ++j) {
            if(tolower(from[i]) == tolower(s[j])) {
                s[j] = isupper(s[j]) ? toupper(to[i]) : tolower(to[i]);
                count++;
            }
        }
    }

    return count;

}

int main() {
    cout << factorielle(5) << " " << factorielle(13)<<endl;;

    cout << getSeason(1) << " " << getSeason(6) << " " << getSeason(10)<<endl;


    string s = "AbC";
    cout << transformer(s, "abc", "bca") << endl;
    cout << s << endl;
    return 0;
}