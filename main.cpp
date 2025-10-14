#include <iostream>
#include <fstream> // Pour ifstream et ofstream
#include <string>
#include <vector>
using namespace std;

int main() {

    string input_filename, output_filename, keyword;

    cout<<"Entrez le nom du fichier d'entree : ";
    getline(cin, input_filename);

    cout<<"Entrez le nom du fichier sortie : ";
    getline(cin, output_filename);

    cout<<"Entrez le mot-cle a rechercher : ";
    getline(cin, keyword);

    ifstream input_file(input_filename);
    if(!input_file.is_open()) {
        cerr<<"Erreur : impossible d'ouvrir le fichier d'entree"<<input_filename<<endl;
        return 1;
    }

    ofstream output_file(output_filename);
    if(!output_file.is_open()) {
        cerr<<"Erreur imposible de cree le fichier de sortie"<<output_filename<<endl;
        input_file.close();

        return 1;
    }

    string ligne;
    int lines_written =0;
    cout<<"\nFiltrage en cours..."<<endl;
    while(getline(input_file, ligne)) {
        if(ligne.find(keyword) != string::npos) {
            output_file<<ligne<<endl;
            lines_written++;
        }
    }

    input_file.close();
    output_file.close();

    return 0;
}