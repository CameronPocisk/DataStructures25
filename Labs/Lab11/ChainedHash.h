#ifndef CHAINEDHASH_H
#define CHAINEDHASH_H

#include <iostream>
#include "LinkedList.h"
using namespace std;

enum{
    DefaultSize = 100,
};

template <typename T>

class ChainedHash{
public:
    // An array as pointer of linked lists storing T*'s
    int size;
    int length;
    LL<T> *allLLs;

    ChainedHash(int sizeIn = DefaultSize){
        size = sizeIn;
        allLLs = new LL<T>[sizeIn]; // New mem alloc of size DefaultSize of LL<T*>'s
        // cout << "basic hash created" << endl;
    }
    ~ChainedHash(){
        delete[] allLLs; // Delete the memory that was allocated
    }

    int Hash(string in){
        int hashSum = 0;
        for(int i = 0; i < in.length(); i++){
            hashSum += in[i];
        }
        // cout << "Hashed to: " << hashSum % size << " From sum: " << hashSum << endl;
        return hashSum % size;
    }

public:

    void Insert(T* toInsert);
    T* Remove(T* toRemove);
    T* GetItem(T* toFind);
    int GetLength(){ return length; }
    void PrintItems();
};

#endif