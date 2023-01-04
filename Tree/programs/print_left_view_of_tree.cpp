/**
 * @file print_left_view_of_tree.cpp
 * @author your name (you@domain.com)
 * @brief Print left view of tree or print the most left node at each level in a tree.
 * @version 0.1
 * @date 2023-01-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "node.hpp"
#include <iostream>
#include <queue>

int print_left_most_node(Node* root, int k, int max){
    if(root == nullptr){
        return 0;
    }
    std::queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node *cur = q.front();
        q.pop();
        if(cur == nullptr){
            q.push(nullptr);
        }
        else{
            
            if(cur->left != nullptr){
                q.push(cur->left);
            }
            if(cur->right != nullptr){
                q.push(cur->right);
            }
        }
    }
    return 0;
}

void print_left_view(Node* root){
    print_left_most_node(root, 0, -1);
}