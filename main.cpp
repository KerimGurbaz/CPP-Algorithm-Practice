#include <iostream>
#include <limits>
#include <cmath>
#include <cctype>

using namespace std;

int lire_entier(const string& n) {
    string s = n;
    int num =static_cast<int>(s);
    return num;
}

int syracuse(int & n) {
    int count =0;
if(n>0) {

   do {
       ++count;
       if(n%2==0) {
           n/=2;
       }else {
           n = n*3+1;
       }
   }while(n!=1);
}
    else {
        cout<<"La valeur n'est pas valide";
    }
    return count;
}


int main() {

    const string msg = "Veuillez saisir une valeur : ";
    int i = lire_entier(msg);
    cout << "La suite de Syracuse pour n = " << i << " : ";
    int nb_iteration = syracuse(i);
    cout << "\nLe nombre d'iterations = " << nb_iteration;
    return 0;
}