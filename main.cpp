
#include <iostream>

using namespace std;

enum class Chiffre {
    ZERO, UN , DEUX, TROIS, QUTRE, CINQ, SIX,SEPT, HUIT, NEUF
};
const int nb_chiffres = 10;

void afficher(Chiffre c) {
    switch(c) {
        case Chiffre::ZERO:
            cout<<"ZERO"; break;
        case Chiffre::UN :
            cout<<"UN"; break;
        case Chiffre::DEUX :
            cout<<"DEUX";break;
        case Chiffre::TROIS:
            cout<<"TROIS"; break;
        case Chiffre::QUTRE:
            cout<<"QUTRE"; break;
        case Chiffre::CINQ:
            cout<<"CINQ"; break;
        case Chiffre::SIX:
            cout<<"SIX"; break;
        case Chiffre::SEPT:
            cout<<"SEPT"; break;
        case Chiffre::HUIT:
            cout<<"HUIT"; break;
        case Chiffre::NEUF:
            cout<<"NEUF"; break;
    }
}

Chiffre next(Chiffre c) {
    int val = static_cast<int>(c);

    val = (val +1) % nb_chiffres;
return static_cast<Chiffre>(val);

}

bool operator<(Chiffre a, Chiffre b) {
    return static_cast<int>(a) < static_cast<int>(b);
}

int main() {
    Chiffre a = Chiffre::NEUF;
    Chiffre b = next(a);

    afficher(a);

cout<< (a<b ? " < " : ">=");

    afficher(b);

    return 0;
}