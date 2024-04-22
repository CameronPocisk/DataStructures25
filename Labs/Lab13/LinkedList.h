#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Exceptions.h"
#include "RandomInfo.h"
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

    Student* ToArray(){
        Student* asArray = new Student[length];
        int loopIttrs = length;
        for(int i = 0; i < loopIttrs; i++){
            asArray[i] = RemoveEnd();
        }
        return asArray;
    }

public:

    void GenerateStudents(int numToGen){
        RandomNames randoms;
        int sudentCount = numToGen; // number from lab
        srand(time(NULL));
        for(int i = 0; i < sudentCount; i++){
            string curFirst = randoms.GetRandomFirst();
            string curLast  = randoms.GetRandomLast();
            int curMnum = 100000 + (rand()*6767 % 900000) ; // 6 dig num

            Student *asPtr = new Student(curMnum, curFirst, curLast);
            InsertEnd(asPtr);
        }
    }
    // The three sorting methods by 3 properties
    void BubbleLast(bool ascending = true){
        cout << "Bubble sorting by LastName..." << endl;
        int sizeCopy = length; // Do this before we get the array so we knowledgeable about the size
        Student* asArr = ToArray();

        // Copied over bubble (Thank you dom <3)
        for(int i = 0; i < sizeCopy - 1; i++){
            bool swapped = false;
            for(int j = 0; j < sizeCopy - i - 1; j++){
                if (ascending){
                    if(asArr[j].lastName > asArr[j+1].lastName) {
                        Student hold = asArr[j];
                        asArr[j] = asArr[j+1];
                        asArr[j+1] = hold;
                        swapped = true;
                    }
                }
                else{
                    if(asArr[j].lastName < asArr[j+1].lastName) {
                        Student hold = asArr[j];
                        asArr[j] = asArr[j+1];
                        asArr[j+1] = hold;
                        swapped = true;
                    }
                }
                    
            }
            if(!swapped){ break; }
        }
        // Add back from list into the LL
        for(int i = 0; i < sizeCopy; i++){
            Student* asNew = new Student;
            *asNew = asArr[i];
            InsertEnd(asNew);
        }

        // PrintList();
        delete[] asArr; // Must free up the memory!!!
        cout << "Bubble complete" << endl;
    }



    void InsertionFirst(bool ascending = true){
        cout << "Insertion sorting by First name..." << endl;
        int sizeCopy = length; // Do this before we get the array so we knowledgeable about the size
        Student* asArr = ToArray();

        // Made my own insertion for ascendingvs descening
        // I think that it can start at one
        for(int i = 0; i < sizeCopy; i++){
            // i == correct
            Student hold = asArr[i];
            int j = i-1;

            while(j >= 0 && asArr[j].firstName > hold.firstName) {
                asArr[j+1] = asArr[j];
                j--;
            }
            asArr[j+1] = hold;
        }
            

        // Add back from list into the LL
        if(ascending){
            for(int i = 0; i < sizeCopy; i++){
                Student* asNew = new Student;
                *asNew = asArr[i];
                InsertEnd(asNew);
            }
        }
        else{
            for(int i = sizeCopy-1 ; i >= 0; i--){
                Student* asNew = new Student;
                *asNew = asArr[i];
                InsertEnd(asNew);
            }
        }

        // PrintList();
        delete[] asArr; // Must free up the memory!!!
        cout << "Insertion complete" << endl;

    }

    void merge(Student* arr, int left, int mid, int right) {
        int lSize = mid - left + 1;
        int rSize = right - mid;

        //Create left and right arrays
        Student* leftArr = new Student[lSize];
        Student* rightArr = new Student[rSize];

        //add to the arrays
        for (int i = 0; i < lSize; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < rSize; j++)
            rightArr[j] = arr[mid + 1 + j];

        //add back to origional array in order
        int i = 0, j = 0, pos = left;
        while (i < lSize && j < rSize) {
            if (leftArr[i] < rightArr[j]) {
                arr[pos] = leftArr[i];
                i++;
            }
            else {
                arr[pos] = rightArr[j];
                j++;
            }
            pos++;
        }

        while (i < lSize) {
            arr[pos] = leftArr[i];
            i++;
            pos++;
        }

        while (j < rSize) {
            arr[pos] = rightArr[j];
            j++;
            pos++;
        }

        delete[] leftArr;
        delete[] rightArr;
    }

    void mergeSort(Student* arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void QuickMnumber(bool ascending = true) {
        cout << "Merge sorting by Mnumber..." << endl;
        int sizeCopy = length;
        Student* asArr = ToArray();
        mergeSort(asArr, 0, sizeCopy - 1);
        
        //decide what order to put the numbers in
        if(ascending){
            for(int i = 0; i < sizeCopy; i++){
                Student* asNew = new Student;
                *asNew = asArr[i];
                InsertEnd(asNew);
            }
        }
        else{
            for(int i = sizeCopy - 1; i >= 0; i--){
                Student* asNew = new Student;
                *asNew = asArr[i];
                InsertEnd(asNew);
            }
        }

        delete[] asArr;
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
    bool IsEmpty(){return head == nullptr || length == 0;}

    void PrintList(){
        if(IsEmpty()){ return; }

        Node* temp = head;
        while(temp != nullptr){
            cout << *(temp->data) << ", ";
            temp = temp->next;
        }
    cout << endl;
    }
};

#endif
