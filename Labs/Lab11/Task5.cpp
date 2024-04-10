#include <iostream>
#include "HashTable.h"
#include "HashTable.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "ChainedHash.h"
#include "ChainedHash.cpp"
#include "Item.h"
#include "Item.cpp"
// My linker is weird

enum{
    SKUSize = 50,
};

using namespace std;

void FillSkus(string values[]){
    for(int i = 0; i < SKUSize; i++){

        // Genearte random string of cap lets and nums
        string sku;
        for(int i = 0; i < 4; i++){
            char curVal = rand() % 256; // Make it a char
            if(isalpha(curVal) || isdigit(curVal)){ // If its a char we want add ot cur sku
                sku += toupper(curVal);
            }
            else{ i--; } // retry
        }
        values[i] = sku;
    }
}

int main(){

    string skus[SKUSize];
    FillSkus(skus);
    // for(int i = 0; i < SKUSize; i++)
    //     cout << skus[i] << ", ";
    // cout << endl;

    HashTable<string> linearProber(100);
    ChainedHash<string> chainer(100);

    // Add SKUS to each

    for(int i = 0; i < SKUSize; i++){
        // cout << skus[i] << ", ";
        linearProber.Insert(&skus[i]);
        chainer.Insert(&skus[i]);
    }
    // linearProber.printInTable();
    // chainer.PrintItems();
    

    cout << "prorgram finished... ";
    return 0;
}

// g++ -c Task5.cpp HashTable.cpp ChainedHash.cpp LinkedList.cpp Item.cpp
// g++ -o main.exe Task5.o HashTable.o ChainedHash.o LinkedList.o Item.o
// ./main.exe

// g++ -c Task5.cpp
// g++ -o main.exe Task5.o
// ./main.exe