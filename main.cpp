#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

template <typename T, typename Pred>
void supprimer_si(vector<T>& v, Pred p) {
    auto slow =v.begin();
    for(auto fast = v.begin(); fast!=v.end(); ++fast ) {
        if(!p(*fast)) {
            if(slow!= fast) {
                  *slow =*fast;
            ++slow;
            }

        }
    }
    v.erase(slow, v.end());
}
bool est_pair(int a) { return a % 2 == 0; }

int main() {
    vector<int> v1{1, 2, 3, 5, 7, 10, 15, 22};
    supprimer_si(v1, est_pair);
    for (int e : v1) cout << e << ' ';
    cout << '\n';

    vector<char> v2{'R', '2', '-', 'D', '2', ' ', 'C', '-', '3', 'P', 'O'};
    supprimer_si(v2, ::isdigit);
    for (char e : v2) cout << e;
    cout << '\n';
}
