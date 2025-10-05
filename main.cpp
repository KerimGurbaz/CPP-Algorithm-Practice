#include <iostream>
#include <cctype>
#include <limits>

using namespace std;
/*
*    int number;
    cin>>number;

    switch(number) {
        case 1: cout<< "Saldir";break;
        case 2: cout<< "Savun";break;
        case 3: cout<< "Kac";break;
        case 4: cout<< "Iyiles";break;
        default : cout<<"Gecersiz komut"; break;
    }
 */
/*
* int sum = 0;
    int num = 0;

    while(true) {
        cout<<"enter un number : ";
        cin>>num;
     if(num == -1 || (num < -1)) {
         break;
     }
        sum += num;
        cout<<"total est "<< sum <<endl;
    }
    cout<<"total est "<< sum <<endl;
 */

/*
* int num;
    do {
        cout<<"Entrez un number [1-10] : "<<endl;
        cin>>num;

    }while(num<1 || num>10);

 */

/*
* bool estPair(int nombre) {
    if(nombre % 2) {
        return false;
    }
    return true;
}
int main() {
   cout<<boolalpha<< estPair(115);
    return 0;
}
 */

/*
* bool estPair(int nombre) {
    if(nombre % 2) {
        return false;
    }
    return true;
}

int main() {

    int sum = 0;
    int num = 0;

    while(true) {
        cout<<"enter un number : ";
        cin>>num;
        if(num == -1 || (num < -1)) {
            break;
        }else if(estPair(num)) {
            sum += num;
        cout<<"total est "<< sum <<endl;
        }

    }
    cout<<"total est "<< sum <<endl;


    return 0;
}
 */
