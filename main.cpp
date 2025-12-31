// #include <iostream>
// #include <string>
// #include <vector>
// #include <array>
// #include <list>
// #include <span>
// using namespace std;
//
// template<typename T>
// void display(T first, T last) {
//     for(auto it = first; it != last; ++it) {
//         cout<<*it<<"\t"<<static_cast<const void*>(&(*it))<<endl;
//     }
//     cout<<endl;
// }
//
//
// int main() {
//     array  a  {1, 2, 3};
//     vector v  {1.1, 2.2, 3.3};
//     string s  ("HEIG-VD"s);
//     list   l  {"chien"s, "chat"s, "souris"s};
//
//     cout << "array"   << endl;    display(a.cbegin(), a.cend());
//     cout << "vector"  << endl;    display(v.cbegin(), v.cend());
//     cout << "string"  << endl;    display(s.cbegin(), s.cend());
//     cout << "list"    << endl;    display(l.cbegin(), l.cend());
// }

// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// template<typename Iterator>
// void display(Iterator first, Iterator last) {
//     cout << "[";
//     for (Iterator it = first; it != last; ++it) {
//         if (it != first) cout << ", ";
//         cout << *it;
//     }
//     cout << "]\n";
// }
//
// int main() {
//     vector v  {1, 2, 3, 4};
//     display(v.cbegin(), v.cend());
//
//     vector<int>::const_iterator begin = v.cbegin();
//     vector<int>::const_iterator end   = v.cend();
//
//     v.push_back(5);
//
//
//     display(v.cbegin(), v.cend());
//     display(v.begin(), v.end());
// }
#include <vector>
#include <iostream>
#include <array>
using namespace std;

template<typename Iterator>
void display(Iterator first, Iterator last) {
    cout << "[";
    for (Iterator it = first; it != last; ++it) {
        if (it != first) cout << ", ";
        cout << *it;
    }
    cout << "]\n";
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int tab[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    display(tab + 5, tab + 2);
}
