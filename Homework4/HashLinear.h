#ifndef HASHLINEAR_H
#define HASHLINEAR_H


#include <iostream>
#include "Exceptions.h"
using namespace std;

enum{
    DefaultMaxSize = 500,
};

class HashLinear{
 public:
    int hashStorage[DefaultMaxSize];
    
    int Hash(int in){

        return in % DefaultMaxSize;
    }

 public:

    HashLinear(){
        for(int i = 0; i < DefaultMaxSize; i++){
            // Set all vals to nullptr for better collision checks
            hashStorage[i] = 0;
        }
    }
    ~HashLinear(){
        cout << "Deleting..." << endl;
        // // THis may need to happen... but maybe not
        // for(int i = 0; i < size; i++){ // Deallocate the memory (what is inside the array needs to be freed)
        //     if(*(hashStorage + i) != nullptr){
        //         delete *(hashStorage + i); // If you had to do the new * thing, delete it
        //         *(hashStorage + i) = nullptr; // (Delete does not do this)
        //     }
        // }
        cout << "Deleted" << endl;
    }
    
    
    void PrintTable(){
        for(int i = 0; i < DefaultMaxSize; i++){
            cout << i << "th value: ";
            if(hashStorage[i] != 0){
                cout << hashStorage[i] << ", ";
            }
            else{cout << "_, "; }
            cout << endl;
        }
    }
    
    int Insert(int in);
    int Find(int toFind);
    int Remove(int in);
    bool IsEmpty();

};


#endif