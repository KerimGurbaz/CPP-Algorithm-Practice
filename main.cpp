#include <cstdlib>
#include <iostream>

using namespace std;

void afficher() {
    static int compteur;
    cout<<"Appel numéro "<<++compteur<<endl;

}


int main() {

    for(int i =1; i<=3; ++i) {
        afficher();

    }

    return 0;
}