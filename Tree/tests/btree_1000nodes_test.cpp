#include "binarytree.hpp"
#include "sample_btree.hpp"
#include <gtest/gtest.h>

class BinaryTreeTest : public ::testing::Test {
 protected:
  void SetUp() override {
    values = generate_random_vector(N);
    bt = createDummyBTree(values);
  }

  void TearDown() override {
   delete bt;
  }

  int N = 1000;
  std::vector<int> values;
  BinaryTree* bt;
};

TEST_F(BinaryTreeTest, BTree1000NodesTestInsertToBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->insert(bt->btroot, -1);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n2-n1, 1);
}

TEST_F(BinaryTreeTest, BTree1000NodesTestDuplicateInsertToBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->insert(bt->btroot, -1);
  bt->insert(bt->btroot, -1);
  bt->insert(bt->btroot, -1);
  bt->insert(bt->btroot, -1);
  bt->insert(bt->btroot, -1);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n2-n1, 5);
}

TEST_F(BinaryTreeTest, BTree1000NodesTestRemoveNode) {
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, values[values.size()/2]);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 1);
}

TEST_F(BinaryTreeTest, BTree1000NodesTestRemoveNodeValueNotInBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, -1);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 0);
}

TEST_F(BinaryTreeTest, BTree1000NodesTestRemovingRootFirst) {
  
  //bt->showLevelOrder(bt->getRoot());
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, values[0]);
  int n2 = bt->getSize(bt->btroot);
  //std::cout<<"\n***************************\n";
  //bt->showLevelOrder(bt->getRoot());
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 1);
}

TEST_F(BinaryTreeTest, BTree1000NodesTestRemoveAllNodes) {
  
  //bt->showLevelOrder(bt->getRoot());
  int n1 = bt->getSize(bt->btroot);
  int count = 1;
  for(auto itr = values.begin(); itr != values.end(); itr++){
    bt->remove(bt->btroot, *itr);
    int n2 = bt->getSize(bt->btroot);
    EXPECT_EQ(n1-n2, count++);
  }
  
  
  //std::cout<<"\n***************************\n";
  //bt->showLevelOrder(bt->getRoot());
  //std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  n1 = bt->getSize(bt->btroot);
  EXPECT_EQ(n1, 0);
}