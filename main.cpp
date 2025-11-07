#include <iostream>
#include <vector>
#include <utility> // std::swap için

using namespace std;

// YARDIMCI FONKSİYON
void print_vec(const vector<int> &v) {
    for (int e: v) cout << e << " ";
    cout << endl;
}

void tri_a_bulle(vector<int> &v) {
    for (size_t i = 0; i < v.size()-1; ++i) {
        for (size_t j = 0; j < v.size()-i-1; ++j) {
            if (v[j] > v[j +1]) {
                swap(v[j + 1], v[j]);
            }
        }
    }
}

// GÖREV 13.8 (Tri par Sélection / Selection Sort)
// Konsept: 'i' pozisyonundan başla. Dizinin geri kalanındaki
// EN KÜÇÜK (le minimum) elemanı bul. Bulduğun en küçüğü 'i' ile yer değiştir.
void tri_par_selection(vector<int> &v) {


    for (size_t j = 0; j < v.size(); ++j) {
        size_t minIdx = j;
        for (size_t i = j+1; i < v.size(); ++i) {
         if(v[i] < v[minIdx]) {
            minIdx =i;
         }
        }
       swap(v[j], v[minIdx]);
    }
}

// GÖREV 13.9 (Tri par Insertion / Insertion Sort)
// Konsept: 'i' pozisyonundaki elemanı ('key') al.
// 'i-1' den geriye doğru git, 'key'den büyük olan her şeyi
// bir sağa kaydır (décaler). 'key' için doğru yeri aç.
void tri_par_insertion(vector<int> &v) {

    for(size_t i =1; i<v.size();++i) {
        int key = v[i];
        size_t j = i;

        while(j>0 && v[j-1] > key) {
            v[j] = v[j-1];
            --j;
        }
        v[j]=key;
    }
}

int main() {
    // Test 1: Bubble Sort
    vector<int> v1 = {5, 1, 4, 2, 8};
    tri_a_bulle(v1);
    cout << "Tri a bulle:     ";
    print_vec(v1); // Beklenen: 1 2 4 5 8

    // Test 2: Selection Sort
    vector<int> v2 = {64, 25, 12, 22, 11};
    tri_par_selection(v2);
    cout << "Tri par selection: ";
    print_vec(v2); // Beklenen: 11 12 22 25 64
      // Test 3: Insertion Sort
        vector<int> v3 = {12, 11, 13, 5, 6};
        tri_par_insertion(v3);
        cout << "Tri par insertion: ";
        print_vec(v3); // Beklenen: 5 6 11 12 13

}
