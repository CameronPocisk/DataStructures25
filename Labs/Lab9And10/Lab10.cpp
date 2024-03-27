#include "Tree.h"
#include "Tree.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class Word{
    string word;
    int frequency;

    public:
    Word(string wordIn){word = wordIn; frequency = 0;}
    void operator ++(){ frequency++;}
    bool operator < (const Word& right){
        string thisWordCopy = word;
        string rightWordCopy = right.word;
        for(int i = 0; i < min(word.length(), right.word.length()); i++){
            if(word[i] < right.word[i]){
                return true;
            }
            else if(word[i] > right.word[i]){
                return false;
            }
        }
        if(right.word.length() != 0){
            return true;
        } // Also less than if right word is longer

        return false;
    }
    bool operator > (const Word& right){
        
        for(int i = 0; i < min(word.length(), right.word.length()); i++){
            if(word[i] > right.word[i]){
                return true;
            }
            else if(right.word[i] > word[i]){
                return false;
            }
        }
        return (word.length() > right.word.length());
    }
    bool operator == (const Word& right){return word == right.word}
};


int main(){
    string fileName;
    cout << "Enter name of file:";
    cin >> fileName;
    
    ifstream readData;
    readData.open(fileName, ios::in);
    while(readData.fail()){
        cout << "Unable to open file enter another file: ";
        cin >> fileName;
        readData.open(fileName, ios::in);   
    }

    Word c


    return 0;
}

// g++ -c Lab10.cpp Tree.cpp
// g++ -o main.exe Lab10.o Tree.o
// ./main.exe

// g++ -c Lab10.cpp
// g++ -o main.exe Lab10.o
// ./main.exe