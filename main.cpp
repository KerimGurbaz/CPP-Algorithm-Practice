#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
int facto(int n) {
    int result = 1;
    if(n<0) {
        cout<<"n ne doit etre inferioer de zero";
    }else if(n ==0 || n==1) {
        return 1;
    }else {

        for(int i =1; i<=n; ++i) {
            if(result > numeric_limits<int>::max()/i) {
                return -1;
            }
            result *=i;
        }
    }
    return result;
}
int factorielle(int n) {
    if(n == 0 || n==1) {
        return 1;
    }else {
        return  (n * factorielle(n-1));
    }
}


int main() {

    int n = 5;

    cout<<factorielle(n)<<endl;
    cout<<facto(n)<<endl;
    return 0;
}