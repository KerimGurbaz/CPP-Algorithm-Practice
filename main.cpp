#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

bool palindrome(string &s) {
    int slow = 0;
    int fast = s.size() - 1;

    while (slow < fast) {
        if (tolower(s[slow]) != tolower(s[fast])) {
            return false;
        }
        ++slow;
        --fast;
    }
    return true;
}

int main() {
    string mot;
    do {
        cout << "entrez un mot(ou 'quitter' pour sortir ) : ";
        cin >> mot;
        if (palindrome(mot)) {
            cout << "Le mot " << mot << " est palindorme" << endl;
        } else {
            cout << "Le mot " << mot << "n'est pas palindorme" << endl;
        }
    } while (mot != "quitter");
}
