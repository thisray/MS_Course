
/*

input file format:
    line1: # of testing data
    line(2k): # of nodes to construct BST
    line(2K+1): A series of integers that are not duplicated

output format:
    inorder traversal 
    (each number should be separated by a single space, and each traversal
    result should be separated by a newline.)


example input:
    2
    1
    33
    3
    18 30 2

output:
    33
    2 18 30

*/

#include <iostream>
#include <cstring>
#include "BinarySearchTree_lab5.h"
using namespace std;

int main(){

    int input_number, nodes_number, insert_value;

    cin >> input_number;

    while(input_number--){
        BinarySearchTree bst;
        cin >> nodes_number;

        while(nodes_number--){
            cin >> insert_value;
            bst.insert(insert_value);
        }

        bst.print_inorder();
    }
}


/*

33
2 18 30
10 20 22 25 40 50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
33 35 37 40 43 45 47 50 53 55 57 60 63 65 67

*/
