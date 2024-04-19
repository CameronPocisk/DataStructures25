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
            if(endPlace == curPlace){
                for(int i = 0; i < arrowAmount; i++){
                    if(arrowPlace[i] == endPlace){
                        cout << "You picked up an arrow!" << endl;
                    }
                }
            }
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

        void populateMapRandom(){

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
        }

        void populateMap(){
            //Three connections to
            //2-4 connections from
            addEdges(1, 2, 5, 12, 0);
            addEdges(2, 1, 3, 8, 0);
            addEdges(3, 2, 7, 15, 0);
            addEdges(4, 9, 11, 0, 0);
            addEdges(5, 1, 6, 16, 0);
            addEdges(6, 5, 9, 18, 0);
            addEdges(7, 3, 14, 0, 0);
            addEdges(8, 2, 10, 13, 0);
            addEdges(9, 4, 6, 17, 0);
            addEdges(10, 8, 15, 0, 0);
            addEdges(11, 4, 12, 19, 0);
            addEdges(12, 1, 11, 20, 0);
            addEdges(13, 8, 14, 20, 0);
            addEdges(14, 7, 13, 18, 0);
            addEdges(15, 3, 10, 0, 0);
            addEdges(16, 5, 17, 0, 0);
            addEdges(17, 9, 16, 0, 0);
            addEdges(18, 6, 14, 0, 0);
            addEdges(19, 11, 20, 0, 0);
            addEdges(20, 12, 13, 19, 0);
        }

        void shuffleVector(int amount, vector<int>& arr){
                for(int i = 0; i < amount; i++){
                    int rand1 = rand() % amount;
                    int rand2 = rand() % amount;
                    while(rand1 == rand2){
                        rand2 = rand() % amount;
                    }
                    int num1 = arr.at(rand1);
                    arr.at(rand1) = arr.at(rand2);
                    arr.at(rand2) = num1;
                }
        }

        void populateMapRandomPrototype(){
            int amount = rand() % 20 + 60; //between 60 (3 connections) and 79 (4 connections)
            vector<int> arrConnections;
            int spacesFilled = 0;
            int curNum = 1;
            bool topReached = false;
            while(spacesFilled < amount){
                int above = rand() % 2 + 2;
                if(curNum > 20){
                    topReached = true;
                    curNum -= 20;
                    above = 1;
                } else if(topReached == true){
                    above = 1;
                }
                for(int i = 0; i < above; i++){
                    arrConnections.push_back(curNum);
                    spacesFilled++;

                    if(spacesFilled >= amount){
                        //Edge case
                        break;
                    }
                }
                curNum++;
            }

            shuffleVector(amount, arrConnections);

            while(arrConnections.size() > 0){
                for(int i = 0; i < 20; i++){
                    int amount = rand() % 2 + 2;
                    for(int j = 0; j < amount; j++){
                        while(map.OutEdges(i).size() > 3){
                            i++;
                        }
                        int num = arrConnections.back();

                        if(arrConnections.size() <= 0){
                            break;
                        }
                        
                        
                        int n = 2;
                        while(map.hasEdge(i, num) || num == i){
                            int hold = arrConnections.back();
                            if((arrConnections.size() - n) == 0){
                                arrConnections.at(arrConnections.size() - 1) = arrConnections.at(arrConnections.size() - n);
                                arrConnections.at(arrConnections.size() - n) = hold;
                            }
                            num = arrConnections.back();
                            n++;
                            if(n >= arrConnections.size()){
                                break;
                            }
                        }

                        map.AddEdge(i, num);

                        
                        arrConnections.pop_back();
                    }
                }
            }
        }
        
        void addEdges(int row, int con1, int con2, int con3, int con4){
            if(con1 != 0){
                map.AddEdge(row, con1);
            }
            if(con2 != 0){
                map.AddEdge(row, con2);
            }
            if(con3 != 0){
                map.AddEdge(row, con3);
            }
            if(con4 != 0){
                map.AddEdge(row, con4);
            }
        }

        void moveWumpus(){
            cout << "Wumpus has moved..." << endl;
            wumpusRoom = rand() % 20;
            while(wumpusRoom == playerRoom || wumpusRoom == batRoom || wumpusRoom == holeRoom){
                wumpusRoom = rand() % 20;
            }
        }

    public:
        void printArrows(){
            for(int i = 0; i < arrowAmount; i++){
                cout << arrowPlace[i] << ", ";
            }
            cout << endl;
        }
        Game(){
            srand(time(NULL));

            // populateMapRandom();
            populateMapRandomPrototype();
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
                moveWumpus();
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

            updateArrows(toRoom - 1, toRoom - 1);

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
            Graph roomsPassed;
            for(int i = 0; i < toShoot - 1; i++){
                //Shoots through x rooms
                roomsPassed.AddEdge(playerRoom, curRoom);
                vector<int> edges = map.OutEdges(curRoom);
                curRoom = edges.at(rand() % edges.size());

                while(roomsPassed.hasEdge(playerRoom, curRoom)){
                    curRoom = edges.at(rand() % edges.size());
                }
                cout << "Shot through room: " << curRoom << endl;

                if(curRoom == wumpusRoom){
                    throw WinError();
                }
            }
            cout << endl;
            cout << "Arrow landed in " << curRoom << endl;
            if(curRoom == batRoom || curRoom == holeRoom){
                cout << "You're arrow got lost :(" << endl;
                loseArrow();
            }
            for(int i = 0; i < arrowAmount; i++){
                if(arrowPlace[i] != -1 && arrowPlace[i] == playerRoom){
                    arrowPlace[i] = curRoom;
                    break;
                }
            }

            moveWumpus();
        }

        void displayOutEdges(int n){
            vector<int> edges = map.OutEdges(n);
            bool holeNear = false;
            bool wumpusNear = false;
            bool batNear = false;
            //Use booleans so user can't tell which room has what
            
            cout << endl << "Can move to room: ";
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