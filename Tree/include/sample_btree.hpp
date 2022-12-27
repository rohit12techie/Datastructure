#ifndef _create_binary_tree_h_
#define _create_binary_tree_h_

#include "binarytree.hpp"
#include <vector>

std::vector<int> generate_random_vector(int numOfNodes);
BinaryTree* createDummyBTree(int numOfNodes);
BinaryTree* createDummyBTree(std::vector<int> values);
BinaryTree* createTestBTree();
BinaryTree* createTestBTree2();

#endif  //_create_binary_tree_h_