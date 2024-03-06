/* 
Linked list - dynamically allocated data structure linked together to form a chain
Advantages:
    Easy to insert or remove something from any point in the list
    Easy to shrink and growmour list
Disadvantages:
    Larger memory usage for every item stored
    Coding a linked list is more complicated
    Possible memory leaks

List is made up of nodes. Each node contains data and a pointer to the next node in the list.
The list only contains a pointer to the first item in the list. Sometimes it contains a variable to track length
The node is called a self-refrential data structure.

Linked list member functions:
    Insert
    Remove
    Length
    MakeEmpty

*/
class node{
    public:
        node* next;
        int data;

};

class LL{
    node* head;

    void insert(int in){
        node* newNode = new node(in);
        if(head == nullptr){
            head = newNode;
            return;
        }
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertFront(int in){
        node* addNode = new node(in);
        addNode->next = head;
        head = addNode;
    }
    void insertO(int in){ // Add to front because list is empty
        if(head == nullptr){
            head = new node(in);
            return;
        }
        if(in < head->data){ // Add to front
            node* temp = head;
            head = new node(in);
            head->next = temp;
        }
        node* temp = head;
        while(temp->next != nullptr && temp->next->data < in){
            temp = temp->next;
        }
        node* restOfList = temp->next;
        temp->next = new node(in);
        temp->next->next = restOfList;
    }

    int removeByVal(int val){
        if(head == nullptr){throw NotFoundException;}
        if(head->data == val){
            int temp = head->data;
            node* old = head;
            head = head->next;
            delete old;
            return temp;
        }
        node* temp = head;
        while(temp->next != nullptr && temp->next->data != val){
            temp = temp->next;
        } 
        if(temp->next == nullptr){throw NotFoundException;}
        int tempVal = temp->next->data;
        node* old = temp->next;
        temp->next = temp->next->next;
        delete old;
        return tempVal;

    }
    int find(int val){
        if(head == nullptr){throw NotFoundException;}
        if(head->data == val){return head->data;}
        node* temp = head;
        while(temp->data != val && temp->next != nullptr){
            temp = temp->next;
        }
        if(temp->next == nullptr && temp->data != val){
            throw NotFoundExcpetion;
        }
        return temp->data;
    }
};
