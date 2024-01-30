#include "CardCatalog.h"
using namespace std;

int main(){

    string repeat = "yes";

    while(repeat == "yes"){
        CardCatalog c;

        string fileName;
        cout << "Enter the file to be processed: " << endl;
        cin >> fileName;

        ifstream readData;
        
        readData.open(fileName, ios::in);
        while(readData.fail())
        {
                cout << "Unable to open file enter another file: ";
                cin >> fileName;
                readData.open(fileName, ios::in);   
        }
        
        c.GetInfo(readData);
        c.AppendOutputFile();

        string ShouldPrintLetterFreq;
        cout << "Would you like to print the letter freq? " << endl;
        cin >> ShouldPrintLetterFreq;
        if(ShouldPrintLetterFreq == "yes"){
            cout << "Printing Letter frequency: " << endl;
            c.PrintLetterFreq();
        }

        cout << "Do you want to process another book? ";
        cin >> repeat;

        while(repeat != "yes" & repeat != "no"){
            cout << "Please type yes or no: ";
            cin >> repeat;
        }
    }
    return 0;
}

// Run these commands sequentially to run

// g++ -c Homework1.cpp CardCatalog.cpp
// g++ -o main.exe Homework1.o Cardcatalog.o
// ./main.exe