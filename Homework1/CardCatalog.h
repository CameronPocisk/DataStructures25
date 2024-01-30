// Declarations of CardCatalog
#ifndef CARDCATALOG
#define CARDCATALOG

#include <iostream> // strings and such
#include <fstream> // for member funtion

enum
{
    NumberOfLettersInAlphabet = 26,
};

struct CardCatalog{
    std::string title;
    std::string authorFullName;
    std::string firstName;
    std::string lastName;
    int wordCount;
    int lineCount;
    float letterFrequency[NumberOfLettersInAlphabet];

    CardCatalog(){
        wordCount = 0; lineCount = 0;
        for(int i = 0; i < NumberOfLettersInAlphabet; i++)
            letterFrequency[i] = 0;
    };

    //public
    void GetInfo(std::ifstream &readData);
    void PrintLetterCount();
    void AppendOutputFile(); 

    //Private / helpers
    void PrintFirstAndLastName(); //helper for AppendOutputFile
    void ResetPosition(std::ifstream &readData); //helper for GetInfo
    void SetPositionToContents(std::ifstream &readData, int textPosition); //helper for GetInfo
    void FindLetterFrequency(std::ifstream &readData);
};

#endif