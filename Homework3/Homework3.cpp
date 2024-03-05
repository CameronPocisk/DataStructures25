// #include "LinkedList.h"
#include "DeckQueue.h"
#include "PileStack.h"
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include<iostream>
using namespace std;

void distributeCards(DeckQueue p, DeckQueue cpu){
    // Create deck
    int deck[52];
    int cur = 0;
    for(int i = 2; i <= 14; i++){
        for(int j = 0; j < 4; j++){
            deck[cur + j] = i;
        }
        cur+=4;
    }

    // Shuffle deck by swapping decksize*2 times
    int numSwaps = 52*2;
    int swapInd1;
    int swapInd2;
    for(int i = 0; i < numSwaps; i++){
        swapInd1 = rand() %52;
        swapInd2 = rand() %52;

        int hold = deck[swapInd1];
        deck[swapInd1] = deck[swapInd2];
        deck[swapInd2] = hold;
    }
    
    // Add to both decks
    for(int i = 0; i < 52; i+=2){
        p.Enqueue(deck[i]);
        cpu.Enqueue(deck[i+1]);
    }
    cout << "Shuffled" << endl;
    
}


int main(){
    cout << "Running file" << endl;
    srand(time(0));

    // initilizations
    DeckQueue pDeck;
    DeckQueue cDeck;
    SidePile pSide;
    SidePile cSide;
    distributeCards(pDeck, cDeck);

    cout << "Welcome to War. The game will end when someone is out of cards." << endl;
    int userChoice;
    int pCurCard;
    int cpuCurCard;
    int pSideCard;
    int cpuSideCard;

    while((pDeck.length() != 0 || pSide.GetNumCards() != 0) && (cDeck.length() != 0 || pSide.GetNumCards() != 0)){
        cout << "In While" << endl;
        if(pDeck.length() != 0){
            pCurCard = pDeck.Dequeue();
        }
        else{
            pCurCard = pSide.RemoveCard();
        }
        if(cDeck.length() != 0){
            cpuCurCard = cDeck.Dequeue();
        }
        else{
            cpuCurCard = cSide.RemoveCard();
        }


        cout << "The first card you pulled is a: " << pCurCard << endl;
        cout << "Press 1 to play this card." << endl << "Press 2 to pull from the side pile." << endl << "Press 3 to push to the side pile." << endl;
        cin >> userChoice;
        //Add exception
        // while(userChoice != 1 && userChoice != 2 && userChoice != 3){
        //     cout << "Please type 1, 2, or 3: ";
        //     cin >> userChoice;
        // }

        // switch(userChoice){
        //     case 1:
        //         if(pCurCard > cpuCurCard){
        //             cout << "Your " << pCurCard << " is higher then the cpu card of " << cpuCurCard << endl;
        //             pDeck.Enqueue(pCurCard);
        //             pDeck.Enqueue(cpuCurCard);
        //         } else {
        //             cout << "The cpu pulled " << cpuCurCard << " which is higher or equal to " << pCurCard << endl;
        //             cDeck.Enqueue(pCurCard);
        //             cDeck.Enqueue(cpuCurCard);
        //         }
                
        //         break;
        //     case 2:
        //         pSideCard = pSide.RemoveCard();
        //         if(pCurCard + pSideCard > cpuCurCard) {
        //             cout << "Your " << pCurCard << " + " << pSideCard << " is higher than the cpu's " << cpuCurCard << endl;
        //             pDeck.Enqueue(pCurCard);
        //             pDeck.Enqueue(cpuCurCard);
        //             pDeck.Enqueue(pSideCard);
        //         } else {
        //             cout << "The cpu pulled " << cpuCurCard << " which is higher or equal to " << pCurCard << " + " << pSideCard;
        //             cDeck.Enqueue(pCurCard);
        //             cDeck.Enqueue(cpuCurCard);
        //             cDeck.Enqueue(pSideCard);
        //         }
        //         break;
        //     case 3:
        //         pSide.AddCard(pCurCard);
        //         pCurCard = pDeck.Dequeue();
        //         if(pCurCard > cpuCurCard){
        //             cout << "Your " << pCurCard << " is higher then the cpu card of " << cpuCurCard << endl;
        //             pDeck.Enqueue(pCurCard);
        //             pDeck.Enqueue(cpuCurCard);
        //         } else {
        //             cout << "The cpu pulled " << cpuCurCard << " which is higher or equal to " << pCurCard << endl;
        //             cDeck.Enqueue(pCurCard);
        //             cDeck.Enqueue(cpuCurCard);
        //         }
        //         break;
        // }

        // cout << "Press 1 to check how many cards are in your deck." << endl << "Press 2 to check how many cards are in the computer's deck." << endl << "Press 3 to check both" << endl << "Press 4 to continue." << endl;
        // cin >> userChoice;
        // while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
        //     cout << "Please type 1, 2, 3, or 4: ";
        //     cin >> userChoice;
        // }
        // switch (userChoice)
        // {
        // case 1:
        //     cout << "There are " << pDeck.length() << " cards in your deck." << endl;
        //     break;
        // case 2:
        //     cout << "There are " << cDeck.length() << " cards in the computer's deck." << endl;
        //     break;
        // case 3:
        //     cout << "There are " << pDeck.length() << " cards in your deck, and " << cDeck.length() << " cards in the computer's deck." << endl;
        
        // default:
        //     break;
        // }
    }
    
    // // Winner message
    // if(pDeck.length() != 0){
    //     cout << "************" << endl;
    //     cout << "Player wins!";
    //     cout << "************" << endl;
    // }
    // else{
    //     cout << "********" << endl;
    //     cout << "Cpu won (you suck :/)";
    //     cout << "********" << endl;
    // }

    return 0;
}

// g++ -c Homework3.cpp LinkedList.cpp DeckQueue.cpp PileStack.cpp
// g++ -o main.exe Homework3.o LinkedList.o DeckQueue.o PileStack.o
// ./main.exe

// g++ -c Homework3.cpp
// g++ -o main.exe Homework3.o
// ./main.exe