
#include <iostream>

using namespace std;

enum class Chiffre {
    ZERO, UN , DEUX, TROIS, QUTRE, CINQ, SIX,SEPT, HUIT, NEUF
};

Chiffre avancer(Chiffre c, int pos) {
    int val = static_cast<int>(c);
    val = (val + pos) %10;
    if(pos<0) {
        val = ( val - pos +10)%10;
    }
    return static_cast<Chiffre>(val);
}

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





int main() {
    Chiffre c = Chiffre::TROIS;

    cout << "Départ : ";
    afficher(c);
    cout << endl;

    Chiffre d = avancer(c, -4); // 🧭 recule de 4 positions
    cout << "Après avancer(c, -4) → ";
    afficher(d);
    cout << endl;

    Chiffre e = avancer(c, 6); // 🧭 avance de 6 positions
    cout << "Après avancer(c, 6) → ";
    afficher(e);
    cout << endl;

    return 0;
}
