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
    Queue (int s=100) {
        this->size = s ;
        arr = new t[size] ;
        front = rear = -1;
    }

    void enqueue (t data) {
        if (!isfull()) {
            rear = (rear + 1) % size ;
            arr[rear] = data ;
        }
       // else cout << "Queue is full\n" ;
    }

    t dequeue () {
        if (!isempty()) {
            front = (front + 1) % size ;
            return arr[front];
        }
        //else return NULL;     
    }

    bool isempty() {
        if (front == (rear + 1) % size) return true;
        return false ;
    }

    bool isfull(){
        if ((rear + 1) % size == front) return true;
        return false;
    }

};

#endif
