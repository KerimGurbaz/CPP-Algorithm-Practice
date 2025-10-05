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
        int num;;
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

 */
int racineNumerique(int n) {
    int sum = 0;
     while(n>0 ) {
         int reste = n%10;
         sum += reste;
         n /=10;
     }
    return sum > 10 ? racineNumerique(sum) : sum;
}


int main() {
    int n =942;

    cout<<racineNumerique(n);

    return 0;
}