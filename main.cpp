
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;


int main() {

    for(int i = 1;  i<=3; ++i) {
        for(int j = 1; j<= 4; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i =1; i<=4; ++i) {
        for(int j =1; j<=i; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i = 1; i<=3; ++i) {
        for(int j= 2; j<=5; ++j) {
            if(j%2 == 0) {
                cout<<"o";
            }else {
                cout<<"x";
            }
        }
        cout<<endl;
    }


    for(int i = 1; i<=3; ++i) {
        for(int j=1 ; j<=5; ++j) {
            if((i+j) %2 == 0) {
                cout<<"o";
            }else {
                cout<<"x";
            }
        }
        cout<<endl;
    }

    int hauter;
    do {
        cout << "Hauteur du triangle (h > 0) : ";
        cin>>hauter;
    }while(hauter<=0);

    for(int i = 1; i<=hauter; ++i) {
        for(int j = 0; j<hauter-i; ++j) {
            cout<<" ";
        }
        for(int k = 0; k<i*2-1; ++k) {
            cout<<"*";
        }
        cout<<endl;
    }



}