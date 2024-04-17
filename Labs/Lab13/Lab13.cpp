#include "Sorting.h"

#include <iostream>
#include <chrono>

using namespace std;
typedef chrono::high_resolution_clock Clock;


int main(){

    auto t1 = Clock::now();
    //Put the algorithm inbetween
    Sorting arr;
    auto t2 = Clock::now();
    arr.RadixAll();





}

// Linker proof
// g++ -c Lab13.cpp 
// g++ -o main.exe Lab13.o
// ./main.exe

// g++ --std=c++17 -c Lab13.cpp
// g++ --std=c++17 -o main.exe Lab13.o
// ./main.exe