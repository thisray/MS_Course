//
//  main.cpp
//  c++final_3
//
//  Created by Andre on 2017/6/20.
//  Copyright © 2017年 Andre. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <queue>

using namespace std;

class BST;
class TreeNode{
private:
    int key;
    TreeNode* leftchild;
    TreeNode* rightchild;
    
public:
    TreeNode():leftchild(0),rightchild(0),key(0){};
    TreeNode(int a):leftchild(0),rightchild(0),key(a){};
    //~TreeNode(){
    //    delete leftchild;
    //    delete rightchild;
    //}
    friend class BST;
    friend void ppre(TreeNode* current);
    friend void ppost(TreeNode* current);
    friend void plevel(TreeNode* current);
};

class BST{
public:
    TreeNode *root;
    BST():root(0){};
    //~BST(){
        //BSTclear(root);
    //    delete root;
        
    //}
    void Search(int key);
    void InsertBST(int key);
    void BSTclear(TreeNode* current);
    void _BSTclear(TreeNode** current);
    void ppre(TreeNode* current);
    void ppost(TreeNode* current);
    void plevel(TreeNode* current);
    
};

void BST::Search(int KEY){
    TreeNode *current = root;               // 將curent指向root作為traversal起點
    int step = 1;
    while (current != NULL && KEY != current->key) {  // 兩種情況跳出迴圈：
        // 1.沒找到 2.有找到
        if (KEY < current->key){
            current = current->leftchild;   // 向左走
            step++;
        }
        else {
            current = current->rightchild;  // 向右走
            step++;
        }
    }
    if(current!=NULL)
        cout<<"hit "<<step<<endl;
    else
        cout<<"miss"<<endl;
}

void BST::BSTclear(TreeNode* current){
    
    if (current == NULL) return;
    
    /* first delete both subtrees */
    BSTclear(current->leftchild);
    BSTclear(current->rightchild);
    
    /* then delete the node */
    delete current;
}

void BST::_BSTclear(TreeNode** current){
    BSTclear(*current);
    
    *current = NULL;
    cout<<"done"<<endl;
}

void BST::InsertBST(int key){
    
    TreeNode *y = 0;        // 準新手爸媽
    TreeNode *x = 0;        // 哨兵
    TreeNode *insert_node = new TreeNode(key);   // insert_node為將要新增的node
    
    x = root;
    while (x != NULL) {                 // 在while中, 以如同Search()的方式尋找適當的位置
        y = x;                          // y先更新到原來x的位置
        if (insert_node->key < x->key){ // 判斷x是要往left- 還是right- 前進
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                   // 跳出迴圈後, x即為NULL
    // y即為insert_node的parent
    //insert_node->parent = y;            // 將insert_node的parent pointer指向y
    
    if (y == NULL){                     // 下面一組if-else, 把insert_node接上BST
        this->root = insert_node;
    }
    else if (insert_node->key < y->key){
        y->leftchild = insert_node;
    }
    else{
        y->rightchild = insert_node;
    }
}

void BST::ppre(TreeNode* current){
    if (!current){
        //cout<<endl;
        return;
    }
    cout << current->key<<" ";    // 先輸出樹根
    ppre(current->leftchild); // 次輸出左子樹
    ppre(current->rightchild);// 後輸right
    
}

void BST::ppost(TreeNode* current){
    if (!current){
        //cout<<endl;
        return;
    }
    ppost(current->leftchild);
    ppost(current->rightchild);
    cout << current->key<<" ";
    
}

void BST::plevel(TreeNode* current){
    queue<TreeNode*> q;
    q.push(current);
    
    while(!q.empty()){
        
        TreeNode* p =q.front();
        q.pop();
        cout<<p->key<<" ";
        if(p->leftchild)
            q.push(p->leftchild);
        if(p->rightchild)
            q.push(p->rightchild);
        
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    fstream fin;
    int number=0;
    BST tree;
    string line,fun;
    stringstream ss;
    fin.open("input.txt",ios::in);
    
    while(getline(fin,line)){
        ss.clear();
        ss.str(line);
        ss>>fun;
        if(fun == "i" || fun == "f"){
            ss>>number;
            if(fun == "i")
                tree.InsertBST(number);
            else if(fun == "f")
                tree.Search(number);
        }
        else if(fun == "ppre"){
            tree.ppre(tree.root);
            cout<<endl;
        }
        else if(fun == "ppost"){
            tree.ppost(tree.root);
            cout<<endl;
        }
        else if(fun == "plevel")
            tree.plevel(tree.root);
        else if(fun == "clear")
            tree._BSTclear(&tree.root);
        else if(fun == "z")
            break;
        fun.clear();
        line.clear();
    }
    
    return 0;
}















