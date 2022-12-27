#include <iostream>

class Node{
    int data; 

    public:

    Node *left;
    Node *right;

    Node *next;
    Node *right;
};

Node* btree_to_2d_list(Node *root, Node *newroot){
    if(root != NULL){
        btree_to_2d_list(root->left, newroot);

        if(newroot == NULL){
            newroot = root;
        }
        

    }
}