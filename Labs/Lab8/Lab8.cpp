#include <iostream>
#include "OrderedDll.h"
// #include "OrderedDll.cpp" //For Dom, mac is so strange
using namespace std;

int main(){
    cout << "Running program" << endl;
    cout << __cplusplus << endl;
    OrderedDll<int> instance;
    int val10 = 10;
    int val15 = 15;
    int val20 = 20;
    int val25 = 25;
    int val30 = 30;
    // int* valPtr = &val;
    instance.AddItem(&val10); // nothing
    // instance.PrintItems();
    instance.AddItem(&val30);
    // // // instance.PrintItems();
    // instance.AddItem(&val15);
    // // instance.PrintItems();
    // instance.AddItem(&val20);
    // // instance.PrintItems();
    // instance.AddItem(&val25);
    instance.PrintItems();

    return 0;
}

// g++ -c Lab8.cpp OrderedDll.cpp
// g++ -o main.exe Lab8.o OrderedDll.o
// ./main.exe


//For dom, mac is weird fr
// g++ --std=c++17 -c Lab8.cpp
// g++ --std=c++17 -o main.exe Lab8.o
// ./main.exe