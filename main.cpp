//
//
// #include <iostream>
// #include <stdexcept>
// using namespace std;
//
// class Fraction {
// private:
//     int num;
//     int den;
//
//     int pgcd(int a, int b)const;
//     void simplifier();
//
// public:
//     Fraction(int num = 0, int den =1);
//
//     Fraction operator+(const Fraction& autre)const;
//
//     bool operator==(const Fraction& autre)const;
//
//     explicit operator double()const;
//
//     friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
//
// };
//
//
// #include <numeric>
// #include <cmath>
//
// Fraction::Fraction(int num , int den ) : num(num), den(den) {
//     if(den == 0) {
//         throw std::invalid_argument("Erreur");
//     }
//     if(den <0) {
//         num = -num;
//         den = -den;
//     }
//     simplifier();
// }
//
// void Fraction::simplifier() {
//     int div = pgcd(abs(num), den);
//     num /= div;
//     den /= div;
// }
//
// Fraction Fraction::operator+(const Fraction& autre)const {
//     int n_num = (num * autre.den) + (autre.num * den);
//     int d_den = den * autre.den;
//
//     return Fraction(n_num, d_den);
// }
//
// bool Fraction::operator==(const Fraction& autre)const {
//     return (num ==autre.num) && (den == autre.den);
// }
//
// Fraction::operator double() const {
//     return static_cast<double>(num) / static_cast<double>(den);
// }
//
// std::ostream& operator<<(std::ostream& os, const Fraction& f){
// os<<f.num<<"/"<<f.den;
//     return os;
// }
// #include <iostream>
//
// using namespace std;
//
// int main() {
//     try {
//         Fraction f1(1, 2);
//         Fraction f2(2, 4);
//         Fraction f3(1, 3);
//
//         if (f1 == f2) cout << "Egaux" << endl;
//
//         Fraction res = f1 + f3; // (1*3 + 1*2) / 6 = 5/6
//         cout << f1 << " + " << f3 << " = " << res << endl;
//         cout << "Decimal: " << double(res) << endl;
//
//         Fraction f4(1, 0); // Exception
//     } catch (std::exception& e) {
//         cout << e.what() << endl;
//     }
// }
//
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <stdexcept>
//
// using namespace std;
//
// struct Mesure {
//     int id;
//     string type;
//     double value;
// };
//
// vector<Mesure> lire_mesures(const string& nomFichier) {
//     vector<Mesure> resultats;
//     ifstream in(nomFichier);
//
//     if(!in.is_open()) {
//         cerr<<"FATAL l'ouverture de fichier...";
//         return resultats;
//     }
//
//     string ligne;
//
//     while(getline(in, ligne)) {
//         if(ligne.empty()) continue;
//
//         stringstream ss(ligne);
//         string segment;
//         vector<string> tokens;
//
//         while(getline(ss, segment, '|')) {
//             tokens.push_back(segment);
//         }
//
//         if(tokens.size() <3) {
//             cerr<<" eksik sutun satir atlaniyor.."<<ligne<<endl;
//             continue;
//         }
//
//         try {
//             Mesure m;
//             m.id = stoi(tokens[0]);
//             m.type = tokens[1];
//             m.value = stod(tokens[2]);
//             resultats.push_back(m);
//         }catch(const exception& e) {
//             continue;
//         }
//     }
//
//     in.close();
//     return resultats;
// }

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;


// struct Produit {
// std::string nom;
//     double prix;
//     int quantite;
// };
//
// std::vector<Produit>charger_inventaire(const std::string& nomFichier) {
//
//     vector<Produit> inventaire;
//
//     ifstream fichier(nomFichier);
//     if(!fichier.is_open()) {
//         cerr<<"Error, ouverture de fichier... "<<nomFichier<<endl;
//         return inventaire;
//     }
//
//     string ligne;
//
//     while(getline(fichier, ligne)) {
//         if(ligne.empty())continue;
//
//         stringstream ss(ligne);
//         string segment;
//         vector<string> colonnes;
//
//         while(getline(ss, segment, ';')) {
//             colonnes.push_back(segment);
//         }
//         if(colonnes.size() != 3) {
//             cerr<<"Warn,.. "<<ligne<<endl;
//             continue;
//         }
//
//         try {
//             Produit p;
//             p.nom = colonnes[0];
//
//             p.prix = stod(colonnes[1]);
//             p.quantite = stoi(colonnes[2]);
//
//             inventaire.push_back(p);
//         }catch(const exception& e) {
//             cerr<<"Warn ... "<<e.what();
//             continue;
//         }
//     }
//     fichier.close();
//     return inventaire;
// }
//
//
// int main() {
//     // Fichier:
//     // Pomme;1.20;50
//     // Poire;invalid;10
//     // Banane;0.90;100
//
//     vector<Produit> stock = charger_inventaire("data.csv");
//     for(const auto& p : stock) {
//         cout << p.nom << ": " << p.prix * p.quantite << " CHF" << endl;
//     }
// }

// class Compteur {
// private:
//     int value;
// public:
//     Compteur(int v = 0) : value(v){}
//     explicit operator int()const {
//         return value;
//     }
//
//     Compteur& operator++() {
//         ++value;
//         return *this;
//     }
//
//     Compteur operator++(int) {
//         Compteur temps(*this);
//         ++value;
//         return temps;
//     }
//
//     Compteur& operator+=(const Compteur& c) {
//         value += c.value;
//         return *this;
//     }
//
//     friend Compteur operator+(Compteur lhs, const Compteur& rhs) {
//         lhs+= rhs;
//         return lhs;
//     }
//
//     bool operator==(const Compteur& other)const {
//         return  value == other.value;
//     }
//
//     bool operator!=(const Compteur&other)const {
//         return !(value == other.value);
//     }
//
//     friend ostream& operator<<(ostream&os, const Compteur& c) {
//         os<<c.value;
//         return os;
//     }
// };
//
// int main() {
//     Compteur c1(10);
//     Compteur c2(5);
//
//     // Test: Operator + ve <<
//     Compteur c3 = c1 + c2;
//     cout << "c1 + c2 = " << c3 << endl; // 15
//
//     // Test: Prefix vs Postfix
//     cout << "Prefix (++c1): " << ++c1 << endl; // 11 yazar, değeri 11 olur
//     cout << "Postfix (c1++): " << c1++ << endl; // 11 yazar (eski değer), değeri 12 olur
//     cout << "Son durum c1: " << c1 << endl;     // 12
//
//     // --- KRİTİK TEST: Explicit Conversion ---
//
//     // int x = c1;       // HATA! (Derleme zamanı hatası: no suitable conversion function)
//
//     int y = int(c1);            // OK (C-Style Cast)
//     int z = static_cast<int>(c1); // OK (C++ Style Cast - Önerilen)
//
//     cout << "Explicit cast sonucu: " << y << endl;
//
//     if (c1 != c2) {
//         cout << "Karsilastirma operatörü calisiyor." << endl;
//     }
//
//     return 0;
// }

// class Compteur {
// private:
//     int value;
//     int max;
//
// public:
//   explicit Compteur(int m);
//     Compteur& operator++();
//     Compteur operator++(int);
//
//     operator int()const;
// };
//
// Compteur::Compteur(int m): value(0), max(m){}
//
// Compteur& Compteur::operator++() {
//     value = (value+1) %max;
//     return *this;
// }
//
// Compteur Compteur::operator++(int) {
//     Compteur temp(*this);
//     value =( value+1)%max;
//     return temp;
// }
// Compteur::operator int() const {
//     return value;
// }
//
// int main() {
//     Compteur c(3); // Compte 0, 1, 2, 0, 1...
//
//     cout << c++ << endl; // Affiche 0, c vaut 1
//     cout << ++c << endl; // c vaut 2, Affiche 2
//     cout << ++c << endl; // c vaut 0 (wrap), Affiche 0
// }

#include <algorithm>
#include <cctype>

// string milieu(const string& s ) {
//     size_t len =  s.length();
//     if(len == 0) return "";
//
//     size_t mid = len/2;
//
//     if(len %2 != 0) {
//         return s.substr(mid,1);
//     }else {
//         return s.substr(mid-1, 2);
//     }
// }
//
//
// int main() {
//     cout << "ABC  -> " << milieu("ABC") << endl;  // Beklenen: B
//     cout << "ABCD -> " << milieu("ABCD") << endl; // Beklenen: BC
//     cout << "A    -> " << milieu("A") << endl;    // Beklenen: A
//     cout << "XY   -> " << milieu("XY") << endl;   // Beklenen: XY
//
//     return 0;
//
//     return 0;
// }

// enum class Niveau{INFO, WARNING, ERROR};
//
// struct Message {
//     string texte;
//     Niveau niveau;
// };
//
// int main() {
//     vector<Message> logs = {
//         {"Disk OK", Niveau::INFO},
//         {"Low memory", Niveau::WARNING},
//         {"Disk error", Niveau::ERROR},
//         {"CPU hot", Niveau::WARNING},
//         {"Crash", Niveau::ERROR}
//     };
//
//     logs.erase(remove_if(logs.begin(), logs.end(),[](const Message& m) {
//         return m.niveau == Niveau::INFO;
//     }), logs.end());
//
//     auto ordre = [](Niveau n){
//         return ( n== Niveau::WARNING) ? 0 : 1;
//         };
//
//     sort(logs.begin(), logs.end(), [&](const Message& a, const Message& b) {
//        return ordre(a.niveau) < ordre(b.niveau);
//     });
//
// int nb_error = count_if(logs.begin(), logs.end(), [](const Message& m) {
//     return m.niveau == Niveau::ERROR;
// });
//
//     cout<<nb_error;
// return 0;


// }
// template<typename T>
// void my_push_back(vector<T>& v, const T& val) {
//     v.insert(v.end(), val);
// }
//
// template<typename T>
// void my_pop_back(vector<T>& v) {
//     if(!!v.empty()) {
//         v.erase(v.end()-1);
//     }
// }
//
// template <typename T>
// void my_resize(vector<T>& v, size_t new_size, const T& val = T());
// int main() {
//
// }

// enum class Statut{OUVERT, EN_COURS, RESOLU, FERME};
//
// struct Ticket {
//     int id;
//     Statut statut;
//     int priorite;
// };
//
// int rang(Statut s) {
//     switch(s) {
//         case Statut::OUVERT : return 0;
//         case Statut::EN_COURS: return 1;
//         case Statut::RESOLU: return 2;
//         case Statut::FERME : return 3;
//     }
//     return 3;
// }
//
// void traiter(vector<Ticket>& tickets) {
//     tickets.erase(remove_if(tickets.begin(), tickets.end(), [](const Ticket& t) {
//         return t.statut == Statut::FERME;
//     }), tickets.end());
//
//     sort(tickets.begin(), tickets.end(), [](const Ticket&a, const Ticket& b) {
//         int ra = rang(a.statut), int rb = rang(b.statut);
//         if(ra != rb) ra< rb;
//         if(a.priorite != b.priorite) return a.priorite < b.priorite;
//         return a.id < b.id;
//     });
//
//     int actifs = count_if(tickets.begin(), tickets.end(), [](const Ticket& t) {
//     return t.statut == Statut::OUVERT || t.statut == Statut::EN_COURS;
//     });
// }

// template<typename T>
// T somme(const vector<T>& elements, T init) {
//     T total = init;
//     for(const auto& e : elements) {
//         total = total + e;
//     }
//
//     return total;
// }
//
// struct Duree {
//     int heures;
//     int minutes;
// };
//
// Duree operator+(const Duree& a, const Duree& b) {
//     Duree resultat ;
//     resultat.heures = a.heures + b.heures;
//     resultat.minutes = a.minutes+ b.minutes;
//
//     if(resultat.minutes >= 60) {
//         resultat.heures += resultat.minutes/60;
//         resultat.minutes %= 60;
//     }
//     return resultat;
// }
//
// ostream& operator<<(ostream &os, const Duree& d) {
//     return os<<d.heures<<"h"<<d.minutes<<"m";
// }
//
// int main() {
//     // Test 1: Integers
//     vector<int> v_int = {10, 20, 30};
//     cout << "Somme int    : " << somme(v_int, 0) << endl;
//     // Çıktı: 60
//
//     // Test 2: Strings
//     vector<string> v_str = {"Hello", " ", "World"};
//     cout << "Somme string : " << somme(v_str, string("")) << endl;
//     // Çıktı: Hello World
//
//     // Test 3: Struct Duree
//     vector<Duree> v_duree = {{1, 45}, {2, 30}, {0, 15}};
//     // Başlangıç değeri 0 saat 0 dakika
//     Duree total_duree = somme(v_duree, Duree{0, 0});
//
//     cout << "Somme duree  : " << total_duree << endl;
//     // Hesap: 1h45 + 2h30 + 0h15 = 3h90 = 4h30
//     // Çıktı: 4h 30m
//
//     return 0;
// }

// template<typename T>
// T compacter(T first, T last) {
//     if(first == last) return last;
//
//     T write = first;
//     T read = first;
//     ++read;
//
//     for( ; read != last; ++ read) {
//         if(*read != *write) {
//             ++write;
//             *write=*read;
//         }
//     }
//     return ++write;
// }
//
// int main() {
//     vector<int> v = {1,2,2,3,3,3,4};
//
//     auto new_end = compacter(v.begin(), v.end());
//
//     // affichage logique
//     for (auto it = v.begin(); it != new_end; ++it)
//         cout << *it << ' ';
// }

// int main() {
//     double note;
//     double somme =0.0;
//     int count=0;
//
//     cout << "Entrez la liste de vos notes, 0 pour quitter :" << endl;
//
//     while(cin>> note && note != 0) {
//         somme+= note;
//         ++count;
//     }
//     cout << "nb de notes saisies = " << count << endl;
//
//     if(count >0) {
//         double moyenne = somme / count;
//         cout<<fixed<<setprecision(2);
//         cout<<moyenne;
//     }
// return 0;
// }
#include <numeric>
// void remplacer(vector<int>& v, int val) {
//     for(int& x : v) {
//         if(x % 2 == 0) {
//             x = val;
//         }
//     }
// }
// int main() {
// transform((v.begin(), v.end(), v.begin(), [](int x) {
//     return x%2 == 0 ? 0 : x;
// }));
//
//     v.erase(remove(v.begin(), v.end(), 0), v.end());
//
//     int somme = accumulate(v.begin(), v.end(), 0);
//
// }

// template <typename T>
// string to_string(const vector<T>& v) {
//     ostringstream oss;
//     oss<<"[";
//
//     for(size_t i = 0; i<v.size();++i) {
//         if(i>0)oss<<",";
//         oss<<v[i];
//     }
//     oss<<"]";
//     return oss.str();
// }

// #include <iterator>
// template<typename C>
// bool est_non(const C& c) {
//     auto it = begin(c);
//     auto end = end(c);
//
//     if(it == end) return true;
//
//     auto prev = it;
//     ++it;
//
//     for(; it != end; ++it, ++ prev) {
//         if(*it < *prev) {
//             return false;
//         }
//         return true;
//     }
// }

// template<typename C>
// vector<int> ensemble(const C&c) {
//     vector<int> res;
//
//     for(const auto& el : c) {
//         if(find(res.begin(), res.end(), el) == res.end() ) {
//             res.push_back(el);
//         }
//     }
// return res;
// }

// class Point {
// private:
//     double x;
//     double y;
//
// public:
//     Point(double xVal =0.0, double yVal = 0.0) : x(xVal), y(yVal){}
//
//     Point operator+(const Point& other)const {
//         return Point(this->x + other.x, this->y + other.y);
//     }
//
//     bool operator==(const Point& other)const {
//         return (this->x == other.x) && this->y == other.y;
//     }
//
//     friend ostream&operator<<(ostream& os, const Point& p) {
//         os<<p.x<<" , "<<p.y;
//         return os;
//     }
// };

//
// #include <cstring>
// template <typename T>
// bool estEgal(T a, T b) {
//     return a==b;
// }
//
// template<>
// bool estEgal(const char* a, const char* b) {
//     return strcmp(a, b)== 0;
// }
//
// template <typename T>
// void slection_sort(T first, T last) {
//     for(T i = first; i != last; ++i) {
//         T min_it = i;
//         for(T j = next(i); j != last; ++j) {
//             if(*j < *min_it ) {
//                 min_it = j;
//             }
//         }
//         swap(*i, *min_it);
//     }
//
//     vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};
//
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//
//     double moy = accumulate(v.begin(), v.end(), 0.0) / v.size();
//
//     int somme = accumulate(v.begin(), v.end(), 0, [&](int s, int x) {
//         return x>moy ? s+x : s;
//     });
//
// cout<< somme;
// }

// template<typename Container>
// string to_string(const Container& c) {
//     ostringstream oss;
//     oss<<"[";
//
//     auto it = begin(c);
//     auto end = end(c);
//
//     if(it != end) {
//         oss<<*it;
//         ++it;
//     }
//
//     while(it != end) {
//         oss<<", "<<*it;
//         ++it;
//     }
//     oss<<"]";
//     return oss.str();
//
// }
// void swap_ptr(int* a, int* b) {
//     int* tmp = a;
//     a = b;
//     b = tmp;
// }
// int main() {
//
//     int x = 5, y = 10;
//     swap_ptr(&x, &y);
//     cout << x << y;
// }
// #pragma once
// class Carnet {
// private:
//     double notes[10];
//     int nbNotes;
//
// public:
//     Carnet() : nbNotes(0){}
//
//     bool ajuter(double n) {
//         if(nbNotes >=10) return false;
//         if(n<0 ||n>20) return false;
//
//         notes[nbNotes] = n;
//         ++nbNotes;
//         return true;
//     }
//
//     double moyenne()const {
//         if(nbNotes == 0) return 0.0;
//
//         double somme = 0.0;
//
//         for(int i = 0; i<nbNotes; ++i) {
//             somme += notes[i];
//         }
//         return somme / nbNotes;
//     }
//
//     void afficher()const {
//         cout << "Notes (" << nbNotes << "/10) : ";
//
//         for(int i = 0; i<nbNotes; ++i) {
//             cout<<notes[i]<<" ";
//         }
//     }
// };

// class Robot {
// private:
//     int position;
//     int direction;
//
// public:
//     Robot(int pos =0): position(pos), direction(1){}
//
//     void deplacer(int n =1) {
//         if(n<=0)return;
//         position += direction* n;
//     }
//
//     void faireDemiTour() {
//         direction = -direction;
//     }
//     int getPosition()const {
//         return position;
//     }
// };
//
// int main() {
//     Robot r1, r2(10);
//
//     cout << "position courante de r2: " << r2.getPosition() << endl;
//
//     r1.deplacer();
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//
//     r1.deplacer(-1);
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//
//     r1.deplacer(2);
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//
//     r1.faireDemiTour();
//     r1.deplacer(4);
//     cout << "position courante de r1: " << r1.getPosition() << endl;
//
//     return EXIT_SUCCESS;
// }
//
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// class Trace {
//     friend ostream& operator<< (ostream& os, const Trace& t) {
//         return os << t.id << t.data;
//     }
//
// public:
//     Trace()                   : id(nextId++), data('a')  { cout << "C0(" << *this << ") "; }
//     Trace(char data)          : id(nextId++), data(data) { cout << "Ci(" << *this << ") "; }
//     Trace(const Trace& other) : id(nextId++) {
//         this->data = other.data;
//         cout << "CC("  << other << "->" << *this << ") ";
//     }
//     ~Trace() { cout << "D(" << *this << ") "; }
//
//     Trace& operator= (const Trace& other) {
//         this->data = other.data;
//         cout << "=C("  << other << "->" << *this << ") ";
//         return *this;
//     }
//
// private:
//     static int  nextId;
//     int  id;
//     char data;
// };
//
// int Trace::nextId = 1;
//
// Trace f1(char i) {
//     cout << "f1 : ";
//     return Trace(i);
// }
//
// Trace f2(Trace t) {
//     cout << "f2 : ";
//     return t;
// }
//
// Trace f3(const Trace& t) {
//     cout << "f3 : ";
//     return t;
// }
//
// int main() {
//     cout << "---- Setup ----\n";
//
//     // trace1a = 1a
//     Trace trace1a;
//
//     // trace2a = ?b
//     Trace trace2a('b');
//
//     // trace2a = trace1a  (operator=)
//     trace2a = trace1a;
//
//     cout << "\n\n---- No 12 ----\n";
//     // no 12
//     trace2a = f2(trace1a);
//
//     cout << "\n\n---- End of main ----\n";
//     return 0;
// }


// class Point {
// private:
//     double x;
//     double y;
//
// public:
//     Point(double xVal = 0.0, double yVal =0.0) : x(xVal), y(yVal){}
//
//     friend ostream& operator<<(ostream& os, const Point& p){
//         os<<p.x<<p.y;
//         return os;
//     }
//
// friend Point operator+(const Point& p1, const Point& p2) {
//         return Point(p1.x +p2.x, p1.y+p2.y);
//     }
// friend  Point operator*(const Point& p, double s) {
//         return Point(p.x*s, p.y*s);
//     }
//
//     friend Point operator*(double s, const Point& p) {
//         return p*s;
//     }
//
//     bool operator==(const Point& other) {
//         return x ==other.x && y == other.y;
//     }
// };
//
// int main() {
//     Point p1(1.2, 2.4);
//     Point p2(3., 4.2);
//
//     cout << "p1" << p1 << ", p2" << p2 << endl;
//
//     cout << "p1 + p2 = " << p1 + p2 << endl;
//     cout << "p2 + p1 = " << p2 + p1 << endl;
//
//     cout << "p1 * 2. = " << p1 * 2. << endl;
//     cout << "3. * p1 = " << 3. * p1 << endl;
//
//     cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
//
//     Point p3(p1); // Constructeur de copie (automatique ici)
//     cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
//
//     return 0;
// }

// #include <stdexcept>
// class Tableau {
// private:
//     int* data;
//     size_t size;
//
// public:
//     Tableau(size_t n) : data(new int[n]), size(n){}
//
//     ~Tableau() {
//         delete[]data;
//     }
//
//     Tableau(const Tableau& other):data(new int[other.size]), size(other.size) {
//         for(size_t i = 0; i<size; ++i) {
//             data[i] = other.data[i];
//         }
//     }
//
//     Tableau& operator==(const Tableau& other) {
//         if(this == &other) {
//             return *this;
//         }
//
//         delete[]data;
//         size = other.size;
//         data = new int[size];
//         for(size_t i =0 ; i<size; ++i) {
//             data[i]= other.data[i];
//         }
//
//         return *this;
//     }
//
//     const int& operator[](size_t i)const {
//         if(i>= size) throw out_of_range("index invalide");
//         return data[i];
//     }
//
//     int& operator[](size_t i) {
//         if(i> size)throw out_of_range("index invalide");
//         return data[i];
//     }
// };

// int main() {
//     vector<double> prix = {45.5, 12.0, 100.0, 5.5, 25.0, 12.0};
//
//     int nbrDouze = count(prix.begin(), prix.end(), 12.0);
//     sort(prix.begin(), prix.end());
//
//     for_each(begin(prix), end(prix), [](double& p) {
//         return p*=0.9;
//     });
//
//     double total = accumulate(prix.begin(), prix.end(), 0.0);
//
//     cout << "Prix apres reduction : ";
//     for (double p : prix) cout << p << " ";
//     cout << endl;
//
//     cout << "Articles a 12.0 (avant tri/red) : " << nbrDouze << endl;
//     cout << "Valeur totale du stock : " << total << endl;
//
//     return 0;
// }

// class MonEntier {
// private:
//     int valeur;
// public:
//     MonEntier(int val = 0): valeur(val){}
//
//     friend ostream& operator<<(ostream& os, const MonEntier& m) {
//         os<<"n = "<<m.valeur;
//         return os;
//     }
//
// bool operator==(const MonEntier&autre)const {
//         return valeur == autre.valeur;
//     }
//
//     bool operator!=(const MonEntier& autre)const {
//         return !(valeur == autre.valeur);
//     }
//     MonEntier& operator++() {
//         ++valeur;
//         return *this;
//     }
//
//     MonEntier operator++(int){
//         MonEntier tmp(*this);
//         ++valeur;
//         return tmp;
//     }
//
// friend MonEntier operator+(const MonEntier& a, const MonEntier& b) {
//         return MonEntier(a.valeur + b.valeur);
//     }
//
// };