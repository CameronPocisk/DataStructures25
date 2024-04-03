#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
using namespace std;

enum{
    DefaultMaxSize = 100,
};

template<typename T>
class HashTable{
 public:
    T** hashStorage; // Pointer to (Array) of T pointers
    int size = 100;
    int length = 0;
    
    int Hash(string in){

        int hashSum = 0;
        for(int i = 0; i < in.length(); i++){
            hashSum += in[i];
        }
        cout << "Hashed to: " << hashSum % size << " From sum: " << hashSum << endl;
        return hashSum % size;
        // I think that this is an actually good has fn but will not be used for now since its hardr
    }


 public:
    HashTable(int s = DefaultMaxSize){
        size = s;
        hashStorage = new T*[size];
        for(int i = 0; i < size; i++){
            // Set all vals to nullptr for better collision checks
            *(hashStorage + i) = nullptr;
        }
    }
    ~HashTable(){
        cout << "Deleting..." << endl;
        // // THis may need to happen... but maybe not
        // for(int i = 0; i < size; i++){ // Deallocate the memory (what is inside the array needs to be freed)
        //     if(*(hashStorage + i) != nullptr){
        //         delete *(hashStorage + i); // If you had to do the new * thing, delete it
        //         *(hashStorage + i) = nullptr; // (Delete does not do this)
        //     }
        // }
        delete[] hashStorage; // Is the above code needed? (and this)
        cout << "Deleted" << endl;
    }
    
    void PrintTable(){
        for(int i = 0; i < size; i++){
            cout << i << "th value: ";
            if(*(hashStorage + i) != nullptr){
                cout << **(hashStorage + i) << ", ";
            }
            else{cout << "_, "; }
            cout << endl;
        }
    }
    
    void Insert(T* in);
    T* Remove(T* in);
    T* GetItem(T* toFind);
    int GetLength(){return length;}
    bool IsEmpty();

};


#endif