// Functionality of CardCatalogStruct
#include "CardCatalog.h"
using namespace std;

void CardCatalog::GetInfo(ifstream &readData)
{
    string val;
    int textPosition;

    getline(readData, title);
    getline(readData, authorFullName);

    while(readData >> val){
        if (val == "Contents:") {
            textPosition = readData.tellg(); //Only loops a few times since it's at the beginning
            break;
        }
    }

    SetPositionToContents(readData, textPosition);

    while(readData >> val){
        for(int i = 0; i < val.length(); i++) {
            if(val[i] >= 'a' && val[i] <= 'z'
            || val[i] >= 'A' && val[i] <= 'Z')
            {
                letterFrequency[tolower(val[i]) - 'a'] += 1; // add if forb if it is a
            } // Range of all caps and lower nums
        }
        wordCount++;
    }
    
    SetPositionToContents(readData, textPosition);

    while(getline(readData, val)) {
        lineCount++;
    }
}

void CardCatalog::PrintLetterCount(){
    // for(int i = 0; i < NumberOfLettersInAlphabet; i++){
    //     cout << (char)(i + 'a') << ": " << letterFrequency[i] << "%" << endl;
    //     // setprecision(4)
    // }
    cout << "bruh";
}

void CardCatalog::AppendOutputFile() {

    ofstream writeData;
    writeData.open("CardCatalog.txt", ios::app);
    if(!writeData){
        writeData.open("CardCatalog.txt", ios::out);
    }

    writeData << "Title: " << title << endl;
    writeData << "Author Full Name: " << authorFullName << endl;
    PrintFirstAndLastName();
    writeData << "Author First Name: " << firstName << endl;
    writeData << "Author Last Name: " << lastName << endl;
    writeData << "Word Count: " << wordCount << endl;
    writeData << "Line Count: " << lineCount << endl << endl;
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
    readData.seekg(0, ios::beg);
}

void CardCatalog::SetPositionToContents(ifstream &readData, int textPosition) {
    readData.clear();
    readData.seekg(textPosition + 2, ios::beg);
}

void CardCatalog::FindLetterFrequency(ifstream &readData){
    // Go through the file and get the frequence and put it into the array
    
    // fstream textData;
    // textData.open(givenFileName, ios::in); // Should be safe to open given dev use

    // Get to contents
    
    // string trashString;
    // getline(textData, trashString);
    // getline(textData, trashString);
    // int totalLetterCount;
    //Get the freq starting at contents
    cout << "bruh";
}
