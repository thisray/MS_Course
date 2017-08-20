#ifndef BinarySearhTree_h
#define BinarySearhTree_h

#include <iostream>
using namespace std;

class BinarySearhTree;      // use to make friend

class TreeNode{
    private:
        friend class BinarySearhTree;       // make friend to use private member
        int data;
        TreeNode *LeftChild; 
        TreeNode *RightChild;
        TreeNode(){ data = 0; LeftChild = RightChild = NULL; }     //
};

class BinarySearhTree{
    private:
        TreeNode *Root;
        void _insert(int, TreeNode *);
        void _find(int, TreeNode *, int);
        void _clear(TreeNode *);
        void _print_preorder(TreeNode *);
        void _print_postorder(TreeNode *);
        void _print_level_order(TreeNode *, int);

    public:
        BinarySearhTree(){ Root = NULL; };
        ~BinarySearhTree(){ this->clear(false); };      // false -> don't show "done"

        void insert(int input){ this->_insert(input, this->Root); };
        void find(int input){ this->_find(input, this->Root, 0); };
        void clear(bool show);
        void print_preorder(){ this->_print_preorder(this->Root); cout << endl; };
        void print_postorder(){ this->_print_postorder(this->Root); cout << endl; };

        int find_depth(TreeNode *);
        void print_level_order();
};

void BinarySearhTree::_insert(int input, TreeNode * node){
    // if(node == NULL){            // <--- why this error?
    //     node = new TreeNode;
    //     node->data = input;
    // }
    if(this->Root == NULL){
        this->Root = new TreeNode;
        this->Root->data = input;
    }
    else if(input < node->data){
        if(node->LeftChild != NULL){            // not NULL -> try to insert next
            this->_insert(input, node->LeftChild);
        }
        else if(node->LeftChild == NULL){       // NULL -> insert OK
            node->LeftChild = new TreeNode;
            node->LeftChild->data = input;      // insert here
        }
    }
    else if(input >= node->data){
        if(node->RightChild != NULL){
            this->_insert(input, node->RightChild);
        }
        else{
            node->RightChild = new TreeNode;
            node->RightChild->data = input;
        }
    }
}

void BinarySearhTree::_find(int input, TreeNode * node, int steps){
    steps = steps + 1;
    if(node != NULL){   
        if(input == node->data){                 // find!
            cout << "hit " << steps << endl;
        }
        else if(input < node->data){
            this->_find(input, node->LeftChild, steps);
        }
        else if(input > node->data){
            this->_find(input, node->RightChild, steps);
        }
    }
    else if(node == NULL){
        cout << "miss" << endl;
    }    
}

void BinarySearhTree::clear(bool show = true){
    this->_clear(this->Root);
    if(show == true){
        cout << "done" << endl;
    }
}

void BinarySearhTree::_clear(TreeNode * node){
    if(node != NULL){
        this->_clear(node->LeftChild);
        this->_clear(node->RightChild);
        delete node;                            // use "delete"
    }
}

void BinarySearhTree::_print_preorder(TreeNode * node){     // root -> left -> right
    if(node != NULL){
        cout << node->data << " ";
        this->_print_preorder(node->LeftChild);
        this->_print_preorder(node->RightChild);
    }
}

void BinarySearhTree::_print_postorder(TreeNode * node){    // left -> right -> root
    if(node != NULL){
        this->_print_postorder(node->LeftChild);
        this->_print_postorder(node->RightChild);
        cout << node->data << " ";
    }
}


// reference: http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
int BinarySearhTree::find_depth(TreeNode * node){
    if(node == NULL){
        return 0;
    }
    else{
        int left_depth = this->find_depth(node->LeftChild);
        int right_depth = this->find_depth(node->RightChild);
        if(left_depth > right_depth){
            return (left_depth + 1);
        }
        else{
            return (right_depth + 1);
        }
    }
}

void BinarySearhTree::print_level_order(){
    int depth = this->find_depth(this->Root);
    for(int i = 0; i < depth; i++){
        this->_print_level_order(this->Root, i);
    } 
    cout << endl; 
};

// reference: http://www.geeksforgeeks.org/level-order-tree-traversal/
void BinarySearhTree::_print_level_order(TreeNode * node, int level){   // root: level-0
    if(node != NULL){
        if(level == 0){
            cout << node->data << " ";
        }
        else if(level > 0){
            this->_print_level_order(node->LeftChild, level-1);
            this->_print_level_order(node->RightChild, level-1);
        }
    }
}


#endif 




/*

hit 1
miss
hit 3
25 20 10 22 50 40 30 60
10 22 20 30 40 60 50 25
25 20 50 10 22 40 60 30
done
miss
10 20 30 40
40 30 20 10
10 20 30 40
hit 4

*/

