#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>
#include <bits/allocated_ptr.h>
using namespace std;


/*
* template<typename T>
void print_container(const T& container) {
    cout<<"[";
    for(auto it = begin(container); it != end(container); ++it) {
        cout<<*it;
        if(next(it) != end(container)) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

template<typename T>
void selection_sort(T begin, T end) {
    for(T it = begin; it!= end; ++it) {
        T min_it = it;
        for(T j = next(it); j != end; ++j) {
            if(*j <*min_it) {
                min_it = j;
            }
        }
        iter_swap(it, min_it);
    }
}




int main() {
    // --- Initialisation des conteneurs ---
    vector<int> v = {6, 2, 8, 7, 1, 3};
    array<string, 4> a = {"chien"s, "chat"s, "souris"s, "poisson"s};
    double t[] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};

    // --- Traitement du vector<int> ---
    cout << "Vector (avant tri) : ";
    print_container(v);
    selection_sort(begin(v), end(v));
    cout << "Vector (après tri) : ";
    print_container(v);
    cout << endl;

    // --- Traitement du array<string, 4> ---
    cout << "Array (avant tri) : ";
    print_container(a);
    selection_sort(begin(a), end(a));
    cout << "Array (après tri) : ";
    print_container(a);
    cout << endl;

    // --- Traitement du C-style array double[] ---
    cout << "C-style Array (avant tri) : ";
    print_container(t);
    // std::begin et std::end fonctionnent aussi pour les tableaux C-style.
    selection_sort(begin(t), end(t));
    cout << "C-style Array (après tri) : ";
    print_container(t);

    return 0;
}

template<typename T>
void selection_sort(T begin, T end) {
    for(T it = begin; it != end; ++it) {
        T min_it = it;
        for(T j = next(it); j != end; ++j) {
            if(*j < *min_it) {
                min_it = j;
            }
        }
        iter_swap(it, min_it);
    }
}


struct Employe {
    string nom;
    int salaire;
};

bool operator<(const Employe& a, const Employe& b) {
    return a.salaire < b.salaire;
}

ostream& operator<<(ostream & os, const Employe&  e) {
    os<<"{"<<e.nom<<", "<< e.salaire<<"}"<<endl;
    return os;
}
int main() {
    vector<Employe> equipe = {
        {"Alice", 80000},
        {"Bob", 65000},
        {"Charlie", 95000},
        {"David", 60000}
    };

    cout << "Équipe avant tri : ";
    for(const auto& e : equipe) cout << e << " ";
    cout << endl;

    selection_sort(begin(equipe), end(equipe));

    cout << "Équipe après tri (par salaire) : ";
    for(const auto& e : equipe) cout << e << " ";
    cout << endl;

    return 0;
}

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Produit {
    string nom;
    double prix;
    int stock;
};

vector<const Produit*> make_pointers(const vector<Produit>& v) {
    vector<const Produit*> ptr_vec;
    ptr_vec.reserve(v.size());
    for(const auto& p : v) {
        ptr_vec.push_back(&p);
    }
    return ptr_vec;
}

bool compareProduits(const Produit* a, const Produit* b) {
    if(a->prix < b-> prix) {
        return true;
    }
    if(a->prix > b->prix) {
        return false;
    }
    return a->nom < b-> nom;
}

int main() {
    const vector<Produit> inventaire = {
        {"Stylo", 1.50, 150},
        {"Cahier", 3.00, 80},
        {"Gomme", 1.00, 200},
        {"Crayon", 1.50, 120}
    };
    vector<const Produit*> ptr_inventaire = make_pointers(inventaire);

    // On utilise l'algorithme std::sort et on lui passe notre fonction de comparaison
    sort(ptr_inventaire.begin(), ptr_inventaire.end(), compareProduits);

    cout << "Inventaire trié par prix, puis par nom :" << endl;
    for (const Produit* p : ptr_inventaire) {
        cout << "- " << p->nom << " (" << p->prix << " CHF, " << p->stock << " en stock)" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using Data = double;
using Ligne = vector<Data>;
using Matrice = vector<Ligne>;

Data calculer_somme(const Ligne& ligne) {
    Data total = 0.0;
    for(Data valeur : ligne) {
        total += valeur;
    }
    return total;
}

Data calculer_moyenne(const Ligne& ligne) {
    if(ligne.empty()) {
        return 0.0;
    }
    return calculer_somme(ligne) / ligne.size();
}

template <typename Operation>
vector<Data> statistique_par_ligne(const Matrice& matrice, Operation op) {
    vector<Data> resultats;
    resultats.reserve(matrice.size());

    for(const Ligne& ligne :matrice) {
        resultats.push_back(op(ligne));
    }
    return resultats;
}

void afficher_resultat(const string& titre, const vector<Data>& vecteur) {
    cout<<titre<<": [";
    for(size_t i = 0; i < vecteur.size(); ++i) {
        cout<<vecteur[i];
        if(i < vecteur.size() - 1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main() {
    const Matrice notes {{4.0, 5.0, 6.0},
                         {4.1, 5.1, 4.8},
                         {3.5, 4.1     },
                         {4.5, 4.5, 4.6}};

    vector<Data> sommes =   statistique_par_ligne(notes, calculer_somme);
    afficher_resultat("somme  ", sommes);

    vector<Data> moyennes = statistique_par_ligne(notes, calculer_moyenne);
    afficher_resultat("moyenne", moyennes);
    return 0;
}

template <typename T>
size_t koleksiyon_boyutu(span<const T> veriler) {
    return veriler.size();
}

template<typename T>
void print_koleksiyon(const T& container ) {
    cout<<"[";
    for(size_t i  =0 ; i<size(container); ++i) {
        cout<<*(data(container) + 1);
        if(i < size(container)- 1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main() {
    // 1. Test: std::vector ile
    vector<int> int_vektoru = {15, 14, 7, 13};
    cout << "Vektör Testi:" << endl;
    cout << "Koleksiyon: ";
    print_koleksiyon(int_vektoru);

    // ÇÖZÜM: Açıkça span oluşturarak çağırıyoruz.
    cout << "Boyutu: " << koleksiyon_boyutu(std::span<const int>(int_vektoru)) << endl;

    cout << "\n--------------------------\n" << endl;

    // 2. Test: C-stili dizi ile
    double c_dizisi[] = {3.14, 2.71, 1.61, 9.81};
    cout << "C-Stili Dizi Testi:" << endl;
    cout << "Koleksiyon: ";
    print_koleksiyon(c_dizisi);

    // ÇÖZÜM: Açıkça span oluşturarak çağırıyoruz.
    cout << "Boyutu: " << koleksiyon_boyutu(std::span<const double>(c_dizisi)) << endl;

    return 0;
}

template<typename T>
T koleksiyon_carpimi(span<T> data) {
    if(data.empty()) {
        return 0;
    }

    T result= 1;

    for(const auto & eleman : data) {
        result *= eleman;
    }

    return result;
}
int main() {
    vector<int> int_vektoru = {1, 2, 3, 4, 5};
    int carpim_sonuc_int = koleksiyon_carpimi<int>(int_vektoru);
    cout << "Integer vektör {1, 2, 3, 4, 5} elemanlarının çarpımı: " << carpim_sonuc_int << endl;


    double double_dizisi[] = {1.5, 2.0, 3.5};
    double carpim_sonuc_double = koleksiyon_carpimi<double>(double_dizisi);
    cout << "Double dizi {1.5, 2.0, 3.5} elemanlarının çarpımı: " << carpim_sonuc_double << endl;

   return 0;
}

template<typename Container>
void print_koleksiyon(const Container& container) {
    cout<<"[";
    for(size_t i = 0; i< size(container); ++i) {
        cout<<*(data(container) + i);
        if(i<size(container)- 1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

template<typename T>
void elemanlari_ikiyle_carp(span<T> c) {
    for(T & eleman : c) {
        eleman = eleman*2;

    }
}

int main() {
    vector<int> int_vektoru = {1, 2, 3, 4, 5};
    int c_dizisi[] = {10, 20, 30};

    // --- Vektör Testi ---
    cout << "Vektörün ilk hali: ";
    print_koleksiyon(int_vektoru);

    // 1. Fonksiyonu çağırarak vektörün içeriğini değiştir.
    elemanlari_ikiyle_carp<int>(int_vektoru); // Geriye değer döndürmediği için sadece çağırıyoruz.

    // 2. Değiştirilmiş vektörü yazdırarak sonucu gör.
    cout << "Vektörün son hali: ";
    print_koleksiyon(int_vektoru);

    cout << "\n--------------------------\n" << endl;

    // --- C-Dizisi Testi (span'in gücü!) ---
    cout << "Dizinin ilk hali: ";
    print_koleksiyon(c_dizisi);

    // Aynı fonksiyon C-stili dizi ile de çalışıyor!
    elemanlari_ikiyle_carp<int>(c_dizisi);

    cout << "Dizinin son hali: ";
    print_koleksiyon(c_dizisi);

    return 0;
}
template <typename T>
bool deger_var_mi(span<const T> c, const T& value) {
    for (const auto& eleman : c) {
        if (eleman == value) {
            return true;
        }
    }
    return false;
}

int main() {

    string kelimeler[] = {"elma", "armut", "kiraz"};

    // boolalpha, '1' ve '0' yerine 'true' ve 'false' yazar.
    cout << boolalpha;

    // --- Sayılarla Test ---
    cout << "Sayılar koleksiyonu: {10, 20, 30, 40, 50}" << endl;
    cout << "30 değeri var mı? " << deger_var_mi<int>(sayilar, 30) << endl;  // true bekliyoruz
    cout << "99 değeri var mı? " << deger_var_mi<int>(sayilar, 99) << endl;  // false bekliyoruz

    cout << "\n--- Kelimelerle Test ---" << endl;
    cout << "Kelimeler koleksiyonu: {\"elma\", \"armut\", \"kiraz\"}" << endl;
    string aranan_kelime = "kiraz";
    cout << "\"" << aranan_kelime << "\" değeri var mı? " << deger_var_mi<string>(kelimeler, aranan_kelime) << endl; //
    // true bekliyoruz
    aranan_kelime = "kavun";
    cout << "\"" << aranan_kelime << "\" değeri var mı? " << deger_var_mi<string>(kelimeler, aranan_kelime) << endl; //
    // false bekliyoruz

    // --- Boş Koleksiyon Testi ---
    vector<int> bos_vektor;
    cout << "\n--- Boş Koleksiyon Testi ---" << endl;
    cout << "Boş koleksiyonda 5 değeri var mı? " << deger_var_mi<int>(bos_vektor, 5) << endl; // false bekliyoruz

    return 0;
}
template<typename T>
T en_buyuk_eleman(span<const T> contianer) {
    if(contianer.size() == 0) {
        return 0;
    }
    T  max_value = contianer[0]; ;
    for(int i = 0; i < size(contianer); ++i) {
        if(contianer[i] > max_value) {
            max_value = contianer[i];
        }
    }
return max_value;
}

int main() {
    vector<int> sayilar = {10, 20, 30, 40, 250};
    cout<<en_buyuk_eleman<int>(sayilar)<<endl;
    return 0;
}

template<typename T>
T max_value(span<const T> container) {
    if(container.empty()) {
        throw runtime_error("Error: ... ");
    }
    T maksimum = container[0];
    for(size_t i = 1; i< container.size(); ++i) {
        if(container[i] > maksimum) {
            maksimum = container[i];
        }
    }

    return maksimum;
}

int main() {
    vector<int> sayilar = {10, 99, 30, 105, 50};
    vector<double> negatif_sayilar = {-25.5, -5.1, -100.2};
    vector<int> bos_vektor;

    cout << "Sayılar içindeki en büyük: " << max_value<int>(sayilar) << endl;
    cout << "Negatif sayılar içindeki en büyük: " << max_value<double>(negatif_sayilar) << endl;

    try {
        cout << "Boş vektör içindeki en büyük: " << max_value<int>(bos_vektor) << endl;
    }catch(const runtime_error& e) {
        cout<<e.what()<<endl;
    }

    return 0;
}

template<typename T, typename Predicat>
vector<T> filtrer(span<const T> s, Predicat pred) {
    vector<T> resultats;
    for(const auto& element : s) {
        if(pred(element)) {
            resultats.push_back(element);
        }
    }
    return resultats;
}

template<typename Container>
void afficher_collection(const string& etiquette, const Container& collection) {
    cout<<etiquette<<": [";
    bool premier = true;
    for(const auto& element :collection) {
        if(!premier) {
            cout<<", ";
        }
        cout<<element;
        premier = false;
    }
    cout<<"]"<<endl;
}

bool est_pair(int nombre) {
    return nombre % 2 == 0;
}

int main() {
    vector<int> nombres ={1,2,3,4,5,6,7,8,9,10};
    afficher_collection("Collection Originale", nombres);
    vector<int> nombres_pairs = filtrer<int>(nombres, &est_pair);
    afficher_collection("Nombres Pairs (avec fonction)", nombres_pairs);

    return 0;
}
// 'transformer' fonksiyonun MÜKEMMEL, HİÇBİR DEĞİŞİKLİK GEREKMİYOR.
template<typename T_out, typename T_in, typename Operation>
vector<size_t> transformer(span<const T_in> sequence, Operation op) {
    vector<T_out> resultats;
    for (const auto& element : sequence) {
        resultats.push_back(op(element));
    }
    return resultats;
}

// Yardımcı yazdırma fonksiyonun da harika.
template<typename Container>
void afficher_collection(const string& etiquette, const Container& collection) {
    cout << etiquette << ": [";
    bool premier = true;
    for (const auto& element : collection) {
        if (!premier) {
            cout << ", ";
        }
        cout << element;
        premier = false;
    }
    cout << "]" << endl;
}

int main() {
    // Girdi verimiz
    vector<string> chaines = {"merci", "pour", "cette", "lecon"};
    afficher_collection("Collection Originale", chaines);

    // ÇAĞRIDAKİ DÜZELTME BURADA:
    // T_out = size_t, T_in = string olarak açıkça belirtiyoruz.
    vector<size_t> longueurs = transformer<size_t, string>(chaines, [](const string& s) {
        return s.size();
    });

    // Sonucu da yazdıralım ki çalıştığını görelim.
    afficher_collection("Longueurs des chaines", longueurs);

    return 0;
}
template<typename T1, typename T2>
bool au_moins_un(span<const T1> sequence, T2 pred) {
    for(const auto & element :  sequence) {
        if(pred(element)) {
            return true;
        }
    }
    return false;
}



int main() {
cout<<boolalpha;
    vector<int> nombres = {1, 3, 5, 8, 9, 10};
    cout << "Collection: [1, 3, 5, 8, 9, 10]" << endl;

    bool un_pair_existe = au_moins_un<int>(nombres, [](int n){ return n % 2 == 0; });
    cout << "Au moins un nombre pair? -> " << un_pair_existe << endl;

    bool plus_grand_que_20_existe = au_moins_un<int>(nombres, [](int n){ return n > 20; });
    cout << "Au moins un nombre > 20? -> " << plus_grand_que_20_existe << endl;
    return 0;

    vector<int> collection_vide;
    cout << "\nCollection: []" << endl;
    bool dans_collection_vide = au_moins_un<int>(collection_vide, [](int n){ return n == 5; });
    cout << "Au moins un 5 dans la collection vide? -> " << dans_collection_vide << endl;
}

template<typename T1 , typename T2>
bool tous_correspondent(span<const T1> sequence, T2 pred) {
    for(const auto& element : sequence) {
        if(!(pred(element))) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << boolalpha;

    vector<int> nombres_positifs = {10, 20, 35, 8, 92};
    cout << "Collection 1: [10, 20, 35, 8, 92]" << endl;

    // Test 1: Koleksiyondaki tüm sayılar pozitif mi? (true bekliyoruz)
    bool tous_positifs = tous_correspondent<int>(nombres_positifs, [](int n){ return n > 0; });
    cout << "Tous les nombres sont positifs? -> " << tous_positifs << endl;

    // Test 2: Koleksiyondaki tüm sayılar 10'dan büyük veya eşit mi? (false bekliyoruz, çünkü 8 var)
    bool tous_plus_grand_que_10 = tous_correspondent<int>(nombres_positifs, [](int n){ return n >= 10; });
    cout << "Tous les nombres sont >= 10? -> " << tous_plus_grand_que_10 << endl;

    vector<int> nombres_melanges = {10, 20, -5, 15};
    cout << "\nCollection 2: [10, 20, -5, 15]" << endl;

    // Test 3: Karışık koleksiyondaki tüm sayılar pozitif mi? (false bekliyoruz, çünkü -5 var)
    tous_positifs = tous_correspondent<int>(nombres_melanges, [](int n){ return n > 0; });
    cout << "Tous les nombres sont positifs? -> " << tous_positifs << endl;

    return 0;
}

template<typename T, typename T2>
string joindre(span< T> sequence, T2 seperateur ) {
    if(sequence.empty()) {
        return "";
    }
    stringstream ss;
    ss<<sequence.front();

    for(const auto& element : sequence.subspan(1)) {
        ss<<seperateur<<element;
    }

    return ss.str();


}

int main() {
    // Test 1: int vektörünü birleştirmek
    vector<int> nombres = {10, 20, 30, 40};
    string resultat1 = joindre<int>(nombres, ", ");
    cout << "Test 1: " << resultat1 << endl;

    // Test 2: string vektörünü birleştirmek
    vector<string> mots = {"un", "deux", "trois"};
    string resultat2 = joindre<string>(mots, " -> ");
    cout << "Test 2: " << resultat2 << endl;

    // Test 3: Boş koleksiyon (edge case)
    vector<double> collection_vide;
    string resultat3 = joindre<double>(collection_vide, ",");
    cout << "Test 3 (vide): '" << resultat3 << "'" << endl;

    // Test 4: Tek elemanlı koleksiyon (edge case)
    array<int, 1> un_seul_element = {100};
    string resultat4 = joindre<int>(un_seul_element, ", ");
    cout << "Test 4 (un seul): " << resultat4 << endl;

    return 0;
}
using namespace std;
using Data = double;
using Ligne = vector<Data>;
using Matrice = vector<Ligne>;

template<typename T>
T calculer_somme (span<const T> sequence) {
T somme {};
    for(const T & element : sequence) {
        somme +=element;
    }
    return somme;
}


template<typename T>
T calculer_moyenne(span<const T> sequence) {
    if(sequence.empty()) {
        return T{};
    }
    T somme_des_elements = calculer_somme(sequence);
    size_t taille = sequence.size();

    return somme_des_elements/ taille;

}

template<typename T_out, typename T_in, typename Operation>
vector<T_out> transformer(const vector<T_in>& matrice, Operation op) {
    vector<T_out> resultats;

    resultats.reserve(matrice.size());

    for(const T_in& ligne: matrice) {
        resultats.push_back(op(ligne));
    }

    return resultats;
}





template<typename Container>
void afficher_collection(const string& etiquette, const Container& collection) {
    cout<<etiquette <<": [";
    bool premier = true;
    for(const auto& element : collection) {
        if(!premier) {
            cout<<",";
        }
        cout<<element;
        premier = false;
    }
    cout<<"]"<<endl;
}

int main() {
    const Matrice notes {{4.0, 5.0, 6.0},
                         {4.1, 5.1, 4.8},
                         {3.5, 4.1     },
                         {4.5, 4.5, 4.6}};

    cout << fixed << setprecision(1);

    // transformer'ı `calculer_somme` operasyonu ile çağırma
    auto sommes = transformer<Data, Ligne>(notes, &calculer_somme<Data>);
    afficher_collection("Sommes  ", sommes);

    // transformer'ı `calculer_moyenne` operasyonu ile çağırma
    auto moyennes = transformer<Data, Ligne>(notes, &calculer_moyenne<Data>);
    afficher_collection("Moyennes", moyennes);

    return 0;
}

template<typename T>
void afficher(span<const T>sequence) {
    cout<<"[";
    bool premier = true;
    for(auto const& element : sequence) {
        if(!premier) {
            cout<<", ";
        }
        cout<<element;
        premier = false;
    }
    cout<<"]"<<endl;
}
template <typename T>
void tri_selection(span< T > sequence) {
    if(sequence.size() < 2) {
        return ;
    }

    for(size_t i = 0; i < sequence.size() ; ++i) {
        size_t min_index = i;
        for(size_t j = i+1; j< sequence.size(); ++j) {
            if(sequence[j] < sequence[min_index]){
                min_index = j;
            }
        }
        if(i != min_index) {
            swap(sequence[min_index], sequence[i]);
        }
    }
}

int main() {
    vector<int> v{6, 2, 8, 7, 1, 3};

    cout << "Avant le tri : ";
    afficher<int>(v);

    tri_selection<int>(v);

    cout << "Apres le tri : ";
    afficher<int>(v);

    return 0;
}

template<typename T>
void afficher(span<const T>sequence) {
    cout<<"[";
    bool premier = true;
    for(auto const& element : sequence) {
        if(!premier) {
            cout<<", ";
        }
        cout<<element;
        premier = false;
    }
    cout<<"]"<<endl;
}
template <typename T>
void tri_selection(span< T > sequence) {
    if(sequence.size() < 2) {
        return ;
    }

    for(size_t i = 0; i < sequence.size() ; ++i) {
        size_t max_index = i;
        for(size_t j = i+1; j< sequence.size(); ++j) {
            if(sequence[j] > sequence[max_index]){
                max_index = j;
            }
        }
        if(i != max_index) {
            swap(sequence[max_index], sequence[i]);
        }
    }
}

int main() {
    vector<int> v{6, 2, 8, 7, 1, 3};

    cout << "Avant le tri : ";
    afficher<int>(v);

    tri_selection<int>(v);

    cout << "Apres le tri : ";
    afficher<int>(v);

    return 0;
}template<typename T>
void afficher(span<const T>sequence) {
    cout<<"[";
    bool premier = true;
    for(auto const& element : sequence) {
        if(!premier) {
            cout<<", ";
        }
        cout<<element;
        premier = false;
    }
    cout<<"]"<<endl;
}
template <typename T>
void tri_selection(span< T > sequence) {
    if(sequence.size() < 2) {
        return ;
    }

    for(size_t i = 0; i < sequence.size() ; ++i) {
        size_t max_index = i;
        for(size_t j = i+1; j< sequence.size(); ++j) {
            if(sequence[j] > sequence[max_index]){
                max_index = j;
            }
        }
        if(i != max_index) {
            swap(sequence[max_index], sequence[i]);
        }
    }
}

int main() {
    vector<int> v{6, 2, 8, 7, 1, 3};

    cout << "Avant le tri : ";
    afficher<int>(v);

    tri_selection<int>(v);

    cout << "Apres le tri : ";
    afficher<int>(v);

    return 0;
}
template <typename T>
auto somme_boucle(const T& matrice) {
    using typeElement = typename T::value_type::value_type;
    typeElement total {};
    for(size_t i = 0; i< matrice.size(); ++i) {
        for(size_t j = 0; j < matrice[i].size(); ++j) {
            total += matrice[i][j];
        }
    }
    return total;
}

template<typename T>
auto somme_boucle_range(const T & matrice) {
    using TypeElement = typename T::value_type::value_type;
    TypeElement total {};

    for(const auto& ligne : matrice) {
        for(const auto& element : ligne) {
            total += element;
        }
    }
    return total;
}



int main() {
using Data = double;
    using Ligne = vector<Data>;
    using Matrice = vector<Ligne>;

    const Matrice matrice_test = {
        {1.1, 2.2, 3.3},
        {4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9}
    };
    cout << "Matrice elemanlarinin toplami hesaplaniyor..." << endl;

    auto total1 = somme_boucle_range(matrice_test);
    cout << "Yontem 1 (range-based for): " << total1 << endl;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <string>
#include <span>
#include <sstream>
#include <iomanip>
#include <utility>

using Data    = double;
using Ligne   = vector<Data>;
using Matrice = vector<Ligne>;
template<typename T>
T calculer_somme(span<const T>ligne) {
    T total {};
    for(const auto & el : ligne) {
     total += el;
    }

    return total;
}

template<typename T>
T calculer_moyenne(span<const T>sequence) {
    if(sequence.empty()) {
        return T{};
    }
    return calculer_somme(sequence) / sequence.size();
}
template<typename T_out, typename T_in, typename Operation>
vector<T_out> transformer(const vector<T_in>& matrice, Operation op) {
    vector<T_out> resultats;

    resultats.reserve(matrice.size());
    for(const T_in & ligne : matrice) {
        resultats.push_back(op(ligne));
    }

    return resultats;
}

template<typename T>
void afficher_collection(const string& etiquette, const T& collecetion) {
    cout<<etiquette<<": [";
    bool premier = true;
    for(const auto& element : collecetion) {
        if(!premier) {
            cout<<", ";
        }
        cout<<element;
        premier =false;
    }
    cout<<"]"<<endl;
}
int main() {
    const Matrice notes {{4.0, 5.0, 6.0},
                         {4.1, 5.1, 4.8},
                         {3.5, 4.1     },
                         {4.5, 4.5, 4.6}};

    cout << fixed << setprecision(1);

    auto sommes = transformer<Data, Ligne>(notes, &calculer_somme<Data>);
    afficher_collection("Sommes  ", sommes);

    auto moyennes = transformer<Data, Ligne>(notes, &calculer_moyenne<Data>);
    afficher_collection("Moyennes", moyennes);

    return 0;
}