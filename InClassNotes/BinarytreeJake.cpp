/*
Binary tree is a data structure where each node in the structure is capable of pointin gto 2 child nodes
Root node - a node with no parent. top of tree
bninary tree must have 1 and only 1 path to any given node
the levels refer to the dostance from the root. the root level is 0. its children are 1, grandchildren are 2
height of the tree is maximum level
max num of nodes in a level is 2^n where n is the level
min num of levels is log2(n) + 1

to get the benefit of a binary tree, the tree needs to be arranged meaningfully. 
usually this is with smaller values as children on the left and larger as children on the right

Why binary trees? Finding a variable is fast.
*/

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int val){
            data = val;
        }
};

class tree{
    node* root;

    void add(int val){
        if(isEmpty()){
            root = new node(val);
            return;
        }
        node* current = root;
        while(current->data > val || current->left != nullptr && current->data < val || current->right != nullptr){
            if(val <= current->data){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(val <= current->data){
            current->left = new node(val);
        }
        else{
            current->right = new node(val);
        }
    }
    bool isEmpty(){
        return root == nullptr;
    }
    int find(int val){
        if(isEmpty()){
            throw notFound(); //Exception
        }
        node* current = root;
        while(current->data > val && current->left != nullptr || current->data < val && current->right != nullptr){
            if(current->data > val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(current->data == val){
            return current->data;
        }
        else{
            throw notFound();
        }
    }
};