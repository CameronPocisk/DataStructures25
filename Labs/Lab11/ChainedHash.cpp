#include "ChainedHash.h"

template <typename T>
void ChainedHash<T>::Insert(T* toInsert){
    length++;
    // get just one hash
    string toString = string(*toInsert);
    int index = Hash(toString);

    // cout << "inserted at " << index << endl;
    numComps++;
    (allLLs + index)->InsertEnd(toInsert);
    // *(allLLs + index).InsertEnd(toInsert);
}

template <typename T>
T*ChainedHash<T>:: Remove(T* toRemove){
    for(int i = 0; i < size; i++){
        numComps++;
        if(! (allLLs + i)->IsEmpty()){
            numComps++;
            (allLLs + i)->RemoveItem(toRemove);
        }
    }
    return nullptr;
}

template <typename T>
T*ChainedHash<T>:: GetItem(T* toFind){
    for(int i = 0; i < size; i++){
        numComps++;
        if(!(allLLs + i)->IsEmpty()){
            numComps++;
            T* foundPtr = (allLLs + i)->GetValue(toFind);
            if(foundPtr != nullptr){ // Found it!!
                numComps++;
                return foundPtr;
            }
        }
    }
    return nullptr; // never found ish
}
template <typename T>
void ChainedHash<T>::PrintItems(){
    for(int i = 0; i < size; i++){
        if((allLLs + i) != nullptr){
            (allLLs + i)->PrintList();
        }
    }
}
