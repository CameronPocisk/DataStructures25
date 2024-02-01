// Functionality of CardCatalogStruct
#include "CardCatalog.h"
using namespace std;

void CardCatalog::GetInfo(ifstream &readData)
{
    // Basic book info
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
            || word[i] >= 'A' && word[i] <= 'Z') // If character is a letter
            {
                // increment count to list and index using gathered character
                letterFrequency[tolower(word[i]) - 'a'] += 1;
            }
        }
    }
    
    // Turn count of all numers into frequencey as a percent
    for(int i = 0; i < NumberOfLettersInAlphabet; i++)
        letterFrequency[i] = letterFrequency[i] /numLetters * 100;
    
    // Get the line count
    SetPositionToContents(readData);
    while(getline(readData, word)) {
        lineCount++;
    }
    lineCount--;
}

void CardCatalog::PrintLetterFreq(){
    // Itterates through every letter and their index in the freq list. Prints formatted data
    for(int i = 0; i < NumberOfLettersInAlphabet; i++){
        cout << (char)('a' + i) << ": " << fixed << setprecision(4) << letterFrequency[i] << "%" << endl;
    }
}

void CardCatalog::AppendOutputFile(){

    // Opens CardCatalog.txt, and cretes the file if it does not exist
    ofstream writeData;
    writeData.open("CardCatalog.txt", ios::app);
    if(!writeData){
        writeData.open("CardCatalog.txt", ios::out);
    }

    // Adds all of the info into CardCatalog.txt
    writeData << "Title: " << title << endl;
    writeData << "Author Full Name: " << authorFullName << endl;
    PrintFirstAndLastName();   // Calls PrintFirstAndLastName to get the Author's first and last name from the full name
    writeData << "Author First Name: " << firstName << endl;
    writeData << "Author Last Name: " << lastName << endl;
    writeData << "Word Count: " << wordCount << endl;
    writeData << "Line Count: " << lineCount << endl << endl;
    writeData.close();
}

void CardCatalog::PrintFirstAndLastName(){
    // Using the authorFullName, split it up for a first name and last name
    // Finds where the space in the full name is, then splis it into the first and last name
    int spacePosition = authorFullName.find(" ");
    firstName = authorFullName.substr(0,spacePosition);
    lastName = authorFullName.substr(spacePosition+1);
}

void CardCatalog::ResetPosition(ifstream &readData) {
    // Resets the position to the beginning of the file
    readData.clear();
    readData.seekg(0, ios::beg);
}

void CardCatalog::SetPositionToContents(ifstream &readData) {
    // Sets the position to after the "Contents:" in the file to correctly get the word/letter count
    ResetPosition(readData);

    string fileWord;
    while(readData >> fileWord){
        if(fileWord == "Contents:"){
            break;
        }
    }
}
