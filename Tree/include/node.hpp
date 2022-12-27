#ifndef _node_h_
#define _node_h_


/**
 * @file node.hpp
 * @author Rohit Kumar (rohit12techie@gmail.com)
 * @brief BinaryTree
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class Node{
 public:
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~Node(){
        //std::cout<<"Destructor of Node called"<<std::endl;
    }
};

#endif  // _node_h_
