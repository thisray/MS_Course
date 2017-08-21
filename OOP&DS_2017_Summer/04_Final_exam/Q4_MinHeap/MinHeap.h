#ifndef MinHeap_h
#define MinHeap_h

#include <iostream>
using namespace std;

/*
Command:
    - insert:
        insert an element into the heap.
    - delete:
        delete the min from the heap.
    - print:
        print the array elements from index 1 to N. (N = # of elements in the heap.)
*/

// *** spec say: the index 0 is not used. ***

// reference: https://goo.gl/O4uAVw

class MinHeap{
private:
    int * array;
    int size, last_index;

public:
    MinHeap();
    MinHeap(int);
    ~MinHeap();

    void expand();                  // expand the space of array
    void exchange(int &, int &);    // exchange 2 val in array
    void check();                   // check from last_index to root (index = 1)

    void _insert(int);
    void _delete();
    void _print();

};

MinHeap::MinHeap(){
    this->size = 100;
    this->array = new int [this->size];
    this->last_index = 1;
}

MinHeap::MinHeap(int set_size){
    this->size = set_size;
    this->array = new int [this->size];
    this->last_index = 1;
}

MinHeap::~MinHeap(){
    delete [] this->array;
}

void MinHeap::expand(){
    int new_size = this->size * 2;
    MinHeap new_heap(new_size);

    for(int i=0; i<this->last_index; i++){
        new_heap._insert(this->array[i]);
    }
    this->array = new_heap.array;
    this->size = new_size;
}

void MinHeap::exchange(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void MinHeap::check(){
    int parent_index, now_index = this->last_index;

    while(now_index > 1){
        parent_index = now_index / 2;

        if(this->array[now_index] < this->array[parent_index]){
            this->exchange(array[now_index], array[parent_index]);
        }
        // else{
        //     break;
        // }
        // now_index = parent_index;
        now_index = now_index -1;
    }
}

void MinHeap::_insert(int input_val){
    this->array[this->last_index] = input_val;
    this->check();
    this->last_index = this->last_index +1;

    if(this->last_index >= this->size){
        this->expand();
    }
}

// delete the min value
void MinHeap::_delete(){
    // use last element instead of root (min)
    this->last_index = this->last_index -1;
    this->array[1] = this->array[this->last_index];
    this->check();

}

void MinHeap::_print(){
    for(int i=1; i<this->last_index; i++){
        cout << this->array[i] << " ";
    }
    cout << endl;
}


#endif



/*

8 20 16
4 8 16 20
4 7 16 20 8
7 8 16 20

*/