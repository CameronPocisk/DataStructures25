#include "Roulette.h"
using namespace std;

enum{
    NoBetChange = 1,
    DoubleBet = 2,
    HalveBet = 3,
};

void Player::DisplayResult(bool WinOrLoss, int houseSpin) {
    if(WinOrLoss){
        cout << "The house spun a " << houseSpin << " which loses to your spin of " << playerSpin << endl;
        cout << "You won $" << bet << " and you currently have $" << money << " left." << endl;
    }
    else{
        cout << "The house spun a " << houseSpin << " which beats your spin of " << playerSpin << endl;
        cout << "You lost $" << bet << " and now have $" << money << endl;
    }
}

void Player::HandleNoBetChange(int houseSpin){
    if(playerSpin > houseSpin){
        // calc stuff
        money += bet;
        DisplayResult(true, houseSpin);
    }
    else{
        // calcs
        money -= bet;
        DisplayResult(false, houseSpin);
    }
}
void Player::HandleDoubleBet(int spinValue1, int spinValue2){
    bet = 2 * bet;
    if(spinValue1 >= playerSpin) {
        money -= bet;
        DisplayResult(false, spinValue1);
        return;
    }
    cout << "The house spun " << spinValue2 << "which is less than your spin, " << spinValue1 << endl;
    cout << "Spinning again!" << endl;
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


void Player::PlayGame(){
    
    // Get valid range;
    Wheel houseWheel;

    int numberOfValuesHold = 0;
    while(numberOfValuesHold > 20 || numberOfValuesHold < 6){
        cout << "Enter the number of spin values (6-20): " << endl;
        cin >> numberOfValuesHold;
    }
    playerWheel.SetNumberOfValues(numberOfValuesHold);
    houseWheel.SetNumberOfValues(numberOfValuesHold);
    
    cout << "How much do you want to bet? ";
    cin  >> bet;
    while(bet > money){
        cout << "You do not have that much money, enter valid bet: ";
        cin >> bet;
    }

    // Player spin

    playerSpin = playerWheel.Spin();
     
    // Get player Bet Change
    int playerBetChoice;
    cout << "Your ball landed on " << playerSpin << endl;
    
    cout << "Would you like to change bet 1: None. 2: Double. 3: Halve?: ";
    cin >> playerBetChoice;
    while(playerBetChoice >= 4 || playerBetChoice <= 0) {
        cout << "Would you like to change bet 1: None. 2: Double. 3: Halve?: " << endl;
        cin >> playerBetChoice;
    }
    int houseSpin = 0;
    int houseSpin2 = 0;
    switch (playerBetChoice)
    {
    case NoBetChange:
        houseSpin = houseWheel.Spin();
        HandleNoBetChange(houseSpin);
        break;
        
    case DoubleBet:
        houseSpin = houseWheel.Spin();
        houseSpin2 = houseWheel.Spin();
        HandleDoubleBet(houseSpin, houseSpin2);
        break;
        
    case HalveBet:
        bet = bet / 2;
        houseSpin = houseWheel.Spin();
        HandleHalfBet(houseSpin);
        
        cout << "The house will now spin again." << endl;
        
        houseSpin = houseWheel.Spin();
        HandleHalfBet(houseSpin);


        break;
    }
}
