#include "node.hpp"

#include <iostream>
#include <queue>

void print_level_order(Node* root){
    if(root == nullptr){
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty()){
        Node *cur = q.front();
        q.pop();

        if(cur == nullptr){
            std::cout<<"\n";
            q.push(nullptr);    
            cur = q.front();
            q.pop();
        }
        if(cur != nullptr){
            std::cout<<cur->data<<" ";
            if(cur->left != nullptr){
                q.push(cur->left);
            }

            if(cur->right != nullptr){
                q.push(cur->right);
            }
        }
    }
}