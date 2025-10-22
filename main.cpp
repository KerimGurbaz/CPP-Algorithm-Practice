
#include <iostream>;

using namespace std;



int main() {


    enum class JOUR {
        LUNDI, MARDI, MECREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE
    };

    JOUR jour = JOUR::JEUDI;

    string chaine = "jour de la semaine : ";

    switch(jour) {
        case JOUR::JEUDI : chaine += "jeudi"; break;
        case JOUR::LUNDI : chaine += "lundi"; break;
        case JOUR::MARDI : chaine += "mardi"; break;
        case JOUR::MECREDI : chaine += "mecredi"; break;
        case JOUR::VENDREDI : chaine += "vendredi"; break;
        case JOUR::SAMEDI : chaine += "samedi"; break;
        case JOUR::DIMANCHE : chaine += "dimanche"; break;
        default : chaine += "jour inconnu";

    }

    cout<<chaine<<endl;

    return 0;
}