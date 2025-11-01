#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Définition de la structure Livre
struct Livre {
    string titre;
    string auteur;
    string langue;
    int year;
};

// Définition de l'enum StatutLivre
// (Enum değerleri DISPONIBLE, EMPRUNTE, RESERVE olmalı)
enum class StatutLivre{
    DISPONIBLE=1, EMPRUNTE=2, RESERVE=3
};


int main() {
    Livre nouveauLivre;
    StatutLivre st;
    int en =0;

    // Lecture des informations du livre
    cout << "Entrez le titre du livre: ";
    std::getline(std::cin,nouveauLivre.titre);
    cout << "Entrez l'auteur du livre: ";
    std::getline(std::cin, nouveauLivre.auteur);
    cout << "Entrez la langue du livre: ";
    std::getline(std::cin, nouveauLivre.langue);
    cout << "Entrez l'année du livre: ";
    std::cin >> nouveauLivre.year;
    cout << "Entrez le statut du livre (1 pour DISPONIBLE, 2 pour EMPRUNTE, 3 pour RESERVE): ";
    std::cin >> en; // int'e oku
    st = static_cast<StatutLivre>(en);

    // Affichage des informations du livre
    cout << "Titre du Livre : " <<nouveauLivre.titre << endl;
    cout << "Auteur du Livre : " <<nouveauLivre.auteur << endl;
    cout << "Langue du Livre : " <<nouveauLivre.langue << endl;
    cout << "Année du Livre : " << nouveauLivre.year<< endl;
    cout << "Statut : ";

    // 'switch' kullanarak enum'u string'e çevirip basın
    switch (st) {
        case StatutLivre::DISPONIBLE: cout<<"DISPONIBLE";break;
        case StatutLivre::EMPRUNTE : cout<<"EMPRUNTE";break;
        case StatutLivre::RESERVE : cout<<"RESERVE"; break;
    };
    cout << std::endl;

    return 0;
}