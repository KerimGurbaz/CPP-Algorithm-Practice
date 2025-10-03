#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;

int premier_e(string_view s) {
    for(int i = 0; i<s.size(); ++i) {
        if(s[i]== 'e' || s[i]== 'E') return i;
    }
    return -1;
}

void echanger(int& a, int &b) {
    int temp = a;
    a =b;
    b=temp;
}

int main() {

    cout<<premier_e("Bonjour")<<endl;
    cout<<premier_e("Renverser")<<endl;
    cout<<premier_e("Elan")<<endl;

    int x = 3, y = 5;
    echanger(x, y);
    cout << x << " " << y << endl;

    return 0;
}