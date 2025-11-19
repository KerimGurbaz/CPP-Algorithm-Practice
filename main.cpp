/**
* #include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


bool check_mult(long a, long b) {
    if(b!=0 &&  a> numeric_limits<long>::max() /b) {
        return false;
    }else {
        return true;
    }


}

    int main(){
        long a = 2000000000;
        long b = 10;
        // Normalde 20 milyar, long (genellikle 2 milyar civarıdır 32-bitte,
        // ama 64-bitte çok daha büyüktür. Biz mantığı kuralım.)

        if (check_mult(a, b)) cout << "OK" << endl;
        else cout << "Overflow!" << endl;
    cout<<endl;
    vector<int> v{1,2,3,2,4,2,5};
    auto it = remove(v.begin(), v.end(), 2);
    for(int x : v) cout << x;
    cout << " | " << (v.end() - it);

    }

#include <iostream>
#include <vector>
#include <numeric> // accumulate (kullanabilirsin ama elle toplamak daha güvenli)

using namespace std;
using matrice = vector<vector<int>>;
vector<double>moyenne_lignes(const matrice& m) {
    vector<double>vecD(m.size());
    if(m.size() == 0 || m[0].size()==0) {
        return vecD;
    }
    for(size_t i = 0; i<m.size(); ++i) {
        double somme =0;
        size_t j =0;
        for(; j<m[i].size(); ++j) {
            somme += m[i][j];
        }
       vecD[i]=(somme/j);
    }
    return vecD;
}


int main() {
    vector<vector<int>> m = {
        {1, 2, 3},      // Ort: 2.0
        {10, 20},       // Ort: 15.0
        {5}             // Ort: 5.0
    };

    auto res = moyenne_lignes(m);
    for(double d : res) cout << d << " ";
    // Beklenen: 2 15 5
}
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using matris =  vector<vector<int>> ;
vector<double> moyenne_lignes(const matris & m) {
    vector<double> res;
    res.resize(m.size());

    for(const auto& ligne : m) {
        if(ligne.empty()) {
            res.push_back(0.0);
        }else {
            double sum = accumulate(ligne.begin(), ligne.end(), 0.0);
            res.push_back(sum/ ligne.size());
        }
    }
    return res;
}


int main() {
    vector<vector<int>> m = {
        {1, 2, 3},      // Ort: 2.0
        {10, 20},       // Ort: 15.0
        {5}             // Ort: 5.0
    };

    auto res = moyenne_lignes(m);
    for(double d : res) cout << d << " ";
    // Beklenen: 2 15 5
}
#include <iostream>
#include <string>

using namespace std;


void replace_manual(string& s, const string&old_sub, const string& new_sub) {

    int pos = 0;
    while((pos=s.find(old_sub, pos)) != string::npos) {
        s.replace(pos, old_sub.size(), new_sub);
        ++pos;
    }
}
int main() {
    string s = "banana";
    replace_manual(s, "ana", "o");
    cout << s << endl;
    // Beklenen: "bo" ("banana" -> ilk "ana" bulunur -> "bo" olur.
    // EĞER "banana" -> "b" + "ana" + "na" -> "b" + "o" + "na" -> "bona" ise algoritmana bağlı.
    // Genellikle soldan sağa ilk bulunanı değiştirir, sonra devam eder.

    string s2 = "aa";
    replace_manual(s2, "a", "b");
    cout << s2 << endl; // "bb"
}
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*
*
unordered_map<int, int> compter_doublons_consecutifs(const vector<int>& v) {

    unordered_map<int, int> result;

    for(const auto& el : v) {
        result[el]++;
    }

    for(const auto& [number, frekans]: result) {
        cout<<number<< " : "<<frekans<<endl;;
    }
cout<<endl;

    return result;

}

int main() {
 compter_doublons_consecutifs({1,1,2,2,2,3,3,5,5,7}) ;
 compter_doublons_consecutifs({1,2,3,4});            // 0
   compter_doublons_consecutifs({9,9,9,9});            // 1
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TODO: v sıralı, kaç farklı eleman en az 2 kez ardışık görünüyor?
size_t compter_doublons_consecutifs(const vector<int>& v) {
    unordered_map<int, int> result;
    for(const auto& el : v) {
        result[el]++;
    }
    int count =0;

    for(const auto&el: result) {
        if(el.second >1) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << compter_doublons_consecutifs({1,1,2,2,2,3,3,5,5,7}) << '\n'; // 4
    cout << compter_doublons_consecutifs({1,2,3,4}) << '\n';             // 0
    cout << compter_doublons_consecutifs({9,9,9,9}) << '\n';             // 1
}

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

// TODO: sadece harfleri tut, hepsini lowercase, kelimeler arası tek boşluk
string nettoyer_string(const string& s) {
    string myStr=s;
    stringstream ss(myStr);
    string mot;
    string result;
    while(ss>>mot) {
        result.push_back(' ');
        for(char & c : mot) {
            if(isalpha(c)) {
                c = tolower(c);
                result+=c;
            }

        }
    }
    result= result.replace(0,1, "");
    return result;
}

int main() {
    cout << nettoyer_string("Hello, C++ World !") << '\n';      // "hello c world"
    cout << nettoyer_string("  HEIG-VD   2025 !!! ") << '\n';   // "heigvd"
    cout << nettoyer_string("C  est    genial") << '\n';        // "c est genial"
}
#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
size_t compter_occurrences(const vector<int>& v, int x) {
unordered_map<int, int> result ;
    for(const auto& el : v) {
        result[el]++;
    }
    for(const auto& el : result) {
        if(el.first == x) {
            return el.second;
        }
    }
    return 0;
}

int main() {
    cout << compter_occurrences({1,2,3,2,2,4}, 2) << '\n'; // 3
    cout << compter_occurrences({1,1,1}, 1) << '\n';       // 3
    cout << compter_occurrences({1,2,3}, 4) << '\n';       // 0
}



 */



