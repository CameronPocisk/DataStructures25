#include <iostream>
#include <vector>
#include "Graph.h"
#include "Game.h"
// #include "Exceptions.h"

using namespace std;


int main() {
    Game main;
    
    bool gameContinue = true;
    while(gameContinue){
        try{
            char userChoice = 'a';
            while(toupper(userChoice) != 'M' && toupper(userChoice) != 'S' && toupper(userChoice) != 'O'){
                cout << "Commands: Move ( M ), Shoot ( S ), or Observe ( O )." << endl;
                cout << "You are in room " << main.getPlayerRoom() << endl;
                cout << "What would you like to do: ";
                cin >> userChoice;
            }
            if(toupper(userChoice) == 'M'){
                main.Move();
            } else if(toupper(userChoice) == 'S'){
                main.Shoot();
                main.PrintMap();
            } else {
                main.displayOutEdges(main.getPlayerRoom() - 1);
            }

        }
        catch(DeadError &e){
            cerr << e.what() << endl;
            gameContinue = false;
        }
        catch(WinError &e){
            cerr << e.what() << endl;
            gameContinue = false;
        }
    }

    return 0;
}


// g++ -c HuntOfWumpus.cpp
// g++ -o main.exe HuntOfWumpus.o
// ./main.exe