#include "HashTwoDim.h"

int HashTwoDim::Insert(int in){
    //Returns number of spots checked
    int hashValue = Hash(in);

    for(int i = 0; i < TwoMaxDepth; i++){
        if(hashStorage[hashValue][i] == 0){
            hashStorage[hashValue][i] = in;
            return i + 1;
        }
    }

    throw OverflowError();
    return 0;
}

int HashTwoDim::Find(int toFind) {
    int hashValue = Hash(toFind);

    for(int i = 0; i < TwoMaxDepth; i++){
        if(hashStorage[hashValue][i] == toFind){
            return i + 1;
        }
    }

    throw NotFound();
    return 0;
}
int HashTwoDim::Remove(int in){
    int hashValue = Hash(in);

    for(int i = 0; i < TwoMaxDepth; i++){
        if(hashStorage[hashValue][i] == in){
            hashStorage[hashValue][i] = 0;
            return i + 1;
        }
    }

    throw NotFound();
    return 0;
}

bool HashTwoDim::IsEmpty() {
    return true;
}