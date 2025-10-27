#include <string>
#include <utility>
#include <iostream>
#include <iomanip>

using namespace std;




int main() {
    const int w_nom =13;
    const int w_age =5;
    const int w_note =15;
    const int w_status =10;


    cout<<"Entrez le nom de l'etudiant.e :"<<endl;
    string nom;
    getline(cin, nom);

    cout<<"Entrez l'age de l'etudiant.e :"<<endl;
    int age;
    do {
        cin>>age;

        if((age < 1 || age > 100) ) {
            cout<<"Saisie invalide. Veuillez entrer un entier entre 1 et 100\n";
            cin>>age;
        }
    } while((age < 1 || age > 100));

    double math;
    cout<<"Entrez la note en mathematiques (max. 6)"<<endl;
    cin>>math;
    double prg1;
    cout<<"Entrez la note en PRG1 (max. 6):"<<endl;
    cin>>prg1;
    double moyenne = (math + prg1) /2.0;

    cout<<setw(w_nom)<<left<<"Nom";
    cout<<setw(w_age)<<right<<"Age";
    cout<<setw(w_note)<<"Note Math";
    cout<<setw(w_note)<<"Note PRG1";
    cout<<setw(w_status)<<right<<"Admis\n";
    cout<<string(60, '-');
    cout<<endl;
    cout<<setw(w_nom)<<left<<nom;
    cout<<setw(w_age)<<right<<age;
    cout<<setw(w_note)<<math;
    cout<<setw(w_note)<<prg1;
    cout<<setw(w_status-2)<<(moyenne < 3.8 ? "NON" : "OUI");
    cout<<endl;
    cout<<string(60, '-');
    cout<<endl;
    cout<<setw(w_nom)<<left<<"Moyenne"<<setw(w_note)<<moyenne<<endl;
    cout<<setw(w_nom)<<left<<"Resultat"<<setw(w_status)<<(moyenne < 3.8 ? "Non Admis" : "Admis") <<endl;














    return 0;
}
