#pragma once

//#include <iostream>
#include <stdexcept>

template <class T, int N > 
class Quene {
    T *S;
    int pointer;
    int head;
    int tail;
public:
    Quene();
    Quene(const Quene<T,N>& obj); //copy constructor
    Quene(Quene<T,N>&& obj); //move constructor
    ~Quene();
    
    Quene& operator=(const Quene<T,N>& obj); //copy opereator=
    Quene& operator=(Quene<T,N>&& obj); //move opereator=

    template<class U>
    void push(U&& x); 
    //template<class U> 
    //void view(U&& elem);
    T pop();  
    T& front(); 
    const T& front() const; 
    int size() const; 
    bool empty() const; 
    bool full() const; 
    //void parameters();

};

template <class T, int N>
Quene<T, N>::Quene(): S(new T[N]), pointer(0), head(0), tail(0){}

template <class T, int N>
Quene<T, N>::Quene(const Quene<T,N>& obj) : S(new T[N]), pointer(obj.pointer), head(obj.head), tail(obj.tail){
    for(int i=0;i<N;i++)S[i]=obj.S[i];
}

template <class T, int N>
Quene<T, N>::Quene(Quene<T,N>&& obj) :  S(obj.S), pointer(obj.pointer),head(obj.head), tail(obj.tail){
    obj.head=obj.tail=obj.pointer=0;
    obj.S=nullptr;
}

template <class T, int N>
Quene<T, N>::~Quene(){
        delete [] S;
}

template <class T, int N>
Quene<T, N>& Quene<T, N>::operator=(const Quene<T,N> &obj){
    if(this!=&obj){
        delete [] S;
        pointer=obj.pointer;
        head=obj.head;
        tail=obj.tail;
        S = new T[N];
        for(int i = 0; i < pointer; i++) S[i] = obj.S[i];
    }
    return *this;

}

template <class T, int N>
Quene<T, N>& Quene<T, N>::operator=(Quene<T,N> &&obj){
    if(this!=&obj){
        delete [] S;
        S = obj.S;
        pointer=obj.pointer;
        head=obj.head;
        tail=obj.tail;
        
        obj.tail=obj.head=obj.pointer=0;
        obj.S=nullptr;
    }
    return *this;

}

template <class T, int N>
template<class U>
void Quene<T, N>::push(U&& x){
    
    if(full()) 
        throw std::out_of_range("Quene Overflow");
 
    if(tail==N)tail=0;

    S[tail]=std::forward<U>(x); 
    tail++;
    pointer++;
}

template <class T, int N>
T Quene<T, N>::pop(){
    if(empty()) 
        throw std::out_of_range("Quene Underflow");

    if(head==N)head=0;
    T x=S[head];
    S[head]=0;
    head++;
    pointer--;
    return std::move(x);
}

template <class T, int N>
T& Quene<T, N>::front(){
    return S[head];
}


template <class T, int N>
const T& Quene<T, N>::front() const{
    return S[head];
}

template <class T, int N>
int Quene<T,N>::size() const{
    return pointer;
}
template <class T, int N>
bool Quene<T, N>::empty() const{
     return pointer==0;
}


template <class T, int N>
bool Quene<T, N>::full() const{
    return pointer==N;
}

// template <class T, int N>
// void Quene<T, N>::parameters(){
//     std::cout<<"tail="<<tail<<" head="<<head<<" pointer="<<pointer<<"\n";
// }


// template <class T, int N>
// template<class U>
// void Quene<T, N>::view(U&& elem){

//     if(elem>=0 && elem<N) std::cout<<S[elem]<<" ";
// }
