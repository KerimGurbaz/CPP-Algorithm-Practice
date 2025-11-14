/*
*#include <iostream>
#include <vector>
#include <algorithm> // std::sort (main'de kullanıldı)

using namespace std;


void rendre_unique(vector<int>& v) {
   if(v.empty()) {
       return;
   }
    int slow = 0;
    for(size_t fast =1; fast<v.size();++fast ) {
        if(v[slow] != v[fast]) {
            v[++slow] =v[fast];
        }
    }
    v.erase(v.begin() + slow+1, v.end());

}


void print_vec(const vector<int>& v) {
    for (int e : v) cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 5, 5, 1};


    sort(v.begin(), v.end());

    print_vec(v); // Sıralı: 1 1 2 2 3 3 3 4 5 5

    rendre_unique(v);

    print_vec(v); // Beklenen: 1 2 3 4 5
}

#include <iostream>
#include <string>
using namespace std;

struct EmailInfo {
    string user;
    string domain;
    string ext;
    bool is_valid = false;
};
EmailInfo analyser_email(const string& email) {
    EmailInfo result;
    size_t atPos = email.find('@');

    if(atPos == string::npos) {
        return result;
    }
    size_t dotPos = email.find('.', atPos);
    if(dotPos ==string::npos ||dotPos == atPos+1) {
        return result;
    }
    result.user = email.substr(0, atPos);
    size_t domainLen = dotPos - (atPos +1);
    result.domain = email.substr(atPos+1 , domainLen);
    result.ext = email.substr(dotPos+1);
    result.is_valid = true;

    return result;
}

int main() {
    auto info1 = analyser_email("etudiant@heig-vd.ch");
    if (info1.is_valid)
        cout << info1.user << " / " << info1.domain << " / " << info1.ext << endl;
    else
        cout << "Invalid 1" << endl;

    auto info2 = analyser_email("mauvais_email.com");
    if (!info2.is_valid) cout << "Invalid 2 detected" << endl;
}
 */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Pays {
    string nom;
    int gold;
    int silver;
    int bronze;
};
void afficher_classement(const vector<Pays>& v) {
    for(const auto& p : v) {
        cout<<p.nom<<": "<<p.gold<<" O, "<<p.silver<<"A, "<<p.bronze<<" B"<<endl;

    }
}

void classer_pays(vector<Pays>& v) {
    sort(v.begin(), v.end(), [](const Pays&a, const Pays& b) {
        if(a.gold != b.gold) {
            return a.gold > b.gold;
        } if(a.silver != b.silver) {
           return a.silver > b.silver;
        }if(a.bronze != b.bronze) {
          return  a.bronze>b.bronze;
        }

        return a.nom < b.nom;
    });
}

int main() {
    vector<Pays> jeux = {
        {"Suisse", 1, 2, 3},
        {"France", 2, 0, 0},
        {"USA", 2, 0, 1},    // France ile Altın/Gümüş aynı, Bronz farklı
        {"Italie", 1, 2, 3}, // Suisse ile her şey aynı
        {"Japon", 5, 0, 0}
    };

    classer_pays(jeux);
    afficher_classement(jeux);
}