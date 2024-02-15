#ifndef ROULETTE_H
#define ROULETTE_H

#include <iostream>
#include <random>

enum{
    DefaultNumberOfValues = 10,
};

class Wheel {
    public:
        int numberOfValues;
    public:
        virtual int Spin(){return rand() % numberOfValues + 1;}
        Wheel(){numberOfValues = DefaultNumberOfValues;}

        void SetNumberOfValues(int num){numberOfValues = num;}
        int GetNumberOfValues(){return numberOfValues;}
};

class Player{
    public:
        int money;
        int bet;
        int playerSpin;
        Wheel playerWheel;

        void HandleNoBetChange(int houseSpin);
        void HandleDoubleBet(int spinValue1, int spinValue2);
        void HandleHalfBet(int spinValue);

    public:
        void SetMoney(int moneyIn){money = moneyIn;}
        int GetMoney(){return money;}
        void PlayGame();

        void DisplayResult(bool WinOrLoss, int houseSpin);
};


#endif