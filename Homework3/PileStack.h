#ifndef PILESTACK_H
#define PILESTACK_H

#include<iostream>
#include<LinkedList.h>

class SidePile {
    const int size = 5;
    LL data;
    int index = 0; //Where next we add goes
    
    void Push(int in);

    int Pop();

    bool IsFull() {return index >= size}

    bool IsEmpty() {return index <= 0}

    int Count() {
        return index;
    }
};

#endif