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

    void RemoveFront(){
        if(head == nullptr){ throw UnderflowError(); }
        // Node<T> *temp = head;
        head = head->next;
        length--;
    }

    void RemoveEnd(){
        if(head == nullptr) { throw UnderflowError(); }
        length--;
        
        if(head->next == nullptr){
            head = nullptr;
            return;
        }
        Node<T>* cur = head;
        while(cur->next->next != nullptr){
            cur = cur->next;
        }
        cur->next = nullptr; // Remove what points to it
    }

    void RemoveItem(T* toRemove){
        cout << "Remove item" << endl;
        
        if(head == nullptr) { throw NotFound(); }
        
        if(*(head->data) == *toRemove){
            RemoveFront(); // Can do this that we made!
            return;
        }

        Node<T>* temp = head;
        while(temp->next != nullptr && *(temp->next->data) != *toRemove){
            temp = temp->next;
            cout << temp->data << endl;
            cout << toRemove << endl;
            cout  << endl;
        }

        if(temp->next == nullptr){ throw NotFound(); }
        // temp next exists and is to remove

        temp->next = temp->next->next;
        length--;
    }

    void InsertEnd(T* in){
        Node<T>* newNode = new Node<T>(in);
        length++;

        if(head == nullptr){ // Empty case
            head = newNode;
            return;
        }

        // Iterate to empty node
        Node<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    T* GetValue(T* toFind){
        if(head == nullptr){throw NotFound(); }// Head case

        Node<T>* cur = head;
        while(cur != nullptr && *(cur->data) != *toFind){
            cur = cur->next; // go to the next!
        }

        if(cur == nullptr){ // Reached end of list
            throw NotFound();
        }
        // not at end case so found case
        return cur->data;
    }

    T* GetIndex(int index){
        if(index > length){
            throw OverflowError();
        }
        Node<T>* cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        return cur->data;
    }

    bool HasNode(T* toFind){
        if(head == nullptr) { return false; }

        Node<T>* cur = head;
        while(cur != nullptr && *cur->data != *toFind){
            cur = cur->next;
        }

        return cur != nullptr;
    }


    int GetLength(){ return length; }

    bool IsEmpty(){return head == nullptr;}

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
