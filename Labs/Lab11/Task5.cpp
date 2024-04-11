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
    NumSkus = 50,
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

    
    // linearProber.printInTable();
    // chainer.PrintItems();

    
    

    

    int userChoice;
    cout << "1. User Test" << endl << "2. Automated Test" << endl << "3. Quit" << endl;
    cin >> userChoice;
    cout << endl;
    while(userChoice < 1 && userChoice > 3){
        cout << "Please enter 1, 2, or 3: ";
        cin >> userChoice;
        cout << endl;
    }
    switch (userChoice)
    {
    case 1:
        cout << "1. Linear Probing from Task 1" << endl << "2. Separate Chaining from Task 4" << endl;
        cout << "3. Quit" << endl;
        cin >> userChoice;
        cout << endl;
        switch (userChoice)
        {
        case 1:
            while(userChoice != 5){
                cout << "1. Add Item" << endl << "2. Remove Item" << endl << "3. Search for Item" << endl;
                cout << "4. Display Length" << endl << "5. Quit" << endl;
                cin >> userChoice;
                cout << endl;
                switch (userChoice)
                {
                case 1:{
                    string userItem;
                    cout << "Enter item to add: ";
                    cin >> userItem;
                    linearProber.Insert(&userItem);
                    cout << "You are at " << linearProber.GetNumComps() << " comparasons." << endl;
                    break;
                }
                case 2:{
                    string userItem;
                    cout << "Enter item to remove: ";
                    cin >> userItem;
                    try
                    {
                        linearProber.Remove(&userItem);
                    }
                    catch(NotFound &e)
                    {
                        cout << userItem << " is not in" << endl;
                    }
                    
                    cout << "You are at " << linearProber.GetNumComps() << " comparasons." << endl;
                    break;
                }
                case 3:{
                    string userItem;
                    cout << "Enter item to search for: ";
                    cin >> userItem;
                    try
                    {
                        linearProber.GetItem(&userItem);
                        cout << userItem << " is in! (You are at " << linearProber.GetNumComps() << " comparasons)" << endl;
                    }
                    catch(NotFound &e)
                    {
                        cout << userItem << " is not in." << endl;
                        cout << "You are at " << linearProber.GetNumComps() << " comparasons." << endl;
                    }
                    break;
                }
                case 4:{
                    cout << "The length is: " << linearProber.GetLength() << endl;
                    cout << "You are at " << linearProber.GetNumComps() << " comparasons." << endl;
                }
                default:
                    break;
                }
            }
            break;
        case 2:
            while(userChoice != 5){
                cout << "1. Add Item" << endl << "2. Remove Item" << endl << "3. Search for Item" << endl;
                cout << "4. Display Length" << endl << "5. Quit" << endl;
                cin >> userChoice;
                cout << endl;
                switch (userChoice)
                {
                case 1:{
                    string userItem;
                    cout << "Enter item to add: ";
                    cin >> userItem;
                    chainer.Insert(&userItem);
                    cout << "You are at " << chainer.GetNumComps() << " comparasons." << endl;
                    break;
                }
                case 2:{
                    string userItem;
                    cout << "Enter item to remove: ";
                    cin >> userItem;
                    try
                    {
                        chainer.Remove(&userItem);
                    }
                    catch(NotFound &e)
                    {
                        cout << userItem << " is not in" << endl;
                    }
                    cout << "You are at " << chainer.GetNumComps() << " comparasons." << endl;
                    break;
                }
                case 3:{
                    string userItem;
                    cout << "Enter item to search for: ";
                    cin >> userItem;
                    try
                    {
                        chainer.GetItem(&userItem);
                        cout << userItem << " is in! (You are at " << chainer.GetNumComps() << " comparasons)" << endl;
                    }
                    catch(NotFound &e)
                    {
                        cout << userItem << " is not in." << endl;
                        cout << "You are at " << chainer.GetNumComps() << " comparasons." << endl;
                    }
                    break;
                }
                case 4:{
                    cout << "The length is: " << chainer.GetLength() << endl;
                    cout << "You are at " << chainer.GetNumComps() << " comparasons." << endl;
                    chainer.PrintItems();
                }
                default:
                    break;
                }
            }
            break;
        default:
            break;
        }
        break;
    case 2:
        for(int i = 0; i < NumSkus; i++){
            linearProber.Insert(&skus[i]);
            chainer.Insert(&skus[i]);
        }
        for(int i = 0; i < NumSkus; i++){
            linearProber.GetItem(&skus[i]);
            chainer.GetItem(&skus[i]);
        }

        cout << "Linear probing comps for " << NumSkus << " items: " << linearProber.GetNumComps() << endl;
        cout << "Chain hash comps for " << NumSkus << " items: " << chainer.GetNumComps() << endl << endl;
        break;
    default:
        break;
    }
    


    cout << "prorgram finished... ";
    return 0;
}

// g++ -c Task5.cpp HashTable.cpp ChainedHash.cpp LinkedList.cpp Item.cpp
// g++ -o main.exe Task5.o HashTable.o ChainedHash.o LinkedList.o Item.o
// ./main.exe

// g++ -c Task5.cpp
// g++ -o main.exe Task5.o
// ./main.exe