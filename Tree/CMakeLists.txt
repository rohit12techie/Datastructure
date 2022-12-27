cmake_minimum_required(VERSION 3.12)
project(binarytree)      

#find_package(Qt6 REQUIRED COMPONENTS Core)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES 
    src/binarytreeimpl.cpp
    tests/createbinarytree.cpp 
    tests/test_btree.cpp
    tests/main.cpp)

set(SOURCES 
    src/binarytreeimpl.cpp
    tests/createbinarytree.cpp 
    tests/test_binary_tree.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(btgoogletest ${SOURCE_FILES})
add_executable(bttest ${SOURCES})
target_include_directories(btgoogletest PRIVATE include)
target_include_directories(bttest PRIVATE include)
target_link_libraries(btgoogletest gtest)
#target_link_libraries(bttest PRIVATE Qt6::Core)

