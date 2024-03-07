#include <iostream>
#include <queue>
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

    void inOrderTraversalRecursive(Node* current) {
        if (current != nullptr) {
            inOrderTraversalRecursive(current->left);
            cout << current->data << " ";
            inOrderTraversalRecursive(current->right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);
    /*

    After root, tree checks value vs root and goes to the left if smaller, right if larger
    If it's null, it puts the value there and sets the right and left to null of that position
    If it's not null it checks again vs the number there and continues 


                10
        5               15
     2     7        12      20
    
    
    
    */

    cout << "In-order traversal: ";
    tree.inOrderTraversal();

    cout << "Is 7 present in the tree? " << (tree.search(7) ? "Yes" : "No") << endl;

    tree.remove(10);
    cout << "In-order traversal after removing 10: ";
    tree.inOrderTraversal();

    return 0;
}

// g++ -c DomBinaryTree.cpp
// g++ -o main.exe DomBinaryTree.o
// ./main.exe