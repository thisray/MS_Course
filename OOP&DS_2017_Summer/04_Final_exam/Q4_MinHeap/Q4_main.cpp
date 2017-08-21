
/*

4.(30%)
Please write a program that using an​ "array​" to implement a​ Min Heap​ with following
functions:​ insert​,​ delete​,​ print.
All numbers are integer.

Command:
    - insert:
        insert an element into the heap.
    - delete:
        delete the min from the heap.
    - print:
        print the array elements from index 1 to N. (N = # of elements in the heap.)

Submission:
● hand in your files. TA will not provide main function, you need to write your
own main function.
● If you have header file, please remember to submit.
● Use standard input and standard output to finish this question.
● Read until EOF(end of file)
● Cannot use STL.
● You can only include <iostream> and <cstring> library
● If your program​can’t stop​, you won’t get any grades.
Note that: the index 0 is not used.

*/

#include <iostream>
#include <cstring>
#include "MinHeap.h"

using namespace std;

int main(){

    string cmd;
    int val;
    MinHeap minheap;

    while(cin >> cmd){

        if(cmd == "insert"){
            cin >> val;
            minheap._insert(val);
        }
        else if(cmd == "delete"){
            minheap._delete();
        }
        else if(cmd == "print"){
            minheap._print();
        }

    }

    return 0;
}


















