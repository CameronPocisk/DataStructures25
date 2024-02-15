#include "Roulette.h"

using namespace std;

int main(){
    Player mainCharacter;
    srand(time(NULL));
    mainCharacter.PlayGame();
}

// g++ -c Homework2.cpp Roulette.cpp
// g++ -o main.exe Homework2.o Roulette.o
// ./main.exe