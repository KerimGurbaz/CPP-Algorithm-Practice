#include <iostream>
#include <limits>
using namespace std;

long long int facto(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    long long int result =1;
    for(int i=2; i<= n; ++i) {
        if(result > numeric_limits< long long int>::max() / i ) {
            return -1;
        }else {
            result *=i;
        }

    }
    return result;
}
int main() {
int num ;

    do {
        cout<<"Enrez un number entre [0 -50] : "<<endl;
        cin>>num;
    }while(num<0 || num>50);

    if(num>1) {
        if(facto(num)) {
            cout<<num<<"! = ";
            for(int i=0; i<=num; ++i) {
                cout<<i<< (i == num ? " = " : " * ");

            }
        }
    }



    cout<<facto(num);

    int cnt = 0;
for ( int i = 0; i < 2; ++i ) {
 for ( int j = i; j < 3; ++j ) {
 cnt++;
 }
 cnt--;
}
cout << cnt;



    return 0;
}