#ifndef ORDEREDDLL_H
#define ORDEREDDLL_H

#include "Exceptions.h"

template <typename T>
class Node{
    public:
    Node* next;
    Node* previous;
    T data;
    // Constructor
    Node(T dataIn = nullptr){
        data = dataIn;
        next = nullptr;
        previous = nullptr;
    }
    void PrintNode();
};


template <typename T>
class OrderedDll{
    private:
    Node<T>* head;
    int length;
    int seePlace;
    bool endReached;
    bool begReached;
    Node<T>* place;
    
    public:
    OrderedDll(){
        head = nullptr;
        place = head;
        length = 0;
        seePlace = 0;
        endReached = false;
        begReached = true;
    }
    // Peep the cpp
    void AddItem(T *in);
    T GetItem(T *val);
    bool IsInList(T *val);
    bool IsEmpty(){return head == nullptr;} // return length?
    int Size() {return length;} // Inline
    T SeeNext();
    T SeePrev();
    T SeeAt(int userPlace);
    void Reset();
    void PrintItems();

    //Destructor
    ~OrderedDll(){
        cout << "Destroying" << endl;
        while(head != nullptr) {
            // itterate and call delete on teh temp node
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
};


#endif