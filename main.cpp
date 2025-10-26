#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void acronyme (const string& s) {
    vector<string>v;
    stringstream ss(s);
    string mot;
    string acr ="";
    while(ss>>mot) {
    v.push_back(mot);
    }
    if(v.empty()) {
        cout<<"Erreur: Aucune entree..";
        return;
    }

    string nom="Votre nom est      :";
    for(int i = 0; i<v.size(); i++) {
        if(i==0) {
            cout<<"Votre prenom est   :"<<v[0]<<endl;
            acr.push_back(toupper(v[i][0]));
        }else if(i != v.size()) {
            nom += v[i] + " ";
            if(i !=v.size()-1) {
                acr.push_back(toupper(v[i][0]));
            }
        }
    }

    cout<<nom;
    acr+=toupper(v[v.size()-1].back());
    cout<<"\nVotre acronyme est :"<<acr;
    cout<<endl;
}




int main() {
    cout<<"Entrez votre prenom et votre nom : ";
    string prenomNom;

   getline(cin, prenomNom);
    acronyme(prenomNom);



    return 0;
}