#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO 1: tri_bulle - klasik bubble sort (erken çıkış optimizasyonu serbest)
// İmza sabit: in-place, artan sıraya göre sıralasın.
void tri_bulle(vector<int> &v) {
if(v.size()<2)return;
    for(size_t i = 0; i<v.size()-1; ++i) {
        size_t minIdx = i;
        for(size_t j =i+1; j<v.size(); ++j) {
            if(v[j] < v[minIdx]) {
                minIdx = j;
            }
            if(minIdx != i) {
                swap(v[i], v[minIdx]);
            }
        }
    }

}

// TODO 2: tri_selection - min-seçimli sıralama (durağan/stable olmak zorunda değil)
void tri_selection(vector<int> &v) {
    for(int i = 0; i<v.size()-1; ++i) {
         size_t min_idx =i;
        for(int j = i+1; j<v.size(); ++j) {
            if(v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        int temp = v[min_idx];
        v[min_idx] = v[i];
        v[i]= temp;
    }

}

// TODO 3: tri_insertion - eklemeli sıralama (stabledır)
// v[i]’yi soldaki uygun yerine kaydırarak yerleştir.
void tri_insertion(vector<int> &v) {
   for(int i = 0; i<v.size()-1; ++i) {
       for(int j = i; i<v.size() -i; ++j) {
           if(v[j] < v[i]) {
               int temp = v[j];
               v[j]= v[i];
               v[i]=temp;
           }
       }
   }
}

// (isteğe bağlı kullanırsın) küçük yardımcı
static void printv(const vector<int> &v, const char *tag) {
    cout << tag << " : ";
    for (int x: v) cout << x << ' ';
    cout << '\n';
}

int main() {
    vector<int> A{5, 1, 4, 2, 8};
    vector<int> B{3, 3, 1, 0, -2, 3, 1};
    vector<int> C{9, 7, 5, 3, 1, -1};
    vector<int> D{1, 2, 3, 4, 5}; // zaten sıralı
    vector<int> E{2}; // tek eleman
    vector<int> F{}; // boş

    // Bubble
    auto v1 = A;
    tri_bulle(v1);
    printv(v1, "bubble(A)");
    auto v2 = B;
    tri_bulle(v2);
    printv(v2, "bubble(B)");

    // Selection
    auto v3 = C;
    tri_selection(v3);
    printv(v3, "select(C)");
    auto v4 = D;
    tri_selection(v4);
    printv(v4, "select(D)");

    // Insertion
    auto v5 = A;
    tri_insertion(v5);
    printv(v5, "insert(A)");
    auto v6 = F;
    tri_insertion(v6);
    printv(v6, "insert(F)");

    // (İstersen) burada is_sorted ile doğruluk testi yapabilirsin
    // cout << boolalpha << is_sorted(v1.begin(), v1.end()) << '\n';

    return 0;
}
