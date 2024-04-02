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

    int val4Copy = 4;

    cout << "Size: " << t.Size() << endl;

    t.Insert(&val3);
    t.Insert(&val6);
    t.Insert(&val7);
    t.Insert(&val5);
    t.Insert(&val1);
    t.Insert(&val8);
    t.Insert(&val2);

    t.RemoveNew(&val5);

    // cout << "Found val4 : "<< (t.Find(&val4Copy)->data == &val4) << endl;
    // cout << "Size: " << t.Size() << endl;
    // // cout << t.EmptyTree() << endl;
    
    // t.PrintOrdered();
    // cout << endl;
    t.PrintStructured();
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
    // vector<Node<int>*> arr = t.GetAllDecending();
    
    // I feel weird abt this
    // for(int i = 0; i < arr.size(); i++){
    //     cout << *arr.at(i)->data << ',';
    // } 
    // cout << endl;

    // t.EmptyTree(); 
    // cout << "Size: " << t.Size() << endl;
    return 0;
}

// g++ -c Lab9.cpp Tree.cpp
// g++ -o main.exe Lab9.o Tree.o
// ./main.exe


// For dom, mac is weird fr
// g++ --std=c++17 -c Lab9.cpp Tree.cpp
// g++ --std=c++17 -o main.exe Lab9.o Tree.o
// ./main.exe