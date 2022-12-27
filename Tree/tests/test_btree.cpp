#include "binarytree.hpp"
#include "createbinarytree.hpp"
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

  int N = 12;
  std::vector<int> values;
  BinaryTree* bt;
};

TEST_F(BinaryTreeTest, TestInsertToBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->insert(bt->btroot, 100);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n2-n1, 1);
}

TEST_F(BinaryTreeTest, TestDuplicateInsertToBT) {
  int n1 = bt->getSize(bt->btroot);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  bt->insert(bt->btroot, 100);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n2-n1, 5);
}

TEST_F(BinaryTreeTest, TestRemoveNode) {
  int n1 = bt->getSize(bt->btroot);
  bt->remove(bt->btroot, values[0]);
  int n2 = bt->getSize(bt->btroot);
  std::cout<<"n1: "<<n1<<" n2: "<<n2<<std::endl;
  EXPECT_EQ(n1-n2, 1);
}