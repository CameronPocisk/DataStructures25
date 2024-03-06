#ifndef DECKQUEUE_H
#define DECKQUEUE_H

#include "Exceptions.h"
#include "LinkedList.h"


class DeckQueue{
    private:
        LL data;
        int index;

    public:
<<<<<<< HEAD
        DeckQueue(){
            index = 0;
        }
=======
        DeckQueue(){index = 0;}
>>>>>>> dee7ac1ab4c633424aef4be0fddd7ee1fb82abc6
        void Enqueue(int in);

        int Dequeue();

        // bool IsFull(){return index >= 52;}
        int length() {return index;}
};

#endif