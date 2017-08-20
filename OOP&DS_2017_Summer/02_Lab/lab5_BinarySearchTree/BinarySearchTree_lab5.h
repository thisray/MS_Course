#ifndef BinarySearchTree_lab5_h
#define BinarySearchTree_lab5_h

#include <iostream>
using namespace std;

class BinarySearchTree;

class TreeNode{
    private:    
        friend class BinarySearchTree;
        int data;
        TreeNode * LeftChild, * RightChild;
        TreeNode(){ data = -1; LeftChild = RightChild = NULL; }
};


class BinarySearchTree{
    private:
        TreeNode * Root;
        void _insert(int, TreeNode *);
        void _clear(TreeNode *);
        void _print_inorder(TreeNode *);
        
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(int);
        void print_inorder();
};

BinarySearchTree::BinarySearchTree(){
    this->Root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    this->_clear(this->Root);
}

void BinarySearchTree::_clear(TreeNode * node){
    if(node != NULL){
        this->_clear(node->LeftChild);
        this->_clear(node->RightChild);
        delete node;
    }
}

void BinarySearchTree::insert(int insert_value){
    this->_insert(insert_value, this->Root);
}

void BinarySearchTree::_insert(int insert_value, TreeNode * node){

    if(this->Root == NULL){
        this->Root = new TreeNode;
        this->Root->data = insert_value;
    }
    else if(insert_value < node->data){
        if(node->LeftChild == NULL){
            node->LeftChild = new TreeNode;
            node->LeftChild->data = insert_value;
        }
        else{
            this->_insert(insert_value, node->LeftChild);
        }
    }
    else if(insert_value >= node->data){
        if(node->RightChild == NULL){
            node->RightChild = new TreeNode;
            node->RightChild->data = insert_value;
        }
        else{
            this->_insert(insert_value, node->RightChild);
        }
    }
}


void BinarySearchTree::print_inorder(){
    this->_print_inorder(this->Root);
    cout << endl;
}

void BinarySearchTree::_print_inorder(TreeNode * node){
    if(node != NULL){
        this->_print_inorder(node->LeftChild);
        cout << node->data << " ";
        this->_print_inorder(node->RightChild);
    }
}


#endif