#include <iostream>
using namespace std;

void triangle_creux_centre(int h, char c) {
    for(int i=1; i<=h; ++i) {
        for(int j = 1; j<h-i; ++j) {
            cout<<" ";
        }
        if(i==1) {
            cout<<c;
        }else if(i==h) {
            for(int k=0; k<2*i-1; ++k) {
                cout<<c;
            }
        }else {
            cout<<c;
            for(int k=1; k<=2*i-3; ++k) {
                cout<<" ";
            }
            cout<<c;
        }
        cout<<endl;
    }

}

int main() {
    int h; char c;
    cin >> h >> c;
    triangle_creux_centre(h, c );
    return 0;
}

/*
Exemples:
h=1, c=#
    #
h=2, c=#
   # 
  ###
h=5, c=#
    #
   # #
  #   #
 #     #
#########
*/
