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
    int index = 0;

    public:
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

};


// class RingQueue{
//     int start = 0;
//     int end = 0;
//     static const int size = 5;
//     char data[size];

//     public:

//     bool isFull(){
//         return start == end && end != 0;
//     }
//     bool isEmpty(){
//         return end == 0;
//     }
//     void enqueue(char in){
//         if(isFull()){
//             throw overflow_error("overlfowring q");
//         }

//         end = (end + 1) % 5; // Nathan cooked
//         data[end] = in;
//         end++;
//     }
//     char dequeue(){
//         if(isEmpty()){
//             throw overflow_error("Underflow ring");
//         }
//         char temp = data[start];
//         start = (start + 1) % size;
//         return start;
//     }
// }

int main(){

    Queue qExample;
    cout << "Is empty: " << qExample.isEmpty() << endl;
    cout << "Is full: " << qExample.isFull() << endl;

    for(int i = 0; i < 5; i++){
        cout << "enqueing " << char('a' + i) << endl; qExample.enqueue('a' + i);
    }
    cout << "Is full: " << qExample.isFull() << endl;

    for(int i = 0; i < 5; i++){
        cout << "Printing dequeue: " << qExample.dequeue() << endl;
    }
    cout << "Is empty: " << qExample.isEmpty() << endl;
    return 0;
}

// g++ -c QueuesNotes.cpp
// g++ -o main.exe QueuesNotes.o
// ./main.exe