#include "HashTable.h"

#include <iostream>
using namespace std;

template <typename T>
void HashTable<T>::Insert(T* in){
    cout << "Inserting... " << endl;
    // T inDeref = *in;
    // cout << inDeref;
    // // if(IsFull){
    // //     throw IsFull;
    // // }
    // string newIn = to_string(inDeref);
    string hashIn;
    hashIn = *in;
    int space = Hash(hashIn);
    // int space = Hash(*in);
    cout << "space " << space << endl;
    length++;
    if(*(hashStorage + space) == nullptr) {
        *(hashStorage + space) = in;
        cout << "Inserted" << endl;
        return;
    }
    
    int index = space;
    while(*(hashStorage + index) != nullptr){
        index = (index + 1) % size;
    }
    *(hashStorage + index) = in;
    cout << "Inserted" << endl;
    return;
}

template <typename T>
T* HashTable<T>::Remove(T *in){
    // if(IsEmpty()){
    //     throw IsEmpty;
    // }
    // if(GetItem() == nullptr){
    //     return nullptr;
    // }
    string hashIn;
    hashIn = *in;
    int index = Hash(hashIn);
    // int index = Hash(*in);

    while(**(hashStorage + index) != *in){
        index = (index + 1) % size;
    }

    T* temp = *(hashStorage + index);
    *(hashStorage + index) = nullptr;
    length--;
    cout << "temp"  << temp << endl;
    return temp;
};

template<typename T>
T* HashTable<T>::GetItem(T* toFind){
    string hashIn;
    hashIn = *toFind;
    int index = Hash(hashIn);

    cout << "Finding..." << endl;
    while(**(hashStorage + index) != *toFind){
        index = (index + 1) % size;
    }

    cout << "Found" << endl;
    // Got to the value
    return *(hashStorage + index);
}

template<typename T>
bool HashTable<T>::IsEmpty(){
    for(int i = 0; i < size; i++){
        if(*(hashStorage + i) != nullptr){
            return false;
        }
    }
    return true;
}