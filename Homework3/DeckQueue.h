#ifndef DECKQUEUE_H
#define DECKQUEUE_H

#include "Exceptions.h"
#include "LinkedList.h"


class DeckQueue{
    private:
        LL data;
        int index;
    public:
        DeckQueue();

        void Enqueue(int in);

        int Dequeue();

        bool IsFull(return index >= size;);

        int length() {return index;}
};


#endif