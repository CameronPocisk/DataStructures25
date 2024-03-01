#ifndef DECKQUEUE_H
#define DECKQUEUE_H

#include "Exceptions.h"
#include "LinkedList.h"


class DeckQueue{
    LL data;
    int index = 0;

    void Enqueue(int in) {
    data.InsertEnd(in);
    index++;
    }

    int Dequeue() {
        if(data.isEmpty()) {
            throw UnderflowError();
        }
        int hold = data.RemoveFront();
        for(int i = 0; i < index; i++){
            data[i] = data[i+1];
        }
        index--;
        return hold;
    }

    bool IsFull() {
        return index >= size;
    }

    int length() {
        return index;
    }
};



#endif