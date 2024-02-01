// Declarations of CardCatalog
#ifndef CARDCATALOG_H
#define CARDCATALOG_H

#include <iostream> // strings and such
#include <fstream> // for member funtion
#include <iomanip> // Print set percision

enum
{
    NumberOfLettersInAlphabet = 26,
};

struct CardCatalog
{
    private:
        std::string title;
        std::string authorFullName;
        std::string firstName;
        std::string lastName;
        int wordCount;
        int lineCount;
        float letterFrequency[NumberOfLettersInAlphabet];


        void PrintFirstAndLastName(); //helper for AppendOutputFile
        void ResetPosition(std::ifstream &readData); //helper for GetInfo
        void SetPositionToContents(std::ifstream &readData); //helper for GetInfo

    public:
        CardCatalog(){ // Contructor that 0s new instances
            wordCount = 0; lineCount = 0;
            for(int i = 0; i < NumberOfLettersInAlphabet; i++)
                letterFrequency[i] = 0;
        };

        void GetInfo(std::ifstream &readData);
        void PrintLetterFreq();
        void AppendOutputFile(); 
};

#endif