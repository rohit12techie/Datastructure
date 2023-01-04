/**
 * @file print_beautiful_btree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "node.hpp"
#include <iostream>
#include <queue>
#include <cmath>

static int tree_height(Node* root){
    if(root == nullptr){
        return 0;
    }

    return std::max(tree_height(root->left), tree_height(root->right)) + 1;
}

void printGap(int count){
    for(int i=0; i<count; i++){
        std::cout<<" ";
    }
}

void beautify_btree(std::queue<Node*> &q, int pos, int gap){
    
    bool first = true;
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        if(first == true){
            printGap(pos-1);
            first = false;
        }
        else{
            printGap(gap-1);
        }
        if(cur!=nullptr)
            std::cout<<cur->data;
        else
            std::cout<<" ";
    }
    std::cout<<"\n";
}

void print_beautiful_btree(Node* root){
    if(root == nullptr){
        return;
    }
    
    int height = tree_height(root);
    std::cout<<"height is "<<height<<"\n";
    std::queue<Node*> q;
    std::queue<Node*> q1;
    q.push(root);
    int parent_pos=0;
    int current_pos=0;

    while(height > 0){
        int cursize = q.size();
        for(int i=0; i<cursize; i++){
            Node* cur = q.front();
            q1.push(cur);
            q.pop();
            if(cur == nullptr){
                q.push(nullptr);
                q.push(nullptr);
            }
            else{
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        current_pos = pow(2, (height - 1));
        beautify_btree(q1, current_pos, parent_pos);
        for(int i=0; i<height/2; i++){
            std::cout<<"\n";
        }
        parent_pos = current_pos;
        height--;
    }
}