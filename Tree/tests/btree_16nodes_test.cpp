#include "binarytree.hpp"
#include "sample_btree.hpp"
#include <gtest/gtest.h>
#include "test_programs.hpp"

class BinaryTreeTest : public ::testing::Test {
 protected:
  void SetUp() override {
    values = generate_random_vector(N);
    bt = createDummyBTree(values);
  }

  void TearDown() override {
   delete bt;
  }

  int N = 16;
  std::vector<int> values;
  BinaryTree* bt;
};

TEST_F(BinaryTreeTest, BTree_16Nodes_TestInsertToBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->insert(bt->btroot, 100);
  int n2 = bt->getSize(bt->btroot);
  //std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n2-n1, 1);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestDuplicateInsertToBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  int n2 = bt->getSize(bt->btroot);
  //std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n2-n1, 5);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestRemoveNode) {
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, values[values.size()/2]);
  int n2 = bt->getSize(bt->btroot);
  //std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 1);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestRemoveNodeValueNotInBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, 100);
  int n2 = bt->getSize(bt->btroot);
  //std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 0);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestRemovingRootFirst) {
  
  //bt->showLevelOrder(bt->getRoot());
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, values[0]);
  int n2 = bt->getSize(bt->btroot);
  //std::cout<<"\n***************************\n";
  //bt->showLevelOrder(bt->getRoot());
  //std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 1);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestRemoveAllNodes) {
  
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

TEST_F(BinaryTreeTest, BTree_16Nodes_TestNodesAtKthDistance) {
  testing::internal::CaptureStdout();
  bt->showLevelOrder(bt->getRoot());
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  int height = bt->getHeight(bt->getRoot());
  for(int k=0; k<height; k++){
    print_kth_nodes(bt->getRoot(), k);
    std::cout<<"\n"; 
  }
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1,output2);
  // std::cout<<"output1:\n"<<output1<<std::endl<<"####################"<<std::endl;
  // std::cout<<"output2:\n"<<output2<<std::endl<<"####################"<<std::endl;
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestRootIsNULL) {
  //bt->showLevelOrder(bt->getRoot());
  testing::internal::CaptureStdout();
  print_kth_nodes(nullptr, 1); 
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output.length(),0);
}


TEST_F(BinaryTreeTest, BTree_16Nodes_TestHeightIsNegative) {
  //bt->showLevelOrder(bt->getRoot());
  testing::internal::CaptureStdout();
  print_kth_nodes(bt->getRoot(), -1); 
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output.length(),0);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_Test_HeightIsMoreThanActual) {
  //bt->showLevelOrder(bt->getRoot());
  testing::internal::CaptureStdout();
  int height = bt->getHeight(bt->getRoot());
  print_kth_nodes(bt->getRoot(), height + 1);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output.length(),0); 
}

TEST_F(BinaryTreeTest, BTree_16Nodes_TestMaxValueInTree) {
  //bt->showLevelOrder(bt->getRoot());
  int m1 = INT32_MIN;
  for(auto itr=values.begin(); itr!=values.end(); itr++){
    m1 = std::max(m1,*itr);
  }
  int m2 = max_value(bt->getRoot());
  EXPECT_EQ(m1,m2); 
}

TEST_F(BinaryTreeTest, BTree_16Nodes_LevelOrderPrint) {
  testing::internal::CaptureStdout();
  bt->showLevelOrder(bt->getRoot());
  std::string output1 = testing::internal::GetCapturedStdout();
  testing::internal::CaptureStdout();
  print_level_order(bt->getRoot());
  std::string output2 = testing::internal::GetCapturedStdout();  
  EXPECT_EQ(output1, output2);
}

TEST_F(BinaryTreeTest, BTree_16Nodes_LevelOrderPrintBeautiful) {
  //testing::internal::CaptureStdout();
  bt->showLevelOrder(bt->getRoot());
  //std::string output1 = testing::internal::GetCapturedStdout();
  //testing::internal::CaptureStdout();
  print_beautiful_btree(bt->getRoot());
  //std::string output2 = testing::internal::GetCapturedStdout();  
  //EXPECT_EQ(output1, output2);
}
