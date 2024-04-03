#include "HashTable.h"

using namespace std; // namespace name


int main(){
    cout << "Hello" << endl;
    HashTable<string> curTable; // default sized table

    string test = "Fortnite";
    curTable.Insert(&test);
    curTable.PrintTable();
    // curTable.PrintTable(); // Good 4 now

    cout << "Bye bye" << endl;
    return 0;
}

// g++ -c Lab11.cpp HashTable.cpp
// g++ -o main.exe Lab11.o HashTable.o
// ./main.exe