#include <iostream>
#include <stdexcept>
#include<random>

using namespace std;

class OverflowError : public exception
{
public:
    const char *what()
{
        return "Overflow Error Occured";
    }
};

class UnderflowError : public exception
{
public:
    const char *what()
    {
        return "Underflow Error Occured";
    }
};

class NotFound : public exception
{
public:
    const char *what()
    {
        return "Item Not Found";
    }
};

template <class T>
class OrderedList
{
protected: // protected for inheritance
    const static int size = 10;
    T *data[size];
    int index; // needed?

public: // user methods
    int numComps;
    int numMoves;
    OrderedList()
    { // Constructor (set 0s?)
        numComps = 0;
        numMoves = 0;
        index = 0;
    }

    int GetIndex() {
        return index;
    }

    void printList(){
        for (int i = 0; i < index; i++){
            cout << *data[i] << ", ";
        }
        cout << endl << endl;
    }

    void AddItem(T right)
    {
        if (isFull()){
            throw OverflowError();
        }
        int i = index;
        while (i > 0 && right < *data[i - 1])
        {
            numComps += 2;
            data[i] = data[i - 1];
            i--;
            numMoves++;
        }
        data[i] = new T(right);
        index++;
    }
    // Is removeitem void?
    void RemoveItem(T remove)
    { // Return?
        if (isEmpty()){
            throw UnderflowError();
        }

        for (int i = 0; i < index; i++)
        {
            numMoves++;
            numComps ++;
            if (*data[i] == remove)
            {
                numComps++;
                // Remove the thing (itterate through the rest and swap)
                for(int j = i; j < index; j++){
                    numComps++;
                    numMoves++;
                    data[j] = data[j + 1]; // cur item = next item until you reach the index
                }
                index--;
                return;
            }
        }
        // Throw Element Not Found
        throw NotFound();
    }

    bool isEmpty()
    {
        numComps++;
        return index == 0;
    }
    bool isFull()
    {
        numComps++;
        return index == size;
    }
    void MakeEmpty()
    {
        index = 0;
    }
};

template <class T>
class MiddleOrdered : public OrderedList<T>
{
private:
    int AddSearch(T right, int low, int high)
    {
        this->numComps++;
        if (low >= high){
            return low;
        }

        int mid = (high + low) / 2;

        this->numComps++;
        if (right == *this->data[mid]){
            return mid + 1;
        }

        this->numComps++;
        if (right > *this->data[mid]){
            return AddSearch(right, mid + 1, high);
        }
        else{ // right < *data[mid]
            return AddSearch(right, low, mid);
        }
    }

    int RemoveSearch(T right, int low, int high){
        int mid = (high + low) / 2;

        this->numComps++;
        if (right == *this->data[mid]){
            return mid;
        } // else if low == high

        this->numComps++;
        if (low >= high){
            throw NotFound();
        }

        this->numComps++;
        if (right > *this->data[mid]){
            return RemoveSearch(right, mid + 1, high);
        }
        else{ // right < *data[mid]
            return RemoveSearch(right, low, mid);
        }
    }

public:
    // Constructor that defines the type
    // MiddleOrdered() : BaseTemplateClass<T>(){}
    // Overides virtual Add/Remover fns from base class
    void AddItem(T right){
        if(this->isFull()){
            throw OverflowError();
        }
        int positionToAdd = AddSearch(right, 0, this->index);

        for (int i = this->index; i > positionToAdd; i--)
        {
            this->numComps++;
            this->data[i] = this->data[i - 1];
            this->numMoves++;
        }

        this->data[positionToAdd] = new T(right);
        this->index++;
    }
    void RemoveItem(T remove){
        if (this->isEmpty()){
            throw UnderflowError();
        }

        // Find the index element is at
        int removeIndex = RemoveSearch(remove, 0, this->index);
        // Remove and shift from there
        for (int i = removeIndex; i < this->index; i++){
            this->numMoves++;
            this->numComps++;
            this->data[i] = this->data[i + 1];
        }
        this->index--;
    }
};

template <class T>
class NullList : public OrderedList<T>
{
    int lastPosition;
    int firstPosition;
    int lastValue;

public:
    NullList(){
        lastPosition = 0;
        firstPosition = 0;
        lastValue = 0;
        for (int i = 0; i < this->size; i++){
            this->data[i] = nullptr;
        }
    }

    void printList(){
        for (int i = 0; i < this->size; i++){
            if (this->data[i] != nullptr){
                cout << *this->data[i] << ", ";
            }
            else{
                cout << '_' << ", ";
            }
        }
        cout << endl << endl;
    }

    void AddItem(T right)
    {
        if (this->isFull()){
            throw OverflowError();
        }
        if (this->isEmpty()){
            this->data[0] = new T(right);
            this->index++;
            return;
        }

        this->numComps++;
        if (lastValue > right)
        {
            // If the new insert is to the left of the previous
            for (int i = lastPosition; i >= 0; i--)
            {
                this->numComps++;
                if (this->data[i] != nullptr)
                {   
                    this->numComps++;
                    if (*this->data[i] > right)
                    {
                        lastPosition = i;
                        // If it finds a number higher than right, that becomes the lastPosition
                    }
                    else
                    {
                        firstPosition = i;
                        // If the number is lower than right than that becomes the first position
                        // Added 1 since we don't want to include the number at the first position
                        break;
                    }
                }
                firstPosition = 0;
            }
        }
        else
        {
            // if the new insert is to the right of the previous
            for (int i = lastPosition; i < this->size; i++)
            {
                if (this->data[i] != nullptr)
                {
                    this->numComps++;
                    if (*this->data[i] <= right)
                    {
                        firstPosition = i;
                    }
                    else
                    {
                        lastPosition = i;
                        break;
                    }
                }
                lastPosition = this->size - 1;
                // Case where there is no numbers we set meaning all null and our top value is the size
            }
        }
        int mid = (firstPosition + lastPosition + 1) / 2;
        // Middle between the before and end positions

        // If lastPosition is greater than firstPosition it has to go in at 0
        // Unless the firstPosition is greater than the size which is handled later
        this->numComps++;
        if (lastPosition < firstPosition && this->data[0] != nullptr && *this->data[0] > right)
        {
            mid = 0;
        }
        // Now find the nearest null position so we only move to there
        int nullPosition;
        for (int i = mid; i < this->size; i++)
        {
            this-> numComps++;

            if (this->data[i] == nullptr)
            {
                // If mid is already empty this just runs once and breaks
                nullPosition = i;
                break;
            }
        }
        int nullPosition2;
        for (int i = this->size - 1; i > 0; i--)
        {
            this-> numComps++;

            if (this->data[i] == nullptr)
            {
                // If mid is already empty this just runs once and breaks
                nullPosition2 = i;
                break;
            }
        }

        /*
        If the firstPosition is greater than or equal to the size
        Edge case of the number must go in the last spot
        So we have to push everything left
        Otherwise shift right until null
        */
        if (mid > nullPosition2){
            for (int j = nullPosition2; j < mid - 1; j++)
            {
                this->numMoves++;
                this->numComps++;
                this->data[j] = this->data[j + 1];
            }
        }
        else{
            for (int j = nullPosition; j >= mid; j--)
            {
                this->numMoves++;
                this->numComps++;
                this->data[j] = this->data[j - 1];
            }
        }
            // Now we have moved everything out of the way and just insert the number in the middle
        lastPosition = mid;
        this->data[mid] = new T(right);
        lastValue = *this->data[mid];
        this->index++;
    }

    void RemoveItem(T right){
        if (this->isEmpty()){
            throw UnderflowError();
        }
        for (int i = 0; i < this->size; i++){
            this->numComps++;
            this->numMoves++;

            this->numComps++;
            if (this->data[i] != nullptr)
            {
                this->numComps++;
                if(*this->data[i] == right){
                    lastValue = *this->data[i];
                    this->data[i] = nullptr;
                    this->index--;
                    return; 
                }
            }
        }
        throw NotFound();
    }
};

int main()
{
    srand(37); // Doms favorite number for random seed //time(0) so it's random every time
    // strand(time(0));

    int userChoice;
    cout << "Press 1 for User Test" << endl << "Press 2 for Automated test" << endl << "Press 3 to Quit" << endl;
    cin >> userChoice;
    if (userChoice == 1)
    {
        OrderedList<int> origLst;
        MiddleOrdered<int> middleLst;
        NullList<int> nullLst;
        cout << "Press 1 to add an item to the list and display current state" << endl
            << "Press 2 to remove an item from the list and display current state" << endl
            << "Press 3 to Quit" << endl;
        cin >> userChoice;
        while (userChoice != 3)
        {
            if(userChoice == 1){
                int numToAdd;
                cout << "What number would you like to add? ";
                cin >> numToAdd;
                cout << endl;
                try{
                    origLst.AddItem(numToAdd);
                    middleLst.AddItem(numToAdd);
                    nullLst.AddItem(numToAdd);

                } catch(OverflowError &e){
                    cerr << e.what() << endl;
                }
                cout << "Task 1 list: ";
                origLst.printList();
                cout << endl << "Number of comparasons: " << origLst.numComps << endl;
                cout << "Number of moves: " << origLst.numMoves << endl;
                cout << endl;

                cout << "Task 2 list: ";
                middleLst.printList();
                cout << endl << "Number of comparasons: " << middleLst.numComps << endl;
                cout << "Number of moves: " << middleLst.numMoves << endl;
                cout << endl;

                cout << "Task 3 list: ";
                nullLst.printList();
                cout << endl << "Number of comparasons: " << nullLst.numComps << endl;
                cout << "Number of moves: " << nullLst.numMoves << endl;
                cout << endl;

            }
            else if(userChoice == 2) {
                int numToRemove;
                cout << "What number would you like to remove? ";
                cin >> numToRemove;
                try{
                    origLst.RemoveItem(numToRemove);
                    middleLst.RemoveItem(numToRemove);
                    nullLst.RemoveItem(numToRemove);
                } catch(NotFound &e){
                    cerr << e.what() << endl;
                } catch(UnderflowError &e){
                    cerr << e.what() << endl;
                }
                cout << "Task 1 list: ";
                origLst.printList();
                cout << endl << "Number of comparasons: " << origLst.numComps << endl;
                cout << "Number of moves: " << origLst.numMoves << endl;
                cout << endl;

                cout << "Task 2 list: ";
                middleLst.printList();
                cout << endl << "Number of comparasons: " << middleLst.numComps << endl;
                cout << "Number of moves: " << middleLst.numMoves << endl;
                cout << endl;

                cout << "Task 3 list: ";
                nullLst.printList();
                cout << endl << "Number of comparasons: " << nullLst.numComps << endl;
                cout << "Number of moves: " << nullLst.numMoves << endl;
                cout << endl;
            }

            cout << "Press 1 to add an item to the list and display current state" << endl
                << "Press 2 to remove an item from the list and display current state" << endl
                << "Press 3 to Quit" << endl;
            cin >> userChoice;
        }
    }
    else if(userChoice == 2){
        // Automated testing
        OrderedList<int> origLst;
        MiddleOrdered<int> middleLst;
        NullList<int> nullLst;
        
        // int randomNums[100];
        const int numOperations = 100;
        for(int i = 0; i < numOperations; i++){
            int numToAdd = rand() % 100 +1;
            // Random insertion or deletion.
            if(i % 3 != 0 || origLst.GetIndex() % 5 != 0){
                try{
                origLst.AddItem(numToAdd);
                middleLst.AddItem(numToAdd);
                nullLst.AddItem(numToAdd);
                }
                catch(OverflowError &e){
                    cerr << e.what() << endl;
                } // Do Nothing on error
            }
            else{
                    try{
                    origLst.RemoveItem(numToAdd);   
                    middleLst.RemoveItem(numToAdd);
                    nullLst.RemoveItem(numToAdd);
                    }
                    catch(NotFound &e){
                        cerr << e.what() << endl;
                    }
                    catch(UnderflowError &e){
                        cerr << e.what() << endl;
                    }
                }
            }
        cout << "Task 1 Number of moves:" << origLst.numMoves << " , Task 1 Number of comps : " << origLst.numComps << endl;
        cout << "Task 2 Number of moves:" << middleLst.numMoves << " , Task 2 Number of comps : " << middleLst.numComps << endl;
        cout << "Task 3 Number of moves:" << nullLst.numMoves << " , Task 3 Number of comps : " << nullLst.numComps << endl;
    }

    return 0;
};

// g++ -c Lab7.cpp
// g++ -o main.exe Lab7.o
// ./main.exe