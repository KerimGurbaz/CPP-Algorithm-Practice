#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
using namespace std;
#include <cassert>
#include <set>
#include <cctype>

bool verifier(string_view a, string_view b) {
    set<char> set_a;
    set<char> set_b;

    for(char c: a) {
        char lower_c = tolower(c);
        if( !set_a.insert(lower_c).second) {
            return false;
        }
    }
    for(char c : b) {
        char lower_c = tolower(c);
        if( !set_b.insert(lower_c).second) {
            return false;
        }
    }

    return set_a == set_b;
}

void tester(string_view a, string_view b) {
    cout << '"' << a << "\" "
         << (verifier(a, b) ? "" : "in")
         << "compatible avec "
         << '"' << b << '"' << '\n';
}

int main() {
    tester("abcdef","FEDBAC");
    tester("abcdef","xyz123");
    tester("abcA","cAba");
}
