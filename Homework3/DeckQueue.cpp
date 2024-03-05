#include "DeckQueue.h"
using namespace std;

void DeckQueue::Enqueue(int in){
    data.InsertEnd(in);
    index++;
}

int DeckQueue::Dequeue(){
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