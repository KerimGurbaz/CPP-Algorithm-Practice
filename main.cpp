#include <iostream>
#include <string>
using namespace std;
#include <iomanip>

enum class StatutLivre{DISPONIBLE=0, EMPRUNTE, RESERVE};
struct Livre {
    string titre;
    string auteur;
    int anne;
    StatutLivre statut;
};

void afficher_livre(const Livre& l) {
    cout<<left;

    cout<<setw(8)<<"Titre  : "<<l.titre<<endl;
    cout<<setw(8)<<"Auteur : "<<l.auteur<<endl;
    cout<<setw(8)<<"Annee  : "<<l.anne<<endl;
    cout<<setw(8)<<"Statut : ";

        switch(l.statut) {
            case StatutLivre::DISPONIBLE : cout<<"DISPONIBLE";break;
            case StatutLivre::EMPRUNTE : cout<<"EMPRUNTE";break;
            case StatutLivre::RESERVE : cout<<"RESERVE";break;

            default:cout <<"inconnu";break;
    }
    cout<<endl;
    cout<<endl;

}
void changer_statut(Livre& l, StatutLivre nouveau) {
 l.statut = nouveau;

}



int main() {
    Livre l1{"Cien Años de Soledad", "Gabriel García Márquez", 1967, StatutLivre::DISPONIBLE};
    afficher_livre(l1);
    changer_statut(l1, StatutLivre::EMPRUNTE);
    afficher_livre(l1);
}
