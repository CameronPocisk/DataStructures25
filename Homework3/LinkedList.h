#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Exceptions.h"
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    // Constructor
    Node(int dataIn = 0){
        data = dataIn;
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

    void InsertEnd(int in){
        Node* newNode = new Node(in);
        length++;

        if(head == nullptr){ // Empty case
            head = newNode; 
            return;
        }

        // Itterate to empty node
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void InsertFront(int in){
        Node* atFront = new Node(in);
        atFront->next = head;
        head = atFront;
        length++;
    }

    void RemoveEnd(int in){
        if(head == nullptr){ // Empty case
            throw UnderflowError();
        }

        // Itterate to empty node
        Node* temp = head;
        while(true){
            if(temp->next == nullptr){
                temp = nullptr;
                length--;
                return;
            }
        }
    }
    
    int RemoveFront(){
        if(head->next == nullptr){
            throw UnderflowError();
        }
        Node *temp = head;
        head = head->next;
        length--;
        return temp->data;
    }

    int Length(){
        return length;
    }
    void MakeEmpty(){
        head = nullptr; // This should remove everything
        length = 0;
    }

    bool IsEmpty(){
        return head == nullptr;
    }

    ~LL(){
        //Destructor
    }
};

#endif
