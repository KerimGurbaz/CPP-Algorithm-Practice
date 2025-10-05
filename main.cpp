#include <iostream>
using namespace std;

/*
* int main() {
while(true) {
    cout<<">> ";
    int a, b;
    char op ;
    cin>>a>>b>>op;
    if(op =='q' || op =='Q') {
        break;
    }
        int result;
        switch(op) {
            case '+': result = a + b ;break;
            case '-': result=  a - b ;break;
            case '*': result = a * b ;break;
            case '/': if(b==0) {
                cout<<"erreur : division par zero ";
                continue;
            }else {
                     result =  a/b;break;
            }
            default:
                cout << "Erreur : Operateur '" << op << "' inconnu." << endl;
            break;
        }

cout<<result<<endl;;
}

    return 0;
}
 */


/*
* int lireNoteValide(int n) {
return !(n>0 && n<11);
}

int main() {

   int num;

    do {
        cout<<"enter un number : ";
        cin>>num;
        if(lireNoteValide(num)) {
                   cout<<num<<endl;
        }
    }while(lireNoteValide(num));
}
 */


/*    int main() {
        int num;
        int tahmin;
        int numInf =1;
        int numSup =20;
        int milieu;
        int count(0);

        cout<<"Entrez un number : ";
        cin>>num;
        char reponse;



        do {
            count++;
            milieu = (numInf + numSup) / 2;
            cout<<"tahmininiz "<<milieu <<" den kucuk ve esit mi ? ";
            cin>>reponse;
            if(reponse == 'o' ||reponse == 'O') {
                numSup = milieu;

            }else {

                numInf =milieu + 1;

            }
        }while(num != milieu);

        cout<<"tahmininiz"<< milieu<<"tebrikler "<<count<<" denemede buldunuz.";

    }*/


/*
* int main() {
    int number =5;
    if(number<1 || number>12) {
        return 0;
    }else {
        switch(number) {
            case 12 :case 1: case 2: cout<<"Hiver"; break;
            case 5 :case 4: case 3: cout<<"Printemps"; break;
            case 6 :case 8: case 7: cout<<"été"; break;
            default:cout<<"Automne";break;
    }
    }
    return 0;
}
int racineNumerique(int n) {
    int sum = 0;
     while(n>0 ) {
         int reste = n%10;
         sum += reste;
         n /=10;
     }
    return sum > 10 ? racineNumerique(sum) : sum;
}

int lireNoteValide() {
    int note;
    do {
        cout<<"Entrez une note [1-10] : ";
        cin>>note;
    }while(note < 1 || note > 10);
    return note;
}
int racineNumerique2(int n) {
    while(n>=10) {
        int somme =0;
        while (n>0) {
            somme += n%10;
            n/=10;
        }
        n = somme;
    }
    return n;
}

int main() {
    int n =942;

    cout<<racineNumerique(n);

    cout << "Notunuzu giriniz." << endl;
    int notum = lireNoteValide(); // main ne kadar temiz, görüyor musun?
    cout << "Gecerli not: " << notum << endl;

    srand(time(0));
    int nombreseCret = 1 + rand()%100;
    int essai = 0;
    int compteur = 0;

    cout << "J'ai choisi un nombre entre 1 et 100. Devinez!" << endl;

    while(essai != nombreseCret) {
        cout<<"Votre essai : ";
        cin >>essai;
        compteur++;
        if(essai < nombreseCret) cout<<"Plus grand !"<<endl;
        else if(essai > nombreseCret) cout<<"Plus petit ! "<<endl;
    }
    cout<<"Bravo ! Trouve en "<<compteur<<essai;
    return 0;
}
 */
void allerAuNord() {
    cout<<"allerAuNord"<<endl;
}
void verifierInventaire() {
    cout<<"Envanterde bir kılıç ve bir iksir var."<<endl;
}


int main() {

int num;

    do {
        cout<<"1. Kuzeye git "<<endl;
        cout<<"2. Kuzeye git "<<endl;
        cout<<"3. Kuzeye git "<<endl;
        cout<<"Choisir un num entre 1-3 : ";
        cin>>num;
        switch (num) {
            case 1: allerAuNord();break;
            case 2: verifierInventaire(); break;
            case 3: break;
            default: cout<<"Geçersiz seçim"; break;
        }
    }while(num>=1 && num<=3);


    return 0;
}
