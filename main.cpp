/*
// --- Ne pas modifier ---
#include <iostream>
#include <string>
using namespace std;

bool parenthesesValides(const string& s) {
    int count=0;
  for(char c : s) {
      if(c =='(') {
          ++count;
      }else if(c==')') {
          --count;
      }
  }
    return count ==0;
}

int main() {

    cout << "()) -> " << boolalpha << parenthesesValides("(())") << endl;         // Attendu: false
    return 0;
}

#include <iostream>
using namespace std;

void dessinerMatrice(int n) {
    for(int i =0; i<n; ++i) {
        for(int j = 0; j<n; ++j) {
            if(i==j) {
                cout<<"1";
            }else if(i+j == n-1) {
                cout<<"2";
            }else {
                cout<<"0";
            }
        }
        cout<<endl;
    }
}


int main() {
    cout << "Matrice de taille 5:" << endl;
    dessinerMatrice(5);
    return 0;
}

*/

