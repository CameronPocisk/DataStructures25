#include "HashTable.h"

// using namespace std;

template <typename T>
void HashTable<T>::Insert(T* in){
    // cout << "Inserting... " << endl;
    // // if(IsFull){
    // //     throw IsFull;
    // // }

    string hashIn = string(*in); // Conversion for expected operator
    int index = Hash(hashIn);
    // cout << "space: " << index << endl;
    
    length++;
    while(*(hashStorage + index) != nullptr){
        index = (index + 1) % size;
    }
    *(hashStorage + index) = in;
    // cout << "Inserted" << endl;
    return;
}

template <typename T>
T* HashTable<T>::Remove(T *in){
    // if(GetItem() == nullptr){
    //     return nullptr;
    // }
    string hashIn = string(*in);
    int index = Hash(hashIn);
    
    int notFoundCount = 0;
    // itterate while there is nothing or you didnt find it
    while(*(hashStorage + index) == nullptr || **(hashStorage + index) != *in){
        index = (index + 1) % size;
        
        if(notFoundCount > size){
            throw NotFound(); // Was not in the whole list
        }
        notFoundCount++;
    }

    T* temp = *(hashStorage + index);
    // cout << "temp: "  << *temp << endl;
    *(hashStorage + index) = nullptr;
    length--;
    return temp;
};

template<typename T>
T* HashTable<T>::GetItem(T* toFind){
    
    string hashIn =  string(*toFind);
    int index = Hash(hashIn);

    int notFoundCount = 0;
    while(*(hashStorage + index) == nullptr || **(hashStorage + index) != *toFind){
        index = (index + 1) % size;

        if(notFoundCount > size){
            throw NotFound(); // Was not in the whole list
        }
        notFoundCount++;
    }

    // Got to the value
    return *(hashStorage + index);
}
template<typename T>
void HashTable<T>::printInTable(){
    for(int i = 0; i < size; i++){
        if(*(hashStorage + i) != nullptr){
            string AsString = string(**(hashStorage + i));
            cout << AsString << ", ";
        }
    }
    cout << endl;
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