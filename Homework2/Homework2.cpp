#include "Roulette.h"

using namespace std;

int main(){
    
    Player mainCharacter;
    int money;
    string playAgain;

    while(playAgain == "yes"){
        // cout << "How much money would you like to start with? ";
        // cin >> money;
        // while(money <= 0){
        //     cout << "Please enter a positive number: ";
        //     cin >> money;
        // }
        money = 1000;
        mainCharacter.SetMoney(money);
        mainCharacter.PlayGame();

        cout << "You have $" << mainCharacter.GetMoney() << endl;
        cout << "Would you like to play again? (Enter yes or no): ";
        cin >> playAgain;
        while(playAgain != "yes" && playAgain != "no"){
            cout << "Please enter yes or no: ";
            cin >> playAgain;
        }
    }
    
}