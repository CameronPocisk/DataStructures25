#ifndef PILESTACK_H
#define PILESTACK_H

#include <iostream>
#include "Exceptions.h"

class SidePile{
    private:
    const static int maxSize = 5;
    int cards[maxSize];
<<<<<<< HEAD
    int index;

    public:
    SidePile(){
        index = 0;
    }
=======
    int index; //Where next we add goes

    public:
    SidePile(){index = 0;}
>>>>>>> dee7ac1ab4c633424aef4be0fddd7ee1fb82abc6
    void AddCard(int in); // Add card

    // No Peek (Not allowed)
    int RemoveCard(); // Remove card

    // Nice Inlines
    bool IsEmpty() {return index <= 0;}
    bool IsFull() {return index >= maxSize;}
    int GetNumCards() {return index;} //This needs a way to tell the player how many cards they have left but not the other player.
};

#endif