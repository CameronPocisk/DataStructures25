#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Graph.h"
#include "Exceptions.h"

enum{
    arrowAmount = 3,
};


class Game{
    private:
        int playerRoom;
        int wumpusRoom;
        int batRoom;
        int holeRoom;

        Graph map;

        int arrowPlace[arrowAmount];

        void updateArrows(int curPlace, int endPlace){
            if(playerRoom == curPlace){
                for(int i = 0; i < arrowAmount; i++) {
                    if(arrowPlace[i] == curPlace){
                        arrowPlace[i] = endPlace;
                    }
                }
            } else {
                for(int i = 0; i < arrowAmount; i++){
                    if(arrowPlace[i] == curPlace){
                        arrowPlace[i] = endPlace;
                        return;
                    }
                }
            }
        }
        
        void loseArrow(){
            for(int i = 0; i < arrowAmount; i++) {
                if(arrowPlace[i] == playerRoom){
                    arrowPlace[i] = -1;
                    return;
                }
            }

            throw DeadError();
        }

    public:
        void printArrows(){
            for(int i = 0; i < arrowAmount; i++){
                cout << arrowPlace[i] << ", ";
            }
            cout << endl;
        }
        Game(){
            srand(time(0));

            for(int i = 0; i < 20; i++){
                int count = rand() % 3 + 2;
                    for(int j = 0; j < count; j++){
                    int randNum = rand() % 20;
                    while(map.hasEdge(i, randNum) || randNum == i){
                        randNum = rand() % 20;
                    }
                map.AddEdge(i, randNum);
                }
            }   
            playerRoom = rand() % 20; //Between 0 and 19
            wumpusRoom = rand() % 20;
            batRoom = rand() % 20;
            holeRoom = rand() % 20;

            while(wumpusRoom == playerRoom){
                wumpusRoom = rand() % 20;
            }
            while(batRoom == playerRoom || batRoom == wumpusRoom){
                batRoom = rand() % 20;
            }
            while(holeRoom == playerRoom || holeRoom == wumpusRoom || holeRoom == batRoom){
                holeRoom = rand() % 20;
            }

            for(int i = 0; i < arrowAmount; i++){
                arrowPlace[i] = playerRoom;
                //Arrows stay in the same spot as player unless fired
            }
        }

        int getPlayerRoom(){return playerRoom + 1;}

        void PrintMap(){map.PrintGraph();}

        void MoveHelper(int toRoom){
            updateArrows(playerRoom, toRoom - 1);
            playerRoom = toRoom - 1;

            if(playerRoom == wumpusRoom){
                cout << "You lose uno arrow" << endl;
                loseArrow();
            }else if(playerRoom == batRoom){
                cout << "AHHHHH BATS" << endl;
                toRoom = rand() % 20;
                while(!map.hasEdge(playerRoom, toRoom)){
                    toRoom = rand() % 20 + 1;
                }
                MoveHelper(toRoom);
            } else if(playerRoom == holeRoom){
                cout << "You fell lol" << endl;
                throw DeadError();
            }
        }

        void Move(){
            //Add cases for collision
            int toRoom;
            cout << "Enter the room to move to: ";
            cin >> toRoom;
            while(!map.hasEdge(playerRoom, toRoom - 1)){
                cout << "Enter the room to move to: ";
                cin >> toRoom;
            }
            cout << endl;

            MoveHelper(toRoom);
        }

        void Shoot(){
            int toShoot = 0;
            while(toShoot < 2 || toShoot > 4){
                cout << "Enter the amount of rooms to shoot through: ";
                cin >> toShoot;
            }

            int curRoom = 0;
            while(!map.hasEdge(playerRoom, curRoom - 1)){
                cout << "Enter the room to shoot at: ";
                cin >> curRoom;
            }
            cout << "Shot at room: " << curRoom << endl;
            for(int i = 0; i < toShoot - 1; i++){
                //Shoots through x rooms
                vector<int> edges = map.OutEdges(curRoom);

                curRoom = edges.at(rand() % edges.size());
                cout << "Shot through room: " << curRoom << endl;
            }
            cout << "Arrow landed in " << curRoom << endl;
            for(int i = 0; i < arrowAmount; i++){
                
            }
        }

        void displayOutEdges(int n){
            vector<int> edges = map.OutEdges(n);
            bool holeNear = false;
            bool wumpusNear = false;
            bool batNear = false;
            //Use booleans so user can't tell which room has what
            
            cout<< "Can move to: ";
            for(int i = 0; i < edges.size(); i++){
                int curRoom = edges.at(i);
                cout << curRoom + 1 << ", ";
                if(curRoom == wumpusRoom){
                    wumpusNear = true;
                } else if(curRoom == batRoom){
                    batNear = true;
                } else if(curRoom == holeRoom){
                    holeNear = true;
                }
            }
            cout << endl;
            if(wumpusNear){
                cout << "You smell an animal sound" << endl;
            }
            if(batNear){
                cout << "You hear screeching" << endl;
            }
            if(holeNear){
                cout << "You feel a slight breeze" << endl;
            }
            cout << endl;
        }



};






#endif