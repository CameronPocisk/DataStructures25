#include "CardCatalog.h"
using namespace std;

// g++ Homework1.cpp CardCatalog.cpp -o CardCatalog.app
int main(){

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
    return 0;
}

// Run these commands sequentially to run

// g++ -c Homework1.cpp CardCatalog.cpp
// g++ -o main.exe Homework1.o Cardcatalog.o
// ./main.exe