#ifndef CirDeque_h
#define CirDeque_h

/*

5.(20%)
Implement a circular deque which have following function:
1. push_front() : Push an element to the front of the deque if the queue is NOT full, o.w.,
print "queue is full".
2. push_back() : Push an element to the end of the deque if the queue is NOT full, o.w.,
print "queue is full".
3. pop_front() : Pop an element from the front of the deque if the queue is NOT empty, o.w.,
print "queue is empty" and return 0.
4. pop_back() : Pop an element from the end of the deque if the queue is NOT empty, o.w.,
print "queue is empty" and return 0.
5. operator<< : Print the elements in queue from front to rear and separate each element by
a space.
The class declaration is below:

            ...

Please write your code in the file we gave.
You only need to update the .h file of the class definition.
We'll use our main function to test your code.
Please make sure your code is runnable. (we will run the command "g++ main.cpp

*/

#include <iostream>
using namespace std;

class CirDeque{
    private:
        int data[10];
        int front, rear;

    public:
        CirDeque(){rear = front = 9;  }; // for test: for(int i=0; i<10; i++){ data[i] = 0;}
        void push_front(int); // push an element to the front of the deque
        void push_back(int); // push an element to the end of the deque
        int pop_front(); // pop an element from the front of the deque
        int pop_back(); // pop an element from the end of the deque
        friend ostream & operator<<(ostream &, const CirDeque &);
        // print the elements in queue from front to rear and separate each element by a space.

        void for_check(){
            cout << "for_check: ";
            for(int i=0; i<10; i++){
             cout << this->data[i] << " ";
            }
            cout << " ,front: " << this->front << " ,rear: " << this->rear << endl;
        }
};
// you may write your code below this line


// check next -> put 'this'
void CirDeque::push_front(int input){
    int new_front = (this->front + 9) % 10;
    if(new_front == this->rear){
        cout << "queue is full" << endl;
    }
    else{
        this->data[this->front] = input;    
        this->front = new_front;
    }
}

// check next -> put 'next'
void CirDeque::push_back(int input){
    int new_rear = (this->rear + 1) % 10;
    if(new_rear == this->front){
        cout << "queue is full" << endl;
    }
    else{
        this->rear = new_rear;
        this->data[this->rear] = input;
    }
}

int CirDeque::pop_front(){
    int return_val;
    if(this->front == this->rear){
        cout << "queue is empty" << endl;
        return_val = 0;
    }
    else{
        return_val = this->data[(this->front +1) % 10];
        this->data[(this->front +1) % 10] = 0;
        this->front = (this->front +1) % 10;
    }
    return return_val;
}

int CirDeque::pop_back(){
    int return_val;
    if(this->front == this->rear){
        cout << "queue is empty" << endl;
        return_val = 0;
    }
    else{
        return_val = this->data[this->rear];
        this->data[this->rear] = 0;
        this->rear = (this->rear + 9) % 10;
    }
    return return_val;
}

// from (front +1) to (rear)
ostream & operator<<(ostream & os, const CirDeque & cirdeque){
    int start = 1, end = 0;

    start = (cirdeque.front +1) % 10;
    end = cirdeque.rear;

    if(start > end){
        for(int i=start; i<10; i++){
            os << cirdeque.data[i] << " ";
        }
        for(int i=0; i<=end; i++){
            os << cirdeque.data[i] << " ";
        }
    }
    else if(cirdeque.front == cirdeque.rear){
            os << " " ;
    }
    else{
        for(int i=start; i<=end; i++){
            os << cirdeque.data[i] << " ";
        }
    }

    return os;
}



// you may write your code above this line
#endif






/*

queue is empty
1 2 3 4 5
queue is full
9 8 7 6 1 2 3 4 5
8 7 6 1 2 3 4 5 9
7 6 1 2 3 4 5 9 8
6 1 2 3 4 5 9 8 7
1 2 3 4 5 9 8 7 6
queue is full
2 3 4 5 9 8 7 6 1
3 4 5 9 8 7 6 1 2
4 5 9 8 7 6 1 2 3
5 9 8 7 6 1 2 3 4
9 8 7 6 1 2 3 4 5
8 7 6 1 2 3 4 5 9
9 8 7 6 1 2 3 4 5
queue is full
5 9 8 7 6 1 2 3 4
4 5 9 8 7 6 1 2 3
3 4 5 9 8 7 6 1 2
2 3 4 5 9 8 7 6 1
1 2 3 4 5 9 8 7 6
queue is full
6 1 2 3 4 5 9 8 7
7 6 1 2 3 4 5 9 8
queue is full
8 7 6 1 2 3 4 5 9
9 8 7 6 1 2 3 4 5
8 7 6 1 2 3 4 5
8 7 6 1 2 3 4
7 6 1 2 3 4
7 6 1 2 3
7 6 1 2
6 1 2
6 1
1

queue is empty

queue is empty

queue is empty

queue is empty

queue is empty


*/