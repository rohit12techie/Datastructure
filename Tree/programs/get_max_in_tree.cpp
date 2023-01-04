#include "node.hpp"
#include <iostream>


/**
 * @brief Print the maximum node value in the binarytree
 * 
 * @param root 
 */
int max_value(Node* root){
    if(root == nullptr){
        return INT32_MIN;
    }
    else{
        return std::max(root->data, std::max(max_value(root->left), max_value(root->right)));     
    }   
}