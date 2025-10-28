#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype> // ::islower
using namespace std;

int main() {
    string s("-vd-HEIG");
    remove_if(s.begin(), s.end(), ::islower);
    cout << s;
}