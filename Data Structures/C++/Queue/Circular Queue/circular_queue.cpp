#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include "node.cpp"
#include <iostream>

using namespace std;

class Queue {

Node **arr ;
int size , rear , front;

public:
    Queue (int size) {
        this->size = size ;
        arr = new Node*[size] ;
        front = rear = -1;
    }

    void enqueue (Node* data) {
        if (!isfull()) {
            rear = (rear + 1) % size ;
            arr[rear] = data ;
        }
        else cout << "Queue is full\n" ;
    }

    Node* dequeue () {
        if (!isempty()) {
            front = (front + 1) % size ;
            return arr[front];
        }
        else return NULL ;    
    }

    bool isempty() {
        if (front == rear) return true;
        return false ;
    }

    bool isfull(){
        if ((rear + 1) % size == front) return true;
        return false;
    }

};

#endif