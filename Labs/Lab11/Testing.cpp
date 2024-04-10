#include "HashTable.h"
#include "HashTable.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "ChainedHash.h"
#include "ChainedHash.cpp"
#include "Item.h"
#include "Item.cpp"

#include <iostream>
using namespace std;

enum{
    UserTest = 1,
    AutomatedTest = 2,
    Quit = 3,
    LinearProbing = 1,
    Chaning = 2,
    MainMenu = 3,
    AddItem = 1,
    RemoveItem = 2,
    SearchItem = 3,
    Displaylength = 4,
    Exit = 5,
};


int main(){
    
    int userChoice = 1;
    while(userChoice != Quit){
        cout << "1: User Test, 2: AutomatedTest, 3: Quit" << endl;
        cin >> userChoice;
        switch (userChoice)
        {
        case UserTest:
            cout << "User tesing" << endl;

            
            while(userChoice != Quit){
                cout << "1: Lienar Probing, 2: Chaining, 3: Quit" << endl;
                cin >> userChoice;
                switch (userChoice)
                {
                case LinearProbing:
                    cout << "Using Linear Probing Hash table" << endl;

                    userChoice = Quit;
                    break;
                case Chaning:
                    cout << "Using Chaining Hash table" << endl;

                    userChoice = Quit;
                    break;
                default:
                    break; // Exits or retrys
                }
            } // Will exit switch with same quit value

            break;

        case AutomatedTest:
            // No Options here. 
            // Do Code Below

            userChoice = Quit; // End after Auto testing 
            break;
        default:
            break; // Returns user to menu
        }
    }

    return 0;
}

// g++ -c Testing.cpp
// g++ -o main.exe Testing.o
// ./main.exe