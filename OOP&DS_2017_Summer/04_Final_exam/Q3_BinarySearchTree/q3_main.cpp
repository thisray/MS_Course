/*

3.(40%)
Binary Searh Tree -- preorder(10%)
-- postorder(10%)
-- level-order(10%)
-- find(10%)
All numbers are integer.
Command
-i : insert the following number to the tree
-f : find the following number is in the tree or not
1. if is find in the tree, print “hit s“
    a. s is the steps during your search
2. if not find, print “miss”
-clear : clear the tree and output “done”
-ppre : print the preorder of the BST
-ppost : print the postorder of the BST
-plevel : print the level order of the BST
-z : last cmd , no need to get the next command

Submission
● hand in your files, TA will not provide main function, you need to write
your own main function
● you can write in class or data structure
● if you have header file, please remember to submit
● Use standard input and standard output to finish this question
● Cannot use STL
● You can only include <iostream> and <cstring> library
● If your program​can’t stop​, you won’t get any grades.

*/

#include <iostream>
#include <cstring>
#include "BinarySearhTree.h"

using namespace std;

int main(){

    BinarySearhTree bst;
    string cmd;
    int val;
    while(cin >> cmd){

        // cout << "cmd: " << cmd << endl;

        if(cmd == "i"){             // insert
            cin >> val;
            bst.insert(val);
        }
        else if(cmd == "f"){        // find
            cin >> val;
            bst.find(val);
        }
        else if(cmd == "clear"){    // clear, output "done"
            bst.clear(true);
        }
        else if(cmd == "ppre"){     // print the preorder
            bst.print_preorder();
        }
        else if(cmd == "ppost"){    // print the postorder
            bst.print_postorder();
        }
        else if(cmd == "plevel"){   // print the level order
            bst.print_level_order();
        }
        else if(cmd == "z"){        // last cmd, no need to get the next command
            // bst.clear(false);
            break;
        }
    }
    return 0;
}




