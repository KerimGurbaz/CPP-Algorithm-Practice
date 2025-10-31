#include <algorithm>
#include <iostream>
#include <string>
#include <vector> // Gerekirse
#include <sstream> // Gerekirse

using namespace std;

string transformer_date(const string& s) {

string result="";
    int pos1 = s.find_first_of('-');
    int pos2 = s.find_last_of('-');
    string day = s.substr(pos2 +1, 2);
    string mounth = s.substr(pos1+1,2);
    string year = s.substr(0, 4);
    vector<string> ss = {day, mounth, year};
    for(int i = 0; i<ss.size(); ++i) {
        result += ss[i];
        if(i != ss.size()-1) {
            result += ".";
        }
    }
    return result;

}
int main() {
    cout << transformer_date("2025-10-31") << endl;
    cout << transformer_date("1999-01-20") << endl;
}