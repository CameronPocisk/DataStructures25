// How to

#include "PileStack.h"
using namespace std;

void SidePile::Push(int in){
    if(IsFull()) {
        throw OverflowError();
    }
    data[index] = in;
    index++;
}

int SidePile::Pop(){
    if(IsEmpty()) {
        throw UnderflowError;
    }
index--;
return data[index];
}