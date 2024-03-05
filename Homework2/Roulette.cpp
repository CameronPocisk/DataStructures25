#include "Roulette.h"
using namespace std;

enum{
    NoBetChange = 1,
    DoubleBet = 2,
    HalveBet = 3,
};

void Player::DisplayResult(bool WinOrLoss, int houseSpin) {
    if(WinOrLoss){
        cout << endl;
        cout << "The house spun a " << houseSpin << " which loses to your spin of " << playerSpin << endl;
        cout << "You won $" << bet << " and you currently have $" << money << "!" << endl << endl;
    }
    else{
        cout << endl;
        cout << "The house spun a " << houseSpin << " which beats your spin of " << playerSpin << endl << endl;
        cout << "You lost $" << bet << " and now have $" << money << " left." << endl << endl;
    }
}

void Player::HandleNoBetChange(int houseSpin){
    // Based on result change bet and print with helper
    if(playerSpin > houseSpin){
        money += bet;
        DisplayResult(true, houseSpin);
    }
    else{
        money -= bet;
        DisplayResult(false, houseSpin);
    }
}
void Player::HandleDoubleBet(int spinValue1, int spinValue2){
    bet *= 2;
    if(spinValue1 >= playerSpin) {
        money -= bet;
        DisplayResult(false, spinValue1);
        return;
    }
    cout << endl << "The house spun " << spinValue1 << " which is less than your spin of " << playerSpin << endl;
    cout << "Spinning again!" << endl << endl;
    if(spinValue2 >= playerSpin) {
        money -= bet;
        DisplayResult(false, spinValue2);
        return;
    }
    money += bet;
    DisplayResult(true, spinValue2);
}
void Player::HandleHalfBet(int spinValue){
    if(spinValue >= playerSpin){
            money -= bet;
            DisplayResult(false, spinValue);
        }
        else{
            money += bet;
            DisplayResult(true, spinValue);
        }
}

void Player::GetStartingPlayerInformation(Wheel &opposingWheel){
    // Get start money value
    cout << "How much money would you like to start with? ";
    cin >> money;
    while(money <= 0){
        cout << "Please enter a positive number: ";
        cin >> money;
    }

    // Get and set valid range;
    int numberOfValuesHold = 0;
    while(numberOfValuesHold > 20 || numberOfValuesHold < 6){
        cout << "Enter the number of spin values (6-20): ";
        cin >> numberOfValuesHold;
    }
    playerWheel.SetNumberOfValues(numberOfValuesHold);
    opposingWheel.SetNumberOfValues(numberOfValuesHold);
}

int Player::GetPlayerBetChoice(){
    int playerBetChoice;
    cout << "Would you like to change bet 1: None. 2: Double. 3: Halve?: ";
    cin >> playerBetChoice;
  
    while(playerBetChoice > 3 || playerBetChoice < 1) {
        cout << "Would you like to change bet 1: None. 2: Double. 3: Halve?: ";
        cin >> playerBetChoice;
    }
    //Don't allow player to bet with insufficient funds
    if(playerBetChoice == 2 && money < 2 * bet) {
        while(playerBetChoice < 1 || playerBetChoice > 3 || playerBetChoice == 2) {
            cout << "You don't have enough money to double" << endl;
            cout << "Enter bet change 1: None. 3: Halve?: ";
            cin >> playerBetChoice;
        }
    }
    return playerBetChoice;
}

void Player::PlayGame(){

    Wheel *houseWheel; // Base version here

    string hardModeChoice = "IDK";
    while(hardModeChoice != "yes" && hardModeChoice != "no"){
        cout << "Would you like to play hardmode? ";
        cin >> hardModeChoice;
    }
    if(hardModeChoice == "yes"){
        houseWheel = new HardmodeWheel; // Will change to derived becuase polymorphism
    }
    else{
        houseWheel = new Wheel;
    }

    GetStartingPlayerInformation(*houseWheel);
    if(hardModeChoice == "Yes"){ // If hardmode also get the range from the user
        houseWheel->SetPlayerNumberOfValues(playerWheel.GetNumberOfValues());
    }

    string playAgain = "yes";
    while(playAgain == "yes"){

        cout << "How much do you want to bet? ";
        cin  >> bet;
        while(bet > money || bet < 1){
            cout << "Invalid bet amount: ";
            cin >> bet;
        }

        // Player and house spin
        playerSpin = playerWheel.Spin(0);
        int houseSpin = houseWheel->Spin(playerSpin);
        int houseSpin2 = houseWheel->Spin(playerSpin);
        cout << "Your ball landed on " << playerSpin << endl;
        
        // Get player Bet Change and act upon it
        int playerBetChoice = GetPlayerBetChoice();
        switch (playerBetChoice)
        {
        case NoBetChange:
            HandleNoBetChange(houseSpin);
            break;
            
        case DoubleBet:
            HandleDoubleBet(houseSpin, houseSpin2);
            break;
            
        case HalveBet:
            bet /= 2;
            HandleHalfBet(houseSpin);

            cout << "The house will now spin again." << endl;
            HandleHalfBet(houseSpin);
            break;
        }

        //Game over handling
        if(money <= 0){
            cout << "You are out of money, Ending game" << endl;
            return;
        }
        
        cout << "You have $" << money << endl;
        cout << "Would you like to play again? (Enter yes or no): ";
        cin >> playAgain;
        while(playAgain != "yes" && playAgain != "no"){
            cout << "Please enter yes or no: ";
            cin >> playAgain;
        }
    }
}
