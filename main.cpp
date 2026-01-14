

#include <iostream>
using namespace std;


// class Panier {
//     double total;
//
// public:
//     Panier() : total(0.0){}
//     Panier(double total) : total(total){}
//
//     Panier& operator +=(double prix) {
//         total+= prix;
//         return *this;
//     }
//
//     friend ostream& operator<<(ostream &os , const Panier& p) {
//         os<<"Total : "<<p.total;
//         return os;
//     }
// };
//
//
// int main() {
//     Panier p;
//     (p += 10.5) += 20.0;
//
//     cout<<p;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
//
// class Trace {
//     int id;
// public:
//     Trace(int i) : id(i) { cout << "C" << id; }
//     ~Trace()             { cout << "D" << id; }
// };
//
// void fonction(Trace t) { // Passage par valeur
//     cout << "F";
// }
//
// int main() {
//     Trace t1(1);
//     {
//         Trace t2(2);
//         fonction(t2);
//     }
//     cout << "Fin";
//
//     vector<int> v = {1, 2, 3, 1, 4};
//
//     // On veut supprimer tous les '1'
//     auto it = remove(v.begin(), v.end(), 1);
//
//     cout << v.size() << ":";
//     for(auto i = v.begin(); i != v.end(); ++i) {
//         cout << *i;
//     }
//
//
//
//     return 0;
// }

// #include <iomanip>
//
//
// class Portefeuille {
// private:
//     double solde;
//
// public:
//
//     Portefeuille(double solde = 0.0) : solde(solde){}
//
//     Portefeuille& operator +=(const Portefeuille& other);
//     friend ostream& operator <<(ostream&os, const Portefeuille& p);
//
//     double getSolde()const;
//
// };
//
// Portefeuille operator+(Portefeuille lhs, const Portefeuille& rhs) {
//     lhs += rhs;
//     return lhs;
// }
//
// bool operator==(const Portefeuille& lhs, const Portefeuille& rhs) {
//     return lhs.getSolde() == rhs.getSolde();
// }
//
//
// Portefeuille& Portefeuille::operator +=(const Portefeuille& other) {
//     this->solde += other.solde;
//     return *this;
// }
//
// ostream& operator <<(ostream&os, const Portefeuille& p) {
//     os<<"Solde : "<<fixed<<setprecision(2)<<p.solde;
//     return os;
// }
// double Portefeuille::getSolde()const {
//     return solde;
// }
//
// int main() {
//     Portefeuille p1(100.0);
//     Portefeuille p2(50.0);
//
//     // Test += Chaining
//     (p1 += 20.0) += 10.0;
//     cout << "p1 (130 olmali): " << p1 << endl;
//
//     // Test + (Yeni nesne)
//     Portefeuille total = p1 + p2; // 130 + 50
//     cout << "Total (180 olmali): " << total << endl;
//
//     // Orijinaller bozulmamali
//     cout << "p1 check: " << p1 << endl;
//
//     // Test Constructor Validasyonu
//     Portefeuille pNegatif(-500);
//     cout << "Negatif Cuzdan: " << pNegatif << endl;
//
//     // Test ==
//     if (total == Portefeuille(180.0)) {
//         cout << "Esitlik testi basarili." << endl;
//     }
//
//     return 0;
// }
//

// #include <cstring>
// #include <string_view>
//
// template<typename T>
// T minimum(T a, T b) {
//     return a<b ?a : b;
// }
// string_view minimum(string_view a, string_view b) {
//     return a<b ?  a : b;
// }
// // template<>
// // const char*minimum(const char* a, const char* b) {
// //     if(strlen(a) <strlen(b)) {
// //         return a;
// //     }else {
// //         return b;
// //     }
// // }
// int main() {
//     cout<<minimum(10, 20);          // Retourne 10
//    cout<< minimum("Poms", "Apple"); // Retourne "Poms" (car longueur 4 < 5)
// }
// #include <vector>
//
// class TableauInt {
// private:
//     vector<int> data;
// public:
//     TableauInt(size_t s) : data(s, 0){}
//
//     int operator[](size_t i)const {
//         return data[i];
//     }
//
//     int& operator[](size_t i){
//     return data[i];
//     }
//
// };
//
// void test(const TableauInt& ct, TableauInt& t) {
//     int x = ct[0]; // 'const' versiyon çalışır (Güvenli Okuma)
//     t[0] = 5;      // 'non-const' versiyon çalışır (Yazma İzni)
// }
//
// class Bufer {
//     int* ptr;
//     size_t taille;
//
// public:
//     Bufer(size_t t) : taille(t) {
//         ptr = new int[t];
//         fill(ptr, ptr+taille, 0);
//     }
//     ~Bufer() {
//         delete[] ptr;
//     }
//     Bufer (const Bufer& autre) : taille(autre.taille) {
//         ptr = new int[taille];
//
//         copy(autre.ptr, autre.ptr+taille, ptr);
//
//     }
//
//     Bufer& operator =(const Bufer& autre) {
//         if(this == &autre) {
//             return *this;
//         }
//
//         delete []ptr;
//         taille = autre.taille;
//         ptr = new int[taille];
//         copy(autre.ptr, autre.ptr+taille, ptr);
//
//         return *this;
//
//     }
//
//     void set(size_t index, int val) {
//         if(index < taille) {
//             ptr[index] = val;
//         }
//     }
//
//     friend ostream& operator<<(ostream& os, const Bufer& b) {
//         for(size_t i = 0; i<b.taille; ++i) {
//             os<<b.ptr[i];
//         }
//         return os;
//     }
// };

#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest;

 copy_if(src.begin(), src.end(), back_inserter(dest),[](int &n) {
  return n%2 == 0;
 });

    transform(dest.begin(), dest.end(), dest.begin(), [](int n) {
        return n*2;
    });

    for(int c : dest) {
        cout<<c<<" ";
    }




}