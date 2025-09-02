#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>
#include <emmintrin.h>
#include <set>
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
}using Data    = double;
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


template<typename T>
using Ligne = vector<T>;

template<typename T>
using Matrice = vector<Ligne<T>>;

template<typename T>
ostream& operator<<(ostream& os, const Ligne<T>& ligne) {
    os<<"[";
    for(size_t i =0;i <ligne.size(); ++i) {
        os<<ligne[i];
        if(i<ligne.size() - 1) {
            os<<", ";
        }
    }
    os<<"]";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const Matrice<T>& matrice) {
    os<<"[";
    for(size_t i = 0; i<matrice.size(); ++i) {
        os<<matrice[i];
       if(i < matrice.size() - 1) {
           os<<endl;
       }

    }
    os<<"]"<<endl;
    return os;
}
int main() {
    // La matrice de l'énoncé
    Matrice<int> m {{0},
                    {1, 2},
                    {3, 4, 5},
                    {6, 7, 8, 9}};

    // Le code d'affichage qui doit maintenant fonctionner
    cout << m << endl;

    return 0;
}

ostream& operator<<(ostream & os, const pair<string, int>& data) {
    os<<data.first<<" => "<<data.second;
    return os;
}

int main() {
    pair<string, int> score = {"Alice", 100};
    cout << "Resultat du joueur : " << score << endl;

    pair<string, int> score_bob = {"Bob", 95};
    cout << score << " | " << score_bob << endl;

    return 0;
}
*
*template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os<<p.first<<" => "<< p.second;
    return os;
}

int main() {
    map<string, int> high_scores = {
        {"Alice", 100},
        {"Bob", 95},
        {"Charlie", 105}
    };

    cout << "Tableau des scores :" << endl;
    for (const auto& entry : high_scores) {
        // Notre surcharge pour pair est appelée automatiquement ici !
        cout << "- " << entry << endl;
    }
    return 0;

}
using Itineraire = vector<string>;

ostream& operator<<(ostream& os, const Itineraire& itineraire) {

    if(itineraire.empty()) {
        os<<"Itineraire vide";
        return os;
    }
    for(size_t i = 0; i<itineraire.size(); ++i) {
        os<<itineraire[i];
        if(i<itineraire.size()-1) {
            os<<" -> ";
        }
    }
    return os;
}




int main() {
    Itineraire road_trip = {"Genève", "Lausanne", "Berne", "Zurich"};
    cout << "Mon voyage : " << road_trip << endl;

    Itineraire vide = {};
    cout << "Un autre voyage : " << vide << endl;

    return 0;
}
enum class Chiffre :int{ ZERO=0, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF};
ostream& operator<<(ostream& os, const Chiffre& c) {
    switch(c) {
        case Chiffre::ZERO : os<<"ZERO"; break;
        case Chiffre::UN : os<<"UN"; break;
        case Chiffre::DEUX : os<<"DEUX"; break;
        case Chiffre::TROIS : os<<"TROIS"; break;
        case Chiffre::QUATRE : os<<"QUATRE"; break;
        case Chiffre::CINQ : os<<"CINQ"; break;
        case Chiffre::SIX : os<<"SIX"; break;
        case Chiffre::SEPT : os<<"SEPT"; break;
        case Chiffre::HUIT : os<<"HUIT"; break;
        case Chiffre::NEUF : os<<"NEUF"; break;
        default: os<<"?" ; break;
    }
    return os;
}

ostream& operator<<(ostream& os, const vector<Chiffre>& vc){
    for(size_t i =0; i<vc.size(); ++i) {
        os<<vc[i];
        if(i<vc.size()-1) {
            os<<" ";
        }
    }
return os;
}

vector<Chiffre> nbreToEnums(int n) {
    if(n == 0) {
        return {Chiffre::ZERO};
    }

    vector<Chiffre> resultat;
    long long num = abs(static_cast<long long>(n));

    while(num > 0) {
        int digit = num % 10;
        resultat.push_back(static_cast<Chiffre>(digit));
        num /= 10;
    }

    reverse(resultat.begin(), resultat.end());
    return resultat;


}


int main() {
    cout << "Test avec 123: ";
    cout << nbreToEnums(123) << endl; // Attendu: UN DEUX TROIS

    cout << "Test avec 9870: ";
    cout << nbreToEnums(9870) << endl; // Attendu: NEUF HUIT SEPT ZERO

    cout << "Test avec 0: ";
    cout << nbreToEnums(0) << endl; // Attendu: ZERO

    cout << "Test avec -5: ";
    cout << nbreToEnums(-5) << endl; // Attendu: CINQ

    return 0;
}

struct Date {
  int jour,mois, annee;
};

struct Personne {
    string prenom, nom;
    Date date;
};

ostream & operator<<(ostream& os,const Date& d) {
    os<<d.jour<<"."<<d.mois<<"."<<d.annee<<endl;
    return os;
}

ostream & operator<<(ostream& os,const Personne& p){
    os<<"prenom : "<<p.prenom<<endl;
    os<<"nom    : "<<p.nom<<endl;
    os<<"date   : "<<p.date<<endl;
    return os;
}

template<size_t N>
ostream& operator<<(ostream& os, const array<Personne, N>& carnet ) {
    for(size_t i = 0; i< carnet.size(); ++i) {
        os<<carnet[i];
        if(i<carnet.size()-1) {
            os<<endl;
        }
    }
    return os;
}

int main() {

    array<Personne, 4> carnet {Personne{"Jean"s,   "Veuxplus"s, Date{ 7,  4, 1975}},
                               Personne{"Alain"s,  "Verse"s,    Date{21, 12, 2018}},
                               Personne{"Justin"s, "Ptipeu"s,   Date{ 1,  8, 2023}},
                               Personne{"Rémi"s,   "Fasol"s,    Date{17,  5, 1957}}};

    // L'instruction d'affichage qui doit maintenant fonctionner
    cout << carnet << endl;

    return 0;
}
struct LigneCommande {
    string nom_produit;
    int quantite;
};

struct Commande {
    int id;
    vector<LigneCommande> lignes;
};

ostream& operator<<(ostream& os, const LigneCommande& ligne) {
    os<<ligne.nom_produit<<", "<<ligne.quantite;
    return os;
}

ostream & operator<<(ostream& os, const Commande& c) {
    os<<c.id<<" => ";
    for(const auto & ligne : c.lignes) {
        os<<"\t"<<ligne<<"\n";
    }
    return os;
}

int main() {
    Commande cmd = {101, {{"Stylo", 4}, {"Cahier", 2}, {"Gomme", 1}}};
    cout << cmd;
    return 0;
}

struct CPU {
    string modele;
    double vitesse_ghz;
};

struct RAM {
    int capacite_go;
    string type;
};

struct Ordinateur {
    CPU cpu;
    RAM ram;
};

ostream& operator<<(ostream& os, const CPU& c) {
    os<<c.modele<<" @ " << c.vitesse_ghz<<"GHz";
    return os;
}

ostream& operator<<(ostream& os, const RAM& r) {
    os<<r.capacite_go<<"GB "<< r.type<<endl;
    return os;
}

ostream& operator<<(ostream& os,const Ordinateur& o) {
    os<<"Configuration PC: \n";
    os<<"Processeur : "<< o.cpu<<"\n";
    os<<"Memoire : "<<o.ram;

    return os;
}

int main() {
    Ordinateur pc = {{"Intel i7", 3.4}, {16, "DDR4"}};
    cout << pc << endl;
    return 0;
}

struct Point {
    double x;
    double y;


    void afficher() const {
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

    void deplacer(double dx, double dy) {
        x += dx;
        y += dy;
    }
};

ostream& operator<<(ostream& os, const Point& p) {
    os<<p.x<< p.y<<endl;
    return os;
}

int main() {
    Point k{24,35};
    cout<<k<<endl;

    Point centre{};
    centre.afficher();
    centre.deplacer(122,333);
    centre.afficher();

    Point p{1.2, 2.4};
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.x = 5.5;
    p.y = 29.5;
    cout<<p.x<<" -> "<<p.y<<endl;

}


class Point {
private:
    double x, y ;

public:
    Point(double val_x = 0, double val_y = 0): x(val_x), y(val_y){};

    double getX() const {
    return x;
    }

    double getY() const {
        return y;
    }
void afficher() const{
        cout<<"("<< x<< ", "<<y<<")"<<endl;
}
    void deplacer(double dx, double dy) {
        x += dx;

        y += dy;

    }
};

class Point {
private:
    double x, y;

public:

    Point(double x_val = 0.0, double y_val=0.0):x(x_val),y(y_val){}

    double getX() const {
        cout<<x<<endl;
    }
    double getY() const {
        cout<<y<<endl;
    }

    void setX(double sx) {
       x =sx;
    }
    void setY(double sy) {
         y =sy;
    }

    void deplacer(double dx, double dy) {
        x+= dx;
        y+= dy;
    }

  void  afficher ()const {
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }

friend ostream& operator<<(ostream& os, const Point& p);
};
ostream & operator<<(ostream& os, const Point& p) {
    os<<"("<<p.x<<", "<<p.y<<")";
    return os;
}

int main() {
    Point centre;      // Appelle le constructeur par défaut Point()
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.afficher();// Appelle le constructeur par défaut Point()
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    // On utilise les getters pour accéder aux valeurs pour l'affichage.
    cout << p.getX() << " -- " << p.getY() << endl;

    return 0;
}

class Point {
private:
    double x, y;

public:
    Point(double x_val=(0), double y_val=(0.0)): x(x_val), y(y_val){}

    double getX()const {
        return x;
    }
    double getY()const {
        return y;
    }

    void afficher() {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    void setX(double x_val) {
        x= x_val;
    }
    void setY(double y_val) {
        y= y_val;
    }

    void deplacer(double dx, double dy) {
        x +=dx;
        y+= dy;
    }
};
int main() {
    Point centre;
    centre.afficher();

    Point p(1.2,2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
class Point {
private:
    double x;
    double y;
    const double xMax;
    const double yMax;

public:
    Point(double x_val=0.0, double y_val = 0.0):
    Point(x_val, y_val,100.0,100.0 ){}

    Point(double x_val, double y_val, double xMax_val, double yMax_val):
x(clamp(x_val, 0.0, xMax_val)),
    y(clamp(y_val, 0.0, yMax_val)),
    xMax(xMax_val),
    yMax(yMax_val){}

    double getX()const {
        return x;
    }
    double getY()const {
        return y;
    }

    void setX(double newX) {
      if(newX >= 0.0 && newX<=xMax) {
          x = newX;
      }
    }
    void setY(double newY) {
        if(newY >=0.0 && newY <= yMax) {
            y = newY;
        }
    }

    void deplacer( double dx, double dy) {
        double newX = x+dx;
        double newY = y+dy;
        if(newX >=0.0 && newX <= xMax && newY>=0.0 && newY <= yMax) {
            x = newX;
            y=newY;
        }
    }

    void afficher()const {
        cout<<"("<<x<<","<<y<<"), contraintes: [0,"<<xMax<<"]x[0,"<<yMax<<"]"<<endl;
    }



};


int main() {
    Point p1(1.2, 2.4);
    cout << "p1"; p1.afficher();
    p1.deplacer(1., 3.);
    cout << "p1"; p1.afficher();
    p1.setX(4.);
    cout << "p1"; p1.afficher();
    p1.setY(7.);
    cout << "p1"; p1.afficher();

    cout << endl; // Séparation pour la lisibilité

    Point p2(3., 4.2, 10., 10.);
    cout << "p2"; p2.afficher();
    p2.deplacer(15, 2); // Doit être rejeté (18 > 10)
    cout << "p2"; p2.afficher();
    p2.deplacer(3, 2);  // Valide
    cout << "p2"; p2.afficher();
    p2.setX(-3);      // Doit être rejeté (-3 < 0)
    cout << "p2"; p2.afficher();
    p2.setY(12);      // Doit être rejeté (12 > 10)
    cout << "p2"; p2.afficher();

    return 0;
}
class Pays {
private:
    string nom;
    double population;
    double superficie;

public:
    Pays(string pays_nom, double pays_pop, double pays_superficie):
    nom(pays_nom), population(pays_pop), superficie(pays_superficie){}

    string get_nom() const {
        return nom;
    }
    double get_population()const {
        return population;
    }
    double get_superficie()const {
        return superficie;
    }

   void set_population(double new_population) {
        population = new_population;
    }
    double getDensite()const {
        if(superficie == 0) {
            return 0;
        }
        return (population * 1000000) / superficie ;
    }
};

int main() {

    vector<Pays> liste_pays = {
        {"Suisse", 8.12, 41290},
        {"France", 66.66, 547030},
        {"Italie", 61.85, 301230},
        {"Allemagne", 80.85, 357021},
        {"Turquie", 80.85, 783562}
    };

    if(liste_pays.empty()) {
        cout<<"La liste des pays est vide."<<endl;
        return 1;
    }

    vector<const Pays*>pays_plus_peuples;
    pays_plus_peuples.push_back(&liste_pays[0]);

    for(size_t i =1; i<liste_pays.size(); ++i) {
        const Pays& pays_actuel = liste_pays[i];

        double pop_gagnant_actuel = pays_plus_peuples[0] -> get_population();
        if(pays_actuel.get_population() > pop_gagnant_actuel) {
            pays_plus_peuples.clear();
            pays_plus_peuples.push_back(&pays_actuel);
        }else if(pays_actuel.get_population() == pop_gagnant_actuel) {
            pays_plus_peuples.push_back(&pays_actuel);
        }

        cout<<"Pays ayant le plus d'habitants ("<< pays_plus_peuples[0] -> get_population() <<"millions) : "<<endl;
        for(const Pays* pays :pays_plus_peuples) {
            cout<<"- "<<pays -> get_nom()<<endl;
        }
    }


    return 0;
}
class Robot {
private:
    int position;
    int direction;

public:
    Robot(int pos_initial = 0, int dir = 1)
    : position(pos_initial), direction(dir){}

    void deplacer(int n = 1) {
        if(n<=0) {
            return;
        }
        position += n*direction;
    }

    void faireDemiTour() {
        direction *= -1;
    }

    int getPosition()const {
        return position;
    }


};
int main() {

    Robot r1, r2(10); // r1 appelle Robot(0), r2 appelle Robot(10)
    cout << "position courante de r2: " << r2.getPosition() << endl;

    r1.deplacer(); // n=1 par défaut. pos: 0 + 1*1 = 1
    cout << "position courante de r1: " << r1.getPosition() << endl;

    r1.deplacer(-1); // n <= 0, pas de mouvement. pos: 1
    cout << "position courante de r1: " << r1.getPosition() << endl;

    r1.deplacer(2); // pos: 1 + 2*1 = 3
    cout << "position courante de r1: " << r1.getPosition() << endl;

    r1.faireDemiTour(); // direction devient -1
    r1.deplacer(4); // pos: 3 + 4*(-1) = -1
    cout << "position courante de r1: " << r1.getPosition() << endl;

    return EXIT_SUCCESS;
}
class Point {
private:
    double x;
    double y;

public:
    Point(double x_val, double y_val):x(x_val), y(y_val){}
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }

    bool operator==(const Point& other) const = default;
};
ostream& operator<<(ostream& os,const Point& p) {
    os<<p.getX()<<","<<p.getY();
    return os;
}
Point operator+(const Point& p1, const Point&p2) {
    return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

Point operator*(const Point& p, double scalaire) {
    return Point(p.getX()* scalaire, p.getY()* scalaire);
}

Point operator *(double scalaire, const Point& p) {
    return p * scalaire;
}
int main() {
    Point p1(1.2, 2.4);
    Point p2(3., 4.2);

    cout << "p1" << p1 << ", p2" << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 + p1 = " << p2 + p1 << endl;

    cout << "p1 * 2. = " << p1 * 2. << endl;
    cout << "3. * p1 = " << 3. * p1 << endl;

    cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
    Point p3(p1); // Utilise le constructeur de copie par défaut
    cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;

    return 0;
}

class Point {
private:
    double x;
    double y;

public:
    Point(double x_val=0.0, double y_val=0.0): x(x_val), y(y_val){}
    bool operator==(const Point &) const = default;

    double getX()const {
        return x;
    }

    double getY() const {
        return y;
    }

};

ostream& operator<<(ostream& os, const Point&p) {
    os<<p.getX()<<", "<<p.getY();
    return os;
}

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.getX() + p2.getX(), p2.getX() + p2.getY());
}

Point operator*(const Point&p, double scalaiere) {
    return Point(p.getX()* scalaiere, p.getY()* scalaiere);
}

Point operator*(double scalaiere, const Point& p) {
    return p* scalaiere;
}

int main() {
    Point p1(1.2, 2.4);
    Point p2(3., 4.2);

    cout << "p1" << p1 << ", p2" << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 + p1 = " << p2 + p1 << endl;

    cout << "p1 * 2. = " << p1 * 2. << endl;
    cout << "3. * p1 = " << 3. * p1 << endl;

    cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
    Point p3(p1); // Utilise le constructeur de copie par défaut
    cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;

    return 0;
}
class Point {

private:
    double x;
    double y;
public:
    Point(double x_val =0.0, double y_val=0.0):
    x(x_val), y(y_val){}

    double getX()const {
        return x;
    }
    double getY() const {
        return y;
    }

    Point& operator+=(const Point& rhs) {
        this -> x += rhs.x;
        this -> y += rhs.y;
        return *this;
    }

    Point& operator *=(double scalaiere) {
        this -> x *= scalaiere;
        this -> y *= scalaiere;
        return *this;
    }

};
ostream& operator<<(ostream & os, const Point& p) {
    os<<p.getX()<<","<< p.getY();
    return os;
}

Point operator +(Point lhs, const Point& rhs ) {
    return lhs+= rhs;
}

Point operator*( Point p, double scalaire) {
    return p *=scalaire;
}

Point operator*(double scalaiere, const Point& p) {
    return p * scalaiere;
}

bool operator ==(const Point& lhs, const Point& rhs) {
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

int main() {
    Point p1(1.2, 2.4);
    Point p2(3., 4.2);

    cout << "p1" << p1 << ", p2" << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 + p1 = " << p2 + p1 << endl;

    cout << "p1 * 2. = " << p1 * 2. << endl;
    cout << "3. * p1 = " << 3. * p1 << endl;

    cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
    Point p3(p1);
    cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
}
class MonEntier {
private:
    int valeur;

public:
    MonEntier(int val = 0): valeur(val){}

    friend ostream& operator<<(ostream & os,const MonEntier & m);
    friend MonEntier operator+(const MonEntier& a, const MonEntier& b);

    MonEntier& operator +=(const MonEntier& other) {
        this-> valeur += other.valeur;
        return *this;
    }

    MonEntier& operator++() {
        ++this -> valeur;
        return *this;
    }

    MonEntier operator++(int) {
        MonEntier temps = *this;
        ++this -> valeur;
        return temps;
    }

    bool operator ==(const MonEntier& other) const = default;
};

ostream& operator<<(ostream& os, const MonEntier& m) {
    os<<"n = "<<m.valeur;
    return os;
}

MonEntier operator+(const MonEntier& a, const MonEntier& b) {
    return MonEntier(a.valeur + b.valeur);
}




int main() {
    MonEntier m0, m1(1), m2 = 5;
    const MonEntier m3{7};

    cout << m0 << endl
         << m1 << endl;

    cout << boolalpha;
    cout << (m0 == m1) << endl;
    cout << (m0 != m1) << endl;
    cout << noboolalpha;

    cout << m1++ << endl;
    cout << m1 << endl;
    cout << ++m1 << endl;

    cout << m1 + m2 << endl;
    m1 += m2;
    cout << m1 << endl;
    cout << m3 + m2 << endl;

    return 0;
}
class Point {
private:
    static int nextId;
    static int nbPoints;

    const int id;
    double x, y;
    double xMax, yMax;

public:
    Point(double x_val =0.0 , double y_val =0.0, double xMax_val=100.0, double yMax_val=100.0): id(nextId), x(x_val), y(y_val),
    xMax(xMax_val), yMax(yMax_val){  nbPoints++;}

    ~Point() {
        nbPoints --;
    }

Point (const Point& other):
    id(nextId),
    x(other.x), y(other.y),
    xMax(other.xMax),yMax(other.yMax) {
        nbPoints++;
    }

    Point& operator =(const Point& other) {
        if(this != &other) {
            this -> x = other.x;
            this -> y = other.y;
            this -> xMax = other.xMax;
            this -> yMax = other.yMax;
        }
        return *this;
    }

    static int getNbPoints() {
        return nbPoints;
    }

    void afficher()const {
        cout << "Point ID = " << id << ", (" << x << "," << y
             << "), contraintes: [0," << xMax << "]x[0," << yMax << "]" << endl;
    }

};
int Point::nextId = 1;
int Point::nbPoints = 0;
int main() {
    Point p1(1.2, 2.4);
    p1.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    {
        Point p2(3., 4.2, 10., 10.);
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;

        p2 = p1; // Assignation, pas de création.
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;

        Point p3 = p2; // Initialisation par copie, création de p3.
        p3.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;
    } // p2 et p3 sont détruits ici, le compteur va diminuer de 2.

    Point p4(5, 10);
    p4.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    return 0;
}


class Message {
private:
    string texte;
    static int compteur_instances;

public:
    Message(const string &s) : texte(s) {
        cout << "   [+] Création du Message (\"" << texte << "\")" << endl;
        compteur_instances++;
    }
    ~Message() {
        cout << "   [-] Destruction du Message (\"" << texte << "\")" << endl;
        compteur_instances--;
    }

  Message(const Message& autre):texte(autre.texte) {
        cout << "   [=>] COPIE du Message (\"" << texte << "\"). Un nouvel objet est ne." << endl;
        compteur_instances++;
    }

    Message& operator=(const Message& autre) {
        cout << "   [=] ASSIGNATION au Message (\"" << this->texte
            << "\") de la valeur (\"" << autre.texte << "\"). Pas de nouvel objet." << endl;

        if(this != &autre) {
            this -> texte = autre.texte;
        }
        return *this;
    }
    static int getNbMessages() {
        return compteur_instances;
    }
};

int Message::compteur_instances = 0;

int main() {
    cout << "--- Début ---" << endl;

    // 1. Création simple
    Message m1("Original");

    // 2. Initialisation par copie -> appelle le CONSTRUCTEUR DE COPIE
    cout << "\n--- Initialisation de m2 a partir de m1 ---" << endl;
    Message m2 = m1; // ou Message m2(m1); même chose

    // 3. Assignation -> appelle l'OPERATEUR D'ASSIGNATION
    cout << "\n--- Assignation de m1 a m3 ---" << endl;
    Message m3("Autre");
    m3 = m1; // m3 existe déjà, on ne fait que le modifier

    cout << "\n--- Fin ---" << endl;
    return 0;
}

class Voiture {
private:
    double capacite_reservoir;
    double consommation_moyenne;
    double nb_litres_restants;
    static double prix_essence;

public:
    Voiture(double capacite, double consommation):
    capacite_reservoir(capacite),
    consommation_moyenne(consommation),
    nb_litres_restants(capacite){}

    double effectuerTrajet(double distance) {
        double litres_necessaires =  distance * consommation_moyenne/100.0;

        if(litres_necessaires > nb_litres_restants) {
            double litres_manquants = litres_necessaires - nb_litres_restants;
            int nb_pleins= ceil(litres_manquants / capacite_reservoir);

            nb_litres_restants += nb_pleins  * capacite_reservoir;
        }

        nb_litres_restants -= litres_necessaires;

        return litres_necessaires * prix_essence;
    }

    double getCapacite()const {
        return capacite_reservoir;
    }
    double getConsommation()const {
        return consommation_moyenne;
    }
    double getNbLitresRestant()const {
        return nb_litres_restants;
    }
    static double getPrixEssence() {
        return prix_essence;
    }
    static void setPrixEssence(double nouveau_prix) {
        prix_essence = nouveau_prix;
    }
};

double Voiture::prix_essence = 1.70;

    void afficherPrixEssence(double prix) {

        cout<<"Prix de l'essence: "<<fixed<<setprecision(2)<<prix<<"Frs"<<endl;
    }

void afficherVoiture(const Voiture& v) {
        cout<<"Capacite du reservoir [l] :"<<v.getCapacite()<<endl;
        cout<<"Consommation moyenne [l/100km] : "<<v.getConsommation()<<endl;
    cout<<"Nb litres restants   : "<<fixed<<setprecision(1)<<v.getNbLitresRestant()<<endl;
    }
void afficherCoutTrajet(double cout_trajet) {
        cout<<"Cout du trajet : "<<fixed<<setprecision(2)<<cout_trajet<<" Frs"<<endl<<endl;
    }


int main() {
        afficherPrixEssence(Voiture::getPrixEssence());

        Voiture::setPrixEssence(1.95);
        afficherPrixEssence(Voiture::getPrixEssence());

        Voiture v(52, 6.7);

        afficherVoiture(v);
        afficherCoutTrajet(v.effectuerTrajet(1000));
        afficherVoiture(v);
        afficherCoutTrajet(v.effectuerTrajet(200));
        afficherVoiture(v);

        return EXIT_SUCCESS;
    }
    class Voiture {
private:
    double capacite_reservoir;
    double consommation_moyenne;
    double nb_litres_restants ;

    static double prix_essance;

public:
    Voiture(double capacite, double consommation):
    capacite_reservoir(capacite),
    consommation_moyenne(consommation),
    nb_litres_restants(capacite){}

    double effectuerTrajet(double distance) {
        double litres_necessaires = distance * consommation_moyenne /100.0;

        if(litres_necessaires > nb_litres_restants) {
            double litres_manquants = litres_necessaires - nb_litres_restants;
            int nb_pleins = ceil(litres_manquants / capacite_reservoir);
            nb_litres_restants += nb_pleins * capacite_reservoir;
        }

        nb_litres_restants -= litres_necessaires;

    return litres_necessaires * prix_essance;
    }

    double getCapacite()const {
        return capacite_reservoir;
    }
    double getConsommation()const {
        return consommation_moyenne;
    }
    double getlitresRestant()const {
        return nb_litres_restants;
        }

    static double getPrixEssence () {
        return prix_essance;
    }

    static void setPrixEssence(double nouveau_prix) {
        prix_essance = nouveau_prix;
    }
};
double Voiture::prix_essance =1.70;

void afficherPrixEssence(double prix) {
    cout<<"Prix de l'essence" << fixed<<setprecision(2)<<prix<<" Frs"<<endl;
}

void afficherVoiture(const Voiture& v) {
    cout<<"Capacite du reservoir [l] :"<<v.getCapacite()<<endl;
    cout<<"Consommation moyenne [l/100km] : "<<v.getConsommation();
    cout<<"Nb litres restants   : "<<fixed<<setprecision(1)<<v.getlitresRestant()<<endl;;
}

void afficherCoutTrajet(double cout_trajet) {
    cout<<"Cout du trajet : "<<fixed<<setprecision(2)<<cout_trajet<<" Frs"<<endl;
}




int main() {

    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture::setPrixEssence(1.95);
    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture v(52, 6.7);

    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(1000));
    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(200));
    afficherVoiture(v);

    return EXIT_SUCCESS;
}

#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;
    double xMax;
    double yMax;
    const int id;

    static int nextId;
    static int nbPoints;

    public:
    Point(double x_val=0.0, double y_val =0.0, double xMax_val=100.0, double yMax_val=100.0);
    Point(const Point& other);

    //Declaration du destructeur
    ~Point();

    Point& operator=(const Point& other);

    void afficher() const;

    static int getNbPoints();

};

#endif



#include "Point.h"
#include <iostream>
using namespace std;

int Point::nextId =1;
int Point::nbPoints = 0;

Point::Point(double x_val, double y_val, double xMax_val, double yMax_val):
x(x_val), y(y_val), xMax(xMax_val), yMax(yMax_val), id(nextId++) {
    nbPoints++;
}

Point::Point(const Point& other)
    : x(other.x), y(other.y), xMax(other.xMax), yMax(other.yMax), id(nextId++) {
    nbPoints++;
}

Point::~Point() {
    nbPoints --;
}

Point& Point::operator=(const Point& other) {
    if(this != &other) {
        this ->x =  other.x;
        this-> y = other.y;
        this -> xMax = other.xMax;
        this -> yMax = other.yMax;
    }
    return *this;
}


void Point::afficher()const {
    cout<<"Point ID = "<<id<<", ("<<x<<","<<y<<"), MaxX = "<<xMax<<", MaxY = "<<yMax<<endl;
}

int Point::getNbPoints() {
    return nbPoints;
}

//main.cpp
#include <iostream>
#include "Point.h"
int main() {
    Point p1(1.2, 2.4);
    p1.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    {
        Point p2(3., 4.2, 10., 10.);
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;
    } // Le destructeur de p2 est appelé ici

    Point p3(5, 10);
    p3.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    return 0;
#ifndef VOITURE_H
#define VOITURE_H
class Voiture {
private:
    double capacite_reservoir;
    double consommation_moyenne;
    double nb_litres_restants;

    static double prix_essence;

public:
    Voiture(double capacite, double consommation);

    double effectuerTrajet(double distance);
    double getCapacite() const;
    double getConsommation()const;
    double getNbLitresRestants()const;

    static double getPrixEssence();
    static void setPrixEssence(double nouveau_prix);
};

void afficherPrixEssence(double prix);
void afficherVoiture(const Voiture& v);
void afficherCoutTrajet(double cout_trajet);



#endif

//voiture.__cpp

#include <Voiture.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Voiture::prix_essence = 1.70;

Voiture::Voiture(double capacite, double consommation)
    :capacite_reservoir(capacite),
consommation_moyenne(consommation),
nb_litres_restants(capacite){}

double Voiture::effectuerTrajet(double distance) {
    double litres_necessaires = distance * consommation_moyenne/100.0;
    if(litres_necessaires > nb_litres_restants) {
        double litres_manquants = litres_necessaires -nb_litres_restants;
        int nb_pleins = ceil(litres_manquants / capacite_reservoir);
        nb_litres_restants += nb_pleins * capacite_reservoir;
    }
    nb_litres_restants -= litres_necessaires;
    return litres_necessaires * prix_essence;
}

double Voiture::getCapacite()const {
    return capacite_reservoir;
}

double Voiture::getConsommation()const {
    return consommation_moyenne;
}
double Voiture::getNbLitresRestants() const {
    return nb_litres_restants;
}

double Voiture::getPrixEssence() {
    return prix_essence;
}

void Voiture::setPrixEssence(double nouveau_prix) {
    prix_essence = nouveau_prix;
}

void afficherPrixEssence(double prix) {
    cout << "Prix de l'essence : " << fixed << setprecision(2) << prix << " Frs" << endl << endl;
}
void afficherVoiture(const Voiture& v) {
    cout << "Capacite du reservoir [l]      : " << v.getCapacite() << endl;
    cout << "Consommation moyenne [l/100km] : " << v.getConsommation() << endl;
    cout << "Nb litres restants             : " << fixed << setprecision(1) << v.getNbLitresRestants() << endl << endl;
}


void afficherCoutTrajet(double cout_trajet) {
    cout << "Cout du trajet : " << fixed << setprecision(2) << cout_trajet << " Frs" << endl << endl;
}
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <vector>
#include <ctime> // time et date

class Message {
private:
    string expediteur;
    string destinateur;
    vector<string> contenu;

    const time_t dateCreation;

public:
    Message(string& sender, string& recipient);

    void ajouter(const string& ligne);

    string toString()const;

    void afficcher()const;
};


#endif

#include "message.h"
#include <iostream>
#include <sstream>

Message::Message(const string& sender, const string& recipient)
    :expediteur(sender),
destinateur(recipient),
dateCreation(time(nullptr)) {}

void Message::ajouter (const string& ligne) {
    contenu.push_back(ligne);
}

string Message::toString()const {
    char buffer[100];
    strftime(buffer, sizeof(buffer),"%d.%m.%Y %X", localtime(&dateCreation));

    stringstream ss;

    ss<< "From: "<<expediteur<<"\n"
    <<"To   : "<< destinateur<<"\n"
    <<"Date : "<<buffer<<"\n\n";

    for(const auto & ligne : contenu) {
        ss<<ligne<<"\n";
    }

    return ss.str();
}

void Message::afficher()const {
    cout<<this->toString();
}

#ifndef
#define
#include <ctime>

class Message {
private:
    string expediteur;
    string destinataire;
    vector<string> contenu;
    const time_t date_creation;

public:
    Message(const string& exp, const string& dest);
    void ajouter(const string& ligne);
    string toString()const;
    void afficher()const;
};
#endif

#include "message.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Message::Message(const string& exp, const string& dest)
    :expediteur(exp),
destinataire(dest),
date_creation(time(nullptr)){}

void Message::ajouter(const string &ligne) {
    contenu.push_back(ligne);
}

string Message::toString() const {
    stringstream ss;
    const string FORMAT = "%d.%m.%Y %X";

    char buffer[256];

    strftime(buffer, sizeof(buffer), FORMAT.c_str(), localtime(&date_creation));

    ss<<"From   : "<<expediteur<<"\n"
    <<"To   : "<<destinataire<<"\n"
    <<"Date     : "<<buffer<<"\n\n";

    for(const auto& ligne : contenu) {
        ss<<ligne<<"\n";
    }

    return ss.str();
}

void Message::afficher() const {
    cout<<this -> toString();
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os<<p.first<<" => "<<p.second;
    return os;
}

template<typename T>
void display(T first, T last) {
    for(T it = first; it != last; ++it) {
        cout<<*it<<"\t"<<static_cast<const void*>(&(*it))<<endl;
    }
    cout<<endl;
}


int main() {
    array  a  {1, 2, 3};
    vector v  {1.1, 2.2, 3.3};
    string s  ("HEIG-VD"s);
    list   l  {"chien"s, "chat"s, "souris"s};

    cout << "array"   << endl;    display(a.cbegin(), a.cend());
    cout << "vector"  << endl;    display(v.cbegin(), v.cend());
    cout << "string"  << endl;    display(s.cbegin(), s.cend());
    cout << "list"    << endl;    display(l.cbegin(), l.cend());

    map<string, int> scores = {
        {"Alice", 100},
        {"Bob", 95},
        {"Charlie", 105}
    };

    cout << "map" << endl;
    display(scores.cbegin(), scores.cend());

    return 0;
}

template<typename Iterator>
void display(Iterator first, Iterator last) {
    cout<<"[";
    for(Iterator it = first; it != last; ++it){
        if(it != first) cout<<", ";
        cout<<*it;
    }
    cout<<"]\n";
}

int main() {
    vector v  {1, 2, 3, 4};
    display(v.cbegin(), v.cend());

    vector<int>::const_iterator begin = v.cbegin();
    vector<int>::const_iterator end   = v.cend();

    v.push_back(5);

    display(v.cbegin(), v.cend());
    display(begin, end);
}

template<typename Iterator>
vector<typename iterator_traits<Iterator>::value_type>
concat_tab_boucle(Iterator first1, Iterator last1, Iterator first2, Iterator last2) {
    using T = typename iterator_traits<Iterator>::value_type;
    vector<T> resultat;
    for(Iterator it = first1; it != last1; ++it) {
        resultat.push_back(*it);
    }

    for(Iterator it = first2 ; it != last2 ; ++it) {
        resultat.push_back(*it);
    }
    return resultat;
}


template<typename Iterator>
vector<typename iterator_traits<Iterator>::value_type>
concat_tab_sans_boucle(Iterator first1, Iterator last1, Iterator first2, Iterator last2) {
    using T = typename iterator_traits<Iterator>::value_type;
    vector<T> resultat(first1, last1);

    resultat.insert(resultat.end(), first2, last2);
    return resultat;
}

template<typename T>
void display(const vector<T>& v) {
    cout<<"[";
    for(size_t i =0; i<v.size(); ++i) {
        cout<<v[i]<<(i == v.size()-1 ? "" : ", ");
    }
    cout<<"]"<<endl;
}
int main() {
    vector<int> v = {11, 12, 13};
    array<int, 5> a = {21, 22, 23, 24, 25};

    cout << "vector   : "; display({v.begin(), v.end()});
    cout << "array    : "; display({a.begin(), a.end()});

    // Test de la solution 1
    auto resultat1 = concat_tab_boucle(v.begin(), v.end(), a.begin(), a.end());
    cout << "resultat (avec boucle) : "; display(resultat1);

    // Test de la solution 2
    auto resultat2 = concat_tab_sans_boucle(v.begin(), v.end(), a.begin(), a.end());
    cout << "resultat (sans boucle) : "; display(resultat2);

    return 0;
}

template<typename Iterator1, typename Iterator2>
auto merge(Iterator1 first1, Iterator1 last1,
            Iterator2 first2, Iterator2 last2) {
    using T = typename iterator_traits<Iterator1>::value_type;
    vector<T> resultat;

    resultat.reserve(distance(first1, last1) + distance(first2, last2));

    while(first1 != last1 && first2 != last2) {
        resultat.push_back(*first1++);
        resultat.push_back(*first2++);
    }

    while(first1 != last1) {
        resultat.push_back(*first1++);
    }
    while(first2 != last2) {
        resultat.push_back(*first2++);
    }
    return resultat;
}

template<typename T>
void display(const T& container) {
    cout<<"[";
    for(auto it = container.begin(); it != container.end(); ++it) {
        if(it != container.begin()) cout<<", ";
        cout<<*it;
    }
    cout<<"]";
    cout<<endl<<endl;
}

int main() {
   // vector<string> v = {"ker", "im", "selam"};
    vector<int> v = {11, 12, 13};
    array<int, 5> a = {21, 22, 23, 24, 25};

    cout << "vector   : "; display(v);
    cout << "array    : "; display(a);

    auto resultat = merge(v.begin(), v.end(), a.begin(), a.end());
    cout << "resultat : "; display(resultat);

    return 0;
}

template<typename T>
auto count_in_range_loop(const vector<T>& vec, T min_el, T max_el) {
    int count = 0;
    for(const T& el : vec) {
        if(el >= min_el && el <= max_el) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> vecteur = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min_intervalle = 3;
    int max_intervalle = 6;

    int resultat = count_in_range_loop(vecteur, min_intervalle, max_intervalle);

    std::cout << "Approche 1 (Boucle Manuelle)" << std::endl;
    std::cout << "Vecteur    : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]" << std::endl;
    std::cout << "Intervalle : [" << min_intervalle << ", " << max_intervalle << "]" << std::endl;
    std::cout << "Résultat   : " << resultat << std::endl; // Doit afficher 4

    return 0;
}

template<typename T>
int count_in_range_stl(const vector<T>& vec, T min_el, T max_el) {
    return count_if(vec.begin(), vec.end(),
        [min_el, max_el](const T& el) {
            return el >= min_el && el <= max_el;
        });
}



int main() {
    std::vector<int> vecteur = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min_intervalle = 3;
    int max_intervalle = 6;

    int resultat = count_in_range_stl(vecteur, min_intervalle, max_intervalle);

    std::cout << "\nApproche 2 (STL avec count_if et lambda)" << std::endl;
    std::cout << "Résultat   : " << resultat << std::endl; // Doit afficher 4

    return 0;
}
template<typename T>
int count_in_range_sorted(const vector<T>& vec, T min_el, T max_el) {
    auto lower = lower_bound(vec.begin(), vec.end(), min_el);
    auto upper = upper_bound(vec.begin(), vec.end(), max_el);

    return distance(lower, upper);
}

int main() {
    // Le vecteur est déjà trié dans cet exemple.
    std::vector<int> vecteur = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min_intervalle = 3;
    int max_intervalle = 6;

    // Si le vecteur n'était pas trié, il faudrait faire :
    // std::sort(vecteur.begin(), vecteur.end());

    int resultat = count_in_range_sorted(vecteur, min_intervalle, max_intervalle);

    std::cout << "\nApproche 3 (Données triées)" << std::endl;
    std::cout << "Résultat   : " << resultat << std::endl; // Doit afficher 4

    return 0;
}
template<typename T>
auto vect_iter_val(const vector<T>& v, const T& valeur) {
    using const_it = typename vector<T>::const_iterator;

    vector<const_it> iter_vec;

    for(const_it it = v.cbegin(); it != v.cend(); ++it) {
        if(*it == valeur) {
            iter_vec.push_back(it);
        }
    }
    return iter_vec;
}

template<typename T>
void display(const vector<T>& v) {
    cout<<"[";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) cout <<", ";
        cout<<*v[i];
    }
    cout<<"]";
}



int main() {

    const vector<int> v = {1, 2, 3, 2, 4, 2, 2, 6, 2};
    int valeur_a_chercher = 2;

    auto iterateurs = vect_iter_val(v, valeur_a_chercher);

    display(iterateurs);

    return 0;
}

template<typename T>
vector<typename vector<T>::const_iterator>
vect_iter_val(const vector<T>& vec, const T& val) {
    using It_type = typename vector<T>::const_iterator;
    vector<It_type> resultat_iters;

    for(auto it = vec.cbegin(); it != vec.cend(); ++it) {
        if(*it == val) {
            resultat_iters.push_back(it);
        }
    }
    return resultat_iters;
}

template<typename T>
void display(const vector<T>& v) {
    cout<<"[";
    for(size_t i =0 ; i < v.size(); ++i) {
        cout<<v[i]<<(i == v.size()-1 ? "" : ", ");
    }
    cout<<"]";
}
template<typename T>
void display_iterateurs(const vector<typename vector<T>::const_iterator>& v_iters) {
    cout<<"[";
    for(size_t i =0; i < v_iters.size(); ++i) {
        cout<<*v_iters[i]<<(i == v_iters.size()-1 ? "" : ", ");
    }
    cout<<"]";
}

int main() {
    const vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};
    cout<<"vecteur d'entiers     : ";
    display(v);

    auto iterateurs_sur_2 = vect_iter_val(v, 2);
}

template<typename T>
auto vect_iter_val_algo(const vector<T>& v, const T& valeur) {
    using const_iterator = typename vector<T>::const_iterator;
vector<const_iterator>iter_vec;

    auto current_pos = v.cbegin();
    while(true) {
        auto found_it = find_if(current_pos , v.cend(),
            [valeur](const T& element) {
                return element == valeur;
            }
            );
        if(found_it == v.cend()) {
            break;
        }
        iter_vec.push_back(found_it);

        current_pos = next(found_it);
    }
    return iter_vec;
}

template<typename T>

void display_dereferenced(const vector<T>& iter_vec) {
    cout<<"[";
    for(auto it = iter_vec.begin(); it != iter_vec.end(); ++it) {
        cout<<**it;
        if(next(it) != iter_vec.end()) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

int main() {
    const std::vector<int> v = {1, 2, 3, 2, 4, 2, 2, 6, 2};
    int valeur_a_chercher = 2;

    std::cout << "--- Algorithmic Solution ---" << std::endl;

    auto iterateurs = vect_iter_val_algo(v, valeur_a_chercher);

    std::cout << "vecteur d'entiers     : [1, 2, 3, 2, 4, 2, 2, 6, 2]" << std::endl;
    std::cout << "vecteur d'iterateurs  : ";
    display_dereferenced(iterateurs);

    return 0;
}
template<typename T>
bool meme_elements(span<const T>v1, span<const T> v2) {
    unordered_set<T> a = {v1.begin(), v1.end()};
    unordered_set<T> b = {v2.begin(), v2.end()};

    return a == b;
}
int main() {
    array<int, 10> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int>v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};

    cout<<boolalpha;
    cout << "Test 1 (Exemple de l'énoncé): Les conteneurs ont-ils les mêmes éléments ? "
         << meme_elements<int>(a, v) << endl;

    // Cas de test supplémentaire (doit retourner false)
    vector<int> v_false = {1, 2, 3, 99};
    cout << "Test 2 (Cas 'false'): Les conteneurs ont-ils les mêmes éléments ? "
         << meme_elements<int>(a, v_false) << endl;

    // Cas de test avec des conteneurs vides (doit retourner true)
    vector<int> empty1, empty2;
    cout << "Test 3 (Conteneurs vides): Les conteneurs ont-ils les mêmes éléments ? "
         << meme_elements<int>(empty1, empty2) << endl;
return 0;

}
template<typename T>
bool sont_anagrammes(span<const T> r1, span<const T>r2){
    if(r1.size() != r2.size()) {
        return false;
    }

    unordered_multiset<T> multiset1(r1.begin(), r1.end());
    unordered_multiset<T> multiset2(r2.begin(), r2.end());

    return multiset1 == multiset2;
}

int main() {
    cout<<boolalpha;
    vector<int> v1 = {1, 5, 2, 2};
    array<int, 4> a1 = {2, 1, 5, 2};
    cout << "Test 1 (Anagrammes): " << sont_anagrammes<int>(v1, a1) << endl;
}
template<typename T1, typename T2>
bool sont_anagrammes_map(const T1& c1, const T2& c2) {
    if(c1.size() != c2.size()) {
        return false;
    }

    unordered_map<typename T1::value_type, int>frequences;
    for(const auto& element : c1) {
        frequences[element]++;
    }

    for(const auto& element : c2) {
        if(frequences.find(element) == frequences.end() || frequences[element] == 0) {
            return false;
        }
        frequences[element]--;
    }
    return true;
}
template<typename T>
class Coord {
private:
    T x;
    T y;

public:
    Coord():x(T{}), y(T{}){}
    Coord(T x_val, T y_val): x(x_val), y(y_val){}

    void setCoord(T new_x, T new_y) {
        x = static_cast<T>(new_x);
        y = static_cast<T>(new_y);
    }

    void deplacer(T new_x, T new_y) {
        x += static_cast<T>(new_x);
        y += static_cast<T>(new_y);
    }

    T getX()const {
        return x;
    }
    T getY()const {
        return y;
    }

    void afficher() const {
        cout<<"("<<x<<", "<<y<<")";
    }

Coord<T>& operator +=(const Coord<T>& other) {
        this -> x += other.x;
        this -> y += other.y;
        return *this;
    }


};

template<typename T>
Coord<T> operator +(Coord<T> lhs, const Coord<T>& rhs) {
    lhs += rhs;
    return lhs;
}


int main() {
    Coord<int> p1(1, 2);
    Coord<int> p2(3, 4);

    cout << "p1 initial : ";
    p1.afficher();
    cout << endl;

    // Utilisation de l'opérateur +=
    p1 += p2;

    cout << "p1 final   : ";
    p1.afficher(); // Devrait afficher (4, 6)
    cout << endl;

    return 0;
}
template<typename T>
class Coord {
private:
    T x;
    T y;
public:
    Coord(): x(T{}), y(T{}){}
    Coord(T x_val, T y_val):x(x_val), y(y_val){}

    //Accesseurs(getters)
    T getX()const {
        return x;
    }

    T getY()const {
        return y;
    }

    template<typename U>
    void deplacer(U dx, U dy) {
        x += static_cast<U>(dx);
        y += static_cast<U>(dy);
    }

    void afficher()const {
        cout<<"("<<x<<", "<<y<<")";
    }
};
template<typename T>
    class Point {
    private:
        string nom;
        Coord<T> coord;

    public:
        Point():nom(""), coord(){}

        explicit Point(const string& name_val) : nom(name_val), coord(){}
        Point(const string& name_val, const Coord<T>& coord_val): nom(name_val), coord(coord_val){}
        Point(const string & name_val, T x, T y):nom(name_val), coord(x,y){}

        void setNom(const string& new_name) {
            nom = new_name;
        }

        void setCoord(const Coord<T>& new_coord) {
            coord = new_coord;
        }

        const string& getNom()const {
            return nom;
        }


        const Coord<T>& getCoord()const {
            return coord;
        }

        template<typename U>
        void deplacer(U dx, U dy) {
            coord.deplacer(dx, dy);
        }
        void afficher()const {
            cout<<nom;
            coord.afficher();
        }

};

    int main() {
        const Point<int> origin;

        cout << "p1       : ";
        Point<int> p1("p1"s);
        p1.afficher();
        cout << endl;

        cout << "p2       : ";
        Point<double> p2("p2"s, Coord(1.2, 3.4));
        p2.afficher();
        cout << endl;

        cout << "p3       : ";
        Point<double> p3("p3"s, 1.2, 3.4);
        p3.afficher();
        cout << endl;

        cout << "p3.1     : ";
        p3.setNom("p3.1"s);
        p3.afficher();
        cout << endl;

        cout << "p1(-1, 1): ";
        p1.setCoord(Coord(-1, 1));
        p1.afficher();
        cout << endl;

        cout << "p1->     : ";
        p1.deplacer(-1, 1);
        p1.afficher();
        cout << endl;

        cout << "p1(x)    : ";
        cout << p1.getNom() << " " << p1.getCoord().getX();
        cout << endl;

        return 0;
    }
template<typename T>
class Coord {
private:
    T x, y;
public:
    Coord(): x(T{}), y({}){}
    Coord(T x_val, T y_Val): x (x_val), y(y_Val){}

    template<typename U>
    void deplacer()

};
using namespace std;

template<typename T>
class Coord {
private:
    T x ,y;

public:
    Coord():x(T{}) , y(T{}){}

    Coord(const T& x_val, const T& y_val) : x(x_val), y(y_val){}

    void setCoord(const T& x_val, const T& y_val) {
        x = x_val;
        y = y_val;
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    void afficher()const {
        cout<<"("<<x<<", "<< y<<")";
    }

    template<typename U>
    void deplacer(const U& dx, const U& dy) {
        x += static_cast<T>(dx);
        y += static_cast<T>(dy);
    }
};

int main() {
    cout << "origine  : ";
    const Coord<int> origin;
    origin.afficher();
    cout << endl;

    cout << "p1       : ";
    Coord<int> p1;
    p1.setCoord(1, 2);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Coord<double> p2(3, 4);
    p2.afficher();
    cout << endl;

    cout << "p2->     : ";
    p2.deplacer(1, 1);   // conversion int => double
    cout << "(" << p2.getX() << ", " << p2.getY() << ")";
    cout << endl;

    return 0;
}
template <typename T>
class Coord {
private:
    T x, y;

public:
    Coord():x(T{}), y(T{}){}
    Coord(T x_val, T y_val): x (x_val), y(y_val){}

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    void afficher()const {
        cout<<"("<<x<<", "<<y<<")";
    }
};

template <typename T>
class Point {
private:
    string nom;
    Coord<T> coord;

public:
    Point():nom(""), coord(){}
    explicit Point(const string& name_val) : nom(name_val), coord(){}
    Point(const string& name_val, const Coord<T>& coord_val) : nom(name_val), coord(coord_val){}
    Point(const string& name_val, T x, T y) : nom(name_val), coord(x, y){}

    const string& getNom()const {
        return nom;
    }

    const Coord<T>& getCoord()const {
        return coord;
    }
    void afficher()const {
        cout<<nom<<"("<<coord.getX()<<", "<<coord.getY()<<")";
    }
};

template<typename T>
ostream& operator<<(ostream& os, const Coord<T>& c) {
    os<<"("<<c.getX()<<", "<<c.getY()<<")";
    return os;
}
template<typename T>
 ostream& operator<<(ostream& os, const Point<T>& p) {
    os<<p.getNom()<<p.getCoord();
    return os;

}

int main() {
    Point<double> p3("p3"s, 1.2, 3.4);

    // Ancienne méthode
    cout << "p3 (via .afficher) : ";
    p3.afficher();
    cout << endl;

    // Nouvelle méthode idiomatique en C++
    cout << "p3 (via operator<<)  : " << p3 << endl;

    // On peut maintenant chaîner les affichages !
    Point<int> p1("p1"s, 10, 20);
    cout << "Deux points sur la meme ligne : " << p1 << " et " << p3 << endl;

    return 0;
}
template<typename T>
class Coord {
private:
    T x, y;
public:
    Coord(T x_val =0, T y_val = 0): x(x_val), y(y_val){}
    T getX() const {return x;}
    T getY() const {return y;}
};
template<typename T>
class Point {
    string nom;
    Coord<T> coord;
public:
    Point(string n, T x, T y) : nom(n), coord(x, y){}
    const Coord<T>& getCoord() const{ return coord;}
    const string& getNom() const { return nom;}
};

int main() {
    vector<Point<int>> dessin {{"p1", 1, 2}, {"p2", 4, 2}, {"p3", 9, 8},
                              {"p4", -1, 5}, {"p5", 3, -1}, {"p6", 7, 0}};

    int sayac_q1 =0;
    cout << "Vektördeki noktalar tek tek kontrol ediliyor..." << endl;

    for(const Point<int>& p : dessin) {
        int x = p.getCoord().getX();
        int y = p.getCoord().getY();

        cout << "  -> " << p.getNom() << "(" << x << ", " << y << ") kontrol ediliyor. ";

        if(x>0 && y > 0) {
            sayac_q1++;
            cout << "Bu nokta I. çeyrekte! Sayaç şimdi: " << sayac_q1 << endl;
        }else {
            cout << "Bu nokta I. çeyrekte değil." << endl;
        }

        cout << "\n----------------------------------------" << endl;
        cout << "Toplam Sonuç: I. çeyrekte " << sayac_q1 << " adet nokta bulundu." << endl;
        cout << "----------------------------------------" << endl;
    }
    return 0;
}
template<typename T>
class Coord {
    T x, y;
public:
    Coord(T x_val = 0, T y_val =0) : x(x_val) , y(y_val){}
    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }
};

template<typename T>
class Point {
    string nom;
    Coord<T> coord;
public:
    Point(string n, T x, T y) : nom(n), coord(x, y){}
    const Coord<T> & getCoord() const {
        return coord;
    }

    const string& getNom()const {
        return nom;
    }
};

enum class Quadrant{I, II, III, IV};
struct DansQuadrant {
    Quadrant quadrant_a_tester;

    explicit DansQuadrant(Quadrant q) {
        quadrant_a_tester = q;
    }

    bool operator()(const Point<int>& p) const {
        int x = p.getCoord().getX();
        int y = p.getCoord().getY();

        if(x == 0 || y == 0) {
            return false;
        }

        switch(quadrant_a_tester) {
            case Quadrant ::I : return x>0 && y>0;
            case Quadrant ::II : return x <0 && y >0;
            case Quadrant :: III : return  x <0 && y <0;
            case Quadrant :: IV : return x >0 && y<0;
            default : return false;
        }

    }
};

int main() {
    vector<Point<int>> dessin {{"p1", 1, 2}, {"p2", 4, 2}, {"p3", 9, 8},
                               {"p4", -1, 5}, {"p5", 3, -1}, {"p6", 7, 0}};


    cout << "Compter pour le 1er quart-temps..." << endl;
    int sayac_q1 = count_if(dessin.begin(), dessin.end(), DansQuadrant(Quadrant::I));
    cout << "result: " << sayac_q1 << " nombre de points trouvés." << endl;



    cout << "\nCompter pour le deuxième quart-temps..." << endl;

    int sayac_q2 = count_if(dessin.begin(), dessin.end(), DansQuadrant(Quadrant::II));
    cout << "result: " << sayac_q2 << " nombre de points trouvés" << endl;

    cout << "\nCompter pour le quatrième quart-temps..." << endl;
    int sayac_q4 = count_if(dessin.begin(), dessin.end(), DansQuadrant(Quadrant::IV));
    cout << "result: " << sayac_q4 << " nombre de points trouvés" << endl;

    return 0;
}
template<typename T>
class Coord {
    T x, y;
public:
    Coord(T x_val =0, T y_val=0): x(x_val), y(y_val){}
    T getX()const{return x;}
    T getY()const {return y;}
};

template<typename T>
class Point {
private:
    string nom;
    Coord<T> coord;

public:
    Point(string n, T x,T y) : nom(n), coord(x, y){}
    const string& getNom()const{return nom;}
    const Coord<T>& getCoord()const{return coord;}
};

template<typename T>
ostream& operator<<(ostream& os, const Coord<T>& c) {
    return os<<"("<<c.getX()<<", "<<c.getY()<<")";
}

template<typename T>
ostream& operator<<(ostream& os, const Point<T>& p) {
    return os<<p.getNom()<<p.getCoord();
}

template<typename T>
void listerPoints(const vector<Point<T>>& points,
    const string& titre,
    ostream& os = cout) {
    os<<titre<<endl;
    os<<string(titre.length(), '-')<<endl;

    if(points.empty()) {
        os<<"la liste est vide."<<endl;
        return;
    }

    for(const auto& point: points) {
        os<<" - "<<point<<endl;
    }
}


int main() {
    vector<Point<int>> dessin {
            {"p1",  1,  2}, {"p2",  4,  2}, {"p3",  9,  8},
            {"p4", -1,  5}, {"p5",  3, -1}, {"p6",  7,  0}
    };

    // On appelle notre nouvelle fonction pour afficher le contenu du vecteur 'dessin'.
    listerPoints(dessin, "Liste des points du dessin");

    return 0;
}
class Coord {
private:
    T x, y;
public:
    Coord() : x(T{}), y(T{}){}
    Coord(T x_val, T y_val) : x(x_val), y(y_val){}
    T getx()const{return x;}
    T getY()const{return y;}
    void afficher()const {
        cout<<"("<<x << ", "<< y<<")";
    }
};

template<typename T>
class Point {
private:
    string nom;
    Coord<T> coord;

public:
    Point(const string& n, T x_val, T y_val) : nom(n), coord(x_val, y_val){}
    const string& getNom()const{ return nom;}
    const Coord<T>& getCoord()const{return coord;}
    void afficher()const {
        cout<<nom;
        coord.afficher();
    }
};

template<typename Container>
void listerPoint(const Container& points) {
    cout<<"--- Liste des points ---";

    for(const auto& point : points) {
        point.afficher();
        cout<<endl;
    }
    cout<<"----------------"<<endl;
}

int main() {
    using namespace std::string_literals;

    // Le même vecteur que dans l'exercice précédent
    std::vector<Point<int>> dessin {{"p1",  1,  2},
                                    {"p2",  4,  2},
                                    {"p3",  9,  8},
                                    {"p4", -1,  5},
                                    {"p5",  3, -1},
                                    {"p6",  7,  0}};

    // Appel de notre nouvelle fonction générique
    listerPoint(dessin);

    return 0;
}
template<typename T>
class Coord {
    T x,  y;
public:
    Coord(T x_val =0, T y_val =0): x(x_val), y(y_val){}
    T getX() const{return x;}
    T getY() const{return y;}
    void deplacer(T dx, T dy) {
        x +=dx;
        y += dy;
    }
};

template<typename T>
class Point {
    string nom;
    Coord<T> coord;
public:
    Point(string n, T x, T y): nom(n), coord(x, y){}
    const string& getNom() const{return nom;}
    const Coord<T>& getCoord()const{return coord;}
    void deplacer(T dx, T dy){coord.deplacer(dx, dy);}
};

template <typename T>
ostream& operator<<(ostream& os, const Point<T>& p) {
    return os<<p.getNom()<<"("<<p.getCoord().getX()<<", "<<p.getCoord().getY()<<")";
}
template<typename T, size_t CAPACITY =100>
class Stack {
private:
    array<T, CAPACITY> data;
    int top_index ;

public:
    Stack(): top_index(-1){}

    //verifie si la pile est vide
    bool empty() const {
        return top_index == -1;
    }

    bool full()const {
        return top_index == static_cast<int>(CAPACITY)-1;
    }
//ajoute un element au sommet de la pile.
    void push(const T& element) {
        if(full()) {
            throw overflow_error("Erreur: La pile est pleine(stack overflow).");
        }
        data[++top_index] = element;
    }

    //retire l'element au sommet de la pile.
    void pop() {
        if (empty()) {
            throw out_of_range("Erreur: la pile est vide(stack underflow).");
        }
        --top_index;
    }

    T& top() {
        if(empty()) {
            throw out_of_range("Erreur: la pile est vide.");
        }
        return data[top_index];
    }

    const T& top()const {
        if(empty()) {
            throw out_of_range("Erreur: La pile est vide.");
        }
        return data[top_index];
    }

};
int main() {
    try {
        cout << "--- Test avec Stack<int, 5> ---" << endl;
        Stack<int, 5> s_int;
        cout << "La pile est vide ? " << boolalpha << s_int.empty() << endl;

        cout << "Empiler : 10, 20, 30" << endl;
        s_int.push(10);
        s_int.push(20);
        s_int.push(30);
        cout << "Sommet de la pile : " << s_int.top() << endl;

        cout<<"depiler"<<endl;
        s_int.pop();
        cout << "Nouveau sommet : " << s_int.top() << endl;
        cout << "La pile est vide ? " << s_int.empty() << endl;

        cout << "\n--- Test avec Stack<string> (capacité par défaut) ---" << endl;
        Stack<string> s_str; // Pile de string, capacité par défaut de 100

        cout << "Empiler : \"hello\", \"world\"" << endl;
        s_str.push("hello");
        s_str.push("world");

        cout << "Sommet de la pile : " << s_str.top() << endl;
        s_str.top() = "everybody"; // Modifier le sommet
        cout << "Nouveau sommet : " << s_str.top() << endl;
        cout << "\n--- Test de débordement (Stack Overflow) ---" << endl;
        Stack<int, 2> s_overflow;
        cout << "Empiler : 1, 2" << endl;
        s_overflow.push(1);
        s_overflow.push(2);
        cout << "La pile est pleine ? " << s_overflow.full() << endl;
        cout << "Tentative d'empiler un 3eme element..." << endl;
        s_overflow.push(3); // Ceci va lancer une exception


    }catch(const exception& e) {
        cerr<<"Exception catchee: "<< e.what()<<endl;
    }
    return 0;
}
template<typename T, size_t N = 100>
class Stack {
private:
    array<T, N> elements;
    size_t top_index;
public:
    Stack(): top_index(0){}

    void push(const T& value) {
        if(isFull()) {
            throw overflow_error("Erreur: la pile est plaine(stack overflow)");

        }
        elements[top_index] = value;
        top_index++;
    }
    void pop() {
        if(isEmpty()) {
            throw underflow_error("Erreur : la pile est vide(stack underflow)");
        }
        top_index--;
    }
    T& top() {
        if(isEmpty()) {
            throw underflow_error("Erreur la pile est vide");
        }
        return elements[top_index -1];
    }

    const T&top()const {
        if(isEmpty()) {
            throw underflow_error("Erreur la pile est vide");
        }
        return elements[top_index - 1];
    }

    bool isEmpty()const {
        return top_index ==0;
    }
    bool isFull()const {
        return top_index == N;
    }
    size_t size()const {
        return top_index;
    }
};

int main() {

    cout << "--- Test avec Stack<int, 5> ---" << endl;
    Stack<int, 5> int_stack;
    cout << "La pile est vide ? " << std::boolalpha << int_stack.isEmpty() << endl;

    cout<<"Ajout de 10, 20, 30.."<<endl;
    int_stack.push(10);
    int_stack.push(20);
    int_stack.push(30);
    cout << "Taille actuelle : " << int_stack.size() << endl;

    cout << "Element au sommet : " << int_stack.top() << endl;
    cout << "Modification du sommet a 33..." << endl;
    int_stack.top() = 33; // Utilise la version non-const de top()
    cout << "Element au sommet : " << int_stack.top() << endl;
    cout << "Retrait de l'element au sommet..." << endl;
    int_stack.pop();

    cout << "Nouveau sommet : " << int_stack.top() << endl;
    cout << "La pile est pleine ? " << int_stack.isFull() << endl;

    cout << "Remplissage de la pile..." << endl;
    int_stack.push(40);
    int_stack.push(50);
    int_stack.push(60);

    cout << "Taille actuelle : " << int_stack.size() << endl;
    cout << "La pile est pleine ? " << int_stack.isFull() << endl;
    try {
        cout << "Tentative d'ajout sur une pile pleine..." << endl;
        int_stack.push(70);
    } catch (const std::overflow_error& e) {
        cout << "Exception capturee (normal) : " << e.what() << endl;
    }
    cout << "\n--- Test avec une pile de strings (taille par defaut) ---" << endl;
    Stack<string> string_stack; // Utilise N = 100 par défaut

    string_stack.push("Bonjour");
    string_stack.push("C++");
    cout << "Sommet de la pile de strings : \"" << string_stack.top() << "\"" << endl;
    string_stack.pop();
    cout << "Nouveau sommet : \"" << string_stack.top() << "\"" << endl;


    return 0;
}

template<typename T, size_t n=100>
class Stack {
private:

    array<T, n> data;
    size_t index;
public:
    Stack():index(0){}
    void push(const T& v);
    void pop();
    const T& top()const;
    void display()const;
    bool empty()const {
        return index ==0;
    }
    bool full()const {
        return index == n;
    }
    size_t size()const {
        return index;
    }
    size_t capacity()const {
        return n;
    }
};

template<typename T, size_t n>
void Stack<T, n>::push(const T& v) {
    if(full()) {
        throw overflow_error("Stack est plein");
    }
    data.at(index++) = v;
}
template<typename T, size_t n>
void Stack<T, n>::pop() {
    if(empty()) {
        throw out_of_range("Erreur: stack est vide.");
    }
    data.at(--index);
}
template<typename T, size_t n>
const T& Stack<T, n>::top()const {
    if(empty()) {
        throw out_of_range("Stack est vide.");
    }
    return data.at(index -1);
}

template<typename T, size_t n>
void Stack<T, n>::display() const {
    cout<<"size : "<<size()<<endl;
    cout<<"data : [";
    for(size_t i = 0; i<index; ++i) {
        if(i)cout<<", ";
        cout<<data[i];
    }
    cout<<"]"<<endl;
}
int main() {

    Stack<int, 10> s;
    int i = 1;

    s.display();
    cout << endl;
    while (not s.full()) {
        s.push(i*=2);
    }
    s.display();
    cout << endl;
    cout << "top  : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    s.display();
    cout << endl;

    while (not s.empty()) {
        s.pop();
    }

    s.display();
    cout << endl;
    return 0;
}#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t n =100>
class Stack {
private:
    size_t index;
    array<T, n> data;
public:
    Stack():index(0){}
    bool full()const{return index == n;}
    bool empty()const{return index == 0;}
    size_t size()const{return index;}
    size_t capacity()const{return n;}

    //declaration des methodes plus complexes
    void push(const T& v);
    void pop();
    const T& top() const;
    void display()const;
};

#include "Stack_impl.h"

#endif
//Stack_impl.h

template<typename T, size_t n>
void Stack<T, n>::push(const T& v) {
    if(full()) {
        throw overflow_error("Stack is full");
    }
    data.at(index++) = v;
}

//definition de la methode pop
template<typename T, size_t n>
void Stack<T, n>::pop() {
    if(empty()) {
        throw out_of_range("Stack is empty");
    }
    --index;
}

// definition de la methode top
template<typename T , size_t n>
const T& Stack<T, n>::top()const {
    if(empty()) {
        throw out_of_range("Stack is empty");
    }
    return data.at(index -1);
}

//definition de la methode display
template<typename T, size_t n>
void Stack<T, n>::display()const {
    cout<<"size : "<<size()<<endl;
    cout<<"data : ";
    cout<<"[";
    for(size_t i=0; i<index; ++i) {
        if(i>0)cout<<", ";
        cout<<data[i];
    }
    cout<<"]"<<endl;
}

int main() {
    Stack<int, 10> s;
    int i = 1;

    s.display();
    cout << endl;

    while (not s.full()) {
        s.push(i *= 2);
    }

    cout << "top  : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    cout << endl;

    s.display();
    cout << endl;

    while (not s.empty()) {
        s.pop();
    }

    s.display();
    cout << endl;

    return 0;
}
template<typename T>
class Coord {
private:
    T x , y;

public:
    Coord(T x_val=0, T y_val =0) : x(x_val), y(y_val){}
    T getX()const{return x;}
    T getY()const{return y;}

    template<typename R>
    R distance(const Coord<T>& other)const {
        T dx = this->x - other.x;
        T dy = this ->y - other.y;
        R r_dx = static_cast<R>(dx);
        R r_dy = static_cast<R>(dy);
        return sqrt(r_dx *r_dx + r_dy*r_dy);
    }
};

template<typename T>
class Point {
private:
    string nom;
    Coord<T> coord;

public:
    Point(string n, T x, T y) : nom(n), coord(x, y){}
    const string& getNom()const{return nom;}
    const Coord<T>& getCoord()const{return coord;}

    template<typename R>
    R distance(const Point<T>& other)const {
        return this->coord.distance<R>(other.getCoord());
    }
};

// --- Programme principal de test ---
int main() {
    Point<int> p1("p1", 2, 3);
    Point<int> p2("p2", 7, -1);

    cout << "p1(" << p1.getCoord().getX() << ", " << p1.getCoord().getY() << ")" << endl;
    cout << "p2(" << p2.getCoord().getX() << ", " << p2.getCoord().getY() << ")" << endl;

    // --- Appels ---

    // 1. Appel via les coordonnées
    // On spécifie explicitement que le retour doit être un <double>
    double d1 = p1.getCoord().distance<double>(p2.getCoord());
    cout << "distance entre deux coordonnees : " << d1 << endl;

    // 2. Appel directement via les points
    double d2 = p1.distance<double>(p2);
    cout << "distance entre deux points      : " << d2 << endl;

    return 0;
}
template<typename T>
class Coord {
private:
    T x, y;
public:
    Coord():x(T{}), y(T{}){}
    Coord(T x_val, T y_val): x(x_val), y(y_val){}
    T getX()const{return x;}
    T getY()const{return y;}

    template<typename R, typename U>
    R distance(const Coord<U>& other)const {
        R r_dx=static_cast<R>(this->x) - static_cast<R>(other.getX());
        R r_dy= static_cast<R>(this->y) - static_cast<R>(other.getY());
        return sqrt(r_dx * r_dx + r_dy*r_dy);
    }
};

template<typename T>
class Point {
private:
    string nom;
    Coord<T> coord;

public:
    Point(string n, T x, T y) : nom(n), coord(x, y){}
    const string& getNom()const{return nom;}
    const Coord<T>& getCoord()const{return coord;}

    template<typename R , typename U>
    R distance(const Point<U>& other)const{
        return this->coord.template distance<R, U>(other.getCoord());
    }
};

int main() {
    Point<int> p_int("p_int", 1, 1);
    Point<double> p_double("p_double", 5.5, 8.2);

    cout << "first point : " << p_int.getNom() << "(" << p_int.getCoord().getX() << ", " << p_int.getCoord().getY() << ")" << endl;
    cout << "second point : " << p_double.getNom() << "(" << p_double.getCoord().getX() << ", " << p_double.getCoord().getY() << ")" << endl;

    double d = p_int.distance<double>(p_double);

    cout << "\nDistance entre deux types de point differents: " << d << endl;

    return 0;
}template<typename T>
class Coord {
private:
    T x, y;
public:
    Coord():x(T{}), y(T{}){}
    Coord(T x_val, T y_val): x(x_val), y(y_val){}
    T getX()const{return x;}
    T getY()const{return y;}

    template<typename R, typename U>
    R distance(const Coord<U>& other) const{
        R dx = static_cast<R>(this->x) - static_cast<R>(other.getX());
        R dy = static_cast<R>(this->y) -static_cast<R>(other.getY());
        return sqrt(dx*dx + dy*dy);
    }
};

template<typename T>
class Point {
private:
    string nom;
    Coord<T> coord;

public:
    Point(string n, T x, T y): nom(n), coord(x, y){}
    const string& getNom()const{return nom;}
    const Coord<T>& getCoord()const{ return coord;}

    template<typename R, typename U>
    R distance(const Point<U>&other) const{
        return this->coord.template distance<R, U>(other.getCoord());
    }
};

int main() {
    Point<int> p_int("p_int", 1, 1);
    Point<double> p_double("p_double", 5.5, 8.2);

    cout << "first point : " << p_int.getNom() << "(" << p_int.getCoord().getX() << ", " << p_int.getCoord().getY() << ")" << endl;
    cout << "second point : " << p_double.getNom() << "(" << p_double.getCoord().getX() << ", " << p_double.getCoord().getY() << ")" << endl;

    double d = p_int.distance<double>(p_double);

    cout << "\nIki farkli tipteki nokta arasindaki mesafe: " << d << endl;

    return 0;
}
template<typename T>
class Coord {
private:
    T x, y;
public:
    Coord():x(T{}), y(T{}){}
    Coord(T x_val, T y_val): x(x_val), y(y_val){}
    T getX()const{return x;}
    T getY()const{return y;}

    template<typename R, typename U>
    R distance(const Coord<U>& other)const {
        R dx = static_cast<R>(this->x) - static_cast<R>(other.getX());
        R dy = static_cast<R>(this->y) - static_cast<R>(other.getY());
        return sqrt(dx*dx + dy*dy);
    }
};

template<typename T>
class Point {
private:
   string nom;
    Coord<T> coord;
public:

    Point(string n, T x, T y): nom(n), coord(x, y){}
    const string& getNom() const{return nom;}
    const Coord<T>& getCoord()const{return coord;}

    template<typename R, typename U>
    R distance(const Point<U>& other) const{
        return this->coord.template distance<R, U>(other.getCoord());
    }
};

int main() {
    Point<int> p_int("p_int", 1, 1);
    Point<double> p_double("p_double", 5.5, 8.2);

    cout << "first point : " << p_int.getNom() << "(" << p_int.getCoord().getX() << ", " << p_int.getCoord().getY() << ")" << endl;
    cout << "second point : " << p_double.getNom() << "(" << p_double.getCoord().getX() << ", " << p_double.getCoord().getY() << ")" << endl;

    double d = p_int.distance<double>(p_double);

    cout << "\nIki farkli tipteki nokta arasindaki mesafe: " << d << endl;

    return 0;
}
#pragma once

template <typename T, size_t N>
class Stack;

template<typename T, size_t N>
ostream& operator <<(ostream& os, const Stack<T, N>& s);

template<typename T, size_t N>
bool operator==(const Stack<T, N>& lhs, const Stack<T, N>& rhs);

template<typename T, size_t N>
class Stack {
public:
    Stack();
    Stack(const Stack& other);

    void push(const T& v);
    void pop();
    const T& top()const;

    bool full()const {
        return index ==N;
    }

    bool empty()const {
        return index ==0;
    }

    size_t size()const {
        return index;
    }

    operator std::string()const;

    friend ostream& operator<< <T,N>(ostream& os, const Stack<T, N>& s);
    friend bool operator==(const Stack<T, N> & lhs, const Stack<T, N>& rhs);

private:
    size_t index;
    array<T, N> data;
};

#include "Stack_Impl.h"

//ifndef STACK_H
#error "N'incluez pas jamais Stack_Impl.h directement. incluez Stack.h à la place"
#endif


template<typename T, size_t N>
Stack<T, N>::Stack() : index(0){}

//Definition du constructeur par copie
template<typename T, size_t N>
Stack<T, N>::Stack(const Stack& other) : index(other.index), data(other.data){

    template<typename T, size_t N>
    void Stack<T, N>::push(const T& v) {
        if(full()) {
            throw std::overflow_error("Stack OverFlow")
        }
        data[index] = v;
        index++;
    }

    template<typename T, size_t N>
    void Stack<T, N>:: pop() {
        if(empty()) {
            throw std::underflow_error("Stack UnderFlow");
        }
        index--;
    }
    template<typename T, size_t N>
    const T& Stack<T, N>::top()const {
        if(empty()) {
            throw std:: out_of_range("Stack is empty");
        }
        return data[index -1];
    }
*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iterator>
#include <span>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <ostream>
#include <stdexcept>
#include <cmath>
using namespace std;
void push(const T& value) {
    if(sz == N) {
        throw overflow_error("Stacjk is full");
    }
    data[sz] = value;
    sz++;
}

void pop() {
    if(sz ==0) {
        throw underflow_error("stack is empty");
    }
    sz--;
}
T& top() {
    if(sz== 0) {
        throw underflow_error("Stack is emty");
    }
    return data[sz -1]
}

string to_string() const {
    ostringstream oss;
    for(size_t i = 0; i <sz; ++i) {
        oss<<"["<<i<<"] " << data[i]<<"\n";
    }
    return oss.str();
}
friend bool operator==(const Stack& a, const Stack& b) {
    if(a.sz != b.sz) return false;
    for(size_t i = 0; i <a.sz; ++i) {
        if(a.data[i] != b.data[i])return false;
    }
    return true;
}

//