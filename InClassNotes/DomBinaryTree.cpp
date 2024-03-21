#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteRecursive(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            // Case 1: No child or only one child
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            // Case 2: Two children
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteRecursive(current->right, temp->data);
        }
        return current;
    }

    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }
        if (current->data == value) {
            return true;
        }
        if (value < current->data) {
            return searchRecursive(current->left, value);
        }
        return searchRecursive(current->right, value);
    }

    void inOrderTraversalRecursive(Node* current, vector<Node*> &sorted) {
        if (current != nullptr) {
            inOrderTraversalRecursive(current->left, sorted);
            sorted.push_back(current);
            inOrderTraversalRecursive(current->right, sorted);
        }
    }

    Node* balanceTreeOnHelper(vector<Node*> sorted, int begPos, int endPos){
        if(begPos > endPos){
            return nullptr;
        }

        int mid = (begPos + endPos) / 2;

        Node* current = new Node(sorted[mid]->data);

        current->left = balanceTreeOnHelper(sorted, begPos, mid - 1);
        current->right = balanceTreeOnHelper(sorted, mid+1, endPos);

        return current;
    }

    Node* balanceTreeLogNHelper(Node* curNode){


        return curNode;
    }

    void PrintStructuredHelper(Node* curNode){
        //(From Class)
        if (curNode == nullptr) { return; }

        // Print root and children data
        cout << curNode->data << '(';

        // Put left info in paren if it exists
        if(curNode->left != nullptr){
            cout << curNode->left->data << " ,";
        }else{
            cout << "_ , ";
        }

        if(curNode->right != nullptr){
            cout << curNode->right->data << ')' << endl;
        }else{
            cout << "_)" << endl;
        }

        PrintStructuredHelper(curNode->left); // Do same with Left
        PrintStructuredHelper(curNode->right); // Then same w/ right
        
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
        root = balanceTreeOn();
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
        root = balanceTreeOn();
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    vector<Node*> inOrderTraversal() {
        vector<Node*> result;
        inOrderTraversalRecursive(root, result);
        return result;
    }

    Node* balanceTreeOn(){ // Balances the tree with O(n) (not super efficient but simple)
        vector<Node*> sorted = inOrderTraversal();
        int n = sorted.size();
        return balanceTreeOnHelper(sorted, 0, n-1);
    }

    Node* balanceTreeLogN(){
        return balanceTreeLogNHelper(root);
    }

    void PrintTree(){
        PrintStructuredHelper(root);
    }





    //Rotate Notes 
    void RotateR(Node* parent, Node* child){
        if(child == parent->left){
            parent->left = child->left;
            child->left = parent->left->right;
            parent->left->right = child;
        }
        else if(child==parent->right){
            parent->right = child->left;
            child->left = parent->right->right;
            parent->right->right = child;
        }
        else {
            root = child->left;
            child->left = root->right;
            root->right = child;
        }
    }

    void RotateL(Node* parent, Node* child){
        
    }

    // void RotateLeftRight(Node* parent, Node* child){
    //     parent->left = child->left->right;
    //     child->left->right = parent->left->left;
    //     parent->left->right = child;
    //     parent->left->left = child->left;
    //     child->left = nullptr;
    //     parent->left->left->right = nullptr;
    // }
    //Not working above below is correct

    void RotateLeftRight(Node* parent, Node* child){
        parent->left = child->left->right;
        child->left->right = parent->left->left;
        parent->left->left = child->left;
        child->left = parent->left->right;
        parent->left->right = child;
    }

    void RotateRightLeft(Node* parent, Node* child){
        parent->right = child->right->left;
        child->right->left = parent->right->right;
        parent->right->right = child->right;
        child->right = parent->right->left;
        parent->right->left = child;
    }

    int depth(Node* curr, Node* parent){
        if(curr == nullptr){return 0;}
        //Curr is child for rotate function
        int Ldepth = depth(curr->left, curr); //Curr will become the next parent, to call for rotate later
        int Rdepth = depth(curr->right, curr);
        if(Ldepth > Rdepth){
            return Ldepth + 1;
        }
        return Rdepth + 1;
    }

    //If L depth and R depth are 1 or less different from each other it's balanced
    //Other wise if it's greater than 1 it's out of balance and we can fix it
    //Right depth is greater we rotate left, Left depth is greater we rotate right, from that position


    
};


int main() {
    BinaryTree tree;
    tree.insert(20);
    tree.insert(15);
    tree.insert(12);
    tree.insert(10);
    tree.insert(7);
    tree.insert(5);
    tree.insert(2);
    /*

    After root, tree checks value vs root and goes to the left if smaller, right if larger
    If it's null, it puts the value there and sets the right and left to null of that position
    If it's not null it checks again vs the number there and continues 


                10
        5               15
     2     7        12      20
    
    
    
    */
    tree.PrintTree();
    return 0;
}

// g++ -c DomBinaryTree.cpp
// g++ -o main.exe DomBinaryTree.o
// ./main.exe