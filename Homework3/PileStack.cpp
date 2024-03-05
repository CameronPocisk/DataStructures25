// How to

#include "PileStack.h"
using namespace std;

void SidePile::Push(int in){
    if(IsFull()) {
        throw StackOverflow;
    }
    data[index] = in;
    index++;
}

int SidePile::Pop(){
    if(IsEmpty()) {
        throw StackUnderflow;
    }
index--;
return data[index];
}