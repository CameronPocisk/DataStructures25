#include "Tree.h"
#include "Tree.cpp"
#include <iostream>

using namespace std;

int main(){
    Tree<int> t;

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    int val4 = 4;


    t.Insert(&val1);
    t.Insert(&val2);
    t.Insert(&val3);
    t.Insert(&val4);
    t.PrintOrdered();


    return 0;
}

// g++ -c Lab9.cpp Tree.cpp
// g++ -o main.exe Lab9.o Tree.o
// ./main.exe


// For dom, mac is weird fr
// g++ --std=c++17 -c Lab8.cpp
// g++ --std=c++17 -o main.exe Lab9.o
// ./main.exe