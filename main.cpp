#include <iostream>
#include <array>

using namespace std;



const int CAPACITY = 10;

struct Stack {
    int size=0;
    array<int, CAPACITY>data;
};

bool empty(const Stack& s) {
    return s.size == 0;
}

bool full(const Stack& s) {
    return s.size == s.data.size();
}

void push( Stack& s, int value) {
  if(!full(s)) {
      s.data[s.size] = value;
      s.size++;
  }
}
void pop( Stack& s){
    if(!empty(s)) {
        s.size--;
    }
}

int top(const Stack& s) {
    return s.data[s.size -1];
}

int size(const Stack& s) {
    return s.size;
}

void display(const Stack& s) {
    cout<<"size : "<<s.size<<endl;
    cout<<"data : [";
    for(int i = 0; i<s.size; ++i) {
        cout<<s.data[i];
        if(i<s.size -1) {
            cout<<", ";
        }
    }
    cout<<"]";
}






int main() {

    Stack s;
    int i = 1;

    display(s);
    cout << endl;

    while (not full(s)) {
        push(s, i*=2);
    }

    cout << "top  : " << top(s)  << endl;
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