#include <iostream>
#include <vector>
#include <string>

using namespace std;

 bool recherche_dichotomique(const vector<int>& v_trie, int cible) {
     int low =0;
     int hight =v_trie.size()-1;
     int mid = hight/2;

     if(cible<=v_trie[mid]) {
         for(size_t i =0; i<mid; ++i) {
             if(v_trie[i] == cible) {
                 return true;
             }
         }
         return false;
     }else {
         for(size_t j = mid; j<v_trie.size();++j) {
             if(v_trie[j] == cible) {
                 return true;
             }
         }
         return false;
     }
 }


int main() {
    vector<int> v = {2, 5, 7, 8, 11, 12, 45, 100};

    cout << boolalpha;
    cout << "Test 11: " << recherche_dichotomique(v, 11) << endl; // Ortada
    cout << "Test 2:  " << recherche_dichotomique(v, 2)  << endl; // Başta
    cout << "Test 100: " << recherche_dichotomique(v, 100) << endl; // Sonda
    cout << "Test 13: " << recherche_dichotomique(v, 13) << endl; // Yok
    cout << "Test 1:  " << recherche_dichotomique(v, 1)  << endl; // Yok (Düşük)
    cout << "Test 200:" << recherche_dichotomique(v, 200) << endl; // Yok (Yüksek)
}