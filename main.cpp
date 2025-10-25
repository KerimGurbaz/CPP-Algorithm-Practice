#include <iostream>
#include <string>
#include <vector>

using namespace std;

int valeur_symbole(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

int romain_vers_entier(const string& s) {
    if(s.empty()) {
        return 0;
    }
    int total =0;
    int precedent =0;
    for(int i = s.size()-1; i>=0; --i) {
        int valuerActuelle = valeur_symbole(s[i]);

        if(valuerActuelle < precedent) {
            total -= valuerActuelle;
        }else {
            total += valuerActuelle;
        }
        precedent = valuerActuelle;
    }
    return total;
}





int main() {
    std::vector<std::string> tests = {
        "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
        "XIV", "MMMMDCCCLXXXVIII"
    };

    for (const std::string& test : tests) {
        std::cout << "\"" << test << "\" = " << romain_vers_entier(test) << std::endl;
    }

    return 0;
}