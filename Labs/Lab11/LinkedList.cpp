#include "LinkedList.h"

template <typename T>
void LL<T>::InsertEnd(T* in){
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
template <typename T>
void LL<T>::InsertFront(T* in){
    Node<T>* atFront = new Node<T>(*in);
    atFront->next = head;
    head = atFront;
    length++;
}

template <typename T>
void LL<T>::RemoveEnd(){
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

template <typename T>
void LL<T>::RemoveFront(){
    if(head == nullptr){
        throw UnderflowError();
    }
    Node<T> *temp = head;
    head = head->next;
    length--;
}

template <typename T>
void LL<T>::RemoveItem(T* toRemove){
    if(*(head->data) == *toRemove){
        RemoveFront(); // Can do this that we made!
        return;
    }

    Node<T>* temp = head;
    while(temp->next != nullptr && *(temp->next->data) != *toRemove){
        temp = temp->next;
    }

    if(temp->next == nullptr){
        // cout << "not found" << endl;
        return;
    }

    temp->next = temp->next->next; // Replace items ptr with its next
}
template <typename T>
T* LL<T>::GetValue(T* toFind){
    if(head == nullptr){ return nullptr; }// Head case

    Node<T>* cur = head;
    while(cur != nullptr && *(cur->data) != *toFind){
        cout << *(cur->data) << ", ";
        cur = cur->next; // go to the next!
    }

    if(cur == nullptr){ // Reached end of list
        return nullptr;
    }
    // not at end case so found case
    return cur->data;
}

template <typename T>
void LL<T>::MakeEmpty(){
    head = nullptr; // This should remove everything
    length = 0;
}

