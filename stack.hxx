#pragma once

//#include <iostream>
#include <stdexcept>

template <class T, int N > 
class Stack {
    T *S;
    int pointer; 
public:
    Stack(); 
    Stack(const Stack<T,N>& obj); //copy constructor
    Stack(Stack<T,N>&& obj); //move constructor
    ~Stack(); 
    
    Stack& operator=(const Stack<T,N>& obj); //copy opereator=
    Stack& operator=(Stack<T,N>&& obj); //move opereator=

    template<class U>
    void push(U&& x); 
    //template<class U> 
    //void view(U&& elem);
    T pop();  
    T& top(); 
    const T& top() const;
    int size() const; 
    bool empty() const; 
    bool full() const; 

};

template <class T, int N>
Stack<T, N>::Stack(): S(new T[N]), pointer(0){}

template <class T, int N>
Stack<T, N>::Stack(const Stack<T,N>& obj) : S(new T[N]), pointer(obj.pointer){
    for(int i=0;i<pointer;i++)S[i]=obj.S[i];
}

template <class T, int N>
Stack<T, N>::Stack(Stack<T,N>&& obj) :  S(obj.S), pointer(obj.pointer){
    obj.pointer=0;
    obj.S=nullptr;
}

template <class T, int N>
Stack<T, N>::~Stack(){
    if (S != nullptr)
        delete [] S;
}

template <class T, int N>
Stack<T, N>& Stack<T, N>::operator=(const Stack<T,N> &obj){
    if(this!=&obj){
        delete [] S;
        pointer=obj.pointer;
        S = new T[N];
        for(int i = 0; i < pointer; i++) S[i] = obj.S[i];
    }
    return *this;

}

template <class T, int N>
Stack<T, N>& Stack<T, N>::operator=(Stack<T,N> &&obj){
    if(this!=&obj){
        delete [] S;
        pointer=obj.pointer;
        S = obj.S;
        obj.pointer=0;
        obj.S=nullptr;
    }
    return *this;

}

template <class T, int N>
template<class U>
void Stack<T, N>::push(U&& x){
    
    if(full()) 
        throw std::out_of_range("Stack Overflow");
    S[pointer]=std::forward<U>(x);
    pointer++;
}

template <class T, int N>
T Stack<T, N>::pop(){
    if(empty()) 
        throw std::out_of_range("Stack Underflow");
    pointer--;
    return std::move(S[pointer]);
}

template <class T, int N>
T& Stack<T, N>::top(){
    return S[pointer-1];
}


template <class T, int N>
const T& Stack<T, N>::top() const{
    return S[pointer-1];
}

template <class T, int N>
int Stack<T,N>::size() const{return pointer;}

template <class T, int N>
bool Stack<T, N>::empty() const{
    return pointer==0;
}

template <class T, int N>
bool Stack<T, N>::full() const{
    return pointer>=N;
}

// template <class T, int N>
// template<class U>
// void Stack<T, N>::view(U&& elem){
//     if(elem>=0 && elem<pointer) std::cout<<S[elem]<<std::endl;
// }
