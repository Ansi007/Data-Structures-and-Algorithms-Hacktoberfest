#ifndef CIRCULARQUEUE
#define CIRCULARQUEUE
#include <iostream>

using namespace std;

template <class t>

class Queue {

t *arr ;
int size , rear , front;

public:
    //Queue () {}
    Queue (int s=50) {
        this->size = s ;
        arr = new t[size] ;
        front = rear = 0;
    }

    void enqueue (t data) {
        if (!isfull()) {
            rear = (rear + 1) % size ;
            arr[rear] = data ;
        }
        else cout << "Queue is full\n" ;
    }

    t dequeue () {
        if (!isempty()) {
            front = (front + 1) % size ;
            return arr[front];
        }   
    }

    bool isempty() {
        if (front == rear  % size) return true;
        return false ;
    }

    bool isfull(){
        if ((rear + 1) % size == front) return true;
        return false;
    }

};

#endif
