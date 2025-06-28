#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;


template<typename T>
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
    for(T it = begin; it != end; ++it) {
        T min_it = it;
        for(T j = next(it); j!= end ; ++j) {
            if(*j < *min_it) {
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