

#include <iostream>
using namespace std;


// class Panier {
//     double total;
//
// public:
//     Panier() : total(0.0){}
//     Panier(double total) : total(total){}
//
//     Panier& operator +=(double prix) {
//         total+= prix;
//         return *this;
//     }
//
//     friend ostream& operator<<(ostream &os , const Panier& p) {
//         os<<"Total : "<<p.total;
//         return os;
//     }
// };
//
//
// int main() {
//     Panier p;
//     (p += 10.5) += 20.0;
//
//     cout<<p;
// }