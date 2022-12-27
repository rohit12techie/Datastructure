#include <iostream>
#include <random>

#include "binarytree.hpp"

std::vector<int> generate_random_vector(int numOfNodes){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,numOfNodes*2); // distribution in range [1, 6]

    std::vector<int> values; 
    for(int i =0; i<numOfNodes; i++){
        int num = dist(rng);
        values.push_back(num);
    }
    return values;
}

BinaryTree* createDummyBTree(int numOfNodes){
    BinaryTree* btree = new BinaryTree();
    std::vector<int> values = generate_random_vector(numOfNodes);
    for(auto itr = values.begin(); itr != values.end(); itr++){
        btree->insert(btree->btroot, *itr);
    }
    return btree;
}

BinaryTree* createDummyBTree(std::vector<int> values){
    BinaryTree* btree = new BinaryTree();
    for(auto itr = values.begin(); itr != values.end(); itr++){
        btree->insert(btree->btroot, *itr);
    }
    return btree;
}

BinaryTree* createTestBTree(){
    BinaryTree* btree = new BinaryTree();
    btree->insert(btree->btroot, 3);
    btree->insert(btree->btroot, 1);
    btree->insert(btree->btroot, 13);
    return btree;
}

BinaryTree* createTestBTree2(){
    BinaryTree* btree = new BinaryTree();
    btree->insert(btree->btroot, 3);
    btree->insert(btree->btroot, 1);
    btree->insert(btree->btroot, 13);
    btree->insert(btree->btroot, 13);
    btree->insert(btree->btroot, 10);
    btree->insert(btree->btroot, 0);
    btree->insert(btree->btroot, 18);
    return btree;
}