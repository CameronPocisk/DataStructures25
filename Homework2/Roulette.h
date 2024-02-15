#ifndef ROULETTE_H
#define ROULETTE_H

#include <iostream>
#include <random>

enum{
    DefaultNumberOfValues = 10,
};

class Wheel {
    protected:
        int numberOfValues;
        int opposingNumberOfValues;

    public:
        virtual int Spin(int playerResult){return rand() % numberOfValues + 1;}
        Wheel(){numberOfValues = DefaultNumberOfValues;}

        void SetPlayerNumberOfValues(int rangeIn){opposingNumberOfValues = rangeIn;}
        void SetNumberOfValues(int num){numberOfValues = num;}
        int GetNumberOfValues(){return numberOfValues;}
};

class Player {
    private:
        int money;
        int bet;
        int playerSpin;
        Wheel playerWheel;

        void GetStartingPlayerInformation(Wheel &opposingWheel);
        int GetPlayerBetChoice();

        void HandleNoBetChange(int houseSpin);
        void HandleDoubleBet(int spinValue1, int spinValue2);
        void HandleHalfBet(int spinValue);
        void DisplayResult(bool WinOrLoss, int houseSpin);

    public:
        void SetMoney(int moneyIn){money = moneyIn;}
        int GetMoney(){return money;}
        void PlayGame();

};

class HardmodeWheel : public Wheel{ // Change to private later
    private:
    int wins;
    
    public:

    HardmodeWheel(){wins = 0;}

    int Spin(int playerResult){
        // Handle logic for incresing hard mode opposing bounds
        int houseSpin = rand() % numberOfValues + 1;
        if(houseSpin < playerResult) {
            numberOfValues++;
            wins = 0;
        } else {
            wins++;
            if(wins % 2 == 0 && numberOfValues > opposingNumberOfValues) {
                numberOfValues--;
            }
        }
        return houseSpin;
    }
};

#endif