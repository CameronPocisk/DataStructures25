#include "OrderedDll.h"

template <typename T>
void OrderedDll<T>::AddItem(T *in){
    length++;
    Node<T>* insertNode = new Node<T>(*in);

    // head case
    if(head == nullptr) {
        head = insertNode;
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
    if(head == nullptr){throw UnderflowError();}
    if(head->data == *val){
        T tempVal = head->data;
        if(head->next != nullptr){
            head = head->next;
            head->previous = nullptr;
        } else {
            head = nullptr;
        }
        length--;
        return tempVal;

        // Node<T>* newHead = head->next;
        // Node<T>* old = head;
        // newHead->previous = nullptr;
        // delete old;
        // length--;
        // return tempVal;
    }
    Node<T>* curNode = head;
    while(curNode->next != nullptr && curNode->next->data != *val){
        curNode = curNode->next;
    }
    if(curNode->next == nullptr){throw NotFound();}

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
    if(IsEmpty()){
        throw UnderflowError();
    }
    
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
T OrderedDll<T>::SeeNext(){
    if(IsEmpty()){
        throw UnderflowError();
    }

    if(place == nullptr) {
        place = head;
        return place->data;
    }
    if(place->next == nullptr){
        throw NotFound();
    }

    place = place->next;
    return place->data;
}

template <typename T>

T OrderedDll<T>::SeePrev(){
    if(IsEmpty()){
        throw UnderflowError();
    }

    if(place == nullptr){
        throw NotFound();
    }

    T temp = place->data;
    place = place->previous;
    return temp;
}

template <typename T>
T OrderedDll<T>::SeeAt(int userPlace){
    if(IsEmpty()){
        throw UnderflowError();
    }

    if(userPlace > length) {
        throw NotFound();
    }

    Node<T>* curNode = head;

    for(int i = 0; i < userPlace - 1; i++){
        curNode = curNode->next;
    }
    
    place = curNode;
    return curNode->data;

}

template <typename T>
void OrderedDll<T>::Reset(){
    // call Delete on all Items?
    place = head;
}

template <typename T>
void OrderedDll<T>::PrintItems(){
    cout << "Printing items: " << endl;
    if(IsEmpty()){cout << "was empty" << endl; return;}
    Node<T>* curNode = head;
    curNode->data.DisplayItem();
    while(curNode->next != nullptr){
        curNode = curNode->next;
        curNode->data.DisplayItem();
    }
}