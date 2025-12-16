#include <iostream>
#include <vector>
#include <span>
#include <algorithm>
using namespace std;

template <typename T>
struct entre {
    const int min;
    const int max;

    bool operator()(const T& e) {
        return e>= min && e<=max;
    }
};

template<typename T>
ostream&operator<<(ostream& os, span<T>s) {
    for(const auto& el: s) {
        os<<el<<" ";
    }
    return os;
}
int main() {

    vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << span(v) << endl;

    cout << count_if(v.begin(), v.end(), entre<int>{3, 6});
}