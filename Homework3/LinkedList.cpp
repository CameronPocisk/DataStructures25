#include "LinkedList.h"


void LL::InsertEnd(int in){
    Node* newNode = new Node(in);
    length++;

    if(head == nullptr){ // Empty case
        head = newNode; 
        return;
    }

    // Iterate to empty node
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void LL::InsertFront(int in){
    Node* atFront = new Node(in);
    atFront->next = head;
    head = atFront;
    length++;
}

void LL::RemoveEnd(int in){
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

int LL::RemoveFront(){
    if(head->next == nullptr){
        throw UnderflowError();
    }
    Node *temp = head;
    head = head->next;
    length--;
    return temp->data;
}

void LL::MakeEmpty(){
    head = nullptr; // This should remove everything
    length = 0;
}

