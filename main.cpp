#include <string>
#include <utility>
#include <iostream>

using namespace std;

string remplacer_occurences(const string& s, const string& from, const string& to) {
    string ss =s;
    int pos = 0;

     while((pos = ss.find(from, pos)) != string::npos) {
    ss.replace(pos, to.size(), to);
         pos += to.size();

    }

   return ss;
}

int main() {
    string texte{"Les sanglots longs de violons de l'automne "
                 "bercent mon coeur d'une langueur monotone"};
    cout << texte << endl;
    for (auto p: {pair<string, string>{"on", "ON"},
                  {"on", "o"},
                  {"on", "oin"},
                  {"o", "ooo"}}) {
        cout << remplacer_occurences(texte, p.first, p.second) << endl;
                  }
}