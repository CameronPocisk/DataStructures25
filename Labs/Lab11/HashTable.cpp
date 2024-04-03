#include "HashTable.h"

#include <iostream>
using namespace std;

template <typename T>
void HashTable<T>::Insert(T *in){
    // T inDeref = *in;
    // cout << inDeref;
    // if(IsFull){
    //     throw IsFull;
    // }
    // string newIn = to_string(inDeref);
    if(*(hashStorage + Hash(*in)) == nullptr) {
        **(hashStorage + Hash(*in)) = *in;
        return;
    }
    
    int index = Hash(*in);
    while(*(hashStorage + index) == nullptr){
        index = (index + 1) % size;
    }
    **(hashStorage + index) = *in;
    length++;
    return;
};

template <typename T>
T HashTable<T>::Remove(T *in){
    // if(IsEmpty()){
    //     throw IsEmpty;
    // }
    // if(GetItem() == nullptr){
    //     return nullptr;
    // }
    
    int index = Hash(in);
    while(**(hashStorage + index) != in){
        index = (index + 1) % size;
    }

    T temp = **(hashStorage + index);
    *(hashStorage + index) = nullptr;
    // *(removed + index) = true; (if we add array to see if there was once a number in an empty spot)
    length--;
    return temp;
};

template<typename T>
T HashTable<T>::GetItem(T *toFind){
    return *toFind;
}


