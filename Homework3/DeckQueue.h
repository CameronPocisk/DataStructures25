#ifndef DECKQUEUE_H
#define DECKQUEUE_H

#include "Exceptions.h"
#include "LinkedList.h"


class DeckQueue{
    private:
        LL data;
        int index;

    public:
        DeckQueue(){
            index = 0;
        }
        void Enqueue(int in);

        int Dequeue();

        // bool IsFull(){return index >= 52;}
        int length() {return index;}
};

#endif