/*
 * #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO 1: tri_bulle - klasik bubble sort (erken çıkış optimizasyonu serbest)
// İmza sabit: in-place, artan sıraya göre sıralasın.
void tri_bulle(vector<int> &v) {
if(v.size()<2)return;
    for(size_t i = 0; i<v.size(); ++i) {
        for(size_t j = 0; j+1 <v.size(); ++j) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

// TODO 2: tri_selection - min-seçimli sıralama (durağan/stable olmak zorunda değil)
void tri_selection(vector<int> &v) {
    if(v.size() < 2)return;
    for(size_t i = 1; i<v.size(); ++i) {
        int key = v[i];
        size_t j = i;
        while(j>0 && v[j-1] > key) {
            v[j] = v[j-1];
            --j;
        }
        v[j]=key;
    }


}

// TODO 3: tri_insertion - eklemeli sıralama (stabledır)

void tri_insertion(vector<int> &v) {
 if(v.size()<2)return;
    for(size_t i = 1; i<v.size(); ++i) {
        int key = v[i];
        size_t j = i;
        while(j>0 && v[j-1] > key) {
            v[j]= v[j-1];
            --j;
        }
        v[j]=key;
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

 */
#include <iostream>
#include <vector>
using namespace std;

#include <utility>


pair<size_t,size_t> tri_bulle_stats(vector<int>& v) {
    if(v.size() <2)return {0,0};
    size_t comps = 0;
    size_t swaps =0;
    for(size_t i = 0; i<v.size()-1; ++i) {
        bool changed = false;
        for(size_t j =0; j<v.size()-i-1; ++j) {
            ++comps;
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                ++swaps;
                changed=true;
            }
            if(!changed)break;
        }
    }
    return {comps, swaps};
}

pair<size_t,size_t> tri_selection_stats(vector<int>& v) {
    size_t comps = 0, swaps = 0;
   if(v.size() <2) {
       return {0,0};
   }
    size_t comp = 0;
    size_t swap = 0;
    for(size_t i = 0; i+1<v.size(); ++i) {
        size_t idx = i;
        for(size_t j = i+1; j<v.size(); ++j) {
            ++comp;
            if(v[j] < v[idx]) {
                idx =j;
            }
        }
        if(i != idx) {
            swap(v[i], v[idx]);
            ++swap;
        }
    }
    return {comps, swaps};
}


pair<size_t,size_t> tri_insertion_stats(vector<int>& v) {
    if(v.size() <2) {
        return {0,0};
    }
    size_t comp = 0;
    size_t swap = 0;

    for(size_t i = 1; i<v.size(); ++i) {
        int key = v[i];
        size_t j = i;
        ++comp;
        while(j>0 && v[j-1] > key) {
            v[j]=v[j-1];
            --j;
            ++swap;
        }
        v[j] = key;
        ++swap;
    }

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
    tri_bulle_stats(v1);

    auto v2 = B;
    tri_bulle_stats(v2);


    return 0;
}