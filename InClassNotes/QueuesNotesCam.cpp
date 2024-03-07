#include <iostream>
#include <stdexcept>
using namespace std;

/*
Queues are FIFO 'line like' data strucutres
A queue has these functions:

enqueu - Add an item to the queue

dequeue - Remove item from queue and return it

peek/Front - Return but keep item in the line

length - Returns num elements in the queue

is empty - true if empty
is full - true if cannot add items

makeEmpty - Completly adds all items to the queue

*/

class Queue{
    protected:
    static const int size = 5;
    char data[size];
    int index;

    public:

    Queue(){
        index = 0;
    }
    bool isEmpty(){
        return index == 0;
    }
    bool isFull(){
        return index == size;
    }
    char peek(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            throw underflow_error("empty");
        }
        return data[0];
    }
    void makeEmpty(){
        index = 0;
    }

    void enqueue(char in){
        if(isFull()){
            cout << "Stack is full" << endl;
            throw underflow_error("full");
        }
        data[index] = in;
        index++;
    }
    char dequeue(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            throw underflow_error("empty");
        }

        char holdReturn = data[0];
        for(int i = 0; i < index; i++){
            data[i] = data[i + 1];
        }
        index--;
        return holdReturn;
    }

    void printQueue(){
        for(int i = 0; i < index; i++){
            cout << data[i] << ", ";
        }
        cout << endl;
    }

};


class RingQueue{
    int start;
    int end;
    static const int size = 5;
    char data[size];

    public:

    RingQueue(){
        start = 0;
        end = 0;
    }

    bool isFull(){
        return end + -(start) >= size;
    }
    bool isEmpty(){
        return end == start;
    }
    void enqueue(char in){
        if(isFull()){
            throw overflow_error("overlfowring q");
        }
        end = (end) % 5; // Nathan cooked // End has to be add after the data is inputted
        data[end] = in;
        end++; //If this is in the (end) than it starts at value 1
    }
    char dequeue(){
        if(isEmpty()){
            throw overflow_error("Underflow ring");
        }
        char temp = data[start];
        start = (start) % size;
        start++;
        return temp;
    }
    void printQueue(){
        for(int i = start; i < end; i++){
            cout << data[i] << ", ";
        }
        cout << endl;
    }
};

int main(){

    Queue qExample;
    cout << "Is empty: " << qExample.isEmpty() << endl;
    cout << "Is full: " << qExample.isFull() << endl;

    for(int i = 0; i < 5; i++){
        cout << "enqueing " << char('a' + i) << endl; 
        qExample.enqueue('a' + i);
    }
    qExample.printQueue();
    cout << "Is full: " << qExample.isFull() << endl;

    for(int i = 0; i < 5; i++){
        cout << "Printing dequeue: " << qExample.dequeue() << endl;
        qExample.printQueue();
    }
    qExample.printQueue();
    cout << "Is empty: " << qExample.isEmpty() << endl;
    
    return 0;
}

// g++ -c QueuesNotesCam.cpp
// g++ -o main.exe QueuesNotesCam.o
// ./main.exe