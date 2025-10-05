#include <iostream>
#include <cctype>
using namespace std;

int compter_voyelles(const string& texte) {
    string s = texte;
    int count = 0;
    for(char c : s) {
      if(  tolower(c) == 'a' ||tolower(c) == 'e'||tolower(c) ==  'i'||tolower(c) == 'o' ||tolower(c) == 'u'){
          count++;
      }
    }
return count;
}

int main() {


        string phrase = "Bonjour le Monde";
        cout << compter_voyelles(phrase);


    return 0;
}