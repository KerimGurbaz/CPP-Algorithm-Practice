#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <sstream>
#include <cctype>
using namespace std;




int main() {
    cout<<"Entrez le nom et le numero de la rue : ";
    string addresse;

   getline(cin, addresse);
    string rue ="";
    int i = 0;

    for(; i<addresse.size()-1; ++i) {
        if(isalpha(addresse[i]) && isdigit(addresse[i+1])) {
            rue = addresse.substr(i);
            break;
        }
    }
    cout<<"Le nom de la rue est :"<<addresse.substr(0, i)<<endl;
    cout<<"Le no de la rue est  :"<<rue;
    return 0;
}