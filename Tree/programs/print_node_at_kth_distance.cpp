#include <iostream>
#include "node.hpp"


/**
 * @brief Print the node at the kth distance. if k=0, print root node. if k=1 then print root's child. 
 * 
 * @param root 
 * @param k 
 */
void print_kth_nodes(Node* root, int k){
    if(root != nullptr){
        if(k == 0){
            std::cout<<root->data<<" ";
        }
        print_kth_nodes(root->left, k-1);
        print_kth_nodes(root->right, k-1);
    }
}


