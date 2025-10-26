#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <cctype>
using namespace std;

bool Palindrome(const string& s) {
    int first = 0;
    int last = s.size()-1;

    while(first<last) {
        while(first<last && !isalnum(s[first])) {
            first++;
        }
        while(first <last && !isalnum(s[last])) {
            last --;
        }
        if(first <last && tolower(s[first]) != tolower(s[last])) {
            return false;
        }
        first++;
        last--;
    }
    return true;
}


void affichage (const string& s) {
    if(Palindrome(s)) {
        cout<<"Le mot "<<s<<" est un palindrome.";
    }else {
          cout<<"Le mot "<<s<<" n'est pas un palindrome..";
    }

}


int main() {
    cout<<"Entrez un nom : ";
    string nom;
   getline(cin, nom);
   affichage (nom);
    return 0;
}