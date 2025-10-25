#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
using namespace std;
void acronyme(const string& s) {
    vector<string>v;
    string mot;
    string res = "";
    stringstream ss(s);
    while(ss>>mot) {
        v.push_back(mot);
        res.push_back(mot[0]);
    }
    res+=toupper(s.back());
    v.push_back(res);
    cout<<"Votre prenom est   : "<<v[0]<<endl;
    cout<<"Votre nom est      : "<<v[1]<<endl;
    cout<<"Votre acronyme est : "<<v[2]<<endl;
}

int main() {
    cout<<"Entrez votre prenom et votre nom : ";
    string nomPrenom;
    getline(cin, nomPrenom);
   acronyme(nomPrenom);
    return 0;
}