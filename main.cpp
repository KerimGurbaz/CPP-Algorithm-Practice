/*
* #include <iostream>
#include <cctype>

using namespace std;

int main() {
    cout<<"Entrez un caractere : ";
    char c ;
    cin>>c;
    cout<<"Code ASCII de "<<c<<"    : "<<static_cast<int>(c)<<endl;
    cout<<c <<" est une lettre de l'alphabet :"<<(isalpha(c)?"vrai":"false")<<endl;
    cout<<c <<"  est une lettre minuscule :"<<(islower(c)?"vrai":"false")<<endl;
    cout<<c <<"  est une chiffre :"<<(!isalpha(c) && isalnum(c))?"vrai":"false"<<endl;
    cout<<c <<"  est un caractere de ponctuation :"<<(ispunct(c)?"vrai":"false")<<endl;

    return 0;
}
 */

#include <iostream>
#include <cctype>   // Requis pour isalpha, islower, isdigit, ispunct
#include <iomanip>  // Requis pour std::setw (pour un meilleur formatage)

using namespace std;

int main() {
    cout << "Entrez un caractere : ";
    char c;
    cin >> c;
    cout << endl; // Pour sauter une ligne, comme dans l'exemple

    // Note : Il est techniquement plus sûr de caster 'c' en 'unsigned char'
    // avant de le passer aux fonctions <cctype>. Voir l'analyse ci-dessous.
    unsigned char uc = static_cast<unsigned char>(c);

    // --- Affichage des résultats ---

    // Utiliser std::setw pour aligner les ':'
    // ou ajouter des espaces manuellement comme dans l'exemple.
    // Nous allons utiliser l'alignement manuel pour coller à l'exemple.

    cout << "Code ASCII de '" << c << "'                   : "
         << static_cast<int>(c) << endl;

    cout << "'" << c << "' est une lettre de l'alphabet    : "

         << (isalpha(uc) ? "vrai" : "faux") << endl;

    cout << "'" << c << "' est une lettre minuscule        : "

         << (islower(uc) ? "vrai" : "faux") << endl;

    cout << "'" << c << "' est un chiffre                  : "

         << (isdigit(uc) ? "vrai" : "faux") << endl;

    cout << "'" << c << "' est un caractere de ponctuation : "

         << (ispunct(uc) ? "vrai" : "faux") << endl;

    return 0;
}