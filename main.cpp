#include <iostream>
#include <array>
#include <iomanip>
#include <cstdint>
#include <string>
#include <limits>
#include <cstdint>
using namespace std;

struct HeureMinute {
    int8_t heure;
    int8_t minute;
};

int toMinutes(const HeureMinute &hm) {
    return hm.heure * 60 + hm.minute;
}

HeureMinute fromMinutes(int totalMinutes) {
    return HeureMinute{
        static_cast<int8_t>(totalMinutes / 60),
        static_cast<int8_t>(totalMinutes % 60)
    };
};

ostream &operator<<(ostream &os, const HeureMinute &hm) {
    os << +hm.heure << ":" << setfill('0') << setw(2) << +hm.minute;
    return os;
}

istream &operator>>(istream &is, HeureMinute &hm) {
    int h, m;
    char sep;

    if (is >> h >> sep >> m) {
        if (sep == ':') {
            hm.heure = static_cast<int8_t>(h);
            hm.minute = static_cast<int8_t>(m);
        } else {
            is.setstate(ios::failbit);
        }
    }
    return is;
}

bool operator<(const HeureMinute &lhs, const HeureMinute &rhs) {
    return toMinutes(lhs) < toMinutes(rhs);
}

bool operator>(const HeureMinute &lhs, const HeureMinute &rhs) {
    return rhs < lhs;
}

bool operator<=(const HeureMinute &lhs, const HeureMinute &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const HeureMinute &lhs, const HeureMinute &rhs) {
    return !(lhs < rhs);
}

bool operator==(const HeureMinute &lhs, const HeureMinute &rhs) {
    return toMinutes(lhs) == toMinutes(rhs);
}

bool operator!=(const HeureMinute &lhs, const HeureMinute &rhs) {
    return !(lhs == rhs);
}

HeureMinute operator+(const HeureMinute& lhs, const HeureMinute& rhs) {
    return fromMinutes(toMinutes(rhs) + toMinutes(lhs));
}

HeureMinute operator+(const HeureMinute &lhs, int minutes) {
    return fromMinutes(toMinutes(lhs) + minutes);
}

HeureMinute operator+(int minutes, const HeureMinute &rhs) {
    return rhs + minutes;
}

HeureMinute &operator +=(HeureMinute &lhs, int minutes) {
    lhs = lhs + minutes;
    return lhs;
}

HeureMinute &operator++(HeureMinute &hm) {
    hm += 1;
    return hm;
}

HeureMinute operator++(HeureMinute& hm, int) {
    HeureMinute temp =hm;
    ++hm;
    return temp;
}


HeureMinute saisie(const string& msg) {
    HeureMinute hm;
    bool erreur;
    do {
        cout<<msg;
        cin>> hm;
        erreur = cin.fail();
        if(erreur) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return hm;
        }
    }while(erreur);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return hm;
}

int main() {
    HeureMinute hm1 = {12, 34};
    HeureMinute hm2 = {21, 43};

    cout << boolalpha;
    cout << hm1 << " <  " << hm2 << "  : " << (hm1 <  hm2) << endl;
    cout << hm1 << " >  " << hm2 << "  : " << (hm1 >  hm2) << endl;
    cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
    cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
    cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
    cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;

    cout << hm1 << " +  " << hm2 << "  : " << (hm1 +  hm2) << endl;
    cout << hm1 << " +  " << 44  << "     : " << (hm1 +  44 ) << endl;
    cout << 44  << "    +  " << hm1 << "  : " << (44  +  hm1) << endl;
    cout << hm1 << " += "  << 2 << "      : " << (hm1+=2 )    << endl;

    cout << "++" << hm1  << "\t\t: " << ++hm1 << endl;
    cout << hm1  << "++" << "\t\t: " << hm1++ << endl;
    cout << hm1 << endl;

    cout << endl;
    // Note: J'ai légèrement nettoyé la fonction saisie pour le buffer,
    // mais la logique reste celle demandée pour tester l'opérateur >>
    HeureMinute hm3 = saisie("heure [hh:mm]: ");
    cout << "votre saisie : " << hm3 << endl;
}