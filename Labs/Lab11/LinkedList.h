#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Exceptions.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node{
    public:
    Node<T>* next;
    T* data;
    // Constructor
    Node(T* dataIn){
        data = dataIn;
        next = nullptr;
    }
};

template <typename T>
class LL{
public:
    Node<T>* head;
    int length; // extra

public:
    LL(){
        length = 0;
        head = nullptr;
    }
    ~LL(){
        //Destructor (needed???)
    }

    void InsertEnd(T* in);
    void InsertFront(T*in);

    void RemoveEnd();
    void RemoveFront();
    void RemoveItem(T* toRemove);
    T* GetValue(T* toFind);

    int Length(){ return length; }

    bool IsEmpty(){return head == nullptr;}
    void MakeEmpty();

    void PrintList(){
        if(IsEmpty()){
            return;
        }

        Node<T>* temp = head;

        while(temp != nullptr){
            // string asData = string(temp->data); // weird here so....
            // cout << asData << ", ";
            cout << *(temp->data) << ", ";
            temp = temp->next;
        }
    }
};

#endif
