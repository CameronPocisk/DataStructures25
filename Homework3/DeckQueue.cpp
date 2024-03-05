#include "DeckQueue.h"
using namespace std;

void DeckQueue::Enqueue(int in){
    data.InsertEnd(in);
    index++;
}

int DeckQueue::Dequeue(){
    if(data.IsEmpty()) {
        throw UnderflowError();
    }
    int hold = data.RemoveFront();
    index--;
    return hold;
}
