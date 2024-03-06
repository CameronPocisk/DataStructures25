#include "OrderedDll.h"

template class OrderedDll<int>;

template <typename T>
void OrderedDll<T>::AddItem(T *in){
    // length++;
    // if(head == nullptr){
    //     head = new Node<T>(*in);
    //     return; // null <- head -> null
    // }
    
    // // loop to find DLL Node
    // Node<T>* curNode = head;
    // while (curNode->next)
    // while(curNode->next != nullptr && curNode->next->data < *in)
    //     curNode = curNode->next;
    //     cout << "loop" << endl;
    // } // Cur Node is Above lesser node
    // if(curNode->previous != nullptr){
    //     cout << "Previous node was: " << curNode->previous->data << endl;
    // }

    
    
    // Node<T>* toInsert = new Node<T>(*in);
    
    // Next note
    // curNode->next = toInsert;

    // toInsert->previous = curNode; // Safe from nullptr assignment bc head call at top
    // toInsert->next = curNode->next; // Next is chill being nullptr if prevwas nullptr
    // // cout << toInsert->previous->data;
    
    // if(toInsert->next != nullptr){
    //     toInsert->next->previous = toInsert;
    // }

    


    length++;
    if(head == nullptr){
        head = new Node<T>(*in);
        return; // null <- head -> null
    }
    // loop to find DLL Node
    Node<T>* curNode = head;
    while(curNode->next != nullptr && *in <= curNode->data){
        curNode = curNode->next;
        cout << "loop" << endl;
        cout << curNode->data;
    } // Cur Node is where we should add

    Node<T>* toInsert = new Node<T>(*in);

    toInsert->next = curNode;
    curNode->previous = toInsert;
    toInsert->next = curNode;
    cout << "next not null" << endl;
    
    
    
        










}

template <typename T>
T OrderedDll<T>::GetItem(T *val){
    if(head == nullptr){throw UnderflowError();}
    if(head->data == *val){
        int tempVal = head->data;
        Node<T>* newHead = head->next;
        Node<T>* old = head;
        newHead->previous = nullptr;
        delete old;
        length--;
        return tempVal;
    }
    Node<T>* curNode = head;
    while(curNode->next != nullptr && curNode->next->data != *val){
        curNode = curNode->next;
    }
    if(curNode->next == nullptr){throw NotFound();}
    int tempVal = curNode->next->data;
    Node<T>* old = curNode->next;
    curNode->next = curNode->next->next;
    curNode->next->previous = curNode;
    delete old;
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

    if(seePlace >= length - 1){
        return 0;
    }

    Node<T>* curNode = head;
    
    for(int i = 0; i <= seePlace; i++){
        curNode = curNode->next;
    }
    seePlace++;
    return curNode->data;
}

template <typename T>

T OrderedDll<T>::SeePrev(){
    Node<T>* curNode = head;
    
    for(int i = 0; i <= seePlace; i++){
        curNode = curNode->previous;
    }
    seePlace--;
    return curNode->data;
}

template <typename T>
T OrderedDll<T>::SeeAt(int place){
    Node<T>* curNode = head;

    for(int i = 0; i < place; i++){
        curNode = curNode->next;
    }
    
    seePlace = place;
    return curNode->data;

}

template <typename T>
void OrderedDll<T>::Reset(){
    // call Delete on all Items?
    seePlace = 0;
}

template <typename T>
void OrderedDll<T>::PrintItems(){
    if(IsEmpty()){cout << "was empty" << endl; return;}
    cout << "Printing items: " << endl;
    Node<T>* curNode = head;
    cout << curNode->data << ", ";
    while(curNode->next != nullptr){
        curNode = curNode->next;
        cout << curNode->data << ", ";
    }
    cout << endl;
}