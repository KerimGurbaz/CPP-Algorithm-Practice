#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <span>
using namespace std;

template<typename T>
void display(T first, T last) {
    for(auto it = first; it != last; ++it) {
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
}
