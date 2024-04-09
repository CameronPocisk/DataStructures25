#ifndef HASHTWODIM_H
#define HASHTWODIM_H


#include <iostream>
#include "Exceptions.h"
using namespace std;

enum{
    TwoMaxSize = 100,
    TwoMaxDepth = 5,
};

class HashTwoDim{
 public:
    int hashStorage[TwoMaxSize][TwoMaxDepth];
    int length;
    
    int Hash(int in){
        return in % TwoMaxSize;
    }


 public:

    HashTwoDim(){
        for(int i = 0; i < TwoMaxSize; i++){
            for(int j = 0; j < TwoMaxDepth; j++){
                hashStorage[i][j] = 0;
            }
            // Set all vals to nullptr for better collision checks
        }
    }
    ~HashTwoDim(){
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
        for(int i = 0; i < TwoMaxSize; i++){
            cout << i << "th value: ";
            for(int j = 0; j < TwoMaxDepth; j++){
                if(hashStorage[i][j] != 0){
                    cout << hashStorage[i][j] << ", ";
                }
                else{cout << "_, "; }
            }
            cout << endl;
        }
    }
    
    int Insert(int in);
    int Find(int toFind);
    int Remove(int in);
    bool IsEmpty();

};


#endif