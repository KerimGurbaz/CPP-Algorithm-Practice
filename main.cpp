#include <cstdint>
#include <iostream>
#include <limits>
using namespace std;

// struct HeureMinute {
//     int8_t heure;
//     int8_t minute;
// };
//
// ostream &operator<<(ostream &os, const HeureMinute &hm) {
//     os << +hm.heure << ":" << +hm.minute;
//     return os;
// }
//
// bool operator<(const HeureMinute &lhs, const HeureMinute &rhs) {
//     if (lhs.heure < rhs.heure) {
//         return true;
//     } else if (lhs.minute < rhs.minute) {
//         return true;
//     } else {
//         false;
//     }
// }
//
// bool operator >(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return !(lhs < rhs);
// }
//
// bool operator <=(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return (rhs > lhs);
// }
//
// bool operator >=(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return !(lhs < rhs);
// }
// bool operator ==(const HeureMinute &lhs, const HeureMinute &rhs) {
//     return (lhs.heure == rhs.heure && lhs.minute == rhs.minute );
// }
//
// bool operator !=(const HeureMinute& lhs, const HeureMinute& rhs) {
//     return !(lhs==lhs);
// }
//
// HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs) {
//     return {int8_t(lhs.heure +rhs.heure +(lhs.minute + rhs.minute)/60), int8_t((lhs.minute + rhs.minute)% 60)};
// }
// HeureMinute& operator+=(HeureMinute& hm , int8_t minute) {
//     hm = {int8_t(hm.heure + (hm.minute + minute)/60),
//     int8_t((hm.minute + minute)%60)};
//     return hm;
// }
//
//
// HeureMinute operator+(HeureMinute hm , int8_t minute) {
//     return hm += minute;
// }
//
// HeureMinute operator+(int8_t minute , HeureMinute hm) {
//     return hm += minute;
// }
//
// HeureMinute& operator++(HeureMinute& hm) {
//     return hm +=1;
// }
// HeureMinute operator++ (HeureMinute& hm, int) {
//     HeureMinute tmp = hm;
//     ++hm;
//     return tmp;
// }
//
// istream& operator>>(istream& is, HeureMinute& h) {
//     char c;
//     int valeur;
//     is>>valeur;
//     h.heure = valeur;
//     is>>c;
//     if(c != ':') {
//         is.setstate(ios::failbit);
//     }
//     is>>valeur;
//     h.minute = valeur;
//
//     if(h.minute >= 60) {
//         cout<<h.minute<<endl;
//         cout<<"fail 60"<<endl;
//         is.setstate(ios::failbit);
//     }
//     return is;
// }
//
//
//
//
// int main() {
//     HeureMinute saisie(const string &msg) {
//         HeureMinute hm;
//         bool erreur;
//         do {
//             cout << msg;
//             cin >> hm;
//             erreur = cin.fail();
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } while (erreur);
//         return hm;
//     }
//
//     HeureMinute hm1 = {12, 34};
//     HeureMinute hm2 = {21, 43};
//
//     cout << boolalpha;
//     cout << hm1 << " <  " << hm2 << "  : " << (hm1 < hm2) << endl;
//     cout << hm1 << " >  " << hm2 << "  : " << (hm1 > hm2) << endl;
//     cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
//     cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
//     cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
//     cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;
//
//     cout << hm1 << " +  " << hm2 << "  : " << (hm1 + hm2) << endl;
//     cout << hm1 << " +  " << 44 << "     : " << (hm1 + 44) << endl;
//     cout << 44 << "    +  " << hm1 << "  : " << (44 + hm1) << endl;
//     cout << hm1 << " += " << 2 << "      : " << (hm1 += 2) << endl;
//
//     cout << "++" << hm1 << "\t\t: " << ++hm1 << endl;
//     cout << hm1 << "++" << "\t\t: " << hm1++ << endl;
//     cout << hm1 << endl;
//
//     cout << endl;
//     HeureMinute hm3 = saisie("heure [hh:mm]: ");
//     cout << "votre saisie : " << hm3 << endl;
// }
