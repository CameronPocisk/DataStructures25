#include "item.h"
#include "HashTable.h"
#include "HashTable.cpp"
#include <iostream>

using namespace std;

int main(){
    Item Test1("abcs");
    Item Test2("zyxs");
    Item Test3("123");


    HashTable<Item> instance(100);
    instance.Insert(&Test1);
    instance.Insert(&Test2);

    try{
        instance.GetItem(&Test3);
        cout << "Found item" << endl;
    }
    catch(NotFound &e){
        cout << "Not found" << endl;
    }

    instance.printInTable();

    return 0;
}

// g++ -c Test.cpp item.cpp HashTable.cpp
// g++ -o main.exe Test.o item.o HashTable.o
// ./main.exe