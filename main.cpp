#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;
const int CAPACITY = 10;

struct Stack {
    array<int, CAPACITY> a;
    size_t sz = 0;
    const int maxVal = 10;
};

void display(const Stack &s) {
    cout << "size : " << s.sz;cout<<endl;
    cout << "data : " ;


    cout << "[";
    for (size_t i = 0; i < s.sz; ++i) {
        cout << s.a[i];
        if (i < s.sz -1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

bool full(const Stack &s) {
    return s.sz == CAPACITY;
}

bool empty(const Stack &s) {
    return s.sz == 0;
}

void push(Stack &s, const int &n) {
    if (!full(s)) {
        s.a[s.sz] = n;
        s.sz++;
    }
}

int top(const Stack &s) {
    return s.a[s.sz - 1];
}

void pop(Stack &s) {
    if(!empty(s)) {
            s.sz--;
    }
}

int size(Stack &s) {
    return s.sz;
}

int main() {
    Stack s;
    int i = 1;

    display(s);
    cout << endl;

    while (not full(s)) {
        push(s, i *= 2);
    }

    cout << "top  : " << top(s) << endl;
    cout << "size : " << size(s) << endl;
    cout << endl;

    display(s);
    cout << endl;

    while (not empty(s)) {
        pop(s);
    }

    display(s);
    cout << endl;
}
