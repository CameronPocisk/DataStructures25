#include "ChainedHash.h"

template <typename T>
void ChainedHash<T>::Insert(T* toInsert){
    length++;
    // get just one hash
    string toString = string(*toInsert);
    int index = Hash(toString);

    cout << "inserted at " << index << endl;
    (allLLs + index)->InsertEnd(toInsert);
    // *(allLLs + index).InsertEnd(toInsert);
}

template <typename T>
T*ChainedHash<T>:: Remove(T* toRemove){
    cout << "Removing" << endl;
    for(int i = 0; i < size; i++){
        if((allLLs + i) != nullptr){
            cout << "Calling remove on " << i << endl;
            (allLLs + i)->RemoveItem(toRemove);
        }
    }
    cout << "Removed";
    return nullptr;
}

template <typename T>
T*ChainedHash<T>:: GetItem(T* toFind){
    // lol this one will suck
    return nullptr;
}
template <typename T>
void ChainedHash<T>::PrintItems(){
    cout << "Printling list: " << endl;
    for(int i = 0; i < size; i++){
        if((allLLs + i) != nullptr){
            (allLLs + i)->PrintList();
        }
    }
}
