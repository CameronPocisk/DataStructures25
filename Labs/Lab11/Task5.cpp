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
    NumSkus = 200,
    HashSize = 250,
};

using namespace std;

void FillSkus(string values[]){
    for(int i = 0; i < NumSkus; i++){

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

    string skus[NumSkus];
    FillSkus(skus);

    HashTable<string> linearProber(HashSize);
    ChainedHash<string> chainer(HashSize);

    // Add SKUS to each
    for(int i = 0; i < NumSkus; i++){
        linearProber.Insert(&skus[i]);
        chainer.Insert(&skus[i]);
    }
    // linearProber.printInTable();
    // chainer.PrintItems();

    // Call find on all items
    for(int i = 0; i < NumSkus; i++){
        linearProber.GetItem(&skus[i]);
        chainer.GetItem(&skus[i]);
    }

    cout << "Linear probling comps: " << linearProber.GetNumComps() << endl;
    cout << "Chain hash comps: " << chainer.GetNumComps() << endl;


    cout << "prorgram finished... ";
    return 0;
}

// g++ -c Task5.cpp HashTable.cpp ChainedHash.cpp LinkedList.cpp Item.cpp
// g++ -o main.exe Task5.o HashTable.o ChainedHash.o LinkedList.o Item.o
// ./main.exe

// g++ -c Task5.cpp
// g++ -o main.exe Task5.o
// ./main.exe