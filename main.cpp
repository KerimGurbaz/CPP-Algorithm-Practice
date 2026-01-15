#include <iostream>
using namespace std;

// bool estHarshad(int n) {
// int orginal =n;
//     int sum =0;
//     while(n>0) {
//       sum += n%10;
//         n /=10;
//     }
//     return orginal %sum ==0;
// }
//
// int main() {
//     int n = 18;
//     if (estHarshad(n)) {
//         cout << n << " est un nombre de Harshad." << endl;
//     } else {
//         cout << n << " n'est pas un nombre de Harshad." << endl;
//     }
//     return 0;
// }

void dessinerSablier(int h) {
int m = h/2;
    for(int i = 0; i<=m; ++i) {
        cout<<string(i, ' ')
        <<string(h-2*i, '*')<<endl;;

    }
    for(int i = m-1; i>=0; --i) {
        cout<<string(i, ' ')
        <<string(h-2*i, '*')
        <<endl;
    }
}

int main() {
    int h;
    cout << "Entrez la hauteur : ";
    cin >> h;
    dessinerSablier(h);
    return 0;
}