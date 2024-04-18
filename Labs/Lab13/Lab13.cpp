#include "Sorting.h"
#include "LinkedList.h"

#include <iostream>
#include <chrono>

using namespace std;
typedef chrono::high_resolution_clock Clock;


int main(){

    Sorting arr;

    LLSortStudent sortedLL;

    Student studentOne(37, "Cameron", "Pocisk");
    Student studentTwo(1, "Dom", "Iquina");
    Student studentThree;

    sortedLL.InsertEnd(&studentOne);
    sortedLL.InsertEnd(&studentTwo);

    sortedLL.PrintList();

    arr.MergeAvg();
}

// Linker proof
// g++ -c Lab13.cpp 
// g++ -o main.exe Lab13.o
// ./main.exe

// g++ --std=c++17 -c Lab13.cpp
// g++ --std=c++17 -o main.exe Lab13.o
// ./main.exe