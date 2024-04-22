#include "Sorting.h"
#include "LinkedList.h"

#include <iostream>
#include <chrono>

using namespace std;
typedef chrono::high_resolution_clock Clock;


int main(){

    // Sorting arr;

    LLSortStudent sortedLL;
    int numStudents = 7;
    sortedLL.GenerateStudents(numStudents); // Way to get random names (50 is default!!)

    int userChoice = 0;
    cout << "List seeded with " << numStudents <<  " random students" << endl;
    while(userChoice != 5){
        cout << "Enter 1 to Print the list " << endl;
        cout << "Enter 2 to BubbleSort By nast name " << endl;
        cout << "Enter 3 to Insertion Sort by first name " << endl;
        cout << "Enter 4 to Merge sort by M Number " << endl;
        cout << "Enter 5 to Quit " << endl;
        cin >> userChoice;
        while(userChoice < 1 || userChoice > 5){
            cout << "Please enter a number 1-5: ";
            cin >> userChoice;
        }

        switch (userChoice)
        {
        case 1:
            sortedLL.PrintList();
            break;
        
        case 2:{
            char userAscend;
            cout << "Sort Last names in ascending(Y/y) or descending(N/n)" << endl;
            cin >> userAscend;
            if(userAscend == 'y' || userAscend == 'Y')
            { sortedLL.BubbleLast(true); }
            else{ sortedLL.BubbleLast(false);}
            break;
        }
        case 3:{
            char userAscend;
            cout << "Sort first names in ascending(Y/y) or descending(N/n)" << endl;
            cin >> userAscend;
            if(userAscend == 'y' || userAscend == 'Y')
            { sortedLL.InsertionFirst(true); }
            else{ sortedLL.InsertionFirst(false);}
            break;
        }
        
        case 4:{
            char userAscend;
            cout << "Sort M Numbers in ascending(Y/y) or descending(N/n)" << endl;
            cin >> userAscend;
            if(userAscend == 'y' || userAscend == 'Y')
            { sortedLL.QuickMnumber(true); }
            else{ sortedLL.QuickMnumber(false);}
            break;
        }
        }
    }
    cout << "Last lab program done :) " << endl;
    // sortedLL.PrintList();
    // sortedLL.InsertionFirst(false); // test new with first
    // sortedLL.PrintList();
    // sortedLL.BubbleLast();
    // sortedLL.PrintList();

    // arr.MergeAvg();
}

// Linker proof
// g++ -c Lab13.cpp 
// g++ -o main.exe Lab13.o
// ./main.exe

// g++ --std=c++17 -c Lab13.cpp
// g++ --std=c++17 -o main.exe Lab13.o
// ./main.exe