#include <iostream>
#include <array>
#include <sstream>
using namespace std;

const int capacity = 10;

struct Stack {
    int size = 0;
    array<int, capacity> data{};
};

void display(const Stack &s) {
    ostringstream os;
    os << "size   :";
    os << s.size << "\n";
    os << "data   :[";
    for (int i = 0; i < s.size; ++i) {
        os << s.data[i];
        if (i < s.size - 1) {
            os << ", ";
        }
    }
    os << "]\n";
    cout << os.str();
}


bool full(const Stack &s) {
    return s.size == capacity;
}

void push(Stack &s, int n) {
    s.data[s.size] = n;
    s.size++;
}

bool empty(const Stack &s) {
    return s.size == 0;
}

size_t top(const Stack &s) {
    if (!empty(s)) {
        return s.data[s.size];
    } else { return 0; };
}

void pop(Stack &s) {
    if (!empty(s)) {
        s.size--;
    }
}

size_t size(const Stack &s) {
    return s.size;
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
