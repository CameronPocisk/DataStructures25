// How to

#include "PileStack.h"
using namespace std;

void SidePile::AddCard(int in){
    if(IsFull()) {
        throw OverflowError();
    }
    cards[index] = in;
    index++;
}

int SidePile::RemoveCard(){
    if(IsEmpty()) {
        throw UnderflowError();
    }
    index--;
    return cards[index];
}