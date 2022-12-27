cmake_minimum_required(VERSION 3.12)
project(binarytree)      

#find_package(Qt6 REQUIRED COMPONENTS Core)

# Add main.cpp file of project root directory as source file
set(GTEST_SRCS 
    src/binarytreeimpl.cpp
    tests/sample_btree.cpp 
    tests/btree_16nodes_test.cpp
    tests/main.cpp)

set(GTEST_SRCS_MORE 
    src/binarytreeimpl.cpp
    tests/sample_btree.cpp 
    tests/btree_1000nodes_test.cpp
    tests/main.cpp)

set(SAMPLE_SRCS 
    src/binarytreeimpl.cpp
    tests/sample_btree.cpp 
    tests/btree_validation_test.cpp)

# Add executable target with source files listed in GTEST_SRCS variable
add_executable(btunittest ${GTEST_SRCS})
add_executable(btunittestmore ${GTEST_SRCS_MORE})
add_executable(btsampletest ${SAMPLE_SRCS})
target_include_directories(btunittest PRIVATE include)
target_include_directories(btunittestmore PRIVATE include)
target_include_directories(btsampletest PRIVATE include)
target_link_libraries(btunittest gtest)
target_link_libraries(btunittestmore gtest)
#target_link_libraries(bttest PRIVATE Qt6::Core)

