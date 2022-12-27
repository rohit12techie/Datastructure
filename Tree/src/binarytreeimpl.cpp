#include <iostream>
#include "binarytree.hpp"

BinaryTree::BinaryTree(){
    //std::cout<<"Constructor is called"<<std::endl;
    this->btroot = NULL;
}

BinaryTree::~BinaryTree(){
    //std::cout<<"Destructor is called"<<std::endl;
}

Node* BinaryTree::getRoot(){
    return this->btroot;
}

void BinaryTree::insert(Node* &root, int num){

    if(this->btroot == nullptr){
        this->btroot = new Node(num);
        return;
    }

    if(root == nullptr){
        root = new Node(num);
    }
    else{
        if( num < root->data) 
            insert(root->left, num);
        else
            insert(root->right, num);
    }
}

Node* BinaryTree::find(Node* root, int val){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == val){
        return root;
    }
    
    Node* findLeft = find(root->left, val);
    if(findLeft != nullptr){
        return findLeft;
    }

    Node* findRight = find(root->right, val);
    if(findRight != nullptr){
        return findRight;
    }

    return nullptr;
}

Node* BinaryTree::update(Node* root, int oldval, int newval){
    Node* updateNode = find(root, oldval);
    if(updateNode != nullptr){
        updateNode->data = newval;
    }
    return updateNode;
}

Node* BinaryTree::minOnRight(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->left == nullptr){
        return root;
    }
    return minOnRight(root->left);
}


Node* BinaryTree::maxOnLeft(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->right == nullptr){
        return root;
    }
    return maxOnLeft(root->right);
}

Node* BinaryTree::removeNode(Node* root, int val){
    if(root != nullptr){
        if(root->data == val){
            if(root->left == nullptr && root->right == nullptr){
                delete(root);
                return nullptr;
            }
            else if(root->left == nullptr){
                Node* tmp = root->right;
                delete(root);
                return tmp;
            }
            else if(root->right == nullptr){
                Node* tmp = root->right;
                delete(root);
                return tmp;
            }
            else{
                Node *tmp = minOnRight(root->right);
                std::swap(tmp->data, root->data);
                root->right = removeNode(tmp, tmp->data);
                return root;
            }
        }
    }
    return nullptr;
}

Node* BinaryTree::remove(Node* root, int val){
    if(root != nullptr){
        if(root->data == val){
            root = removeNode(root, val);
            this->btroot = root;
        }
        else{
            Node* pleft = find(root->left, val);
            if(pleft != nullptr){
                root->left = removeNode(pleft, val);
            }
            else{
                Node* pright = find(root->right, val);
                if(pright != nullptr){
                    root->right = removeNode(pright, val);
                }   
            }
        }
    }
    return root;
}

void BinaryTree::showInOrder(Node* root){
    if(root != nullptr){
        showInOrder(root->left);
        std::cout<<root->data<<" ";
        showInOrder(root->right);
    }
}

void BinaryTree::showPreOrder(Node* root){
    if(root != nullptr){
        std::cout<<root->data<<" ";
        showInOrder(root->left);
        showInOrder(root->right);
    }
}

void BinaryTree::showPostOrder(Node* root){
    if(root != nullptr){
        showInOrder(root->left);
        showInOrder(root->right);
        std::cout<<root->data<<" ";
    }
}

void BinaryTree::printLevel(Node* root, int level){
    if(root != nullptr){
        if(level == 0){
            std::cout<<root->data<<" ";
        }
        else{
            printLevel(root->left, level-1);
            printLevel(root->right, level-1);
        }
    }
}

void BinaryTree::showLevelOrder(Node* root){
    int height = getHeight(root);
    //std::cout<<"root: "<<root <<"Height : "<<height<<std::endl;
    for(int i=0; i<height; i++){
        printLevel(root, i);
        std::cout<<"\n";
    }
}

int BinaryTree::getHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void BinaryTree::getLevelWidth(Node *root, int level, int &count){
    if(root != nullptr){
        if(level == 0){
            count = count + 1;
        }
        getLevelWidth(root->left, level-1, count);
        getLevelWidth(root->right, level-1, count);
    }
}

int BinaryTree::getWidth(Node* root){
    int height = getHeight(root);
    int width = INT32_MIN;
    for(int i=0; i<height; i++){
        int count = 0;
        getLevelWidth(root, i, count);
        width = std::max(width, count);
    }
    return width;
}

int BinaryTree::getSize(Node* root){
    int height = getHeight(root);
    int btsize = 0;
    for(int i=0; i<height; i++){
        int count = 0;
        getLevelWidth(root, i, count);
        btsize+=count;
    }
    return btsize;
}