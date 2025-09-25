#include <iostream>
using namespace std;

int main() {

    double note;

        cout<<"Entrez la note UNIGE "<<endl;
        cin>>note;
        if(note < 0 or note>6.00) {
           cout<<"Erreur";
        }else {
            if(note>=5.25) {
                cout<<"A";
            }else if(note >= 4.75) {
                cout<<"B";
            }else if(note >= 4.50) {
                cout<<"C";
            }else if(note >= 4.25) {
                cout<<"D";
            }else if(note >= 4.) {
                cout<<"E";
            }else{
                cout<<"F";
            }
        }
    return 0;
}