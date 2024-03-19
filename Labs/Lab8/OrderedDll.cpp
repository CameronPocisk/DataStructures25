#include "OrderedDll.h"

template <typename T>
void OrderedDll<T>::AddItem(T *in){
    length++; // Len will increase no matter what and you will make a node no matter what
    Node<T>* insertNode = new Node<T>(*in);

    // head case
    if(head == nullptr) {
        head = insertNode;
        place = head;
        return;
    }

    // Before case
    if(*in < head->data) {
        insertNode->next = head;
        head->previous = insertNode;
        head = insertNode;
        return;
    }

    // Get behind greater element
    Node<T>* curNode = head;
    while(curNode->next != nullptr && curNode->next->data < *in){
        curNode = curNode->next;
    }

    // Assign pointers for new node, previous, and next if it exists
    if(curNode->next == nullptr){
        curNode->next = insertNode;
        insertNode->previous = curNode;
    } else {
        insertNode->next = curNode->next;
        insertNode->previous = curNode;
        curNode->next->previous = insertNode;
        curNode->next = insertNode;
    }

}

template <typename T>
T OrderedDll<T>::GetItem(T *val){
    if(head == nullptr){throw UnderflowError();} // Throw error if not found
    // Head case
    if(head->data == *val){
        T tempVal = head->data;
        // Swap pointers and check for existince
        if(head->next != nullptr){
            head = head->next;
            head->previous = nullptr;
        } else {
            head = nullptr;
        }
        length--;
        return tempVal; // Done !!
    }
    // Search from here
    Node<T>* curNode = head;
    while(curNode->next != nullptr && curNode->next->data != *val){
        curNode = curNode->next;
    }
    if(curNode->next == nullptr){throw NotFound();} // gas

    //Set pointers accoringly
    T tempVal = curNode->next->data;
    if(curNode->next->next){
        curNode->next = curNode->next->next;
        curNode->next->previous = curNode;
    } else {
        curNode->next = nullptr;
    }
    length--;
    return tempVal;
}

template <typename T>
bool OrderedDll<T>::IsInList(T *val){
    if(IsEmpty()){ // Error check
        throw UnderflowError();
    }
    
    // traverse with copy of head and compare to values
    Node<T>* curNode = head;
    for(int i = 0; i < length; i++){
        if(curNode->data == *val){
            return true;
        }
        curNode = curNode->next;
    }
    return false;
}

template <typename T>
T OrderedDll<T>::SeeNext() {
    if (IsEmpty()) { // Error handling
        throw UnderflowError();
    }
    if (place->next == nullptr && endReached) {
        throw NotFound(); // End of list reached, throw NotFound
    }
    Node<T>* temp = place;
    if (place->next == nullptr) {
        endReached = true; // Mark end of list reached
    } else {
        place = place->next;
    }
    return temp->data;
}

template <typename T>

T OrderedDll<T>::SeePrev() {
    if (IsEmpty()) {
        throw UnderflowError();
    }
    if (place->next == nullptr && endReached) {
        endReached = false; // Reset endReached flag;
        return place->data; // Return the last node's data
    }
    if(place->previous == nullptr && begReached){
        throw NotFound();
    }
    if(place->previous == nullptr) {
        begReached = true; //Mark begining of list true
    } else {
        place = place->previous;
    }
    return place->data;
}

template <typename T>
T OrderedDll<T>::SeeAt(int userPlace){
    if(IsEmpty()){
        throw UnderflowError();
    }
    if(userPlace > length || userPlace <= 0) {
        throw NotFound();
    }

    Node<T>* curNode = head;
    // Grab the node at the user place.
    for(int i = 0; i < userPlace - 1; i++){
        curNode = curNode->next;
    }

    place = curNode;
    return curNode->data;

}

template <typename T>
void OrderedDll<T>::Reset(){
    begReached = true;
    endReached = false;
    place = head;
}

template <typename T>
void OrderedDll<T>::PrintItems(){
    cout << "Printing items: " << endl;

    if(IsEmpty()){throw UnderflowError();}
    
    // Head case and traversal head copy
    Node<T>* curNode = head;
    curNode->data.DisplayItem();
    //  go to next and print if there
    while(curNode->next != nullptr){
        curNode = curNode->next;
        curNode->data.DisplayItem();
    }
}
