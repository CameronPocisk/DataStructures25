#include "Roulette.h"

using namespace std;

int main(){
    
    Player mainCharacter;
    int money;
    string playAgain = "yes";
    srand(time(NULL));

    cout << "How much money would you like to start with? ";
    cin >> money;
    while(money <= 0){
        cout << "Please enter a positive number: ";
        cin >> money;
    }
    mainCharacter.SetMoney(money);


    while(playAgain == "yes" && money > 0){
        
        mainCharacter.PlayGame();
        cout << "You have $" << mainCharacter.GetMoney() << endl;
        cout << "Would you like to play again? (Enter yes or no): ";
        cin >> playAgain;
        while(playAgain != "yes" && playAgain != "no"){
            cout << "Please enter yes or no: ";
            cin >> playAgain;
        }
    }

    if(money <= 0){cout << "You are out of money" << endl;}
}

// g++ -c Homework2.cpp Roulette.cpp
// g++ -o main.exe Homework2.o Roulette.o
// ./main.exe