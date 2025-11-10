#include <iostream>
#include <string>
#include <array>
#include <sstream>

using namespace std;
/*
#include <unordered_map>

int compter_voyelles(const string& s) {
    const string voyelles = "aeiouy";
    size_t count =0;
    unordered_map<char, int>myMap;
    for(char c : s) {
        myMap[tolower(c)]++;
    }
    for(const auto&p : myMap) {
        for(char c : voyelles) {
            if(p.first == c) {
                count += p.second;
            }
        }
    }
    return count;
}

int main() {

    const string s = "Ali ata bak lutfen..";


    cout<< compter_voyelles(s);
    return 0;
}
int compter_voyelles(const string& s) {
    int count= 0;
    const string voyelle ="aeiouy";
  for(char c : s) {
      c= tolower(c);
      if(voyelle.find(c) != string::npos) {
          ++count;
      }
  }
    return count;
}

int main() {

    const string s = "Ali ata bak lutfen..";


    cout<< compter_voyelles(s);
    return 0;
}
 */
#include <sstream>
#include <vector>
string plus_long_mot(const string& phrase) {
    stringstream ss(phrase);
    string mot ;
    string maxMot ="";
    while (ss>>mot) {
        if(mot.size() > maxMot.size()) {
            maxMot =mot;
        }
    }
    return maxMot;
}
bool est_symetrique(const vector<int>& v) {
    int slow = 0;
    int fast = v.size()-1;
    while(slow < fast) {
        if(v[slow] != v[fast]) {
            return false;
        }
        ++slow; --fast;
    }
    return true;
}




int main() {
    cout << plus_long_mot("Le C++ moderne est puissant!") << endl;
    vector<int>v = {1,2,3};

    cout<<boolalpha<<est_symetrique(v);

    return 0;
}