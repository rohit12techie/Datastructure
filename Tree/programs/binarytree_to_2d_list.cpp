#include <iostream>
#include "node.hpp"

Node* btree_to_2d_list(Node *root, Node *newroot){
    if(root != NULL){
        btree_to_2d_list(root->left, newroot);

        if(newroot == NULL){
            newroot = root;
        }
        

    }
}