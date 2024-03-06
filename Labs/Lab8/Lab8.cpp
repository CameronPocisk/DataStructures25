#include <iostream>
#include "OrderedDll.h"
using namespace std;

int main(){
    cout << "Running program" << endl;
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
    // instance.PrintItems();
    instance.AddItem(&val15);
    // instance.PrintItems();
    instance.AddItem(&val20);
    // instance.PrintItems();
    instance.AddItem(&val25);
    
    instance.PrintItems();

}

// g++ -c Lab8.cpp OrderedDll.cpp
// g++ -o main.exe Lab8.o OrderedDll.o
// ./main.exe
