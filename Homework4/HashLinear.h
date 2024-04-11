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
    void PrintItems(){
        for(int i = 0; i < DefaultMaxSize; i++){
            cout << i << "th value: ";
            if(hashStorage[i] != 0){
                cout << hashStorage[i] << ", ";
            }
        }
        cout << endl;
    }
    
    int Insert(int in);
    int Find(int toFind);
    int Remove(int in);
    bool IsEmpty();

};


#endif