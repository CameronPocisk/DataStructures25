#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H

#include "Exceptions.h"
#include "AdjGraph.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node{
    public:
    Node<T>* next;
    T data;
    // Constructor
    Node(T dataIn){
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
    
    ~LL(){ ; }//Destructor (needed???)

    void InsertEnd(T in){
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
    
    void InsertFront(T in){
        Node<T>* atFront = new Node<T>(in);
        atFront->next = head;
        head = atFront;
        length++;
    }

    void RemoveEnd(){
        if(head == nullptr){ // Empty case
            throw UnderflowError();
        }

        // Itterate to empty node and set to nullptr
        Node<T>* cur = head;
        while(true){
            if(cur->next->next == nullptr){
                cur->next = nullptr;
                length--;
                return;
            }
            cur = cur->next; // itterate!
        }
    }

    void RemoveFront(){
        if(head == nullptr){
            throw UnderflowError();
        }
        Node<T> *temp = head;
        head = head->next;
        length--;
    }
    void RemoveItem(T toRemove){
        if(head->data == toRemove){
            RemoveFront(); // Can do this that we made!
            return;
        }

        Node<T>* temp = head;
        while(temp->next != nullptr && temp->next->data != toRemove){
            temp = temp->next;
        }

        if(temp->next == nullptr){
            throw NotFound();
        }

        temp->next = temp->next->next; // Replace items ptr with its next
    }
    T GetValue(T toFind){
        if(head == nullptr){ throw NotFound(); }// Head case

        Node<T>* cur = head;
        while(cur != nullptr && cur->data != toFind){
            cur = cur->next; // go to the next!
        }

        if(cur == nullptr){ // Reached end of list
            throw NotFound();
        }
        // not at end case so found case
        return cur->data;
    }
    
    T GetIndex(int index){
        if(index > length){
            throw OverflowError();
        }
        Node<T>* cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        return cur->data;
    }

    int Length(){ return length; }

    bool IsEmpty(){return head == nullptr;}
    void MakeEmpty(){
        head = nullptr; // This should remove everything
        length = 0;
    }


    void PrintList(){
        
        if(IsEmpty()){
            cout << "was empty" << endl;
            return;
        }

        Node<T>* temp = head;
        while(temp != nullptr){
            // string asData = string(temp->data); // weird here so....
            // cout << asData << ", ";
            cout << temp->data << ", ";
            temp = temp->next;
        }
    }
};

#endif
