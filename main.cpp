#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

int transformer(string& s, string from, string to) {
assert(from.size() == to.size());
    size_t count = 0;

    for(size_t j =0; j<s.size(); ++j) {
        char orj = s[j];
        char lower_s = tolower(orj);

        for(size_t i =0 ; i<from.size();++i) {
            if(tolower(from[i]) == lower_s) {
                char replacement_char = to[i];
                s[j] = isupper(orj) ? toupper(replacement_char) : tolower(replacement_char);
                ++count;
                break;
            }
        }
    }
return count;

}

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

// TODO: size_t transformer(string& s, string_view from, string_view to);

int main() {
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
               "Phasellus facilisis at dolor eget congue. "
               "Duis in lacus placerat ante consectetur tempor. "
               "Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";

    cout << transformer(s,"abcdefgh.!,:","fghabcde!,:.") << "\n";
    cout << s << "\n";
    cout << transformer(s,"fghabcde!,:.","abcdefgh.!,:") << "\n";
    cout << s << "\n";
}
