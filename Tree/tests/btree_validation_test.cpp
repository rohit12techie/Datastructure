#include <iostream>
#include "sample_btree.hpp"
#include "binarytree.hpp"

void test_minimal(){
    BinaryTree *bt = createTestBTree();
    std::cout<<"************** test-minimal START ************* "<<std::endl;
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node not in the BT"<<std::endl;
    bt->remove(bt->getRoot(), 15);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 13"<<std::endl;
    bt->remove(bt->getRoot(), 13);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 1"<<std::endl;
    bt->remove(bt->getRoot(), 1);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 3"<<std::endl;
    bt->remove(bt->getRoot(), 3);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"************** test-minimal END ************* "<<std::endl;
}

void test_minimal_remove_root_first(){
    BinaryTree *bt = createTestBTree();
    std::cout<<"\n************** test-minimal-with-root-first START ************* "<<std::endl;
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Root Node first - 3"<<std::endl;
    bt->remove(bt->getRoot(), 3);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 1"<<std::endl;
    bt->remove(bt->getRoot(), 1);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node not present in BT- 21"<<std::endl;
    bt->remove(bt->getRoot(), 21);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 13"<<std::endl;
    bt->remove(bt->getRoot(), 13);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"************** test-minimal-with-root-first END ************* "<<std::endl;
}

void test_duplicate_remove(){
    BinaryTree *bt = createTestBTree2();
    std::cout<<"\n************** test-remove-with-root-first START ************* "<<std::endl;
    bt->update(bt->getRoot(), 10, 13);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Root Node first - 13"<<std::endl;
    bt->remove(bt->getRoot(), 13);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 1"<<std::endl;
    bt->remove(bt->getRoot(), 1);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node not present in BT- 21"<<std::endl;
    bt->remove(bt->getRoot(), 21);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Node 3"<<std::endl;
    bt->remove(bt->getRoot(), 3);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"************** test-remove-with-root-first END ************* "<<std::endl;
}

void test_remove_random(){
    int N = 12;
    std::vector<int> values = generate_random_vector(N);
    BinaryTree *bt = createDummyBTree(values);

    std::cout<<"\n************** test-remove-random-with-root-first START ************* "<<std::endl;
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"Removing Root Node : "<<values[values.size()/2]<<std::endl;
    bt->remove(bt->getRoot(), values[values.size()/2]);
    bt->showLevelOrder(bt->getRoot());
    std::cout<<"************** test-remove-random-with-root-first END ************* "<<std::endl;
}


void test_find_and_update(){
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
    //test_minimal();
    //test_minimal_remove_root_first();
    //test_find_and_update();
    test_duplicate_remove();
    //test_remove_random();
    return 0;
}