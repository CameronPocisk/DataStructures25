// Functionality of CardCatalogStruct
#include "CardCatalog.h"
#include <vector>
using namespace std;

void CardCatalog::GetInfo(ifstream &readData)
{
    getline(readData, title);
    getline(readData, authorFullName);

    string word;
    int numLetters;
    SetPositionToContents(readData);

    while(readData >> word){
        wordCount++;
        for(int i = 0; i < word.length(); i++) {
            numLetters++;
            if(word[i] >= 'a' && word[i] <= 'z'
            || word[i] >= 'A' && word[i] <= 'Z') // Range of all caps and lower nums
            {
                letterFrequency[tolower(word[i]) - 'a'] += 1;
            }
        }
    }

    for(int i = 0; i < NumberOfLettersInAlphabet; i++)
        letterFrequency[i] = letterFrequency[i] /numLetters * 100;
    
    SetPositionToContents(readData);
    while(getline(readData, word)) {
        lineCount++;
    }
    lineCount--;
}

void CardCatalog::PrintLetterCount(){
    for(int i = 0; i < NumberOfLettersInAlphabet; i++){
        cout << (char)(i + 'a') << ": " << fixed << setprecision(4) << letterFrequency[i] << "%" << endl;
    }
}


void CardCatalog::AppendOutputFile() {

    ofstream writeData;
    writeData.open("CardCatalog.txt", ios::out);

    writeData << "Title: " << title << endl;
    writeData << "Author Full Name: " << authorFullName << endl;
    PrintFirstAndLastName();
    writeData << "Author First Name: " << firstName << endl;
    writeData << "Author Last Name: " << lastName << endl;
    writeData << "Word Count: " << wordCount << endl;
    writeData << "Line Count: " << lineCount << endl;
    writeData.close();
}

void CardCatalog::PrintFirstAndLastName() {
    //Using the authorFullName, split it up for a first name and last name
    int count = 0;
    for(std::string::size_type i = 0; i < authorFullName.size(); i++){
        if(authorFullName[i] != ' '){
            firstName += authorFullName[i];
            count ++;
        }
        else{
            count++;
            break;
        }
    }
    int startLastName = count; //Starts on the character after the space
    for(std::string::size_type i = startLastName; i < authorFullName.size(); i++){
        lastName += authorFullName[i];
    } 

}

void CardCatalog::ResetPosition(ifstream &readData) {
    readData.clear();
    readData.seekg(0, ios::beg);
}

void CardCatalog::SetPositionToContents(ifstream &readData) {
    ResetPosition(readData);

    string fileLine;
    while(readData >> fileLine){
        if(fileLine == "Contents:") {
            break;
        }
    }
}
