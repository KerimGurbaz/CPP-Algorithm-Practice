#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
 string filename;
    cout <<" entrez le nom du fichier de sortie..";
    getline(cin, filename);

    ifstream check_file(filename);
    if(check_file.is_open()) {
        cerr<<"Erreur le fichier "<<filename<<"existe deja:"<<endl;
        check_file.close();
        return 1;
    }


    ofstream output_file(filename);
    if(!output_file.is_open()) {
        cerr<<"erreur critique :  impossible de creer de fichier"<< filename<<endl;
        return 1;
    }

    cout<<"Entrez le texte a enregistrer..."<<endl;
    string line;
    while (getline(cin, line)) {
        if(line== "#exit#") {
            break;
        }

        output_file<<line<<endl;
    }
cout<<"Saisie est termine.."<<endl;
    output_file.close();

    return 0;
}