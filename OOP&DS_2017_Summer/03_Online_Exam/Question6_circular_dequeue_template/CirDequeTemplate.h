#ifndef CirDequeTemplate_h
#define CirDequeTemplate_h


#include <iostream>
using namespace std;

// // ????? why need these ?????  (without these can't "cout" anything)
template<class T> 
class CirDequeTemplate;

template<class T> 
ostream & operator<<(ostream &, const CirDequeTemplate<T> &);


template<class T> 
class CirDequeTemplate{
    private:
        T data[10];
        int front, rear;

    public:
        CirDequeTemplate(){ rear = front = 9; }; // for test: for(int i=0; i<10; i++){ data[i] = 0;}
        void push_front(T); // push an element to the front of the deque
        void push_back(T); // push an element to the end of the deque
        T pop_front(); // pop an element from the front of the deque
        T pop_back(); // pop an element from the end of the deque
        friend ostream & operator<< <>(ostream &, const CirDequeTemplate &);
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
template<class T> 
void CirDequeTemplate<T>::push_front(T input){
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
template<class T> 
void CirDequeTemplate<T>::push_back(T input){
    int new_rear = (this->rear + 1) % 10;
    if(new_rear == this->front){
        cout << "queue is full" << endl;
    }
    else{
        this->rear = new_rear;
        this->data[this->rear] = input;
    }
}

template<class T> 
T CirDequeTemplate<T>::pop_front(){
    T return_val;
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

template<class T> 
T CirDequeTemplate<T>::pop_back(){
    T return_val;
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
template<class T> 
ostream & operator<<(ostream & os, const CirDequeTemplate<T> & cirdeque){
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















#endif