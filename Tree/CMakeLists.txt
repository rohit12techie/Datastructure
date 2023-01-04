cmake_minimum_required(VERSION 3.12)
project(binarytree)      

set(add_compile_options -std=C++14)

set(GTEST_SRCS  
    tests/btree_16nodes_test.cpp
    tests/main.cpp)

set(GTEST_SRCS_MORE  
    tests/btree_1000nodes_test.cpp
    tests/main.cpp)

set(SAMPLE_TEST_SRCS
    sample/btree_validation_test.cpp)

set(PROGRAM_SRCS 
    programs/print_node_at_kth_distance.cpp
    programs/get_max_in_tree.cpp
    programs/print_left_view_of_tree.cpp
    programs/print_level_order_using_queue.cpp
    programs/print_beautiful_btree.cpp)

ADD_LIBRARY(binarytree STATIC
    src/binarytreeimpl.cpp)

ADD_LIBRARY(samplebtree STATIC
    sample/sample_btree.cpp)

ADD_LIBRARY(btreeprograms STATIC
    ${PROGRAM_SRCS})


# Add executable target with source files listed in GTEST_SRCS variable
add_executable(btunittest ${GTEST_SRCS})
add_executable(btunittestmore ${GTEST_SRCS_MORE})
add_executable(btsampletest ${SAMPLE_TEST_SRCS})
target_include_directories(binarytree PRIVATE include)
target_include_directories(samplebtree PRIVATE include)
target_include_directories(btreeprograms PRIVATE include)
target_include_directories(btunittest PRIVATE include)
target_include_directories(btunittestmore PRIVATE include)
target_include_directories(btsampletest PRIVATE include)
target_link_libraries(btunittest binarytree samplebtree btreeprograms gtest)
target_link_libraries(btunittestmore binarytree samplebtree btreeprograms gtest)
target_link_libraries(btsampletest binarytree samplebtree btreeprograms)
#target_link_libraries(bttest PRIVATE Qt6::Core)

