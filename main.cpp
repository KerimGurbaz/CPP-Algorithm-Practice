// #include <iostream>
// using namespace std;
// class Mouchard {
//     int id;
// public:
//     // Constructeur par défaut (délégué)
//     Mouchard() : Mouchard(0) { cout << "D"; }
//     // Constructeur paramétré
//     Mouchard(int i) : id(i) { cout << "C" << id; }
//     // Constructeur de copie
//     Mouchard(const Mouchard& m) : id(m.id) { cout << "Y"; }
//     // Destructeur
//     ~Mouchard() { cout << "~" << id; }
// };
// int main() {
//     cout << "Start/";
//     {
//         Mouchard m1(1);
//         Mouchard m2;
//         cout << "/Mid/";
//         {
//             Mouchard m3(3);
//             Mouchard m4 = m1; // Attention: Copie !
//         }
//         cout << "/EndBlock";
//     }
//
//     cout << "/Fin";
//
//     return 0;
//
// }
//


