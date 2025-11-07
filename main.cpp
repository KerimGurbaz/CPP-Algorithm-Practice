#include <iostream>
#include <vector>
#include <iterator> // next, prev için

using namespace std;

void supprimer_elements_centraux(vector<int>& v) {
    if(v.size()<3) {
        return;
    }

    v.erase(v.begin()+1, v.end()-1);

}
void print_vec(const vector<int>& v) {
    for (int e : v) cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    supprimer_elements_centraux(v1);
    print_vec(v1); // Beklenen Çıktı: 1 5

    vector<int> v2 = {1, 2};
    supprimer_elements_centraux(v2);
    print_vec(v2); // Beklenen Çıktı: 1 2

    vector<int> v3 = {1};
    supprimer_elements_centraux(v3);
    print_vec(v3); // Beklenen Çıktı: 1
    
    vector<int> v4 = {1, 2, 3};
    supprimer_elements_centraux(v4);
    print_vec(v4); // Beklenen Çıktı: 1 3
}