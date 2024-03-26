#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        height = 0;
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

    void PrintStructuredHelper(Node* curNode, Node* parent){
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
            cout << curNode->right->data << ')' << curNode->height << endl;
        }else{
            cout << "_)"  << curNode->height << endl;
        }

        PrintStructuredHelper(curNode->left, curNode); // Do same with Left
        PrintStructuredHelper(curNode->right, curNode); // Then same w/ right
        
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
        // RotateBalance(root, nullptr);
        root->height = depthNew(root, nullptr);
        // root = balanceTreeOn();
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
        cout << "Depthnew" << endl;
        root->height = depthNew(root, nullptr);
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

    void PrintTree(){
        PrintStructuredHelper(root, nullptr);
    }





    //Rotate Notes 
    int RotateR(Node* parent, Node* child){
        if(parent == nullptr){
            root = child->left;
            child->left = root->right;
            root->right = child;
        }
        else if(child == parent->left){
            parent->left = child->left;
            child->left = parent->left->right;
            parent->left->right = child;
        }
        else if(child==parent->right){
            parent->right = child->left;
            child->left = parent->right->right;
            parent->right->right = child;
        }
        return depthNew(child, parent);
    }

    int RotateL(Node* parent, Node* child){
        if(parent == nullptr){
            root = child->right;
            child->right = root->left;
            root->left = child;
        }
        else if(child == parent->right){
            parent->right = child->right;
            child->right = parent->right->left;
            parent->right->left = child;
        }
        else if(child == parent->left){
            parent->left = child->right;
            child->right = parent->left->left;
            parent->left->left = child;
        }
        return depthNew(child, parent);
    }

    int RotateLeftRight(Node* parent, Node* child){
        if(parent == nullptr){
            //Rotate around root
            Node* newRoot = root->left->right;
            root->left->right = newRoot->left;
            newRoot->left = root->left;
            root->left = newRoot->right;
            newRoot->right = root;
            root = newRoot;

            return depthNew(root, nullptr);
        }
        parent->left = child->left->right;
        child->left->right = parent->left->left;
        parent->left->left = child->left;
        child->left = parent->left->right;
        parent->left->right = child;

        return depthNew(child, parent);
    }

    int RotateRightLeft(Node* parent, Node* child){
        if(parent == nullptr){
            //Rotate around root
            Node* newRoot = root->right->left;
            root->right->left = newRoot->right;
            newRoot->right = root->right;
            root->right = newRoot->left;
            newRoot->left = root;
            root = newRoot;

            return depthNew(root, nullptr);
        }
        parent->right = child->right->left;
        child->right->left = parent->right->right;
        parent->right->right = child->right;
        child->right = parent->right->left;
        parent->right->left = child;

        return depthNew(child, parent);
    }




    int depthNew(Node* curr, Node* parent){
        if(curr == nullptr){return 0;}
        //Curr is child for rotate function
        int Lheight = depthNew(curr->left, curr); //Curr will become the next parent, to call for rotate later
        int Rheight = depthNew(curr->right, curr);
        if(Lheight > Rheight){
            if(Lheight > Rheight + 1){
                int Lchild = depthNew(curr->left->left, curr->left);
                int Rchild =  depthNew(curr->left->right, curr->left);
                if(Rchild > Lchild) {
                    // PrintStructuredHelper(curr, parent);
                    cout << "LEFTRIGHT" << endl;
                    Lheight = RotateLeftRight(parent, curr);
                } else{
                    cout << "RIGHT" << endl;
                    Lheight = RotateR(parent, curr);
                }
            } 
            curr->height = Lheight + 1;
            return Lheight + 1;
        } else if(Rheight > Lheight){
            if(Rheight > Lheight + 1){
            int Lchild = depthNew(curr->right->left, curr->right);
            int Rchild =  depthNew(curr->right->right, curr->right);
                if(Lchild > Rchild) {
                    // PrintStructuredHelper(curr, parent);
                    cout << "RIGHTLEFT" << endl;
                    Rheight = RotateRightLeft(parent, curr); //Readjust height after rotate
                } else{
                    // PrintStructuredHelper(curr, parent);
                    cout << "LEFT" << endl;
                    Rheight = RotateL(parent, curr); //Readjust height after rotate
                }   
            }
        }
        curr->height = Rheight + 1;
        return Rheight + 1;
    }

    
// Old scuffed code
//    void RotateBalance(Node* curr, Node* parent){
//         int childLeft = depth(curr->left, curr);
//         int childRight = depth(curr->right, curr);
//         cout << childLeft << endl;
//         cout << childRight << endl;
//         if(childLeft > childRight + 1){
//             //Ldepth is 2 higher here, have to balance
//             if(depth(curr->left->right, curr->left) > depth(curr->left->left, curr->left) + 1) {
//                 cout << "LEFTRIGHT" << endl;
//                 RotateLeftRight(curr, curr->left);
//             } else {
//                 cout << "RIGHT" << endl;
//                 RotateR(curr, curr->left);
//             }
//         } else if(childRight > childLeft + 1) {
//             //Rdepth is 2 higher here, have to balance
//             cout << "_____" << endl;
//             cout << depth(curr->right->right, curr->right) << endl;
//             cout << depth(curr->right->left, curr->right) << endl;
//             if(depth(curr->right->right, curr->right) > depth(curr->right->left, curr->right) + 1){
//                 PrintStructuredHelper(curr, parent);
//                 cout << "RIGHTLEFT" << endl;
//                 RotateRightLeft(curr, curr->right);
//             } else {
//                 PrintStructuredHelper(curr, parent);
//                 cout << "LEFT" << endl;
//                 RotateL(parent, curr);
//             }
//         }
//         cout << "already balanced" << endl;
//     }

//     int depth(Node* curr, Node* parent){
//         if(curr == nullptr){return 0;}
//         //Curr is child for rotate function
//         int Lheight = depth(curr->left, curr); //Curr will become the next parent, to call for rotate later
//         int Rheight = depth(curr->right, curr);
//         if(Lheight > Rheight){
//             curr->height = Lheight + 1;
//             return Lheight + 1;
//         }
//         curr->height = Rheight + 1;
//         return Rheight + 1;
//     }
    //If L depth and R depth are 1 or less different from each other it's balanced
    //Other wise if it's greater than 1 it's out of balance and we can fix it
    //Right depth is greater we rotate left, Left depth is greater we rotate right, from that position
    
};


int main() {
    BinaryTree tree;
    tree.insert(13);
    tree.insert(55);
    tree.insert(33);

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