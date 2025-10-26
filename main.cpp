#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <cctype>
using namespace std;

string to_lower(string& s) {
    for(char & c: s) {
       c= tolower(c);
    }
    return s;
}

int occurance( const string& s,const   string& o) {
    string n_s =s;
    n_s = to_lower(n_s);

    string n_o = o;
    n_o = to_lower(n_o);

    int pos=0;
    int count=0;
    while((pos = n_s.find(n_o,pos)) != string::npos){
        pos ++;
        count++;
    }
    return count;
}


int main() {
    cout<<"Entrez une chaine de caracteres ";
    string nom;
    string occur;
   getline(cin, nom);
   getline(cin, occur);

cout<<occurance(nom, occur);


    return 0;
}