//
// Created by Krm on 01.09.2025.
//
//stack
#pragma
#include <array>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;



/*
* template<typename T, size_t N>
class Stack {
private:
    array<T, N> data;
    size_t sz = 0;

public:
    Stack()= default;
    Stack(const Stack&) = default;
    Stack& operator==(const Stack&) = default;

    void push(const T& value) {
        if(sz ==N )throw overflow_error("Stack is full");
        data[sz]=value;
        sz++;
    }

    void pop() {
        if(sz == 0) throw underflow_error("Stack is empty");
        sz--;
    }

    const T& top()const{
        if(sz == 0)throw underflow_error("Stack is empty");
        return data[sz -1];
    }

    bool empty() const {
        return sz==0;
    }

    bool full()const {
        return sz ==N;
    }

    size_t size()const {
        return sz;
    }

    void clear() {
        sz = 0;
    }

    explicit operator string()const {
        ostringstream oss;
        for(size_t i =0; i <sz; ++i) {
            oss<<"["<<i<<"]"<<data[i]<<"\n";
        }
        return oss.str();
    }

    friend bool operator==(const Stack& a, const Stack& b) {
        if(a.sz != b.sz) return false;
        for(size_t i = 0; i<a.sz; ++i) {
            if(a.data[i] != b.data[i]) return false;
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, const Stack& s) {
        return os<<string(s);
    }
};
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <array>
#include <string>
#include <sstream>
using namespace std;

template<typename T, size_t N>
class Stack;
template <typename T, size_t N>
ostream& operator<<(ostream& os, const Stack<T, N>& s);

template<typename T, size_t N>
bool operator<<(const Stack<T,N>& lhs,const Stack<T,N>& rhs );

template<typename T, size_t N>
class Stack {
private:
    size_t index;
    array<T, N>data;

    friend ostream& operator<<<T, N>(ostream& os, const Stack<T,N>& s);
    friend bool operator==<T, N>(const Stack<T, N>& lhs,const Stack<T, N>& rhs);

public:
    Stack(): index(0){}
    Stack(Const Stack<T, N>& other);
    operator string()const;

    bool full()const{return index == N;}
    bool empty()const{return index ==0;}
    size_t size()const{return index;}
    void push(const T& v);
    void pop();
    const T& top()const;

};
#include "Stack_Impl.h"
#endif

template<typename T, size_t N>
Stack<T,N>::Stack(const Stack<T, N>& other): index(other.index), data(other.data){}
template<typename T, size_t N>
Stack<T,N>::operator string() const{
    stringstream ss;
    for(size_t i = 0; i<index; ++i) {
        ss<<"["<<i<<"]"<<data[i]<<"\n";
    }
    return ss.str();
}

template<typename T, size_t N>
ostream& operator<<(ostream& os, const Stack<T,N>& s) {
    os<<string(s);
    return os;
}
template<typename T, size_t N>
bool operator==(const Stack<T,N>& lhs, const Stack<T,N>& rhs) {
    if(lhs.index != rhs.index) {
        return false;
    }
    for(size_t i = 0; i <lhs.index; ++i) {
        if(lhs.data[i] != rhs.data[i]) {
            return false;
        }
    }
    return true;
}

template<typename T, size_t N>
void Stack<T,N>::push(const T& valeur) {
    if(full()) {
        throw overflow_error("Stack is full");
    }
    data[index]= valeur;
    index++;
}
template<typename T, size_t N>
void Stack<T,N>::pop() {
    if(empty()) {
        throw out_of_range("Stack is empty");
    }
    --index;
}
template<typename T, size_t N>
const T &Stack<T, N>::top() const {
    if(empty()) {
        throw out_of_range("Stack is empty");
    }
    return data[index - 1];
}
