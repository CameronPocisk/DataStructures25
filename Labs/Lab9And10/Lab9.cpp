#include "Tree.h"
#include "Tree.cpp"
#include <iostream>

using namespace std;

int main(){
    Tree<int> t;
    int val0 = 0;
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    int val4 = 4;
    int val5 = 5;
    int val6 = 6;
    int val7 = 7;
    int val8 = 8;


    // cout << "Size: " << t.Size() << endl;

    t.Insert(&val5);
    t.Insert(&val7);
    t.Insert(&val3);
    t.Insert(&val8);
    t.Insert(&val2);
    t.Insert(&val6);
    t.Insert(&val4);
    t.PrintStructured();


    cout << "Removing..." << endl;
    t.RemoveNew(&val7); // Two children
    t.RemoveNew(&val6); // One children
    t.RemoveNew(&val8); // Zero children
    t.RemoveNew(&val3); // Two and Root
    // Should be good
    cout << "Done removing" << endl;
    t.PrintStructured();

    int val4Copy = 4;
    int val7Copy = 7;
    cout << "Found val4 : "<< (t.Find(&val4Copy)->data == &val4) << endl;
    // cout << "Found val7 : "<< (t.Find(&val7Copy)->data == &val7) << endl; // Throws not found
    cout << "Size: " << t.Size() << endl;
    // cout << t.EmptyTree() << endl;
    
    // t.PrintOrdered();
    // cout << endl;
    // t.PrintStructuredWithRootSizes();

    // int toFind = 5; // Test find
    // try{
    //     t.Find(&toFind);
    //     cout << "Found it!" << endl;
    // }
    // catch(NotFound &e){
    //     cout << "did not find value" << endl;
    // }

    // // Ascending and descending things
    
    // // Descending already tested
    vector<Node<int>*> arr = t.GetAllDecending();
    
    // I feel weird abt this
    for(int i = 0; i < arr.size(); i++){
        cout << *arr.at(i)->data << ',';
    } 
    cout << endl;

    cout << "Emptying tree " << endl;
    t.EmptyTree(); 
    cout << "Size: " << t.Size() << endl;
    return 0;
}

// g++ -c Lab9.cpp Tree.cpp
// g++ -o main.exe Lab9.o Tree.o
// ./main.exe


// For dom, mac is weird fr
// g++ --std=c++17 -c Lab9.cpp Tree.cpp
// g++ --std=c++17 -o main.exe Lab9.o Tree.o
// ./main.exe