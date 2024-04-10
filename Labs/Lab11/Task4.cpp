// #include "ChainedHash.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "ChainedHash.h"
#include "ChainedHash.cpp"
#include <iostream>

using namespace std;
int main(){
    cout << "Running..." << endl;

    LL<string> tester;
    string val1 = "abc";
    string val2 = "newString";
    string val3 = "abcd";
    string val4 = "test";
    tester.InsertEnd(&val1);
    tester.InsertEnd(&val2);
    tester.InsertEnd(&val3);

    tester.PrintList(); 
    // tester.RemoveFront();
    tester.RemoveItem(&val2); cout << endl;
    tester.PrintList(); 
    string* findHold = tester.GetValue(&val2);
    if(findHold != nullptr){
        cout << "Found: " << *findHold << endl;
    }
    else{cout << "didnt find none" << endl; }

    cout << endl << "testing hash chain" << endl;
    ChainedHash<string> hashTester(100);
    hashTester.Insert(&val1);
    hashTester.Insert(&val2);
    hashTester.Insert(&val3);

    hashTester.PrintItems(); cout << endl;
    // hashTester.Remove(&val3);
    // cout << "Removed " << val3 << endl;

    string* gainedItem = hashTester.GetItem(&val3);
    if(gainedItem != nullptr){
        cout << "Found: " << *gainedItem << endl;
    }
    else{
        cout << "Did not find ish" << endl;
    }

    // hashTester.PrintItems();

    cout << "Ended program... " << endl;
    return 0;
}

// g++ -c Task4.cpp ChainedHash.cpp LinkedList.cpp
// g++ -o main.exe Task4.o ChainedHash.o LinkedList.o
// ./main.exe

// g++ -c Task4.cpp  LinkedList.cpp
// g++ -o main.exe Task4.o LinkedList.o
// ./main.exe