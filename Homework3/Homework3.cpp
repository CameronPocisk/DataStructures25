#include "DeckQueue.h"
#include "PileStack.h"
#include<iostream>
using namespace std;

enum{
    DeckSize = 52,
    HandSize = 26,
    PlayCurCard = 1,
    PullFromSide = 2,
    PushToSide = 3,
    CheckCardsInDeck = 1,
    CheckComputerCards = 2,
    CheckBothCards = 3,
    Continue = 4,
};

void distributeCards(DeckQueue &p, DeckQueue &cpu){
    // Create deck
    int deck[DeckSize];
    int cur = 0;
    for(int i = 2; i <= 14; i++){
        for(int j = 0; j < 4; j++){
            deck[cur + j] = i;
        }
        cur+=4;
    }

    //Shuffle deck by swapping decksize*2 times
    int numSwaps = DeckSize*2;
    int swapInd1;
    int swapInd2;
    for(int i = 0; i < numSwaps; i++){
        swapInd1 = rand() % DeckSize;
        swapInd2 = rand() % DeckSize;

        int hold = deck[swapInd1];
        deck[swapInd1] = deck[swapInd2];
        deck[swapInd2] = hold;
    }

    // Add to both decks, 26 is the main
    for(int i = 0; i < HandSize; i++){
        p.Enqueue(deck[i]);
        cpu.Enqueue(deck[HandSize + i]);
    }
}

int GetCpuValue(int curCard, DeckQueue &cpuDeck, SidePile &cpuPile, bool &twoCards)
{
    // cout << "CPU GOT: " << curCard << endl; // (for testing)
    if(curCard >= 10){ // Cur card is enough
        cout << "Cpu is happy with card" << endl;
        return curCard;
    }
    else if(curCard < 7){ // Add To Side Pile
        // Cannot add to side
        if(cpuPile.IsFull() || cpuDeck.IsEmpty()){
            cout << "CPU wanted to add to side but couldnt. Playing cur card" << endl;
            return curCard;
        }
        else{ // Can add to pile and play next card
            cout << "Cpu addded to pile and plays next card" << endl;
            cpuPile.AddCard(curCard);
            curCard = cpuDeck.Dequeue();
            return curCard;
        }
    }
    else{ // Get from side if possible
        if(!(cpuPile.IsEmpty())){
            cout << "Cpu pulled from pile and played both" << endl;
            twoCards = true;
            return curCard + cpuPile.RemoveCard();
        }
        else{
            cout << "Cpu played card after finding nothing in side" << endl;
            return curCard;
        }
    }
}

void GetBothCardsIfTwo(DeckQueue &deckIn, bool shouldGetBoth, int secondCard){
    if(shouldGetBoth){
        deckIn.Enqueue(secondCard);
    }
}


int main(){
    cout << "Running file" << endl;
    srand(time(0));

    // initilizations
    DeckQueue pDeck, cDeck;
    SidePile pSide, cSide;
    distributeCards(pDeck, cDeck);
    int userChoice;
    int pCurCard, pSideCard;
    int cpuCurCard, cpuSideCard;

    cout << "Welcome to War. The game will end when someone is out of cards." << endl;

    while((!pDeck.IsEmpty() || !pSide.IsEmpty()) && (!cDeck.IsEmpty() || !cSide.IsEmpty()))
    {
        try{
            pCurCard = pDeck.Dequeue();
        }
        catch(UnderflowError &e){
            cerr << "No cards left in deck, resorting to side" << endl;
            pCurCard = pSide.RemoveCard();
        }

        cout << "The first card you pulled is a: " << pCurCard << endl << endl;
        cout << "Press 1 to play this card." << endl << "Press 2 to pull from the side pile." << endl << "Press 3 to push to the side pile." << endl;
        cin >> userChoice;

        while(userChoice != PlayCurCard && userChoice != PullFromSide && userChoice != PushToSide){
            cout << "Please type 1, 2, or 3: ";
            cin >> userChoice;
        }
        // Find CPU choice and use sum to check if they use 2 cards
        int cpuFirstCard;
        try{
            cpuFirstCard = cDeck.Dequeue();
        } 
        catch(UnderflowError &e){
            cerr << e.what() << endl;
            cout << "CPU is out of main deck, resorting to side" << endl;
            cpuFirstCard = cSide.RemoveCard();
        }

        bool twoCards = false; //Every loop it's changed to false, if the cpu draws two cards it's set to true
        if(!cDeck.IsEmpty()){
            cpuCurCard = GetCpuValue(cpuFirstCard, cDeck, cSide, twoCards);
        } else {
            cpuCurCard = cpuFirstCard;
        }

        switch(userChoice){
            case PlayCurCard:
                if(pCurCard > cpuCurCard){
                    cout << "Your " << pCurCard << " is higher then the cpu card of " << cpuCurCard << endl << endl;
                    pDeck.Enqueue(pCurCard);
                    pDeck.Enqueue(cpuFirstCard);
                    // Player gets both of the CPUs cards if they double up (Helper?)
                    GetBothCardsIfTwo(pDeck, twoCards, cpuCurCard-cpuFirstCard);
                } else {
                    cout << "The cpu pulled " << cpuCurCard << " which is higher or equal to " << pCurCard << endl << endl;
                    cDeck.Enqueue(pCurCard);
                    cDeck.Enqueue(cpuFirstCard);
                    
                    GetBothCardsIfTwo(cDeck, twoCards, cpuCurCard-cpuFirstCard);
                }
                
                break;
            case PullFromSide:
                try{  
                pSideCard = pSide.RemoveCard();
                }
                catch(UnderflowError &e){
                    cerr << e.what() << endl;
                    cout << "Cannot grab from empty pile, using origional card" << endl;
                    pSideCard = 0;
                }
                
                if(pCurCard + pSideCard > cpuCurCard) {
                    cout << "Your " << pCurCard << " + " << pSideCard << " is higher than the cpu's " << cpuCurCard << endl;
                    pDeck.Enqueue(pCurCard);
                    pDeck.Enqueue(cpuFirstCard);
                    if(pSideCard != 0){
                        pDeck.Enqueue(pSideCard);
                    }
                    GetBothCardsIfTwo(pDeck, twoCards, cpuCurCard-cpuFirstCard);
                } else {
                    cout << "The cpu pulled " << cpuCurCard << " which is higher or equal to " << pCurCard << " + " << pSideCard << endl;
                    cDeck.Enqueue(pCurCard);
                    cDeck.Enqueue(cpuFirstCard);
                    if(pSideCard != 0){
                        cDeck.Enqueue(pSideCard);
                    }
                    GetBothCardsIfTwo(cDeck, twoCards, cpuCurCard-cpuFirstCard);
                }
                break;
            case PushToSide:
                try{
                    pSide.AddCard(pCurCard);
                    pCurCard = pDeck.Dequeue();
                }
                catch(OverflowError &e){
                    cerr << e.what() << endl;
                    cout << "Cannot add to full pile (5)" << endl;
                }
                catch(UnderflowError &e){
                    cerr << e.what() << endl;
                    pSide.RemoveCard();
                    cout << "Main deck empty" << endl;
                }
                if(pCurCard > cpuCurCard){
                    cout << "Your " << pCurCard << " is higher then the cpu card of " << cpuCurCard << endl;
                    pDeck.Enqueue(pCurCard);
                    pDeck.Enqueue(cpuFirstCard);
                    GetBothCardsIfTwo(pDeck, twoCards, cpuCurCard-cpuFirstCard);
                    
                } else {
                    cout << "The cpu pulled " << cpuCurCard << " which is higher or equal to " << pCurCard << endl;
                    cDeck.Enqueue(pCurCard);
                    cDeck.Enqueue(cpuFirstCard);
                    GetBothCardsIfTwo(cDeck, twoCards, cpuCurCard-cpuFirstCard);
                }
                break;
        }

        cout << "Press 1 to check how many cards are in your deck." << endl << "Press 2 to check how many cards are in the computer's deck." << endl << "Press 3 to check both" << endl << "Press 4 to continue." << endl;
        cin >> userChoice;
        
        while(userChoice != CheckCardsInDeck && userChoice != CheckComputerCards && userChoice != CheckBothCards && userChoice != Continue){
            cout << "Please type 1, 2, 3, or 4: ";
            cin >> userChoice;
        }

        switch (userChoice) {
            case CheckCardsInDeck:
                cout << "There are " << pDeck.length() << " cards in your deck." << endl;
                cout << "There are " << pSide.GetNumCards() << " cards in your side pile" << endl << endl;
                break;
            case CheckComputerCards:
                cout << "There are " << cDeck.length() << " cards in the computer's deck." << endl;
                cout << "There are " << cSide.GetNumCards() << " cards in the computer's side pile" << endl << endl;
                break;
            case CheckBothCards:
                cout << "There are " << pDeck.length() << " cards in your deck, and " << pSide.GetNumCards() << " cards in your side pile." << endl;
                cout << "There are " << cDeck.length() << " cards in the computer's deck, and " << cSide.GetNumCards() << " cards in the computer's side pile." << endl << endl;
                cout << "There are a total of " << pDeck.length() + cDeck.length() + cSide.GetNumCards() + pSide.GetNumCards() << " cards" << endl;
    
            default:
                break;
        }
    }
    
    // Winner message
    if(!pDeck.IsEmpty()){
        cout << "************" << endl;
        cout << "Player wins!" << endl;
        cout << "************" << endl;
    }
    else{
        cout << "*********************" << endl;
        cout << "Cpu won (you suck :/)" << endl;
        cout << "*********************" << endl;
    }

    return 0;
}

// g++ -c Homework3.cpp LinkedList.cpp DeckQueue.cpp PileStack.cpp
// g++ -o main.exe Homework3.o LinkedList.o DeckQueue.o PileStack.o
// ./main.exe

// g++ -c Homework3.cpp
// g++ -o main.exe Homework3.o
// ./main.exe