// #include "LinkedList.h"
#include "DeckQueue.h"
#include "PileStack.h"
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

#include<iostream>
using namespace std;

void distributeCards(DeckQueue &p, DeckQueue &cpu){
    // Create deck
    int deck[52];
    int cur = 0;
    for(int i = 2; i <= 14; i++){
        for(int j = 0; j < 4; j++){
            deck[cur + j] = i;
        }
        cur+=4;
    }

    //Shuffle deck by swapping decksize*2 times
    int numSwaps = 52*2;
    int swapInd1;
    int swapInd2;
    for(int i = 0; i < numSwaps; i++){
        swapInd1 = rand() % 52;
        swapInd2 = rand() % 52;

        int hold = deck[swapInd1];
        deck[swapInd1] = deck[swapInd2];
        deck[swapInd2] = hold;
    }
    
    // Add to both decks
    for(int i = 0; i < 26; i++){
        p.Enqueue(deck[i]);
        cpu.Enqueue(deck[26 + i]);
    }
}

int GetCpuValue(int curCard, DeckQueue &cpuDeck, SidePile &cpuPile, bool &twoCards){
    if(curCard >= 10){ // Cur card is enough
        cout << "Cpu is happy with card" << endl;
        return curCard;
    }
    else if(curCard < 7 && !cpuPile.IsFull()){ // Add To Side Pile
        cout << "Cpu added a card to the side pile" << endl;
        cpuPile.AddCard(curCard);
        curCard = cpuDeck.Dequeue();
        return curCard;
    }
    else{ // Get from side if possible
        if(!(cpuPile.IsEmpty())){
            cout << "Cpu pulled the top card from the side pile" << endl;
            twoCards = true;
            return curCard + cpuPile.RemoveCard();
        }
        else{
            cout << "Cpu played average card" << endl;
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

    cout << "Welcome to War. The game will end when someone is out of cards." << endl;
    int userChoice;
    int pCurCard;
    int pSideCard;
    int cpuCurCard;
    int cpuSideCard;

    while((pDeck.length() != 0 || pSide.GetNumCards() != 0) && (cDeck.length() != 0 || pSide.GetNumCards() != 0)){
        // If user has 0 cards in deck, must use side card
        try{
            pCurCard = pDeck.Dequeue();
        }
        catch(UnderflowError &e){
            cerr << "No cards left in deck" << endl;
            try{
            pCurCard = pSide.RemoveCard();
            }
            catch(UnderflowError &e){
                cerr << e.what() << endl;
                cout << "No cards left" << endl;
            }
        }
        
        // Find CPU choice and use sum to check if they use 2 cards
        int cpuFirstCard;
        try{
            cpuFirstCard = cDeck.Dequeue();
            
        } catch(UnderflowError &e){
            cerr << e.what() << endl;
            try{
                int cpuFirstCard = cSide.RemoveCard();
            } catch(UnderflowError &e){
                cerr << e.what() << endl;
                cout << "No cards left" << endl;
            }
        }
        bool twoCards = false; //Every loop it's changed to false, if the cpu draws two cards it's set to true
        cpuCurCard = GetCpuValue(cpuFirstCard, cDeck, cSide, twoCards);


        cout << "The first card you pulled is a: " << pCurCard << endl << endl;
        cout << "Press 1 to play this card." << endl << "Press 2 to pull from the side pile." << endl << "Press 3 to push to the side pile." << endl;
        cin >> userChoice;
        while(userChoice != 1 && userChoice != 2 && userChoice != 3){
            cout << "Please type 1, 2, or 3: ";
            cin >> userChoice;
        }

        switch(userChoice){
            case 1:
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
            case 2:
                try{  
                pSideCard = pSide.RemoveCard();
                }
                catch(UnderflowError &e){
                    cerr << e.what() << endl;
                    cout << "Cannot grab from empty pile comparing" << endl;
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
            case 3:
                try{
                    pSide.AddCard(pCurCard);
                    pCurCard = pDeck.Dequeue();
                }
                catch(OverflowError &e){
                    cerr << e.what() << endl;
                    cout << "Cannot add to full pile (5)" << endl;
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
        
        while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
            cout << "Please type 1, 2, 3, or 4: ";
            cin >> userChoice;
        }
        switch (userChoice)
        {
        case 1:
            cout << "There are " << pDeck.length() << " cards in your deck." << endl << endl;
            break;
        case 2:
            cout << "There are " << cDeck.length() << " cards in the computer's deck." << endl << endl;
            break;
        case 3:
            cout << "There are " << pDeck.length() << " cards in your deck, and " << cDeck.length() << " cards in the computer's deck." << endl << endl;
        default:
            break;
        }
    }
    
    // Winner message
    if(pDeck.length() != 0){
        cout << "************" << endl;
        cout << "Player wins!";
        cout << "************" << endl;
    }
    else{
        cout << "********" << endl;
        cout << "Cpu won (you suck :/)";
        cout << "********" << endl;
    }

    return 0;
}

// g++ -c Homework3.cpp LinkedList.cpp DeckQueue.cpp PileStack.cpp
// g++ -o main.exe Homework3.o LinkedList.o DeckQueue.o PileStack.o
// ./main.exe

// g++ -c Homework3.cpp
// g++ -o main.exe Homework3.o
// ./main.exe