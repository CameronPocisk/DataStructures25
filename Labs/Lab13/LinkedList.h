#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Exceptions.h"
#include <iostream>
#include <string>
using namespace std;

class Student{
    public:

    int mNumber;
    string firstName;
    string lastName;

    Student(int mNumIn = 69, string firstIn = "noFirst", string lastIn = "noLast"){
        mNumber = mNumIn;
        firstName = firstIn;
        lastName = lastIn;
    } // Contructor that makes random students

    bool operator == (const Student& RHS) { return mNumber == RHS.mNumber; }
    bool operator != (const Student& RHS) { return mNumber != RHS.mNumber; }
    bool operator <  (const Student& RHS) { return mNumber < RHS.mNumber;  }
    bool operator >  (const Student& RHS) { return mNumber > RHS.mNumber;  }
    bool operator <= (const Student& RHS) { return mNumber <= RHS.mNumber; }
    bool operator >= (const Student& RHS) { return mNumber >= RHS.mNumber; }

    friend ostream& operator<<(ostream& os, const Student& data) {
        // Ovveride the << operator
        cout << data.firstName << ' ' << data.lastName << ": " << data.mNumber;
        os << "";
        return os;
    }

    void printName(){cout << firstName << " " << lastName << endl;}
};

class Node{
    public:
    Node* next;
    Student* data;
    // Constructor
    Node(Student* dataIn){
        data = dataIn;
        next = nullptr;
    }
};

class LLSortStudent{
public:
    Node* head;
    int length; // extra

public:

    // The three sorting methods by 3 properties
    void BubbleLast(bool ascending = true){
        cout << "Bubble sorting by LastName..." << endl;

    }
    void InsertionFirst(bool ascending = true){
        cout << "Insertion sorting by FirstName..." << endl;

    }
    void QuickMnumber(bool ascending = true){
        cout << "Insertion sorting by Mnumber..." << endl;

    }

    LLSortStudent(){
        length = 0;
        head = nullptr;
    }
    ~LLSortStudent(){
        //Destructor (needed???)
    }

    void InsertEnd(Student* in){
        Node* newNode = new Node(in);
        length++;

        if(head == nullptr){ // Empty case
            head = newNode;
            return;
        }

        // Iterate to empty node
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Student RemoveEnd(){
        if(head == nullptr) { throw UnderflowError(); }
        
        length--;
        if(head->next == nullptr){
            Student hold = *(head->data);
            head = nullptr;
            return hold;
        }
        Node* cur = head;
        while(cur->next->next != nullptr){
            cur = cur->next;
        }
        Student hold = *(cur->next->data);
        cur->next = nullptr; // Remove what points to it
        return hold;
    }

    int GetLength(){ return length; }
    bool IsEmpty(){return head == nullptr;}

    void PrintList(){
        if(IsEmpty()){ return; }

        Node* temp = head;
        while(temp != nullptr){
            cout << *(temp->data) << ", ";
            temp = temp->next;
        }
    }
};

#endif
