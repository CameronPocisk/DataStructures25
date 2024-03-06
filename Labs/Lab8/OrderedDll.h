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
    Node(T dataIn = 0){
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
    
    public:
    OrderedDll(){
        head = nullptr;
        length = 0;
        seePlace = 0;
    }
    void AddItem(T *in);
    T GetItem(T *val);
    bool IsInList(T *val);
    bool IsEmpty(){return head == nullptr;} // return length?
    int Size() {return length;} // Inline
    T SeeNext();
    T SeePrev();
    T SeeAt(int place);
    void Reset();
    void PrintItems();

    //Destructor
    ~OrderedDll(){
        
    }
    
};


#endif