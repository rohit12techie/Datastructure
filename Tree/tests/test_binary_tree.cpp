#include <iostream>
#include "createbinarytree.hpp"
#include "binarytree.hpp"

void test_minimal(){
    BinaryTree *bt = createTestBTree();
    bt->showLevelOrder(bt->btroot);
    bt->remove(bt->btroot, 13);
    bt->showLevelOrder(bt->btroot);
    bt->remove(bt->btroot, 1);
    bt->showLevelOrder(bt->btroot);
    bt->remove(bt->btroot, 3);
    bt->showLevelOrder(bt->btroot);
}

void test_random(){
    int N = 12;
    std::vector<int> values = generate_random_vector(N);
    BinaryTree *bt = createDummyBTree(values);

    values.push_back(N*3);
    values.push_back(N*4);

    std::cout<<"*********** Test find and Replace start ************"<<std::endl;
    bt->showLevelOrder(bt->btroot);
    std::cout<<std::endl;

    for(auto itr = values.begin(); itr != values.end(); itr++){
        std::cout<<"val:"<<*itr<<" ";
        Node* node = bt->find(bt->btroot, *itr);
        if(node != nullptr){
            std::cout<<"Found - "<<node->data<<" |"<<node->left<<" |"<<node->right<<"|";
            bt->update(bt->btroot, *itr, ((*itr)*100));
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    bt->showLevelOrder(bt->btroot);
    std::cout<<"*********** Test find and Replace end ************"<<std::endl;
    std::cout<<"*********** Test width start ************"<<std::endl;
    std::cout<<"Width : "<<bt->getWidth(bt->btroot)<<std::endl;
    std::cout<<"*********** Test widht end ************"<<std::endl;
    delete bt;
}

int main(){
    test_minimal();
    test_random();
    return 0;
}