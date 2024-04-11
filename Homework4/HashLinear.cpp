#include "HashLinear.h"

int HashLinear::Insert(int in){
    //Returns number of spots checked
    int hashValue = Hash(in);
    int i = 0;

    if(hashStorage[hashValue] != 0){
        //Collision
        while(hashStorage[i] != 0){
            i++;
        }
        hashValue = i;
        i++;
    }

    hashStorage[hashValue] = in;
    return i + 1;

}

int HashLinear::Find(int toFind) {
    int hashValue = Hash(toFind);

    if(hashStorage[hashValue] != toFind){
       for(int i = 0; i < DefaultMaxSize; i++){
            if(hashStorage[(hashValue + i) % DefaultMaxSize] == toFind){
                hashStorage[i] = 0; // Removes it from list as well
                return i + 1;
            }
       }
        throw NotFound();
    }
    return 1;
}
int HashLinear::Remove(int in){
    int hashValue = Hash(in);

    if(hashStorage[hashValue] != in){
       for(int i = 0; i < DefaultMaxSize; i++){
            if(hashStorage[i] == in){
                hashStorage[i] = 0;
                return i + 1;
            }
       }
        throw NotFound();
    }
    hashStorage[hashValue] = 0;
    return 1;
}

bool HashLinear::IsEmpty() {
    return true;
}