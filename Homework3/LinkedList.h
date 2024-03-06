#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Exceptions.h"
#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    // Constructor
    Node(int dataIn = 0){
        data = dataIn;
        next = nullptr;
    }
};

class LL{
    Node* head;
    int length;
    public:

    LL(){
        length = 0;
        head = nullptr;
    }

    void InsertEnd(int in);
    
    void InsertFront(int in);

    void RemoveEnd(int in);
    
    int RemoveFront();

    int Length(){
        return length;
    }
    void MakeEmpty();

    bool IsEmpty(){return head == nullptr;}

    ~LL(){
        //Destructor
    }
};

#endif
