#ifndef _binarytree_h_
#define _binarytree_h_

/**
 * @file binarytree.hpp
 * @author Rohit Kumar (rohit12techie@gmail.com)
 * @brief BinaryTree
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "node.hpp"

class BinaryTree{
 public:
    Node* btroot;
    
    BinaryTree();
    ~BinaryTree();
    Node* getRoot();
    /**
     * I/O
    */
    void insert(Node* &root, int val);
    Node* remove(Node* root, int val);
    Node* find(Node* root, int val);
    Node* update(Node* root, int oldval, int newval);
    Node* minOnRight(Node* root);
    Node* maxOnLeft(Node* root);
    Node* removeNode(Node* root, int val);

    /**
     * @brief properties
     *  
     */

    void getLevelWidth(Node *root, int level, int &count);
    int getHeight(Node* root);
    int getWidth(Node* root);
    int getSize(Node* root);

    /**
     * @brief Traversal functions
     *
     */
    void showInOrder(Node* root);
    void showPreOrder(Node* root);
    void showPostOrder(Node* root);
    void printLevel(Node* root, int level);
    void showLevelOrder(Node* root);
};

#endif 