/*
* #include <iostream>
#include <vector>
#include <array>

using namespace std;

size_t oter_hors_limite(vector<double>&v , array<double, 2>limites) {
    double min = limites[0];
    double max = limites[1];

    size_t slow = 0;
    for(size_t fast = 0; fast<v.size();++fast) {
        if((v[fast] >= min) && (v[fast] <= max)) {
                v[slow]= v[fast];
                ++slow;
        }
    }
    return slow;
}


int main() {
    vector<double> v1{1.0, 2.3, 1.4, 5.3, 3.4, 2.4, 4.6};
    array<double, 2> lim1{2.3, 5.0};

    // v1 = {1.0, 2.3, 1.4, 5.3, 3.4, 2.4, 4.6}
    // Korunanlar: 2.3, 3.4, 2.4, 4.6 (5.3 aralık dışında)

    size_t n1 = oter_hors_limite(v1, lim1);

    // Sadece yeni boyuta kadar bas
    for (size_t i = 0; i < n1; ++i)
        cout << v1[i] << ' ';
    // Beklenen Çıktı: 2.3 3.4 2.4 4.6

    cout << "\nvektorun son hali: ";
    for (double e : v1) cout << e << ' ';

}
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool est_palindrome_insensible(const string& s) {
    int first = 0;
    int last = s.size()-1;

    while(first < last) {
        while(ispunct(s[first]) || isspace(s[first])) {
            ++first;
        }
        while(ispunct(s[last]) || isspace(s[last])) {
            --last;
        }
        if(tolower(s[first]) !=tolower( s[last])) {
            return false;
        }
        ++first;
        --last;
    }
    return true;
}

int main() {
    cout << boolalpha; // 'true'/'false' basar
    cout << est_palindrome_insensible("Radar") << endl;
    cout << est_palindrome_insensible("A man, a plan, a canal: Panama") << endl;
    cout << est_palindrome_insensible("hello") << endl;
}
 */

#include <iostream>
#include <string>
using namespace std;

string compresser(const string& s) {
    int count =1;


    string result ="";
    for(size_t i = 0; i<s.size();++i) {
        if(s[i]==s[i+1]) {
            count++;
        }else if(s[i] != s[i+1]) {

            result +=s[i];
            result += to_string(count) ;
            count=1;
        }
    }
    return result;
}

int main() {
    cout << compresser("aabcccccaaa") << endl;
   cout << compresser("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB") << endl;
    cout << compresser("abc") << endl;
}