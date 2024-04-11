#include "HashTable.h"
#include "HashTable.cpp"

using namespace std; // namespace name


int main(){
    cout << "Hello" << endl;
    HashTable<string> curTable; // default sized table

    cout << "Is empty: " << curTable.IsEmpty() << endl;

    string test1 = "Fortnite";
    string test2 = "goon";
    string test3 = "Fortnited"; // Overlap
    // int hashed = curTable.Hash(test);
    curTable.Insert(&test1);
    curTable.Insert(&test2);
    curTable.Insert(&test3);

    string copy1 = "Fortnited";
    curTable.Remove(&copy1);
    
    string* gotItem = curTable.GetItem(&test2);
    cout << "found it? " << (gotItem == &test2) << endl;
    // cout << "Is empty: " << curTable.IsEmpty() << endl;
    try{
        cout << "Found item not in list: ";
        curTable.GetItem(&test3);
    }
    catch(NotFound &e){
        cout << "Not found" << endl;
    }
    // curTable.PrintTable();
    curTable.printInTable();
    // curTable.PrintTable(); // Good 4 now

    cout << "Ending program..." << endl;
    return 0;
}

// g++ -c Lab11.cpp HashTable.cpp
// g++ -o main.exe Lab11.o HashTable.o
// ./main.exe