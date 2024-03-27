#include "Tree.h"
#include "Tree.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class Word{
    public:
    string word;
    int frequency;

    public:
    Word(string wordIn){word = wordIn; frequency = 1;}
    int getFrequency(){return frequency;}
    string getWord(){return word;}
    void incrementFreq(){frequency++;}
    // string GetWord(){return word;}
    
    bool operator < (const Word& right){return (word < right.word);} // cpp strings have lexographical overloads for > and <
    bool operator > (const Word& right){return (word > right.word);}
    bool operator == (const Word& right){return (word == right.word);}
    bool operator != (const Word& right){return (word != right.word);}
    
    // Overloading the "<<" operator as a member function
    
    // Put friend fn inside of class
    friend ostream& operator<<(ostream& os, const Word& data) {
        os << data.word;
        return os;
    }

// Definition of the << operator overload
};


int main(){

    Tree<Word> allWords;
    string fileName;
    // cout << "Enter name of file: ";
    // cin >> fileName;
    fileName = "mobydick.txt";

    ifstream readData;
    readData.open(fileName, ios::in);
    while(readData.fail()){
        cout << "Unable to open file enter another file: ";
        cin >> fileName;
        readData.open(fileName, ios::in);   
    }

    string data;
    while(readData >> data){
        Word *curWord = new Word(data);
        try{
            Node<Word>* spot = allWords.Find(curWord);
            // If code gets here, found word
            // (spot->data->frequency)++;; // wasnt able to use ++ op?
            spot->data->incrementFreq();
            delete curWord;
        }
        catch(NotFound &e){ // IF NOT FOUND
            cerr << e.what() << endl;
            allWords.Insert(curWord);
        }
    }
    cout << endl << endl;
    allWords.PrintStructuredWithRootSizes();

    // allWords.PrintOrdered();

    int userChoice = 0;
    while(userChoice != 7){
        cout << "Press 1 to search for a word" << endl;
        cout << "Press 2 to view words in ascending alphabetical order" << endl;
        cout << "Press 3 to view words in descending alphabetical order" << endl;
        cout << "Press 4 to view the size of the tree" << endl;
        cout << "Press 5 to empty the tree" << endl;
        cout << "Press 6 to remove a word" << endl;
        cout << "Press 7 to quit" << endl;

        cin >> userChoice;
        while(userChoice < 1 && userChoice > 7){
            cout << "Please enter a number 1-7";
        }
        switch (userChoice){
        case 1: {
            string userWord;
            cout << "Enter a word to search for: ";
            cin >> userWord;
            Word *curWord = new Word(userWord);
            try{
                Node<Word>* found = allWords.Find(curWord);
                cout << "Number of times " << userWord << " appears: ";
                cout << found->data->getFrequency() << endl;
            }
            catch(NotFound &e){
                cout << "Did not find word" << endl;
            }
            delete curWord;
            break;
        }
        case 2:{
            vector<Node<Word>*> ascending = allWords.GetAllAscending();
            for(unsigned int i = 0; i < ascending.size(); i++){
                cout << ascending[i]->data->getWord() << ": " << ascending[i]->data->getFrequency() << endl;
            }
            break;
        }
        case 3:{
            vector<Node<Word>*> descending = allWords.GetAllDecending();
            for(unsigned int i = 0; i < descending.size(); i++){
                cout << descending[i]->data->getWord() << ": " << descending[i]->data->getFrequency() << endl;
            }
            break;
        }
        case 4:{
            cout << "Size of tree:" << allWords.Size() << endl;
            break;
        }
        case 5:{
            allWords.EmptyTree();
            cout << "Tree is now empty" << endl;
            break;
        }
        case 6:{
            string removeWord;
            cout << "Enter word to remove: ";
            cin >> removeWord;
            Word *curWord = new Word(removeWord);
            try{
                Node<Word>* found = allWords.Find(curWord);
                allWords.Remove(curWord);
            }
            catch(NotFound &e){
                cout << "Word is not in tree" << endl;
            }
            delete curWord;
            break;
        }
        case 7:{
            allWords.PrintStructuredWithRootSizes();
            break;
        }
        default:
            break;
        }
    }
    

    return 0;
}

// g++ -c Lab10.cpp Tree.cpp
// g++ -o main.exe Lab10.o Tree.o
// ./main.exe

// g++ -c Lab10.cpp
// g++ -o main.exe Lab10.o
// ./main.exe