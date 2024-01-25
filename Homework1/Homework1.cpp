#include "CardCatalog.h"
using namespace std;

// g++ Homework1.cpp CardCatalog.cpp -o CardCatalog.app
int main()
{
    CardCatalog card;

    string fileName;
    cout << "Enter the file to be processed: " << endl;
    // cin >> fileName;
    fileName = "MobyDick.txt";
    // fileName = "PeterPan.txt";

    ifstream readData;    
    readData.open(fileName, ios::in);
    while(readData.fail())
    {
        cout << "Error: Unable to open file enter another file: ";
        cin >> fileName;
        readData.open(fileName, ios::in);   
    }
    
    card.GetInfo(readData);
    card.AppendOutputFile();

    // Ask user if they would like to see letter freq HERE
    // Jake this u

    card.PrintIfno(); // Not what the assignment asks for, need to make output file. This is proof of info that we have

    // Ask user if they want to process another book 
    // Jake jake pleeeasseeeeee

    // We will talk about the final part (pdf with name, compile instructions, and contributions at the end)
    return 0;
}

// Run these commands sequentially to run

// g++ -c Homework1.cpp CardCatalog.cpp
// g++ -o main.exe Homework1.o Cardcatalog.o
// ./main.exe