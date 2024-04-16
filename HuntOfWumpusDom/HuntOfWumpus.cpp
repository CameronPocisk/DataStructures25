#include <iostream>
#include <vector>
#include "Graph.h"
#include "Game.h"
// #include "Exceptions.h"

using namespace std;


int main() {
    Game main;
    
    bool notDead = true;
    while(notDead){
        try{

            cout << "You are in room " << main.getPlayerRoom() << endl;
            main.displayOutEdges(main.getPlayerRoom() - 1);
            char userChoice = 'a';
            while(toupper(userChoice) != 'M' && toupper(userChoice) != 'S'){
                cout << "Enter 'M' to move, or 'S' to shoot: ";
                cin >> userChoice;
            }
            if(toupper(userChoice) == 'M'){
                main.Move();
            } else{
                main.Shoot();
                main.PrintMap();
            }

            main.printArrows();

        }
        catch(DeadError &e){
            cerr << e.what() << endl;
            notDead = false;
        }
    }

    return 0;
}


// g++ -c HuntOfWumpus.cpp
// g++ -o main.exe HuntOfWumpus.o
// ./main.exe