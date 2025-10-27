/*
* #include <iostream>
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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> filtrer_pairs( vector<int>& v) {
    //vector<int>cv;

    auto debut =  remove_if(v.begin(), v.end(), [](int n) {
           return (n%2 == 0);
       });
    v.erase(debut, v.end());

    return v;

}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    auto pairs = filtrer_pairs(v);
    for (int n : pairs) cout << n << ' ';
    cout << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> filtrer_pairs( vector<int>& v) {
    //vector<int>cv;

    auto debut =  remove_if(v.begin(), v.end(), [](int n) {
           return (n%2 == 0);
       });
    v.erase(debut, v.end());

    return v;

}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    auto pairs = filtrer_pairs(v);
    for (int n : pairs) cout << n << ' ';
    cout << endl;
}
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int somme_carres(const vector<int>& v) {

return accumulate(v.begin(), v.end(),1,[](int acc, int n) {
    return acc * n;
});

}


int main() {
    vector<int> v = {1,2,3,4,5};
    cout << somme_carres(v) << endl;
}
#include <iostream>
#include <vector>
#include <cctype>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int, int, int> compter_types(const string& s) {
    int letrre =0;int ch = 0;
    int autre = 0;
for(char c : s) {
    if(isalpha(c)) {
        letrre++;
    }else if(isdigit(c)) {
        ch++;
    }else {
        autre++;
    }
}
    return {letrre, ch, autre};

}

int main() {
    auto [lettres, chiffres, autres] = compter_types("HEIG-VD 2025!");
    cout << "Lettres=" << lettres
         << "  Chiffres=" << chiffres
         << "  Autres=" << autres << endl;
 */


#include <iostream>
#include <string>
using namespace std;

bool est_palindrome(const string& s) {
    int first =0;
    int last =s.size()-1;
 while(first<last) {
        while(first<last && !isalnum(s[first])) {
            ++first;
        }
        while(first<last && !isalnum(s[last])) {
            --last;
        }
        if(tolower(s[first]) != tolower(s[last])) {
            return false;
        }
        ++first;
     --last;
 }


    return true;
}

int main() {
    cout << boolalpha;
    cout << est_palindrome("Kayak") << endl;                // true
    cout << est_palindrome("Engage le jeu que je le gagne") << endl;  // true
    cout << est_palindrome("Bonjour") << endl;
    cout << est_palindrome("No 'x' in Nixon") << endl;
    cout << est_palindrome("A man, a plan, a canal: Panama!") << endl;
}

