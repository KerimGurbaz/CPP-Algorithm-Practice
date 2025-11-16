#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

string nettoyer_adn(const string & s) {
    string ss = s;
    const string DNA ="ACGT";
            auto ne = remove_if(ss.begin(), ss.end(), [](char c) {
            return isspace(c);
    });
    string result ="";
    ss.erase(ne, ss.end());
    for(char c : ss ) {
        c=toupper(c);
    if(DNA.find(c) == string::npos) {
        return "";
    }else {
        result += c;
    }
    }
    return result;
}

int main() {
    cout << "|" << nettoyer_adn("a c g t A G") << "|" << endl; // |ACGTAG|
    cout << "|" << nettoyer_adn("AcGtX") << "|" << endl;       // || (X geçersiz)
    cout << "|" << nettoyer_adn("") << "|" << endl;            // ||
}